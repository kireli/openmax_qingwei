/** @addtogroup limoi_component_ffmpeg_enc
 * @{
 */

#ifndef _IVA10_SINK_BULK_H_
#define _IVA10_SINK_BULK_H_

#include "limoi.h"

/** video src camera component private data structure. */
typedef struct
{
    limoi_videoIVA10_t parent; /** inherit limoi video src. */

} iva10_sink_bulk_priv_t;

#define IVA10_SINK_BULK(c) ((iva10_sink_bulk_priv_t *)OMX_COMPONENT(c))

/** @} */
#endif /* _IVA40_SINK_BULK_H_ */
