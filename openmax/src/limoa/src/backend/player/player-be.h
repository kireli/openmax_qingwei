/*
  Copyright (C) 2009 - 2011 SWOAG Technology <www.swoag.com>

  This library is free software; you can redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation; either version 2.1 of the License, or (at your option)
  any later version.

  This library is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
  details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St, Fifth Floor, Boston, MA
  02110-1301  USA

  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  OpenMAX AL ENGINE - player back end header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-17 MG
*/

/** @addtogroup limoa_backend
 * @{
 */

#ifndef PLAYER_BE_H__
#define PLAYER_BE_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <OMX_Core.h>
#include <OMX_Audio.h>
#include <OMX_Types.h>
#include <OMX_Component.h>
#include "OpenMAXAL.h"
#include "limipc.h"
#include "limqlist.h"
#include "limthread.h"
#include "limmemory.h"
#include "limtime.h"
#include "ox-session.h"

/** player state bit-map flags. */
#define PSF_INVALID                      0x80000000
#define PSF_EOS_DETECTED                 0x00000010
#define PSF_PAUSE                        0x00000008
#define PSF_EXECUTING                    0x00000004
#define PSF_IDLE                         0x00000002
#define PSF_LOADED                       0x00000001

/** player port state bit-map-flags. */
#define PSF_PORT_ENABLED(p)              (1 << (p))
#define PSF_PORT_DISABLED(p)             (1 << ((p) + 8))
#define PSF_PORT_FLUSHED(p)              (1 << ((p) + 16))
#define PSF_PORT_SETTINGS_CHANGED(p)     (1 << ((p) + 24))

/** player synchronization thread state. */
typedef enum
{
    OPSS_INVALID,
    OPSS_IDLE,
    OPSS_STOP,
} ox_player_sync_state_t;

/** player synchronization request bit-map flags. */
#define PSR_AUDIO_DECODER_OUTPUT_PORTSETTINGSCHANGED    0x00000001
//wait for: audio tunnel input port disable
//          audio tunnel input port disable

#define PSR_VIDEO_DECODER_OUTPUT_PORTSETTINGSCHANGED    0x00010000
//wait for: video decoder output port disable
//          video tunnel input port disable

#define PSR_VIDEO_SCHEDULER_INPUT_PORTSETTINGSCHANGED   0x00020000
//wait for: video scheduler output port disable
//          video tunnel input port disable

#define PSR_DECODER_OUTPUT_ENABLE                       0x40000000
//wait for: audio sink output port enable if audio is present
//          video sink output port enable if video is present

#define PSR_DEMUXER_EOS_DETECTED                        0x80000000
//wait for: audio sink EOS event if audio is present
//          video sink EOS event if video is present

typedef struct
{
    // session reference
    ox_session_t * ox;

    // player source sink parameters
    // actual data may contain in buffer pointed to by source_sink_dptr
    XADataSource data_src;
    XADataSource bank_src;
    XADataSink audio_snk;
    XADataSink image_video_snk;
    XADataSink vibra_snk;
    XADataSink LED_array_snk;
    void * source_sink_dptr;

    // player omx handles
    OMX_HANDLETYPE demux_handle;
    OMX_HANDLETYPE clock_handle;
    OMX_HANDLETYPE audio_decode_handle;
    OMX_HANDLETYPE audio_sink_handle;
    OMX_HANDLETYPE video_decode_handle;
    OMX_HANDLETYPE video_scheduler_handle;
    OMX_HANDLETYPE video_sink_handle;

    // player state mgmt variables
    lthread_mutex_t mutex;
    lthread_cond_t cond;

    /** thread to monitor component callbacks and synchronize. */
    lthread_t sync_thread;
    int sync_state; /** sync thread state @ref ox_player_sync_state_t. */
    uint32_t sync_flags; /** sync thread request flags. */

    uint32_t demux_flags;
    uint32_t clock_flags;
    uint32_t audio_decode_flags;
    uint32_t audio_sink_flags;
    uint32_t video_decode_flags;
    uint32_t video_scheduler_flags;
    uint32_t video_sink_flags;
    uint32_t demux_port_flags;
    uint32_t clock_port_flags;
    uint32_t audio_decode_port_flags;
    uint32_t audio_sink_port_flags;
    uint32_t video_decode_port_flags;
    uint32_t video_scheduler_port_flags;
    uint32_t video_sink_port_flags;

    // player callback to client
    ox_callback_play_t callback;
    XAuint32 callback_events_mask;

    /** dummy buffer for demuxer initialization
     * to fool demuxer output port so that content can be discovered without
     * actually allocating any buffer.
     */
    OMX_U8 dummy_buf[1];
} ox_player_t;


int player_parse_packet (
    ox_session_t * ox,
    ipc_packet_t * rqst,
    ipc_packet_t * rsps);


/** create backend player object.
 *
 * @param player
 *        player object pointer.
 * @return
 *        OpenMAXAL object realize error code.
 */
XAresult ox_player_realize (ox_player_t * player);


/** destroy backend player object.
 *
 * @param player
 *        player object pointer.
 * @return
 *        0 if successful, non-zero otherwise.
 */
int ox_player_destroy (ox_player_t * player);


/** player interface start playing.
 *
 * @param player
 *        player object pointer.
 * @return
 *        OpenMAXAL error code.
 */
XAresult ox_player_play (ox_player_t * player);


/** player interface pause playing.
 *
 * @param player
 *        player object pointer.
 * @return
 *        OpenMAXAL error code.
 */
XAresult ox_player_pause (ox_player_t * player);


/** player interface stop playing.
 *
 * @param player
 *        player object pointer.
 * @return
 *        OpenMAXAL error code.
 */
XAresult ox_player_stop (ox_player_t * player);


/** player interface get position.
 *
 * @param player
 *        player object pointer.
 * @param pos
 *        current playback position in millisecond.
 * @return
 *        OpenMAXAL error code.
 */
XAresult ox_player_get_position (ox_player_t * player, XAmillisecond * pos);


/** player seek interface set position.
 *
 * @param player
 *        player object pointer.
 * @param pos
 *        target playback position in millisecond.
 * @param seek_mode
 *        seek mode.
 * @return
 *        OpenMAXAL error code.
 */
XAresult ox_player_set_position (
    ox_player_t * player,
    XAmillisecond pos,
    XAuint32 seek_mode);

/** @} */
#endif /* PLAYER_BE_H__ */
