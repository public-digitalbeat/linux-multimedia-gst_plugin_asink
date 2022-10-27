/* GStreamer
 * Copyright (C) 2020 Amlogic, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free SoftwareFoundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#ifndef __GST_META_PES_HEADER_H__
#define __GST_META_PES_HEADER_H__

#include <gst/gst.h>
#include <gst/gstmeta.h>

G_BEGIN_DECLS

typedef struct _GstMetaPesHeader GstMetaPesHeader;
typedef struct _GstMetaPesHeaderInitParams GstMetaPesHeaderInitParams;

struct _GstMetaPesHeader {
    GstMeta meta;
    //TBD: GstClockTime timestamp;
    guint length;
    guchar* header;
};

struct _GstMetaPesHeaderInitParams {
    guint length;
    guchar* header;
};

GType gst_meta_pes_header_api_get_type (void);
const GstMetaInfo* gst_meta_pes_header_get_info (void);
#define GST_META_PES_HEADER_GET(buf) ((GstMetaPesHeader *)gst_buffer_get_meta(buf,gst_meta_pes_header_api_get_type()))
#define GST_META_PES_HEADER_ADD(buf,init_params) ((GstMetaPesHeader *)gst_buffer_add_meta(buf,gst_meta_pes_header_get_info(),(gpointer)&init_params))

G_END_DECLS

#endif //#ifndef __GST_META_PES_HEADER_H__
