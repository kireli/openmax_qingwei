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

  OpenMAX IL core content pipe support header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-12-06 MG
*/

/** @defgroup contentpipe limoi content pipe
 * @ingroup limoi_core
 * @{
 */

#ifndef CONTENT_PIPE_H__
#define CONTENT_PIPE_H__
#define _FILE_OFFSET_BITS 64
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "core.h"
#include "OMX_ContentPipe.h"
#include "limthread.h"

#define BUFFER_CONTAINS(ptr, buf, bytes) \
    ((void*)(ptr) >= (void*)(buf) && (void*)(ptr) < (void*)(buf) + (bytes))

typedef void * content_handle_t;

/** content information structure. */
typedef struct
{
    /** content length in bytes. */
    off_t content_length_bytes;

    /** content access internal circular buffer length in bytes. */
    int circular_buffer_bytes;

    /** content commit step bytes.
     * read or write this much of bytes at a time from or to physical content.
     */
    int commit_step_bytes;
} content_info_t;

/** content access interface.
 * caller should make sure interface calls are serialized.
 */
typedef struct
{
    /** can interface access given content? */
    int (*can_access) (CPstring szURI);

    /** Open a content stream for reading or writing. */
    CPresult (*open) (content_handle_t * content,
                      CPstring szURI,
                      CP_ACCESSTYPE eAccess);

    /** Close a content stream. */
    CPresult (*close) (content_handle_t content);

    /** Seek to certain position in the content. */
    CPresult (*seek) (content_handle_t content,
                      CPint nOffset,
                      CP_ORIGINTYPE eOrigin);

    /** Retrieve data of the specified size from the content. */
    CPresult (*read) (content_handle_t content,
                      CPbyte * pData,
                      CPuint * nSize);

    /** Write data of the specified size to the content. */
    CPresult (*write) (content_handle_t content,
                       CPbyte * pData,
                       CPuint * nSize);

    /** retrieve content information. */
    CPresult (*info) (content_handle_t content,
                      content_info_t * info);
} content_access_itf_t;

extern content_access_itf_t content_access_itf_file;

/** @} */
#endif /* CONTENT_PIPE_H__ */
