/*
 * QEMU HAXM support
 *
 * Copyright IBM, Corp. 2008
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * Copyright (c) 2011 Intel Corporation
 *  Written by:
 *  Jiang Yunhong<yunhong.jiang@intel.com>
 *  Xin Xiaohui<xiaohui.xin@intel.com>
 *  Zhang Xiantao<xiantao.zhang@intel.com>
 *
 * Copyright 2016 Google, Inc.
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 *
 */

#ifndef QEMU_HAX_H
#define QEMU_HAX_H

#include "config-host.h"
#include "qemu-common.h"

int hax_pre_init(uint64_t ram_size);
int hax_sync_vcpus(void);
void hax_disable(int disable);
int hax_init_vcpu(CPUState *cpu);
int hax_smp_cpu_exec(CPUState *cpu);
int hax_vcpu_exec(CPUState *cpu);
int hax_vcpu_emulation_mode(CPUState *cpu);
int hax_stop_emulation(CPUState *cpu);
int hax_stop_translate(CPUState *cpu);
/* get the max haxm ram even before haxm library is initialized */
int hax_get_max_ram(uint64_t *max_ram);
int hax_populate_ram(uint64_t va, uint32_t size);

void hax_cpu_synchronize_state(CPUState *cpu);
void hax_cpu_synchronize_post_reset(CPUState *cpu);
void hax_cpu_synchronize_post_init(CPUState *cpu);

#ifdef CONFIG_HAX

int hax_enabled(void);
int hax_ug_platform(void);

#include "hw/hw.h"
#include "qemu/bitops.h"
#include "exec/memory.h"
int hax_vcpu_destroy(CPUState *cpu);
void hax_raise_event(CPUState *cpu);
void hax_reset_vcpu_state(void *opaque);
#include "target-i386/hax-interface.h"
#include "target-i386/hax-i386.h"

#else /* CONFIG_HAX */

#define hax_enabled() (0)
#define hax_ug_platform() (0)

#endif /* CONFIG_HAX */

#endif /* QEMU_HAX_H */