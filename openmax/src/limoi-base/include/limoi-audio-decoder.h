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

  OpenMAX IL implementation - limoi audio decoder component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-12-06 MG
*/

/** @addtogroup limoi_base_audio_decoder
 * @{
 */

#ifndef LIMOI_AUDIO_DECODER_COMPONENT_H__
#define LIMOI_AUDIO_DECODER_COMPONENT_H__

#include "limoi-component.h"

/** limoi audio decoder component callbacks. */
typedef struct
{
    /** component private command preparation handle.
     * if not null, this gets called before the decoder processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_prep) (limoi_component_cmd_t * cmd);

    /** component private command post process handle.
     * if not null, this gets called after the decoder processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_post) (limoi_component_cmd_t * cmd);

    /** decoding function.
     * @return
     *        0: OK
     *       -1: unrecoverable error.
     */
    int (*decode) (OMX_HANDLETYPE hComp,
                   OMX_BUFFERHEADERTYPE * in, OMX_BUFFERHEADERTYPE * out);

} limoi_audio_decoder_callbacks_t;

/** opaque limoi audio deocoder private data structure. */
typedef struct limoi_audio_decoder_priv_t limoi_audio_decoder_priv_t;

/** limoi audio decoder component base class. */
typedef struct
{
    limoi_component_t parent;
    limoi_audio_decoder_priv_t * priv; /** opaque private data. */
} limoi_audio_decoder_t;

#define LIMOI_AUDIO_DECODER(c) ((limoi_audio_decoder_t *)OMX_COMPONENT(c))

/** limoi audio decoder component deinitialization routine.
 * destructs limoi audio decoder base component.
 *
 * @param hComp
 *        component handle.
 */
OMX_ERRORTYPE limoi_audio_decoder_deinit (
    OMX_HANDLETYPE hComp);

/** limoi asynchronous audio decoder component initialization routine.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 * @param type
 *        input audio coding type/format.
 */
OMX_ERRORTYPE limoi_audio_decoder_init (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version,
    OMX_AUDIO_CODINGTYPE type);

/** limoi synchronous audio decoder component initialization routine.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 * @param type
 *        input audio coding type/format.
 */
OMX_ERRORTYPE limoi_audio_decoder_init_sync (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version,
    OMX_AUDIO_CODINGTYPE type);

/** set limoi audio decoder component callbacks.
 *
 * @param callbacks
 *        limoi_component_callbacks_t callbacks.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_audio_decoder_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_audio_decoder_callbacks_t * callbacks);

/** set limoi audio decoder output parameter.
 * also check to see if porting setting is changed, if changed,
 * a PortSettingsChanged event is delivered to client.
 *
 */
int limoi_audio_decoder_set_pcm_mode (
    OMX_HANDLETYPE hComp,
    OMX_AUDIO_PARAM_PCMMODETYPE * pcmmode);

/** @} */
#endif /* LIMOI_AUDIO_DECODER_COMPONENT_H__ */
