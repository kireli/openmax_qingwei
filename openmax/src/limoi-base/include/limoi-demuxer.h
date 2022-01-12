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

  OpenMAX IL implementation - limoi container demuxer component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-01-28 MG
*/

/** @defgroup limoi_base_other_demuxer limoi demuxer base
 * @ingroup limoi_base_other
 * @{
 */

#ifndef LIMOI_DEMUXER_COMPONENT_H__
#define LIMOI_DEMUXER_COMPONENT_H__

#include "limoi-component.h"

/** limoi demuxer component callbacks. */
typedef struct
{
    /** component private command preparation handle.
     * if not null, this gets called before the demuxer processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_prep) (limoi_component_cmd_t * cmd);

    /** component private command post process handle.
     * if not null, this gets called after the demuxer processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_post) (limoi_component_cmd_t * cmd);

    /** demuxing function. */
    OMX_ERRORTYPE (*demux) (OMX_HANDLETYPE hComp,
                            CP_PIPETYPE * pipe,
                            CPhandle content,
                            OMX_BUFFERHEADERTYPE * audio_out,
                            OMX_BUFFERHEADERTYPE * video_out);

    /** clock update function.
     *
     * @param hComp
     *        demuxer component handle
     * @param clock_tunnel_comp
     *        tunneled clock component if not null.
     * @param clock_buf
     *        clock buffer if available.
     */
    OMX_ERRORTYPE (*clock) (OMX_HANDLETYPE hComp,
                            OMX_HANDLETYPE clock_tunnel_comp,
                            OMX_BUFFERHEADERTYPE * clock_buf);

    /** metadata count
     * if not null, this returns number of metadata items available
     * for given search scope/specifier.
     *
     * @param scope
     *        metadata search scope
     * @param scope_specifier
     *        metadata search scope specifier
     * @param language_country
     *        metadata language country specifier if not NULL.
     * @return
     *        -1 upon error, otherwise metadata count.
     */
    int (*get_metadata_count) (OMX_HANDLETYPE hComp,
                               OMX_METADATASCOPETYPE scope,
                               int scope_specifier,
                               const char * language_country);

    /** metadata access function.
     * if not null, this gets called when client requests metadata, should
     * return key/value for given search scope/specifier on given index.
     *
     * @param scope
     *        metadata search scope
     * @param scope_specifier
     *        metadata search scope specifier
     * @param language_country
     *        metadata language country specifier if not NULL.
     * @param index
     *        metadata index
     */
    OMX_ERRORTYPE (*get_metadata) (OMX_HANDLETYPE hComp,
                                   OMX_METADATASCOPETYPE scope,
                                   int scope_specifier,
                                   const char * language_country,
                                   OMX_U32 index,
                                   OMX_U8 * key_bytes,
                                   void * key,
                                   OMX_METADATACHARSETTYPE * key_charset,
                                   OMX_U32 * value_bytes,
                                   void * value,
                                   OMX_METADATACHARSETTYPE * value_charset);
} limoi_demuxer_callbacks_t;

/** opaque limoi content demuxer private data structure. */
typedef struct limoi_demuxer_priv_t limoi_demuxer_priv_t;

/** limoi content demuxer component base class. */
typedef struct
{
    limoi_component_t parent;
    limoi_demuxer_priv_t * priv; /** opaque private data. */
} limoi_demuxer_t;

#define LIMOI_DEMUXER(c) ((limoi_demuxer_t *)OMX_COMPONENT(c))

/** limoi demuxer component deinitialization routine.
 * destructs limoi demuxer base component.
 *
 * @param hComp
 *        component handle.
 */
OMX_ERRORTYPE limoi_demuxer_deinit (
    OMX_HANDLETYPE hComp);

/** limoi demuxer component initialization routine.
 * demuxer component will internally query to use OMX_IndexParamContentURI
 * parameter as its input URI.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 */
OMX_ERRORTYPE limoi_demuxer_init (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version);

/** set limoi demuxer component callbacks.
 *
 * @param callbacks
 *        limoi_component_callbacks_t callbacks.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_demuxer_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_demuxer_callbacks_t * callbacks);

/** set limoi demuxer component output port parameters.
 *
 * @param num_audio_streams
 *        number of audio streams available.
 * @param audio_format
 *        array of audio format type bounded by num_audio_streams.
 * @param num_video_streams
 *        number of video streams available.
 * @param video_format
 *        array of video format type bounded by num_video_streams.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_demuxer_set_port_params (
    OMX_HANDLETYPE hComp,
    int num_audio_streams,
    limoi_audio_format_t * audio_format,
    int num_video_streams,
    limoi_video_format_t * video_format);

/** @} */
#endif /* LIMOI_DEMUXER_COMPONENT_H__ */
