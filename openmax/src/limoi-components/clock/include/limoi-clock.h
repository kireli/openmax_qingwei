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

  OpenMAX IL implementation - clock component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-02-28 MG
*/

/** @defgroup limoi_component_clock limoi clock component
 * @ingroup limoi_components
 * @{
 */

#ifndef LIMOI_CLOCK_H__
#define LIMOI_CLOCK_H__

//#include "config.h"
#include "limutil.h"
#include "limoi.h"

/** maximum number of simultaneous media time requests. */
#define MAX_MEDIA_TIME_REQUESTS 16

/** clock component private data structure. */
typedef struct
{
    limoi_component_t parent;

    int rclock_base_set; /** flag to indicate that reference clock is set. */

    /** maintains the media time's current scale factor. */
    OMX_S32 mclock_xScale;

    /** media clock state. */
    OMX_TIME_CLOCKSTATE mclock_eState;

    /** the media time when the clock was started or will be started. */
    OMX_TICKS mclock_nStartTime;

    /** the time by which to offset the media time. */
    OMX_TICKS mclock_nOffset;

    /** bit mask specifying the client components that the clock
     *  component will wait on.
     */
    OMX_U32 mclock_nWaitMask;

    /** which reference clock the clock component uses (if any). */
    OMX_TIME_REFCLOCKTYPE rclock_eClock;

    /** the reference clock base of extrapolation. */
    OMX_TICKS rclock_base;

    /** the wall clock base of extrapolation. */
    OMX_TICKS wclock_base;

    /** media time request queue handle. */
    limq_handle_t media_time_rqst_q;
} clock_private_t;

#define LIMOI_CLOCK(c) ((clock_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_CLOCK_H__ */
