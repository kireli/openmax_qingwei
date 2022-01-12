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

  OpenMAX IL implementation - limoi component internal header.

  REVISION:

    2) synchronous component support. ---------------------------- 2011-06-01 MG
    1) initial creation. ----------------------------------------- 2009-11-30 MG
*/

/** @addtogroup limoi_base_private
 * @{
 */

#ifndef LIMOI_COMPONENT_PRIVATE_H__
#define LIMOI_COMPONENT_PRIVATE_H__

#include "OMX_Types.h"
#include "OMX_Core.h"
#include "OMX_Component.h"
#include "OMX_ContentPipe.h"
#include "limqlist.h"
#include "limthread.h"
#include "limmemory.h"

/** limoi component role list entry structure. */
typedef struct
{
    list_t list;
    const char * role_name;
} limoi_role_t;

/** limoi parameter / configuration list entry structure. */
typedef struct
{
    list_t list;
    OMX_INDEXTYPE index;
    OMX_PTR param_config;
} limoi_param_config_t;

/** limoi component client event data structure. */
typedef struct
{
    lthread_t threadId;
    OMX_EVENTTYPE eEvent;
    OMX_U32 nData1;
    OMX_U32 nData2;
    OMX_PTR pEventData;
} limoi_component_client_event_t;

/** limoi port buffer list entry structure. */
typedef struct
{
    list_t list;
    OMX_BUFFERHEADERTYPE * header;
    int allocated; /** buffer allocated by component. */
} limoi_port_buffer_t;

/** limoi component port buffer queue max number of entries. */
#define LIMOI_COMPONENT_PORT_BUF_Q_MAX 256

/** limoi component port buffer sharing type. */
typedef enum
{
    LIMOX_BufferShareDisabled,
    LIMOX_BufferShareSupplier,
    LIMOX_BufferShareConsumer
} LIMOX_BUFFERSHARETYPE;

/** limoi component port buffer sharing custom parameter. */
typedef struct
{
    //OMX_U32 nSize; /** Size of this structure, in Bytes */
    //OMX_VERSIONTYPE nVersion; /** OMX specification version information */
    //OMX_U32 nPortIndex; /** port that this structure applies to */
    LIMOX_BUFFERSHARETYPE type; /** port share type */
    OMX_U32 share_num; /** number of sharing or shared port when applicable. */

    /** port(s) based on share type.
     * if disabled, this field is not used.
     * if supplier, contains ports index that share buffers from this port.
     * if consumer, contain one and only one entry, the supplier port index
     */
    OMX_U32 ports[LIMOI_BUFFER_SHARING_PAIRS_MAX];
} LIMOX_PARAM_BUFFERSHAREPOLICY;

//keeping it here for now as a private implementation, should be
//published to OMX_Index.h and OMX_Component.h accordingly.
//#define OMX_IndexLimoxBufferShare (OMX_IndexVendorStartUnused | 0xfffffe)

/** limoi component port list entry structure. */
struct limoi_port_t
{
    list_t list;
    OMX_U32 index; /** port index. */
    OMX_HANDLETYPE tunnel_comp; /** tunneled component handle. */
    OMX_U32 tunnel_port; /** tunneled port index. */
    list_t params_list_head; /** list with entry of limoi_param_config_t. */
    list_t buffers_list_head; /** list with entry of limoi_port_buffer_t. */

    lthread_mutex_t mutex; /** port mutex. */
    lthread_cond_t cond; /** port conditional. */
	lthread_cond_t cond_bufq; /** port conditional. */
	
    lim_mem_pool_t buf_mem_pool; /** port buffer memory pool handle. */

    int activated; /** port buffer activation state. */

    //port buffer queue controls.
    limq_handle_t bufq; /** port buffer queue handle. */
    /** port is in the middle of state transitioning if non-zero. */
    int bufq_state_transition;

    LIMOX_PARAM_BUFFERSHAREPOLICY buffer_share; /** port buffer share policy. */
};

/** component busy status bit flags. */
#define COMP_MAIN_THREAD_BUSY      0x0001 /**asynchronous component only. */
#define COMP_SUB_THREAD_BUSY       0x0002 /**asynchronous component only. */
#define COMP_BUFFER_CONSUMING_BUSY 0x0004 /**synchronous component only. */

/** limoi component base data structure. */
struct limoi_component_priv_t
{
    OMX_CALLBACKTYPE callbacks; /** active component callbacks. */
    limoi_component_callbacks_t limoi_callbacks; /** active limoi callbacks. */

    OMX_STATETYPE state; /** current component state. */
    lthread_cond_t cond; /** component conditional. */
    lthread_mutex_t mutex; /** component mutex. */
    int lock_count; /** component mutex lock count. */

