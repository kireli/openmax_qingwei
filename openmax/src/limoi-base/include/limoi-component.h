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

  OpenMAX IL implementation - limoi component header.

  REVISION:

    2) synchronous component support. ---------------------------- 2011-06-01 MG
    1) initial creation. ----------------------------------------- 2009-11-30 MG
*/

/** @addtogroup limoi_base_component
 * @{
 */

#ifndef LIMOI_COMPONENT_H__
#define LIMOI_COMPONENT_H__
#include "OMX_Types.h"
#include "OMX_Core.h"
#include "OMX_Component.h"
#include "OMX_ContentPipe.h"
#include "OMX_Lim.h"
#include "limqlist.h"
#include "limthread.h"
#include "limmemory.h"

/////////////////////////////////////////////////////
//START OF LIMOI COMPONENT TUNING KNOBS
#define LIMOI_MUXER_AUDIO_INPUT_BUFFER_NUM 64
#define LIMOI_MUXER_AUDIO_INPUT_BUFFER_BYTES (1024 * 4)
#define LIMOI_MUXER_VIDEO_INPUT_BUFFER_NUM 64
#define LIMOI_MUXER_VIDEO_INPUT_BUFFER_BYTES (1024 * 8)

#define LIMOI_VIDEO_ENCODER_INPUT_BUFFER_NUM 4
#define LIMOI_VIDEO_ENCODER_INPUT_BUFFER_BYTES (352 * 288 + 352 * 288 / 2)
#define LIMOI_VIDEO_ENCODER_OUTPUT_BUFFER_NUM 4
#define LIMOI_VIDEO_ENCODER_OUTPUT_BUFFER_BYTES (1024 * 8)

#define LIMOI_AUDIO_ENCODER_INPUT_BUFFER_NUM 4
#define LIMOI_AUDIO_ENCODER_INPUT_BUFFER_BYTES (1024 * 192)
#define LIMOI_AUDIO_ENCODER_OUTPUT_BUFFER_NUM 4
#define LIMOI_AUDIO_ENCODER_OUTPUT_BUFFER_BYTES (1024 * 32)

#define LIMOI_DEMUXER_AUDIO_OUTPUT_BUFFER_NUM 64
#define LIMOI_DEMUXER_AUDIO_OUTPUT_BUFFER_BYTES (1024 * 4)
#define LIMOI_DEMUXER_VIDEO_OUTPUT_BUFFER_NUM 64
#define LIMOI_DEMUXER_VIDEO_OUTPUT_BUFFER_BYTES (1024 * 8)

#define LIMOI_VIDEO_DECODER_INPUT_BUFFER_NUM 4
#define LIMOI_VIDEO_DECODER_INPUT_BUFFER_BYTES (1024 * 8)
#define LIMOI_VIDEO_DECODER_OUTPUT_BUFFER_NUM 4
#define LIMOI_VIDEO_DECODER_OUTPUT_BUFFER_BYTES (352 * 288 + 352 * 288 / 2)

#define LIMOI_AUDIO_DECODER_INPUT_BUFFER_NUM 4
#define LIMOI_AUDIO_DECODER_INPUT_BUFFER_BYTES (1024 * 4)
#define LIMOI_AUDIO_DECODER_OUTPUT_BUFFER_NUM 4
#define LIMOI_AUDIO_DECODER_OUTPUT_BUFFER_BYTES (1024 * 192)



#define LIMOI_VIDEO_CAMERA_INPUT_BUFFER_NUM 1
#define LIMOI_VIDEO_CAMERA_INPUT_BUFFER_BYTES (640*480*4)

#define LIMOI_VIDEO_CAMERA_OUTPUT_BUFFER_NUM 1
#define LIMOI_VIDEO_CAMERA_OUTPUT_BUFFER_BYTES (640*360*4)

#define LIMOI_VIDEO_AIE_OUTPUT_BUFFER_NUM 1
#define LIMOI_VIDEO_AIE_OUTPUT_BUFFER_BYTES (100)

