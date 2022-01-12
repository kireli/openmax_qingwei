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

  OpenMAX IL implementation - demo resource manager.

  REVISION:

    1) initial creation. ----------------------------------------- 2011-05-01 MG
*/

/** @defgroup limoi_resource_manager limoi resource manager
 * @ingroup limoi_plugins
 */

/** @defgroup limoi_demo_rm demo resource manager
 * @ingroup limoi_resource_manager
 * @{
 */

#ifndef LIM_DEMO_RESOURCE_MANAGER_H__
#define LIM_DEMO_RESOURCE_MANAGER_H__

#include "limutil.h"
#include "limoi-resource-manager.h"

/** @page rm_demo_p1
 * this demo implementation demonstrates how a custom resource manager can
 * be implemented using LIM OpenMAX resource manager framework.
 *
 * In order for resource manager to be automatically detected by LIM OpenMAX
 * IL core, resource manager must implement @ref LIM_ResourceManagerInit()
 * and @ref LIM_ResourceManagerDeinit(), which will be respectively called
 * by IL core once upon core initialization and deinitialization.
 *
 * Within @ref LIM_ResourceManagerInit(), resource manager is required to
 * register all its managed resources with LIM OpenMAX by calling to
 * @ref limoi_resource_register(). Each implementation must identify itself by
 * unique 'manager_id'. How this is defined is out of the LIM scope.
 *
 * Implementation may choose to also carry out actual resource initialization
 * within @ref LIM_ResourceManagerInit(), however this will block OpenMAX IL
 * core initialization. Thus it is recommended to put resource initialization
 * in background, or implementation can choose to do lazy initialization, where
 * resourece gets initialized only before it actually gets used.
 *
 * It is safe for implementation to release all managed resources upon
 * @ref LIM_ResourceManagerDeinit().
 */

/** arbitrary unique resourece manager ID. */
#define DEMO_RESOURCE_MANAGER_ID 0xDEADBEEF


/** @} */
#endif /* LIM_DEMO_RESOURCE_MANAGER_H__ */
