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

  OpenMAX IL core component loader plugin header.

  REVISION:

    1) initial creation. ----------------------------------------- 2011-05-23 MG
*/

#ifndef OMX_LIM_H__
#define OMX_LIM_H__

/** @defgroup core_loader limoi component registration
 * @ingroup limoi_core
 * @{
 *
 * LIM OpenMAX IL core supports both static linking and dynamic loading of
 * OpenMAX IL components. Also, LIM OpenMAX IL core can serve as the super
 * IL core where components from other IL cores can be dynamically loaded
 * and universally enumerated.
 *
 * @section cl_s1 static linking
 * Components can be statically linked with limoi-core, by implementing
 * @ref lim_omx_component_registration_t and populating
 * @ref LIM_OMX_ComponentRegistrationTable().
 *
 * @section cl_s2 dynamic loading
 * Components can be dynamically discovered and loaded by limoi OpenMAX IL
 * core, by implementing @ref OMX_ComponentRegistration() and installing to
 * <libdir>/limoi/component area. There can be one or multiple components
 * within one implementation.
 *
 * Components can optionally implement @ref OMX_ComponentDeregistration()
 * if they have resource that need to be deallocated. If present,
 * @ref OMX_ComponentDeregistration() will be called upon @ref OMX_Deinit().

 * This mechanism can be extended to write arbitrary dynamic component loader
 * for components implemented out of LIM context, by writing a 'loader' who
 * implements @ref OMX_ComponentRegistration() and installs to
 * <libdir>/limoi/loader area. This 'loader' can then scan all supported
 * components following the rules defined by 'loader' itself.
 *
 * @section cl_s3 super core
 * LIM OpenMAX IL core can load and enumerate components from other IL cores,
 * thus to present client with one universal IL core to link with. To do this,
 * simply install any other IL core to <libdir>/limoi/other-core area.
 *
 */

#include "OMX_Core.h"
#include "OMX_Component.h"
#include "OMX_Types.h"


/** construct and initialize component
 * This is called only upon @ref OMX_GetHandle(), to instantiate component.
 *
 * @param hComponent
 *        component handle allocated by core, freed upon @ref OMX_FreeHandle().
 * @param name
 *        unique OpenMAX IL standard component name.
 * @return
 *        OpenMAX IL return code.
 */
typedef OMX_ERRORTYPE (*OMX_ComponentInit)
(OMX_HANDLETYPE * hComponent, const char * name);


/** limoi component registration data structure. */
typedef struct
{
    char * name; /** IL standard component name. */
    char ** roles; /** IL standard component roles, ends with NULL. */
    OMX_ComponentInit init; /** component constructor. */
} lim_omx_component_registration_t;


/** return array of component registration data
 * This is called upon @ref OMX_Init(), to register component with core.
 * This must be implemented by component that is intended to be dynamically
 * loaded by core.
 *
 * @param num
 *        output, number of components available.
 * @return
 *        component registration data @ref limoi_component_registration_t.
 */
lim_omx_component_registration_t ** OMX_ComponentRegistration (int * num);


/** revert the component registration
 * when implemented, this gets called upon @ref OMX_Deinit().
 */
void OMX_ComponentDeregistration (void);


/** components statically linked with core shall populate this table. */
extern lim_omx_component_registration_t * LIM_OMX_ComponentRegistrationTable[];


/** @} */
#endif /* OMX_LIM_H__ */
