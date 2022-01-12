/*
  Copyright (C) 2011 SWOAG Technology <www.swoag.com>

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

  OpenMAX IL implementation - limoi resource manager header.

  REVISION:

    1) initial creation. ----------------------------------------- 2011-04-03 MG
*/

/** @addtogroup limoi_base_rm
 * @{
 */

#ifndef LIMOI_RESOURCE_MANAGER_H__
#define LIMOI_RESOURCE_MANAGER_H__

/** @page rm_p1 resource manager design
 * limoi resource manager manages resource at abstract layor, it has no knowledge
 * of what the resource is, nor how the resource can be used. The only thing
 * that matters is the resource uniquely identified by resourece manager and
 * resource ID. Each resource management implementation shall take unique
 * manager ID and then assign unique resource ID for each resource it manages.
 *
 * limoi resource manager manages wait queue but does not internally track
 * resource usage, the actual resource acquisition and release is always done
 * through callbacks, namely @ref limoi_resource_get_cb_t() and
 * @ref limoi_resource_put_cb_t(), neither callback shall block in any case.
 *
 * hardware dependent or vendor specific resource manager implementation shall
 * register resource through @ref limoi_resource_register(). Resources can then
 * be used by particular component through limoi component resource access APIs
 * defined in limoi-component.h.

 * How resource manager is implemented is out of the scope here, however for
 * obvious reason, client shall make sure each individual resource manager is
 * initialized before instantiating component that actaully uses the resource,
 * and destroyed afterwards. @ref OMX_init() becomes a natural place to invoke
 * resource manager initialization, and @ref OMX_deinit() for resource manager
 * unloading.
 *
 * In order for @ref OMX_init() to automatically initialize and destroy, each
 * resource manager component implementation should provide entry point handles
 * called @ref LIM_ResourceManagerInit() and @ref LIM_ResourceManagerDeinit().
 * By wrapping resource manager loading and unloading within OMX core, resource
 * management becomes completely transparent to IL clients.
 */


/** LIM resource manager initialization handle.
 * called only once upon @ref OMX_init().
 */
void LIM_ResourceManagerInit (void);


/** LIM resource manager deinitialization handle.
 * called only once upon @ref OMX_deinit().
 */
void LIM_ResourceManagerDeinit (void);


/** callback type to acquire resource with specified ID.
 *
 * @param arg
 *        resource manager private data if any.
 * @return
 *        opaque resource object if successful, NULL otherwise.
 */
typedef void * (*limoi_resource_get_cb_t)
  (int manager_id, int resource_id, void * arg);


/** callback type to release resource with specified ID.
 *
 * @param arg
 *        resource manager private data if any.
 * @return
 *        0 if successful, -1 otherwise.
 */
typedef int (*limoi_resource_put_cb_t)
  (int manager_id, int resource_id, void * arg);


/** register specified resource with limoi resource manager.
 * this can be called any number of times for the same manager_id, with
 * different or the same release get/put callbacks, as long as resource
 * id is unique within the same resource manager specified by manager_id.
 *
 * @param manager_id
 *        resource manager ID.
 * @param resource_id
 *        resource ID array, the last element must be -1.
 * @param get
 *        resource acquisition callback.
 * @param put
 *        resource release callback.
 * @param arg
 *        resource manager private data if any.
 * @return
 *        0 if resource successfulled registered, -1 otherwise.
 */
int limoi_resource_register (
    int manager_id,
    int resource_id[],
    limoi_resource_get_cb_t get,
    limoi_resource_put_cb_t put,
    void * arg);


/** unregister all resources from given resource manager.
 * called only when no component is using or waiting any resource out of
 * specifed resource manager. LIM only calls this API after @ref OMX_deinit().
 *
 * @param manager_id
 *        resource manager ID.
 */
void limoi_resource_unregister (int manager_id);


/** notify the availability of given resource
 * resource manager implementation shall call this API to notify the
 * availability of given resource specified by resource_id at the time of
 * calling. LIM IL only uses this information to determine whether it should
 * try to acquire given resource or not. This does not change resource state
 * or consume resource itself.
 *
 * It is entirely up to resource manager implementation to determine when
 * to call this API for which resource. However it is recommended that resource
 * manager shall post resource as soon as it becomes available for others to
 * use, since resource manager itself will not know whether there is any IL
 * component waiting for this resource or not.
 *
 * Note that LIM internally reposts resource right after it calls
 * @ref limoi_resource_put_cb_t(), thus it is not necessary for resource manager
 * to post the resource that has just been released, within
 * @ref limoi_resource_put_cb_t().
 *
 * @param manager_id
 *        resource manager ID.
 * @param resource_id
 *        resource ID.
 */
void limoi_resource_post (int manager_id, int resource_id);


#endif /* LIMOI_RESOURCE_MANAGER_H__ */
