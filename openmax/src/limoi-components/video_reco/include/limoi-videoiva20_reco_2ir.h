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

  OpenMAX IL implementation - ffmpeg video encoder component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-05-19 MG
*/

/** @addtogroup limoi_component_ffmpeg_enc
 * @{
 */

#ifndef LIMOI_VIDEOIVA20_RECO_2IR_H__
#define LIMOI_VIDEOIVA20_RECO_2IR_H__

#include "limoi.h"

/** video src camera component private data structure. */
typedef struct
{
    limoi_videoIVA20_t parent; /** inherit limoi video src. */

} videoIVA20_reco_2ir_private_t;

#define LIMOI_VIDEOIVA20_RECO_2IR(c) ((videoIVA20_reco_2ir_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_VIDEOIVA11_RECO_IR_H__ */
