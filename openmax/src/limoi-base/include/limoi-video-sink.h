/*
  Copyright (C) 202007 Tsingmicro Technology 
*/

#ifndef LIMOI_VIDEOSINK_COMPONENT_H__
#define LIMOI_VIDEOSINK_COMPONENT_H__

#include "limoi-component.h"
#include "component.h"

/** limoi video sink component callbacks. */
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

    /** read video input port(hardware or sink.file)
     * @return
     *        0: OK
     *       -1: unrecoverable error.
     */
    int (*write) (OMX_HANDLETYPE hComp, OMX_BUFFERHEADERTYPE * in);
                   

} limoi_videosink_callbacks_t;

/** limoi_video_sink component private data structure. */
struct limoi_videosink_priv_t
{
    limoi_videosink_callbacks_t callbacks; /** sink callbacks. */
};


/** opaque limoi video sink private data structure. */
typedef struct limoi_videosink_priv_t limoi_videosink_priv_t;

/** limoi video sink component base class. */
typedef struct
{
    limoi_component_t parent;
    limoi_videosink_priv_t * priv; /** opaque private data. */
} limoi_videosink_t;

#define LIMOI_VIDEOSINK(c) ((limoi_videosink_t *)OMX_COMPONENT(c))


/** limoi video sink component deinitialization routine.
 * destructs limoi video sink base component.
 *
 * @param hComp component handle.
 *        
 */
OMX_ERRORTYPE limoi_videosink_deinit (OMX_HANDLETYPE hComp);


/** limoi asynchronous video sink component initialization routine.
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
OMX_ERRORTYPE limoi_videosink_init (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version,
    OMX_VIDEO_CODINGTYPE type);


/** limoi synchronous video sink component initialization routine.
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
OMX_ERRORTYPE limoi_videosink_init_sync (
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
int limoi_videosink_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_videosink_callbacks_t * callbacks);

/** @} */
#endif /* LIMOI_VIDEOsink_COMPONENT_H__ */
