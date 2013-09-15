/*
 * (C) Copyright 2010
 * Texas Instruments, <www.ti.com>
 *
 * Aneesh V <aneesh@ti.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <common.h>
#include <spl.h>
#include <asm/u-boot.h>
#include <asm/utils.h>
#include <version.h>
#include <ide.h>

inline void  init_part (block_dev_desc_t *dev_desc) {}
inline void dev_print(block_dev_desc_t *dev_desc) {}

static int ide_load_image_raw(int device, unsigned long sector)
{
	int n;
	u32 image_size_sectors;
	struct image_header *header;

	header = (struct image_header *)(CONFIG_SYS_TEXT_BASE -
						sizeof(struct image_header));

	/* read image header to find the image size & load address */
	n = ide_read(device, sector, 1, header);
	if (n != 1) {
		printf("spl: ide blk read err\n");
		return 1;
	}

	spl_parse_image_header(header);

	/* convert size to sectors - round up */
	image_size_sectors = (spl_image.size + 512 - 1) / 512;

	n = ide_read(device, sector, image_size_sectors, (void *)spl_image.load_addr);
	if (n != image_size_sectors) {
		printf("spl: ide blk read err\n");
		return 1;
	}
	return 0;
}

#ifdef CONFIG_SPL_OS_BOOT
static int ide_load_image_raw_os(int device)
{
	int n;
	n = ide_read(device, CONFIG_SYS_BLOCK_RAW_MODE_ARGS_SECTOR,
		CONFIG_SYS_BLOCK_RAW_MODE_ARGS_SECTORS,
		(u32 *)CONFIG_SYS_SPL_ARGS_ADDR);

	/* flush cache after read */
	flush_cache(addr, CONFIG_SYS_BLOCK_RAW_MODE_ARGS_SECTORS * 512);

	if (n != CONFIG_SYS_BLOCK_RAW_MODE_ARGS_SECTORS) {
		printf("ide args blk read error\n");
		return -1;
	}

	return ide_load_image_raw(device, CONFIG_SYS_BLOCK_RAW_MODE_KERNEL_SECTOR);
}
#endif


void spl_block_load_image(void)
{
	int err;

	ide_init();

#ifdef CONFIG_SPL_OS_BOOT
	if (spl_start_uboot() || ide_load_image_raw_os(0))
#endif
	err = ide_load_image_raw(0,
				 CONFIG_SYS_BLOCK_RAW_MODE_U_BOOT_SECTOR);

	if (err)
		hang();
}
