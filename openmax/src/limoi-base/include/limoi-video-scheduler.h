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

  OpenMAX IL implementation - limoi video scheduler component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-02-28 MG
*/

/** @addtogroup limoi_base_video_scheduler
 * @{
 */

#ifndef LIMOI_VIDEO_SCHEDULER_COMPONENT_H__
#define LIMOI_VIDEO_SCHEDULER_COMPONENT_H__

#include "limoi-component.h"

/** limoi video scheduler component callbacks. */
typedef struct
{
    /** component private command preparation handle.
     * if not null, this gets called before the scheduler processes command
     * within the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_prep) (limoi_component_cmd_t * cmd);

    /** component private command post process handle.
     * if not null, this gets called after the scheduler processes command
     * within the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_post) (limoi_component_cmd_t * cmd);

    /** scheduling function.
     *
     * @param hComp
     *        video scheduler component handle
     * @param in_port
     *        video input port.
     * @param in_buf
     *        video buffer to schedule.
     * @param out_buf
     *        scheduled output video buffer, useful for passthru test.
     * @param clock_tunnel_comp
     *        tunneled clock component if available.
     * @param clock_tunnel_port
     *        tunneled clock port index if available.
     * @param clock_port
     *        scheduler clock port index.
     * @return
     *        0: OK and input buffer has been scheduled.
     *        1: OK but input buffer has not been scheduled.
     *       -1: unrecoverable error.
     */
    int (*schedule) (OMX_HANDLETYPE hComp,
                     limoi_port_t * in_port,
                     OMX_BUFFERHEADERTYPE ** in_buf,
                     OMX_BUFFERHEADERTYPE * out_buf,
                     OMX_HANDLETYPE clock_tunnel_comp,
                     int clock_tunnel_port,
                     int clock_port);

    /** clock update function.
     *
     * @param hComp
     *        video scheduler component handle
     * @param in_port
     *        video input port.
     * @param out_buf
     *        scheduled output video buffer.
     * @param clock_tunnel_comp
     *        tunneled clock component if not null.
     * @param clock_buf
     *        clock buffer if available.
     */
    int (*clock) (OMX_HANDLETYPE hComp,
                  limoi_port_t * in_port,
                  limoi_port_t * out_port,
                  OMX_BUFFERHEADERTYPE * out_buf,
                  OMX_HANDLETYPE clock_tunnel_comp,
                  OMX_BUFFERHEADERTYPE * clock_buf);
} limoi_video_scheduler_callbacks_t;

/** opaque limoi video scheduler private data structure. */
typedef struct limoi_video_scheduler_priv_t limoi_video_scheduler_priv_t;

/** limoi video scheduler component base private data structure. */
typedef struct
{
    limoi_component_t parent;
    limoi_video_scheduler_priv_t * priv; /** opaque private data. */
} limoi_video_scheduler_t;

#define LIMOI_VIDEO_SCHEDULER(c) ((limoi_video_scheduler_t *)OMX_COMPONENT(c))


/** limoi video scheduler component deinitialization routine.
 * destructs limoi video scheduler base component.
 *
 * @param hComp
 *        component handle.
 */
OMX_ERRORTYPE limoi_video_scheduler_deinit (
    OMX_HANDLETYPE hComp);


/** limoi video scheduler component initialization routine.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 */
OMX_ERRORTYPE limoi_video_scheduler_init (
    OMX_HANDLETYPE * hComp,
    int bytes,
    const char * comp_name,
    const char * comp_version);


/** set limoi video scheduler component callbacks.
 *
 * @param callbacks
 *        limoi_component_callbacks_t callbacks.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_video_scheduler_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_video_scheduler_callbacks_t * callbacks);

/** @} */
#endif /* LIMOI_VIDEO_SCHEDULER_COMPONENT_H__ */
