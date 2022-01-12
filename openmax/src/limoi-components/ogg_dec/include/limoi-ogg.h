/*
  Copyright (C) 2009-2011 SWOAG Technology <www.swoag.com>

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

  OpenMAX IL implementation - ogg audio decoder component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-12-22 MG
*/

/** @defgroup limoi_component_ogg_dec limoi ogg decoder component
 * @ingroup limoi_components
 * @{
 */

#ifndef LIMOI_OGG_H__
#define LIMOI_OGG_H__

#include "config.h"
#include "limoi.h"
#include <vorbis/codec.h>
#include <math.h>

/** ogg decoder component private data structure. */
typedef struct
{
    limoi_audio_decoder_t audio_decoder; /** inherit limoi audio decoder. */
    int header_counts; /** stream header counts. */
    int decoder_inited; /** decoder initialization state. */
    int decoder_pcm_ready; /** decoder has PCM output ready. */
    int decoder_first_time; /** first time decoding op. */

    ogg_sync_state oy; /** sync and verify incoming physical bitstream */
    ogg_stream_state os; /** take physical pages, weld into a logical
                             stream of packets */
    ogg_page og; /** one Ogg bitstream page. Vorbis packets are inside */
    ogg_packet op; /** one raw packet of data for decode */
    vorbis_info vi; /** struct that stores all the static vorbis
                        bitstream settings */
    vorbis_comment vc; /** struct that stores all the bitstream
                           user comments */
    vorbis_dsp_state vd; /** central working state for the
                             packet->PCM decoder */
    vorbis_block vb; /** local working space for packet->PCM decode */
} ogg_private_t;

#define LIMOI_OGG_DEC(c) ((ogg_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_OGG_H__ */
