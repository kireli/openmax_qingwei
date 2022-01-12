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

  OpenMAX IL implementation - log and debug msg support header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-11-20 MG
*/

/** @addtogroup limoi_base_generics
 * @{
 */

#ifndef LIMOI_LOG_H__
#define LIMOI_LOG_H__

#include "limlog.h"
#include "OMX_Core.h"

/** OpenMAX IL error code string. */
const char * limoi_omx_error_string (OMX_ERRORTYPE res);

/** OpenMAX IL component state string. */
const char * limoi_omx_state_string (OMX_STATETYPE state);

/** OpenMAX IL component event string. */
const char * limoi_omx_event_string (OMX_EVENTTYPE event);

/** OpenMAX IL command string. */
const char * limoi_omx_command_string (OMX_COMMANDTYPE cmd);

/** OpenMAX IL component port status report. */
void limoi_omx_port_status (OMX_HANDLETYPE hComp, OMX_U32 index);


/** @} */
#endif /* LIMOI_LOG_H__ */
