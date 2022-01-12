/** @addtogroup 
 * @{
 */

#ifndef __IVA50_SINK_UVC_H__
#define __IVA50_SINK_UVC_H__

#include "limoi.h"

/** video src camera component private data structure. */
typedef struct
{
    limoi_iva50_uvc_t parent; /** inherit limoi video src. */

} iva50_sink_uvc_priv_t;

#define IVA50_SINK_UVC(c) ((iva50_sink_uvc_priv_t *)OMX_COMPONENT(c))

/** @} */
#endif /* __IVA50_SINK_UVC_H__ */
