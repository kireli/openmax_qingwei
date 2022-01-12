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

  OpenMAX IL core resource manager header.

  REVISION:

    1) initial creation. ----------------------------------------- 2011-04-30 MG
*/

#ifndef RESOURCE_MANAGER_H__
#define RESOURCE_MANAGER_H__

/** @addtogroup core_internal
 * @{
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

#include "limlog.h"
#include "limqlist.h"
#include "limdir.h"

/** resource manager initialization
 * Entry point to load and initialize all resource managers, called at
 * @ref OMX_init(). This searches 'limoi/resource-manager' area for resource
 * manager plugins, and call each manager's @ref LIM_ResourceManagerInit()
 * routine to register it with system.
 */
void lim_resource_manager_init (void);


/** resource manager initialization
 * Entry point to deinitialize all resource managers, called at
 * @ref OMX_Deinit() time. This loops through all registered resource managers
 * and call each manager's @ref LIM_ResourceManagerInit() routine to unregister.
 */
void lim_resource_manager_deinit (void);


/** @} */
#endif /* CORE_H__ */
