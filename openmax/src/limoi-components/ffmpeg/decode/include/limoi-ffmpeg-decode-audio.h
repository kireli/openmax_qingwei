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

  OpenMAX IL implementation - ffmpeg audio decoder component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-02-17 MG
*/

/** @addtogroup limoi_component_ffmpeg_dec
 * @{
 */

#ifndef LIMOI_FFMPEG_AUDIO_DECODER_H__
#define LIMOI_FFMPEG_AUDIO_DECODER_H__

#include "config.h"
#include "limoi.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/audioconvert.h"
#include "omx-ffmpeg.h"

/** ffmpeg audio decoder component private data structure. */
typedef struct
{
    limoi_audio_decoder_t parent; /** inherit limoi audio decoder. */

    int inited; /** decoder initialization state. */

    enum SampleFormat pcm_format; /** pcm output format. */
    AVAudioConvert * reformat; /** pcm reformat contex. */
    int pcm_channels; /** pcm output channels. */
    int pcm_sample_rate; /** pcm sampling rate. */

    int avcodec_allocated; /** is avcodec allocated by component? */
    AVStream * stream; /** active stream. */
    AVCodecContext * avcodec; /** av codec context. */
    AVCodec * codec; /** av codec. */
    AVPacket avpkt; /** decoder input packet. */
} ffmpeg_adecoder_private_t;

#define LIMOI_FFMPEG_ADECODER(c) ((ffmpeg_adecoder_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_FFMPEG_AUDIO_DECODER_H__ */
