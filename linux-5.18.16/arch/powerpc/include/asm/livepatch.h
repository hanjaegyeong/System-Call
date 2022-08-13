/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * livepatch.h - powerpc-specific Kernel Live Patching Core
 *
 * Copyright (C) 2015-2016, SUSE, IBM Corp.
 */
#ifndef _ASM_POWERPC_LIVEPATCH_H
#define _ASM_POWERPC_LIVEPATCH_H

#include <linux/module.h>
#include <linux/ftrace.h>
#include <linux/sched/task_stack.h>

#ifdef CONFIG_LIVEPATCH
static inline void klp_arch_set_pc(struct ftrace_regs *fregs, unsigned long ip)
{
	ftrace_instruction_pointer_set(fregs, ip);
}
#endif /* CONFIG_LIVEPATCH */

#ifdef CONFIG_LIVEPATCH_64
static inline void klp_init_thread_info(struct task_struct *p)
{
	/* + 1 to account for STACK_END_MAGIC */
	task_thread_info(p)->livepatch_sp = end_of_stack(p) + 1;
}
#else
static inline void klp_init_thread_info(struct task_struct *p) { }
#endif

#endif /* _ASM_POWERPC_LIVEPATCH_H */
