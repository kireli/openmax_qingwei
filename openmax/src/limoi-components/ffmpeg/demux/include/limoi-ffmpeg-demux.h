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

  OpenMAX IL implementation - ffmpeg demuxer component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-01-28 MG
*/

/** @addtogroup limoi_component_ffmpeg_demux
 * @{
 */

#ifndef LIMOI_FFMPEG_DEMUXER_H__
#define LIMOI_FFMPEG_DEMUXER_H__

#include "config.h"
#include "limoi.h"
#include "omx-ffmpeg.h"

/** bytes IO context buffer size in bytes. */
#define FFMPEG_BIO_BUFFER_SIZE (1024 * 8)


/** ffmpeg demuxer content pipe callback support structure. */
typedef struct
{
    CP_PIPETYPE * pipe; /** content pipe. */
    CPhandle content; /** content pipe content. */
    OMX_HANDLETYPE hComp; /** demuxer component handle. */

    /** content bytes available
     * communicated thru pipe callback, upon pipe busy or starving.
     */
    CPuint bytes_available;
} ffmpeg_cb_t;

/** ffmpeg demuxer component private data structure. */
typedef struct
{
    limoi_demuxer_t parent; /** inherit limoi demuxer. */

    ffmpeg_cb_t cb; /** ffmpeg demuxer content pipe callback support. */

    AVIOContext * bio; /** ffmpeg byte IO context. */
    unsigned char bio_buffer[FFMPEG_BIO_BUFFER_SIZE]; /** byte IO buffer. */

    AVFormatContext * avformat; /** av format context. */

    OMX_U8 uri[LIMOI_URI_MAX_LENGTH]; /** content URI. */

    char * metadata_language_country;
    int metadata_scope;
    int metadata_scope_specifier;
    int metadata_count;

    int active_audio_index;
    int active_video_index;
} ffmpeg_demuxer_private_t;

#define LIMOI_FFMPEG_DEMUXER(c) ((ffmpeg_demuxer_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_FFMPEG_DEMUXER_H__ */