#define VIDEO_1080P_YUV_SIZE (1920*1080*2)
#define VIDEO_1080P_RAW16_SIZE  (1920*1080*2)
#define VIDEO_1080P_RAW8_SIZE  (1920*1080)

#define VIDEO_640x480_YUV_SIZE (640*480*2)
#define VIDEO_640x480_RAW16_SIZE  (640*480*2)
#define VIDEO_640x480_RAW8_SIZE  (640*480)

#define LIMOI_VIDEO_ADDR_SIZE 4

#define LIMOI_IMAGE_PROC_INPUT_BUFFER_NUM 4
#define LIMOI_IMAGE_PROC_INPUT_BUFFER_BYTES (1024 * 1024 * 1)
#define LIMOI_IMAGE_PROC_OUTPUT_BUFFER_NUM 4
#define LIMOI_IMAGE_PROC_OUTPUT_BUFFER_BYTES (1024 * 1024 * 1)


/** maximum number of clock ports. */
#define LIMOI_MAX_CLOCK_PORTS 8

/** maximum number of clock port buffers. */
#define LIMOI_MAX_CLOCK_PORT_BUFFERS 8

/** maximum URI length in bytes.
 * platform specific, can be tuned, either up or down.
 */
#define LIMOI_URI_MAX_LENGTH 4096

/** limoi component command queue maximum depth */
#define LIMOI_COMPONENT_CMD_Q_DEPTH_MAX 128

/** limoi component client event set maximum depeth */
#define LIMOI_COMPONENT_CLIENT_EVENT_SET_DEPTH_MAX 64

/** limoi component chain buffer preload count. */
#define LIMOI_PRELOAD_BUFFER_COUNT 2

/** limoi component maximum number of run time buffer share requests.
 * maximum allowed buffers to be shared with output ports before
 * buffers are recycled back.
 */
#define LIMOI_BUFFER_SHARING_POOL_MAX 8

/** limoi component maximum number of port-pairs that share buffers. */
#define LIMOI_BUFFER_SHARING_PAIRS_MAX 8

//END OF LIMOI COMPONENT TUNING KNOBS
/////////////////////////////////////////////////////

/** @page comp_p1 component mutex policy
 * to prevent system deadlock, if needed, mutex must be acquired in the
 * following order, base->port->other (component subclass ones for example)
 */


/** limoi component buffer sharing policy structure.
 * defines component buffer sharing port mapping, all index specified must
 * be absolute, which is port base plus port index.
 */
typedef struct
{
    /** indices of sharing pair, supplier-port-index:sharing-port-index. */
    OMX_U32 ports[LIMOI_BUFFER_SHARING_PAIRS_MAX * 2];

    /** total number of available share pairs. */
    int num_share_pairs;
} limoi_buffer_share_policy_t;

/** limoi component command structure.
 * please refer to OpenMAX IL spec for member definitions.
 */
typedef struct
{
    OMX_HANDLETYPE hComponent;
    OMX_COMMANDTYPE Cmd;
    OMX_U32 nParam1;
    OMX_PTR pCmdData;
} limoi_component_cmd_t;

/** opaque limoi component port handle. */
typedef struct limoi_port_t limoi_port_t;

/** limoi base component callbacks.
 * while 'command' and 'sub' callbacks are optional, 'main' callback is
 * mandatory. For asynchronous component, each type of callback is
 * carried out in its own thread.
 */
