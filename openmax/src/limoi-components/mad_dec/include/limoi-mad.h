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

  OpenMAX IL implementation - alsa sink component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-12-22 MG
*/

/** @defgroup limoi_component_mad_dec limoi mad docoder component
 * @ingroup limoi_components
 * @{
 */

#ifndef LIMOI_MAD_H__
#define LIMOI_MAD_H__

#include "config.h"
#include "limoi.h"
#include <mad.h>

#define LIMOI_MAD_BITSTREAM_BUFFER_BYTES 8192

/** alsa component private data structure. */
typedef struct
{
    limoi_audio_decoder_t audio_decoder; /** inherit limoi audio decoder. */
    int decoder_inited; /** decoder initialization state. */
    int bitstream_bytes; /** bytes in bitstream buffer. */
    unsigned char * bitstream_buf; /** decoder scratch bitstream buffer. */
    struct mad_decoder decoder;
} mad_private_t;

#define LIMOI_MAD_DEC(c) ((mad_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_MAD_H__ */
