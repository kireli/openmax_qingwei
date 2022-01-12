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

  OpenMAX IL implementation - limoi audio renderer component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-12-06 MG
*/

/** @addtogroup limoi_base_audio_renderer
 * @{
 */

#ifndef LIMOI_AUDIO_RENDERER_COMPONENT_H__
#define LIMOI_AUDIO_RENDERER_COMPONENT_H__

#include "limoi-component.h"

/** default limoi audio renderer role name. */
#define LIMOI_AUDIO_RENDERER_ROLE "audio_renderer.pcm"

/** limoi audio renderer component callbacks. */
typedef struct
{
    /** component private command preparation handle.
     * if not null, this gets called before the renderer processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_prep) (limoi_component_cmd_t * cmd);

    /** component private command post process handle.
     * if not null, this gets called after the renderer processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_post) (limoi_component_cmd_t * cmd);

    /** rendering function.
     *
     * @param hComp
     *        audio renderer component handle
     * @param buf
     *        audio buffer to render.
     * @param clock_tunnel_comp
     *        tunneled clock component if available.
     * @param clock_tunnel_port
     *        tunneled clock port index if available.
     * @param clock_port
     *        renderer clock port index.
     */
    int (*render) (OMX_HANDLETYPE hComp,
                   OMX_BUFFERHEADERTYPE * buf,
                   OMX_HANDLETYPE clock_tunnel_comp,
                   int clock_tunnel_port,
                   int clock_port);

    /** clock update function.
     *
     * @param hComp
     *        audio renderer component handle
     * @param clock_tunnel_comp
     *        tunneled clock component if not null.
     * @param clock_buf
     *        clock buffer if available.
     */
    int (*clock) (OMX_HANDLETYPE hComp,
                  OMX_HANDLETYPE clock_tunnel_comp,
                  OMX_BUFFERHEADERTYPE * clock_buf);
} limoi_audio_renderer_callbacks_t;

/** opaque limoi audio renderer private data structure. */
typedef struct limoi_audio_renderer_priv_t limoi_audio_renderer_priv_t;

/** limoi audio renderer component base class. */
typedef struct
{
    limoi_component_t parent;
    limoi_audio_renderer_priv_t * priv; /** opaque private data. */
} limoi_audio_renderer_t;

#define LIMOI_AUDIO_RENDERER(c) ((limoi_audio_renderer_t *)OMX_COMPONENT(c))

/** limoi audio renderer component deinitialization routine.
 * destructs limoi audio renderer base component.
 *
 * @param hComp
 *        component handle.
 */
OMX_ERRORTYPE limoi_audio_renderer_deinit (
    OMX_HANDLETYPE hComp);

/** limoi audio renderer component initialization routine.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 */
OMX_ERRORTYPE limoi_audio_renderer_init (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version);

/** set limoi audio renderer component callbacks.
 *
 * @param callbacks
 *        limoi_component_callbacks_t callbacks.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_audio_renderer_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_audio_renderer_callbacks_t * callbacks);

/** @} */
#endif /* LIMOI_AUDIO_RENDERER_COMPONENT_H__ */
