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

  OpenMAX AL engine implementation - output mix object ipc ID definitions.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-17 MG
*/

/** @addtogroup limoa_generics
 * @{
 */

#ifndef LIMIPC_ID_OUTPUT_MIX_H__
#define LIMIPC_ID_OUTPUT_MIX_H__

// output mix message ID
#define OX_RQST_OUTPUT_MIX_CREATE                  MSG(SGMT_OUTPUT_MIX, 1)
#define OX_RQST_OUTPUT_MIX_REALIZE                 MSG(SGMT_OUTPUT_MIX, 2)
#define OX_RQST_OUTPUT_MIX_DESTROY                 MSG(SGMT_OUTPUT_MIX, 3)

/** @} */
#endif /* LIMIPC_ID_OUTPUT_MIX_H__ */
