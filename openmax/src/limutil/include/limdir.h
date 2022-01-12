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

  LIM directory entry helper module header.

  REVISION:

    1) initial creation. ----------------------------------------- 2011-05-25 MG
*/

/** @defgroup dir directory entry helper
 * @ingroup limutil
 * @{
 */

#ifndef LIMDIRENT_H__
#define LIMDIRENT_H__

#include <sys/types.h>
//#include <dirent.h>

/** recursively scan given directory.
 *
 * @param path
 *        absolute target directory path to scan.
 * @param next
 *        callback with next non-directory (regular file, for example)
 *        entry, and user callback context.
 * @param arg
 *        user callback context.
 * @return
 *        0 if successfully scanned, -1 otherwise.
 */
int limdir_recursive_scan (
    const char * path,
    void (*next) (const char * ent, void * arg),
    void * arg);

/** @} */
#endif /* LIMDIRENT_H__ */