    lthread_t main_thread; /** component main data processing thread. */
	lthread_attr_t *main_attr;
    lthread_t sub_thread; /** component supplementory data processing thread. */
	lthread_attr_t *sub_attr;
	
    lthread_t cmd_thread; /** command callback handling thread. */
    lthread_mutex_t cmd_mutex; /** command interface mutex. */
    lthread_cond_t cmd_cond; /** command interface conditional. */
    limq_handle_t cmd_q; /** command queue handle. */
    int cmd_received; /** number of commands received. */

    lthread_mutex_t event_mutex; /** client event set mutex. */
    limset_handle_t event_set; /** client event set handle. */

    char * name; /** component name. */
    OMX_VERSIONTYPE version; /** component version. */
    list_t roles_list_head; /** list with entry of limoi_role_t. */
    list_t ports_list_head; /** list with entry of limoi_port_t. */
    list_t params_list_head; /** list with entry of limoi_param_config_t. */

    limoi_port_t ** audio_port; /** enumerated audio ports if available. */
    limoi_port_t ** video_port; /** enumerated video ports if available. */
    limoi_port_t ** other_port; /** enumerated other ports if available. */

    int preloaded; /** component preloaded buffer count. */

    /** bit mapped flags to indicate component busy status,
     * where buffer is actively being processed. */
    int busy;

    /** flag to indicate component is in the middle of
     * putting buffer back, thus possibly calling APIs
     * from tunneled component. Command interface must
     * block waiting for this to be cleared. Otherwise
     * upstream component may suffer deadlock due to
     * early state transition completion of downstream
     * component. */
    int putting_buffer;

    /** flag to indicate component state transition
     * request in progress. */
    int state_transition;

    int synchronous; /** synchronous component if set. */

    /** default component configured buffer sharing policy.
     * actual sharing policy depends on client tunnel setup, and is reflected
     * on each individual port.
     */
    limoi_buffer_share_policy_t * buffer_share_policy;

    /** buffer sharing request pool. */
    void * buffer_share_pool;

    int mode; //work mode
};
#define LIMOI_COMPONENT_PRIV(hComp) (*LIMOI_COMPONENT(hComp))


/** port definition parameter helper.
 * shortcut helper for efficient port definition parameter access, API can be
 * used only when port is added by @ref limoi_component_add_port(). API does
 * not implement any lock mechanism internally, it is the caller's
 * responsibility to properly aquire component lock.
 */
#define LIMOI_PORTDEF(p) ((OMX_PARAM_PORTDEFINITIONTYPE *)              \
                          (((limoi_param_config_t *)                    \
                            ((p)->params_list_head.prev))               \
                           ->param_config))

/** port buffer supplier type parameter helper.
 * shortcut helper for efficient port supplier type parameter access, API can be
 * used only when port is added by @ref limoi_component_add_port(). API does
 * not implement any lock mechanism internally, it is the caller's
 * responsibility to properly aquire component lock.
 */
#define LIMOI_BUF_SUPPLIER(p) ((OMX_PARAM_BUFFERSUPPLIERTYPE *)         \
                               (((limoi_param_config_t *)               \
                                 ((p)->params_list_head.prev->prev))    \
                                ->param_config))

/** validate component buffer share policy.
 * called upon tunnel setup on per port basis, by default buffer
 * share policy is turned off for base profile (non-tunneled) component.
 *
 * @return
 *        0 on success, -1 on failure.
 */
int buffer_share_validate_policy (OMX_HANDLETYPE hComp, OMX_U32 nPortIndex);

/** check whether port is a buffer share supplier. */
int buffer_share_is_supplier (OMX_HANDLETYPE hComp, limoi_port_t * limoi_port);

/** get supplier port buffer by index.
 * caller must hold port mutex.
 * caller must have made sure calling port is a consumer.
 *
 * @param index
 *        port buffer index.
 * @return
 *        current port buffer on success, NULL otherwise.
 */
void * buffer_share_get_supplier_buffer (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port,
    int index);

/** get minimum buffer count and size in bytes of given port.
 * check will go through entire tunnel and share chain when available.
 * caller must not hold any mutex, as this may require tunnel component access.
 *
 *
 * @return
 *        0 on success, -1 on error.
 */
int buffer_share_get_buffer_count_size (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port,
    OMX_U32 * count,
    OMX_U32 * bytes);

/** set minimum buffer count and size in bytes of given port.
 * check will go through entire tunnel and share chain when available.
 * caller must not hold any mutex, as this may require tunnel component access.
 *
 * @return
 *        0 on success, -1 on error.
 */
int buffer_share_set_buffer_count_size (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port,
    OMX_U32 count,
    OMX_U32 bytes);

/** add buffer sharing request to request pool
 * caller must hold base->mutex
 *
 * @return
 *        0 if successful, -1 if error.
 */
