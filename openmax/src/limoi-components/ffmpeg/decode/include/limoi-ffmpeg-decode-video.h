/*
  Copyright (C) 2010 - 2011 SWOAG Technology <www.swoag.com>

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

  OpenMAX IL implementation - ffmpeg video decoder component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-02-17 MG
*/

/** @addtogroup limoi_component_ffmpeg_dec
 * @{
 */

#ifndef LIMOI_FFMPEG_VIDEO_DECODER_H__
#define LIMOI_FFMPEG_VIDEO_DECODER_H__

#include "config.h"
#include "limoi.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "omx-ffmpeg.h"

/** ffmpeg video decoder component private data structure. */
typedef struct
{
    limoi_video_decoder_t parent; /** inherit limoi video decoder. */

    int inited; /** decoder initialization state. */
    int has_frame; /** decoder has picture in output frame to be consumed. */

    OMX_TICKS pts; /** decoder previous pts. */
    int avcodec_allocated; /** is avcodec allocated by component? */
    AVStream * stream; /** active stream. */
    AVCodecContext * avcodec; /** av codec context. */
    AVCodec * codec; /** av codec. */
    AVPacket avpkt; /** decoder input packet. */
    AVFrame frame; /** decoder output frame. */
    struct SwsContext * sws; /** software scaler context. */
} ffmpeg_vdecoder_private_t;

#define LIMOI_FFMPEG_VDECODER(c) ((ffmpeg_vdecoder_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_FFMPEG_VIDEO_DECODER_H__ */
