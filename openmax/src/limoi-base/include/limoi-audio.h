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

  OpenMAX IL implementation - limoi audio component common header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-02-03 MG
*/

/** @defgroup limoi_base_audio_decoder audio decoder base
 * @ingroup limoi_base_audio
 */

/** @defgroup limoi_base_audio_encoder audio encoder base
 * @ingroup limoi_base_audio
 */

/** @defgroup limoi_base_audio_renderer audio renderer base
 * @ingroup limoi_base_audio
 */

/** @addtogroup limoi_base_audio
 * @{
 */

#ifndef LIMOI_AUDIO_COMPONENT_H__
#define LIMOI_AUDIO_COMPONENT_H__

#include "limoi-component.h"

/** limoi component audio format structure. */
typedef struct
{
    OMX_AUDIO_CODINGTYPE coding_type;
} limoi_audio_format_t;

/** @} */
#endif /* LIMOI_AUDIO_COMPONENT_H__ */
