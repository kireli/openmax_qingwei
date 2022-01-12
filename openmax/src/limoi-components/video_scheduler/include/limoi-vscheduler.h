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

  OpenMAX IL implementation - video scheduler component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-02-27 MG
*/

/** @defgroup limoi_component_video_scheduler limoi video scheduler component
 * @ingroup limoi_components
 * @{
 */

#ifndef VIDEO_SCHEDULER_H__
#define VIDEO_SCHEDULER_H__

#include "config.h"
#include "limoi.h"


/** video scheduler media time request private data structure. */
typedef struct {
    void * priv; /** actual buffer been scheduled. */
    uint32_t id; /** running ID of the buffer scheduled. */
} vsm_rqst_priv_t;


/** video scheduler component private data structure. */
typedef struct
{
    limoi_video_scheduler_t parent; /** inherit limoi video scheduler. */

    int clock_scale_set; /** flag to indicate that clock scale has been set. */
    OMX_S32 clock_scale; /** current media clock scale. */
    int clock_running; /** is current media clock running yet? */
    int reference_clock; /** is this component a reference clock provider? */

    /** buffer pool for internal buffer hold tracking. */
    vsm_rqst_priv_t hold_buf_pool[LIMOI_MAX_CLOCK_PORT_BUFFERS];

    /** internal buffer signature tracking. */
    uint32_t buf_signature[LIMOI_MAX_CLOCK_PORT_BUFFERS];

    int hold_buf_count; /** number of buffers on hold. */
} video_scheduler_private_t;

#define VIDEO_SCHEDULER(c) ((video_scheduler_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* VIDEO_SCHEDULER_H__ */