typedef struct
{
    /** component private command preparation handle.
     * if not null, this gets called before the core processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_prep) (limoi_component_cmd_t * cmd);

    /** component private command post process handle.
     * if not null, this gets called after the core processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_post) (limoi_component_cmd_t * cmd);

    /** component main data processing handle.
     * this gets called without holding any mutex, when component
     * is in executing state, or pause state before preload is completed,
     * where the component completes its data processing.
     *
     * callback shall return upon completing of each port buffer, thus giving
     * the underlying system the opportunity to respond to state transition
     * request.
     *
     * callback usually should not block other than on starving of port
     * buffers, if it blocks otherwise, sub-class implementor must provide
     * mechanism to unblock upon state transition from executing/pause to idle,
     * or any port disable command.
     *
     * if callback returns any value otherthan OMX_ErrorNone, component will
     * wait for base->cond for a bit before retry. To exit main thread, client
     * has to explicitly request a state transition.
     */
    OMX_ERRORTYPE (*main) (OMX_HANDLETYPE hComp,
                           limoi_port_t ** audio_port,
                           limoi_port_t ** video_port,
                           limoi_port_t ** other_port,
                           int * preloaded);

    /** component supplementory data processing handle.
     * this gets called without holding any mutex, when component is in
     * executing state.
     *
     * the main interest of this thread shall be 'other_port', so that
     * component can process supplementory data asynchronously, to respond
     * to clock update as an example.
     *
     * if callback returns any value otherthan OMX_ErrorNone, component will
     * wait for base->cond for a bit before retry, except that if callback
     * returns OMX_ErrorNoMore, sub thread will be automatically shutdown.
     */
    OMX_ERRORTYPE (*sub)  (OMX_HANDLETYPE hComp,
                           limoi_port_t ** audio_port,
                           limoi_port_t ** video_port,
                           limoi_port_t ** other_port);
} limoi_component_callbacks_t;

/** opaque limoi component private data structure. */
typedef struct limoi_component_priv_t limoi_component_priv_t;

/** limoi component base class structure.
 * all limoi components shall derive from this base structure, by specifying
 * their first structure member as 'limoi_component_t parent'.
 *
 * limoi component implementation can choose not to use this structure, however
 * in that case component shall provide complete implementation of all methods.
 */
typedef struct limoi_component_priv_t * limoi_component_t;
#define OMX_COMPONENT(hComp) (((OMX_COMPONENTTYPE *)(hComp))->pComponentPrivate)
#define LIMOI_COMPONENT(hComp) ((limoi_component_t *)OMX_COMPONENT(hComp))


/** limoi asynchronous component initialization routine.
 * constructs limoi asynchronous base component and allocates component
 * private data.
 *
 * @param hComp
 *        component handle.
 * @param bytes
 *        size of component private data in bytes.
 */
OMX_ERRORTYPE limoi_component_init (OMX_HANDLETYPE * hComp, int bytes);


/** limoi synchronous component initialization routine.
 * constructs limoi synchronous base component and allocates component
 * private data.
 *
 * @param hComp
 *        component handle.
 * @param bytes
 *        size of component private data in bytes.
 */
OMX_ERRORTYPE limoi_component_init_sync (OMX_HANDLETYPE * hComp, int bytes);


/** set limoi component buffer sharing policy.
 * only can be called when component is in OMX_StateLoaded state.
 *
 * @param hComp
 *        component handle.
 * @param policy
 *        component buffer sharing policy.
 */
OMX_ERRORTYPE limoi_component_set_buffer_share_policy (
    OMX_HANDLETYPE hComp,
    const limoi_buffer_share_policy_t * policy);


/** limoi component deinitialization routine.
 * destructs limoi base component.
 *
 * @param hComp
 *        component handle.
 */
OMX_ERRORTYPE limoi_component_deinit (OMX_HANDLETYPE hComp);


/** get limoi component current state. */
OMX_STATETYPE limoi_component_state (OMX_HANDLETYPE hComp);

int limoi_component_mode (OMX_HANDLETYPE hComp);

/** lock limoi component.
 * lock can be recursive, but the same number of unlock is required.
 *
 */
void limoi_component_lock (OMX_HANDLETYPE hComp);


/** unlock limoi component. */
void limoi_component_unlock (OMX_HANDLETYPE hComp);


/** broadcast limoi component conditional.
 * caller must hold component lock by @limoi_component_lock().
 */
void limoi_component_cond_broadcast (OMX_HANDLETYPE hComp);


/** timed wait on limoi component condition.
 * caller must hold component lock by @limoi_component_lock().
 */
int limoi_component_cond_timedwait (OMX_HANDLETYPE hComp, int miliseconds);


