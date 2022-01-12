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

    1) initial creation. ----------------------------------------- 2009-11-25 MG
*/

/** @defgroup limoi_component_alsa_sink limoi alsa sink component
 * @ingroup limoi_components
 * @{
 */

#ifndef LIMOI_ALSA_H__
#define LIMOI_ALSA_H__

#include "config.h"
#include "limoi.h"
#include <alsa/asoundlib.h>

#define LIMOI_ALSA_LATENCY 100 /** alsa layer latency in miliseconds. */


/** alsa component private data structure. */
typedef struct
{
    limoi_audio_renderer_t audio_renderer; /** inherit limoi audio renderer. */
    snd_pcm_t * handle; /** PCM handle. */
    int sample_step; /** sample step in bytes = channels * sample width. */
    int sample_rate; /** sample rate in Hz. */
    OMX_TICKS prev_timestamp; /** previous frame timestamp.*/
} alsa_private_t;

#define LIMOI_ALSA_SINK(c) ((alsa_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_ALSA_H__ */
