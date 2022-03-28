/*
 * Copyright (C) 2020 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef __GED_SKI_H__
#define __GED_SKI_H__

#include <linux/kobject.h>
#include <linux/sysfs.h>

#include "ged_base.h"

#define GED_SKI_MAX_BUFF_SIZE 128

#define KOBJ_ATTR_RW(_name)	\
	struct kobj_attribute kobj_attr_##_name =	\
		__ATTR(_name, 0660,	\
		_name##_show, _name##_store)
#define KOBJ_ATTR_RO(_name)	\
	struct kobj_attribute kobj_attr_##_name =	\
		__ATTR(_name, 0440,	\
		_name##_show, NULL)

GED_ERROR ged_ski_init(void);
void ged_ski_exit(void);

GED_ERROR ged_ski_create_dir(struct kobject *parent,
		const char *name, struct kobject **ppsKobj);
void ged_ski_remove_dir(struct kobject **ppsKobj);

GED_ERROR ged_ski_create_file(struct kobject *parent,
		struct kobj_attribute *kobj_attr);
void ged_ski_remove_file(struct kobject *parent,
		struct kobj_attribute *kobj_attr);

GED_ERROR ged_ski_init(void);
void ged_ski_exit(void);

extern struct kobject *kernel_kobj;

#endif