/** set limoi component callbacks.
 *
 * @param callbacks
 *        limoi_component_callbacks_t callbacks.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_component_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_component_callbacks_t * callbacks);


/** set component name and version.
 * @param name
 *        component name assigned by component implementor.
 * @param version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_component_set_name_version (
    OMX_HANDLETYPE hComp,
    const char * name,
    const char * version);


/** add component role
 *
 * @param role
 *        role description string.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_component_add_role (OMX_HANDLETYPE hComp, const char * role);


/** get current component role
 * helper function to get current role set by client, if available.
 *
 * @param hComp
 *        component handle.
 * @param role
 *        role description string buffer, with length no less than
 *        OMX_MAX_STRINGNAME_SIZE
 * @return
 *        OpenMax error code.
 */
OMX_ERRORTYPE limoi_component_get_current_role (
    OMX_HANDLETYPE hComp,
    char * role);


/** set component ports
 *
 * @param port
 *        port definition.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_component_add_port (
    OMX_HANDLETYPE hComp,
    const OMX_PARAM_PORTDEFINITIONTYPE * port);


/** get component port from port index.
 *
 * @return
 *        limoi port handle if successful, NULL otherwise.
 */
limoi_port_t * limoi_component_get_port (
    OMX_HANDLETYPE hComponent,
    OMX_U32 nPortIndex);


/** limoi component get parameter
 *
 *
 */
OMX_ERRORTYPE limoi_component_get_parameter (
    OMX_HANDLETYPE hComponent,
    OMX_INDEXTYPE nIndex,
    OMX_PTR pComponentParameterStructure);


/** limoi component set parameter
 * regardless of actual component state.
 *
 */
OMX_ERRORTYPE limoi_component_set_parameter (
    OMX_HANDLETYPE hComponent,
    OMX_INDEXTYPE nIndex,
    OMX_PTR pComponentParameterStructure);


/** port definition parameter helper.
 * shortcut helper for efficient port definition parameter access, API can be
 * used only when port is added by @ref limoi_component_add_port(). API does
 * not implement any lock mechanism internally, it is the caller's
 * responsibility to properly aquire component lock.
 */
OMX_PARAM_PORTDEFINITIONTYPE * limoi_component_get_port_definition (
     limoi_port_t * port);


/** port buffer supplier type parameter helper.
 * shortcut helper for efficient port supplier type parameter access, API can be
 * used only when port is added by @ref limoi_component_add_port(). API does
 * not implement any lock mechanism internally, it is the caller's
 * responsibility to properly aquire component lock.
 */
OMX_PARAM_BUFFERSUPPLIERTYPE * limoi_component_get_port_buffer_supplier (
     limoi_port_t * port);


/** check whether port buffer share is enabled at run time.
 *
 * @return
 *        1 if enabled, 0 otherwise.
 */
int limoi_component_port_buffer_share_enabled (limoi_port_t * port);


/** get next component port buffer.
 *
 * @param timeout
 *        timeout value in miliseconds, -1 to wait infinitely.
 * @return
 *        buffer header if successful, NULL otherwise.
 */
OMX_BUFFERHEADERTYPE ** limoi_component_get_port_buffer (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port,
    int timeout);


/** reallocate component port buffer.
 *
 * @param buf_header
 *        port buffer header
 * @param bytes
 *        reallocation port buffer bytes.
 * @return
 *        0 if successful, -1 otherwise.
 */
int limoi_component_realloc_port_buffer (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port,
    OMX_BUFFERHEADERTYPE * buf_header,
    int bytes);


/** hold component port buffer
 * hold current buffer and advance queue pointer.
 *
 * @param buf_header
 *        buffer returned by @ref limoi_component_get_port_buffer().
 * @return
 *        0 if successful, -1 otherwise.
 */
int limoi_component_hold_port_buffer (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port,
    OMX_BUFFERHEADERTYPE ** buf_header);


/** release component port buffer
 * caller must not hold any mutex, since successful releasing buffer
 * may lead to API calls on tunneled component.
 *
 * @param buf_header
 *        buffer returned by @ref limoi_component_get_port_buffer().
 * @return
 *        0 if successful, -1 if internal error, 1 if client or
 *        tunneled component error.
 */
