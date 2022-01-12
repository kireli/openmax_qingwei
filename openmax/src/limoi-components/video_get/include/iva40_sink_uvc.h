/** @addtogroup limoi_component_ffmpeg_enc
 * @{
 */

#ifndef __IVA40_SINK_UVC_H__
#define __IVA40_SINK_UVC_H__

#include "limoi.h"

/** video src camera component private data structure. */
typedef struct
{
    limoi_iva40_uvc_t parent; /** inherit limoi video src. */

} iva40_sink_uvc_priv_t;

#define IVA40_SINK_UVC(c) ((iva40_sink_uvc_priv_t *)OMX_COMPONENT(c))

/** @} */
#endif /* __IVA40_SINK_UVC_H__ */
