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

  OpenMAX IL implementation - limoi video component common header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-02-03 MG
*/

/** @defgroup limoi_base_video_decoder video decoder base
 * @ingroup limoi_base_video
 */

/** @defgroup limoi_base_video_encoder video encoder base
 * @ingroup limoi_base_video
 */

/** @defgroup limoi_base_video_renderer video renderer base
 * @ingroup limoi_base_video
 */

/** @defgroup limoi_base_video_scheduler video scheduler base
 * @ingroup limoi_base_video
 */

/** @addtogroup limoi_base_video
 * @{
 */

#ifndef LIMOI_VIDEO_COMPONENT_H__
#define LIMOI_VIDEO_COMPONENT_H__

#include "limoi-component.h"

/** limoi component video format structure. */
typedef struct
{
    OMX_VIDEO_CODINGTYPE coding_type;
    OMX_COLOR_FORMATTYPE color_format;
    OMX_U32 framerate;
} limoi_video_format_t;

/** @} */
#endif /* LIMOI_VIDEO_COMPONENT_H__ */