int buffer_share_pool_in (
    OMX_HANDLETYPE hComp,
    limoi_port_t * in_port,
    limoi_port_t * out_port,
    OMX_BUFFERHEADERTYPE ** in_buf_header,
    OMX_BUFFERHEADERTYPE * out_buf_header);

/** retrieve and release buffer sharing request from request pool.
 * caller must hold base->mutex
 *
 * note that buffer header is dereferenced, because FillThisBuffer
 * API does not carry the implementation specific queue info.
 *
 * @return
 *        0 if matching found, 1 if no matching found, -1 otherwise.
 */
int buffer_share_pool_out (
    OMX_HANDLETYPE hComp,
    limoi_port_t * out_port,
    OMX_BUFFERHEADERTYPE * out_buf_header);

static inline int tunnel_is_supplier (limoi_port_t * limoi_port)
{
    OMX_PARAM_PORTDEFINITIONTYPE * port;
    OMX_PARAM_BUFFERSUPPLIERTYPE *supplier;

    if (!limoi_port->tunnel_comp) return 0;

    port = LIMOI_PORTDEF(limoi_port);
    supplier = LIMOI_BUF_SUPPLIER(limoi_port);
	
//	printf("portindex=%d; dir=%d, supplier=%d\n", limoi_port->index,  port->eDir,supplier->eBufferSupplier);
	
    return ((supplier->eBufferSupplier == OMX_BufferSupplyInput
             && port->eDir == OMX_DirInput)
            || (supplier->eBufferSupplier == OMX_BufferSupplyOutput
                && port->eDir == OMX_DirOutput))? 1 : 0;
}

static inline int tunnel_is_allocator (
    OMX_HANDLETYPE hComp,
    limoi_port_t * limoi_port)
{
//	printf("%08x;(%d) limoi_port->buffer_share.type=%d, num=%d; %08x \n", 
//		hComp, 
//		limoi_port->index, 
//		limoi_port->buffer_share.type,
//		limoi_port->buffer_share.share_num,
//		LIMOI_COMPONENT_PRIV(hComp)->buffer_share_policy);

	if(LIMOI_COMPONENT_PRIV(hComp)->buffer_share_policy)
	{
		if(limoi_port->buffer_share.type == LIMOX_BufferShareConsumer)
		{
			return 0;
		}
		else
			return tunnel_is_supplier(limoi_port)? 1 : 0;
	}
	else
	{
		return tunnel_is_supplier(limoi_port)? 1 : 0;
	}
		
//    return ((!LIMOI_COMPONENT_PRIV(hComp)->buffer_share_policy
//             || buffer_share_is_supplier(hComp, limoi_port))
//            || tunnel_is_supplier(limoi_port))? 1 : 0;
}

/** release all component or port parameter entries. */
void param_release (list_t * params_list_head);

/** allocate and set component parameter. */
OMX_ERRORTYPE param_allocate_and_set (
    OMX_INDEXTYPE nIndex,
    void * param,
    int bytes,
    list_t * params_list_head);

/** queue up client event into internal event buffer queue.
 * caller should not hold any mutex.
 */
void event_deliver (
    OMX_HANDLETYPE hComp,
    OMX_EVENTTYPE eEvent,
    OMX_U32 nData1,
    OMX_U32 nData2,
    OMX_PTR pEventData);

/** consume internal event buffer and deliver event back to client.
 * caller should not hold any mutex.
 */
void event_deliver_real (OMX_HANDLETYPE hComp);

/** synchronously consume component port buffers. */
OMX_ERRORTYPE sync_consume_buffers (OMX_HANDLETYPE hComp);

/** component main thread handler. */
void * thread_main_handle (void * arg);

/** command interface initialization.
 *
 * @return
 *        0 if successful,-1 otherwise.
 */
int command_interface_init (OMX_HANDLETYPE hComp);
void command_interface_deinit (OMX_HANDLETYPE hComp);

/** component command callback wrapper
 * caller must not hold base->mutex
 */
OMX_ERRORTYPE command_callback (
    limoi_component_priv_t * base,
    limoi_component_cmd_t * cmd,
    int prep);

void role_release (list_t * roles_list_head);

/** release all port entries from component. */
void port_release (list_t * ports_list_head, OMX_HANDLETYPE hComp);

/** disable component port and release all port resources.
 * caller should not hold any mutex.
 */
void port_disable (limoi_component_cmd_t * cmd);

/** enable component port and allocate all port resources.
 * caller should not hold any mutex.
 */
void port_enable (limoi_component_cmd_t * cmd);

/** release all port buffers.
 * caller should not hold any mutex.
 */
void port_flush (limoi_component_cmd_t * cmd);

/** activate all component ports and their buffers.
 * caller must hold base->mutex.
 */
