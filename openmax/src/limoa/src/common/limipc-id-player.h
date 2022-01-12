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

  OpenMAX AL engine implementation - player object ipc ID definitions.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-17 MG
*/

/** @addtogroup limoa_generics
 * @{
 */

#ifndef LIMIPC_ID_PLAYER_H__
#define LIMIPC_ID_PLAYER_H__

// all requests requires a standard default response as ipc_standard_rsps_t,
// unless otherwise specified or commented below.

// player message ID
#define OX_RQST_PLAYER_CREATE                      MSG(SGMT_PLAYER, 1)
typedef struct
{
    void * ptrbase;
    XADataSource data_src;
    XADataSource bank_src;
    XADataSink audio_snk;
    XADataSink image_video_snk;
    XADataSink vibra_snk;
    XADataSink LED_array_snk;
} ox_rqst_player_create_t;

#define OX_RQST_PLAYER_REALIZE                     MSG(SGMT_PLAYER, 2)
typedef struct
{
    XAboolean async;
} ox_rqst_player_realize_t;

#define OX_RQST_PLAYER_DESTROY                     MSG(SGMT_PLAYER, 3)
#define OX_RQST_PLAYER_PLAY                        MSG(SGMT_PLAYER, 4)
#define OX_RQST_PLAYER_PAUSE                       MSG(SGMT_PLAYER, 5)
#define OX_RQST_PLAYER_STOP                        MSG(SGMT_PLAYER, 6)

#define OX_RQST_PLAYER_GET_POSITION                MSG(SGMT_PLAYER, 7)
typedef struct
{
    XAresult result;
    XAmillisecond pos;
} ox_rsps_player_get_position_t;

#define OX_RQST_PLAYER_REGISTER_CALLBACK           MSG(SGMT_PLAYER, 20)
// no response required
typedef struct
{
    XAPlayItf caller;
    xaPlayCallback func;
    void * context;
} ox_rqst_player_register_callback_t;

#define OX_RQST_PLAYER_SET_CALLBACK_EVENTS_MASK    MSG(SGMT_PLAYER, 21)
// no response required
typedef struct
{
    XAuint32 mask;
} ox_rqst_player_set_callback_events_mask_t;

#define OX_RQST_PLAYER_SET_POSITION                MSG(SGMT_PLAYER, 22)
typedef struct
{
    XAmillisecond pos;
    XAuint32 seek_mode;
} ox_rqst_player_set_position_t;

/** @} */
#endif /* LIMIPC_ID_PLAYER_H__ */
