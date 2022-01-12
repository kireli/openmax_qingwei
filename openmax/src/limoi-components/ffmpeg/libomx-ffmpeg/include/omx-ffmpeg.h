/*
  Copyright (C) 2011 SWOAG Technology <www.swoag.com>

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

  OpenMAX IL implementation - openmax ffmpeg wrapper library header.

  REVISION:

    1) initial creation. ----------------------------------------- 2011-03-08 MG
*/

/** @defgroup limoi_component_ffmpeg limoi ffmpeg component
 * @ingroup limoi_components
 */

/** @defgroup limoi_component_ffmpeg_omx openmax ffmpeg wrapper library
 * @ingroup limoi_component_ffmpeg
 */

/** @defgroup limoi_component_ffmpeg_demux ffmpeg demuxer component
 * @ingroup limoi_component_ffmpeg
 */

/** @defgroup limoi_component_ffmpeg_mux ffmpeg muxer component
 * @ingroup limoi_component_ffmpeg
 */

/** @defgroup limoi_component_ffmpeg_dec ffmpeg decoder component
 * @ingroup limoi_component_ffmpeg
 */

/** @defgroup limoi_component_ffmpeg_enc ffmpeg encoder component
 * @ingroup limoi_component_ffmpeg
 */

/** @addtogroup limoi_component_ffmpeg_omx
 * @{
 */

#ifndef OMX_FFMPEG_H__
#define OMX_FFMPEG_H__

#include "limoi.h"
#include "libavformat/avformat.h"

/** OpenMax to ffmpeg audio codec ID translation.
 *
 * @param omx_codec_id
 *        OpenMax codec ID.
 * @return
 *        ffmpeg coding ID.
 */
int omx_ffmpeg_audio_codec_id_omx2ffmpeg (int omx_codec_id);

/** OpenMax to ffmpeg video codec ID translation.
 *
 * @param omx_codec_id
 *        OpenMax codec ID.
 * @return
 *        ffmpeg coding ID.
 */
int omx_ffmpeg_video_codec_id_omx2ffmpeg (int omx_codec_id);

/** ffmpeg to OpenMax codec ID translation.
 *
 * @param ffmpeg_codec_id
 *        ffmpeg codec ID.
 * @return
 *        OpenMax codec ID.
 */
int omx_ffmpeg_codec_id_ffmpeg2omx (int ffmpeg_codec_id);

/** ffmpeg codec interface initialization.
 *
 * @return
 *        0 upon success, non-zero otherwise.
 */
int omx_ffmpeg_codec_init (void);

/** ffmpeg muxer/demuxer interface initialization.
 *
 * @return
 *        0 upon success, non-zero otherwise.
 */
int omx_ffmpeg_mux_init (void);

/** @} */
#endif /* OMX_FFMPEG_H__ */