int limoi_component_release_port_buffer (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port,
    OMX_BUFFERHEADERTYPE ** buf_header);


/** put back component port buffer.
 * caller must not hold any mutex, since successful putting buffer
 * may lead to API calls on tunneled component.
 *
 * @return
 *        0 if successful, -1 if internal error, 1 if client or
 *        tunneled component error.
 */
int limoi_component_put_port_buffer (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port,
    OMX_BUFFERHEADERTYPE ** buf_header);


/** share buffer between input and output port.
 * caller must hold base->mutex
 *
 * can only and must be called by component that implements buffer sharing,
 * this call internally replaces buffer pointer of the output buffer
 * header with that of supplied input buffer header. It then registers
 * with system this sharing request, and automatically releases buffer
 * upon output port and its tunnel has done with the buffer.
 *
 * @return
 *        0 if successful, -1 if error.
 */
int limoi_component_share_port_buffer (
    OMX_HANDLETYPE hComp,
    limoi_port_t * in_port,
    limoi_port_t * out_port,
    OMX_BUFFERHEADERTYPE ** in_buf_header,
    OMX_BUFFERHEADERTYPE * out_buf_header);


/** deliver limoi component event.
 *
 */
void limoi_component_deliver_event (
    OMX_HANDLETYPE hComp,
    OMX_EVENTTYPE eEvent,
    OMX_U32 nData1,
    OMX_U32 nData2,
    OMX_PTR pEventData);

/** send component to invalid state.
 * set component state to OMX_StateInvalid and deliver client error event
 * OMX_ErrorInvalidState. Following IL spec, client must reinit component
 * before using it again, by @ref OMX_FreeHandle() and @ref OMX_GetHandle().
 */
void limoi_component_goto_invalid_state (OMX_HANDLETYPE hComp);


/** resource preempt request callback type.
 * when called, component shall immediately relinquish specified resource,
 * by calling @ref limoi_resource_release(), after internal cleanup.
 *
 * @return
 *        0 if resource successfully preempted, -1 if error.
 */
typedef int (*limoi_resource_preempt_cb_t)
(int manager_id, int resource_id, OMX_HANDLETYPE hComp);


/** acquire specified component resource
 *
 * @preempt
 * resource preemptation request callback, called by resource manager to
 * request component to release specified resource when it is allowed
 * by policy, meaning there's higher priority component is requesting
 * the resource.
 *
 * @return
 *        opaque resource object if successful. NULL otherwise.
 */
void * limoi_resource_acquire (
    int manager_id,
    int resource_id,
    limoi_resource_preempt_cb_t preempt,
    OMX_HANDLETYPE hComp);


/** release specified component resource
 *
 * @return
 *        0 if successful, -1 otherwise.
 */
int limoi_resource_release (
    int manager_id,
    int resource_id,
    OMX_HANDLETYPE hComp);


/** resource notification callback type.
 *
 * @status
 *        0 if resource becomes available, -1 if error.
 */
typedef void (*limoi_resource_notify_cb_t)
(int manager_id, int resource_id, int status, OMX_HANDLETYPE hComp);


/** wait on specified component resource
 *
 * @param notify
 *        callback to notify resource wait status
 * @return
 *        0 if wait request is successfully queued, -1 otherwise.
 */
int limoi_resource_wait (
    int manager_id,
    int resource_id,
    OMX_HANDLETYPE hComp,
    limoi_resource_notify_cb_t notify);


/** cancel wait on specified component resource
 *
 * @return
 *        0 if wait canceled, -1 otherwise.
 */
int limoi_resource_cancel_wait (
    int manager_id,
    int resource_id,
    OMX_HANDLETYPE hComp);


OMX_U8* get_port_queue_buffer_addr(
		OMX_HANDLETYPE hComp,
		int port_index, 
		int buf_index);





/** @} */
#endif /* LIMOI_COMPONENT_H__ */
