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

  OpenMAX IL implementation - limoi video component internal header.

  REVISION:

    1) initial creation. ----------------------------------------- 2011-04-23 MG
*/

#ifndef LIMOI_VIDEO_PRIVATE_H__
#define LIMOI_VIDEO_PRIVATE_H__

#include "../component.h"

/** @addtogroup limoi_base_private
 * @{
 */

/** limoi_video_renderer component private data structure. */
struct limoi_video_renderer_priv_t
{
    limoi_video_renderer_callbacks_t callbacks; /** renderer callbacks. */
};

/** limoi_video_scheduler component private data structure. */
struct limoi_video_scheduler_priv_t
{
    limoi_video_scheduler_callbacks_t callbacks; /** scheduler callbacks. */
};

/** limoi_video_decoder component private data structure. */
struct limoi_video_decoder_priv_t
{
    limoi_video_decoder_callbacks_t callbacks; /** decoder callbacks. */
};

/** limoi_video_encoder component private data structure. */
struct limoi_video_encoder_priv_t
{
    limoi_video_encoder_callbacks_t callbacks; /** encoder callbacks. */
};

/** @} */
#endif /* LIMOI_VIDEO_PRIVATE_H__ */
