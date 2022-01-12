/*
  Copyright (C) 202007 Tsingmicro Technology 
*/

#ifndef LIMOI_VIDEOSPLIT12_COMPONENT_H__
#define LIMOI_VIDEOSPLIT12_COMPONENT_H__

#include "limoi-component.h"
#include "component.h"

/** limoi video src component callbacks. */
typedef struct
{
    /** component private command preparation handle.
     * if not null, this gets called before the encoder processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_prep) (limoi_component_cmd_t * cmd);

    /** component private command post process handle.
     * if not null, this gets called after the encoder processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_post) (limoi_component_cmd_t * cmd);

    /** read video input port(hardware or src.file)
     * @return
     *        0: OK
     *       -1: unrecoverable error.
     */
    int (*main) (OMX_HANDLETYPE hComp, 
			    limoi_port_t * in_port,
			    limoi_port_t * out_port,
			    limoi_port_t * out_port1,
			    OMX_BUFFERHEADERTYPE ** in,
			    OMX_BUFFERHEADERTYPE * out,
			    OMX_BUFFERHEADERTYPE * out1);
                   

} limoi_videoSplit12_callbacks_t;

/** limoi_video_src component private data structure. */
struct limoi_videoSplit12_priv_t
{
    limoi_videoSplit12_callbacks_t callbacks; /** src callbacks. */
};


/** opaque limoi video src private data structure. */
typedef struct limoi_videoSplit12_priv_t limoi_videoSplit12_priv_t;

/** limoi video src component base class. */
typedef struct
{
    limoi_component_t parent;
    limoi_videoSplit12_priv_t * priv; /** opaque private data. */
} limoi_videoSplit12_t;

#define LIMOI_VIDEO_SPLIT12(c) ((limoi_videoSplit12_t *)OMX_COMPONENT(c))


/** limoi video src component deinitialization routine.
 * destructs limoi video src base component.
 *
 * @param hComp component handle.
 *        
 */
OMX_ERRORTYPE limoi_videoSplit12_deinit (OMX_HANDLETYPE hComp);


/** limoi asynchronous video src component initialization routine.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 * @param type
 *        input video coding type/format.
 */
OMX_ERRORTYPE limoi_videoSplit12_init (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version,
    OMX_VIDEO_CODINGTYPE type);


/** limoi synchronous video src component initialization routine.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 * @param type
 *        input video coding type/format.
 */
OMX_ERRORTYPE limoi_videoSplit12_init_sync (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version,
    OMX_VIDEO_CODINGTYPE type);


/** set limoi video encoder component callbacks.
 *
 * @param callbacks
 *        limoi_component_callbacks_t callbacks.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_videoSplit12_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_videoSplit12_callbacks_t *callbacks);

/** @} */
#endif /* LIMOI_VIDEO_SPLIT_COMPONENT_H__ */
