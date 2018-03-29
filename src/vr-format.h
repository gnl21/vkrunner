/*
 * vkrunner
 *
 * Copyright (C) 2018 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef VR_FORMAT_H
#define VR_FORMAT_H

#include "vr-vk.h"

enum vr_format_mode {
        VR_FORMAT_MODE_UNORM,
        VR_FORMAT_MODE_SNORM,
        VR_FORMAT_MODE_USCALED,
        VR_FORMAT_MODE_SSCALED,
        VR_FORMAT_MODE_UINT,
        VR_FORMAT_MODE_SINT,
        VR_FORMAT_MODE_UFLOAT,
        VR_FORMAT_MODE_SFLOAT,
        VR_FORMAT_MODE_SRGB,
};

enum vr_format_swizzle {
        VR_FORMAT_SWIZZLE_RGBA,
        VR_FORMAT_SWIZZLE_BGRA,
        VR_FORMAT_SWIZZLE_ARGB,
        VR_FORMAT_SWIZZLE_ABGR,
};

struct vr_format_component {
        int bits;
};

struct vr_format {
        VkFormat vk_format;
        const char *name;
        /* If the format is packed, this is the total number of bits.
         * Otherwise it is zero.
         */
        int packed_size;
        enum vr_format_swizzle swizzle;
        enum vr_format_mode mode;
        int n_components;
        struct vr_format_component components[4];
};

const struct vr_format *
vr_format_lookup_by_name(const char *name);

const struct vr_format *
vr_format_lookup_by_vk_format(VkFormat vk_format);

const struct vr_format *
vr_format_lookup_by_details(int bit_size,
                            enum vr_format_mode mode,
                            int n_components);

int
vr_format_get_size(const struct vr_format *format);

#endif /* VR_FORMAT_H */