OMX_ERRORTYPE port_activate_buffer_all (OMX_HANDLETYPE hComp);

/** deactivate all component ports and their buffers.
 * caller must hold base->mutex.
 */
OMX_ERRORTYPE port_deactivate_buffer_all (OMX_HANDLETYPE hComp);

/** free all component ports and their buffers.
 * caller must hold base->mutex.
 */
OMX_ERRORTYPE port_free_buffer_all (OMX_HANDLETYPE hComp);

/** immediately respond to port disable command.
 * set bPortDisabled right away.
 * caller must hold base->mutex.
 */
void port_disable_now (OMX_HANDLETYPE hComp, OMX_U32 nPortIndex);

/** allocate port buffer.
 * allocate port buffers per port definition, populating.
 * buffers do not belong to any bufq yet.
 * caller should not hold any mutext.
 *
 * @return
 *        0 if successful, -1 otherwise.
 */
int port_allocate_buffer (OMX_HANDLETYPE hComp, limoi_port_t * limoi_port);

/** component state set command handler.
 * caller should not hold any mutex.
 */
OMX_ERRORTYPE state_set (limoi_component_cmd_t * cmd);
//OMX_ERRORTYPE mode_set(limoi_component_cmd_t * cmd);
OMX_ERRORTYPE mode_set (OMX_HANDLETYPE hComp, int mode);

OMX_ERRORTYPE omx_send_command (
    OMX_HANDLETYPE hComponent,
    OMX_COMMANDTYPE Cmd,
    OMX_U32 nParam1,
    OMX_PTR pCmdData);

OMX_ERRORTYPE omx_component_role_enum (
    OMX_HANDLETYPE hComponent,
    OMX_U8 *cRole,
    OMX_U32 nIndex);

OMX_ERRORTYPE omx_get_parameter (
    OMX_HANDLETYPE hComponent,
    OMX_INDEXTYPE nParamIndex,
    OMX_PTR pComponentParameterStructure);

OMX_ERRORTYPE omx_set_parameter (
    OMX_HANDLETYPE hComponent,
    OMX_INDEXTYPE nIndex,
    OMX_PTR pComponentParameterStructure);

OMX_ERRORTYPE omx_get_config (
    OMX_HANDLETYPE hComponent,
    OMX_INDEXTYPE nIndex,
    OMX_PTR pComponentConfigStructure);

OMX_ERRORTYPE omx_set_config (
    OMX_HANDLETYPE hComponent,
    OMX_INDEXTYPE nIndex,
    OMX_PTR pComponentConfigStructure);

OMX_ERRORTYPE omx_get_component_version (
    OMX_HANDLETYPE hComponent,
    OMX_STRING pComponentName,
    OMX_VERSIONTYPE* pComponentVersion,
    OMX_VERSIONTYPE* pSpecVersion,
    OMX_UUIDTYPE* pComponentUUID);

OMX_ERRORTYPE omx_set_callbacks (
    OMX_HANDLETYPE hComponent,
    OMX_CALLBACKTYPE* pCallbacks,
    OMX_PTR pAppData);

OMX_ERRORTYPE omx_use_buffer (
    OMX_HANDLETYPE hComponent,
    OMX_BUFFERHEADERTYPE** ppBufferHdr,
    OMX_U32 nPortIndex,
    OMX_PTR pAppPrivate,
    OMX_U32 nSizeBytes,
    OMX_U8* pBuffer);

OMX_ERRORTYPE omx_allocate_buffer (
    OMX_HANDLETYPE hComponent,
    OMX_BUFFERHEADERTYPE** ppBuffer,
    OMX_U32 nPortIndex,
    OMX_PTR pAppPrivate,
    OMX_U32 nSizeBytes);

OMX_ERRORTYPE omx_free_buffer (
    OMX_HANDLETYPE hComponent,
    OMX_U32 nPortIndex,
    OMX_BUFFERHEADERTYPE* pBuffer);

OMX_ERRORTYPE omx_empty_this_buffer (
    OMX_HANDLETYPE hComponent,
    OMX_BUFFERHEADERTYPE* pBuffer);

OMX_ERRORTYPE omx_fill_this_buffer (
    OMX_HANDLETYPE hComponent,
    OMX_BUFFERHEADERTYPE* pBuffer);

OMX_ERRORTYPE omx_get_state (
    OMX_HANDLETYPE hComponent,
    OMX_STATETYPE * pState);

OMX_ERRORTYPE omx_component_tunnel_request (
    OMX_HANDLETYPE hComp,
    OMX_U32 nPort,
    OMX_HANDLETYPE hTunneledComp,
    OMX_U32 nTunneledPort,
    OMX_TUNNELSETUPTYPE* pTunnelSetup);

/** @} */
#endif /* LIMOI_COMPONENT_PRIVATE_H__ */
