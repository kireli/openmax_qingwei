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

  OpenMAX IL core internal header.

  REVISION:

    2) component multi-instantiation support. -------------------- 2011-05-22 MG
    1) initial creation. ----------------------------------------- 2009-11-23 MG
*/

#ifndef CORE_H__
#define CORE_H__

/** @defgroup core_internal limoi core internal
 * @ingroup limoi_core
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

#include "OMX_Core.h"
#include "OMX_Component.h"
#include "OMX_Types.h"
#include "OMX_Lim.h"
#include "limlog.h"
#include "limqlist.h"
#include "limthread.h"

typedef lim_omx_component_registration_t ** (*comp_registration_entry_t) (int *);
typedef void (*comp_deregistration_entry_t) (void);

/** component role registration structure. */
typedef struct
{
    list_t list;
    const char * name; /** role name. */
} role_reg_t;

/** component instance registration structure. */
typedef struct
{
    list_t list;
    void * handle; /** non-null component handle if loaded. */
} instance_reg_t;

/** component so registration structure. */
typedef struct
{
    list_t list;
    const char * name; /** full path to component library. */
    void * lib; /** non-null library handle if loaded. */
    comp_registration_entry_t registration; /** registration handle if non-null. */
    comp_deregistration_entry_t deregistration; /** deregistration handle if non-null. */
    int ref_count; /** library handle reference count. */
} so_reg_t;

/** external OpenMAX IL core registration structure. */
typedef struct
{
    list_t list;
    void * lib; /** core library handle. */
    OMX_ERRORTYPE (*OMX_Init) (void);
    OMX_ERRORTYPE (*OMX_Deinit) (void);
    OMX_ERRORTYPE (*OMX_ComponentNameEnum) (OMX_STRING, OMX_U32, OMX_U32);
    OMX_ERRORTYPE (*OMX_GetHandle)
                  (OMX_HANDLETYPE *, OMX_STRING, OMX_PTR, OMX_CALLBACKTYPE *);
    OMX_ERRORTYPE (*OMX_FreeHandle) (OMX_HANDLETYPE);
    OMX_ERRORTYPE (*OMX_GetRolesOfComponent) (OMX_STRING, OMX_U32 *, OMX_U8 **);
} core_reg_t;

/** component internal management object structure. */
typedef struct
{
    /** component libraray registration handle, valid only for
     * dynamically-loading component, NULL for static-linking component.
     */
    so_reg_t * so;
    /** component constructor, valid only for static-linking component,
     * NULL for dynamically-loading component.
     */
    OMX_ComponentInit init;
    /** OpenMAX IL core registration handle, valid for component from
     * external IL core, NULL for regular component.
     */
    core_reg_t * core;
    list_t comps_list_head; /** component instances handle list head; */
} component_obj_t;

typedef struct
{
    list_t list;
    const char * name; /** component name. */
    list_t roles_list_head; /** component roles list head. */
    component_obj_t * obj; /** component blob that has all details. */
} component_reg_t;

typedef struct
{
    list_t components_list_head; /** component registration list. */
    list_t so_list_head; /** component libraray (so) registration list. */
    list_t core_list_head; /** external OpenMAX IL core registration list. */
    lthread_mutex_t mutex; /** component registration mutex. */
} limoi_omx_t;

extern limoi_omx_t limoi_omx;


component_reg_t * get_comp_registration_by_name (const char * name);
component_reg_t * get_comp_registration_by_handle (void * comp_handle);

/** @} */
#endif /* CORE_H__ */
