#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MTD_DEBUG
#define CONFIG_MTD_DEBUG_VERBOSE 10000
/* High Level Configuration Options */
#define CONFIG_ARM1136
#define CONFIG_OX820

#include <asm/arch/cpu.h>		/* get chip and board defs */

/*#define CONFIG_ARCH_CPU_INIT*/
/*#define CONFIG_DISPLAY_CPUINFO*/
/*#define CONFIG_DISPLAY_BOARDINFO*/
/*#define CONFIG_BOARD_EARLY_INIT_F*/
/*#define CONFIG_SKIP_LOWLEVEL_INIT*/

/* mem */
#define CONFIG_SYS_SDRAM_BASE		0x60000000
#define CONFIG_NR_DRAM_BANKS		1
#define SDRAM_SIZE			(128 * 1024 * 1024)	/* 128 MB */
#define CONFIG_SRAM_BASE		0x50000000
#define CONFIG_SRAM_SIZE		(64 * 1024)

/* need do dma so better keep dcache off */
#define CONFIG_SYS_DCACHE_OFF

/* clock */
#define CONFIG_PLLA_FREQ_MHZ		800
#define CONFIG_RPSCLK			6250000
#define CONFIG_SYS_HZ			(CONFIG_RPSCLK / 16)
#define CONFIG_SYS_CLK_FREQ		CONFIG_RPSCLK
#define CONFIG_SYS_TIMERBASE		TIMER1_BASE
#define CONFIG_TIMER_PRESCALE		TIMER_PRESCALE_16

/* serial */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_CLK		CONFIG_RPSCLK
#define CONFIG_SYS_NS16550_REG_SIZE	1
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_NS16550_COM1		UART_1_BASE
#define CONFIG_CONS_INDEX		1

/* ide */
#define CONFIG_SYS_ATA_BASE_ADDR	0
#define CONFIG_SYS_ATA_DATA_OFFSET	0
#define CONFIG_SYS_ATA_REG_OFFSET	0
#define CONFIG_SYS_ATA_ALT_OFFSET	0
#define CONFIG_IDE_PLX
#define CONFIG_SYS_IDE_MAXDEVICE	1
#define CONFIG_SYS_IDE_MAXBUS		1
#define CONFIG_IDE_PREINIT

/* nand */
#define CONFIG_NAND
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		STATIC_CS0_BASE
#define NAND_CLE_ADDR_PIN		19
#define NAND_ALE_ADDR_PIN		18


/* net */
#define CONFIG_DESIGNWARE_ETH
#define CONFIG_DW_ALTDESCRIPTOR
#define CONFIG_DW_AUTONEG
#define CONFIG_DW_SEARCH_PHY
#define CONFIG_MII
#define CONFIG_CMD_MII
#define CONFIG_PHYLIB
#define CONFIG_PHY_REALTEK
#define CONFIG_ETHADDR			00:25:31:01:66:5F

/* spl */
#define CONFIG_SPL
#define CONFIG_SPL_BOARD_INIT
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_TEXT_BASE		0x50000000
#define CONFIG_SPL_MAX_SIZE		(32 * 1024)
#define CONFIG_SPL_STACK		(CONFIG_SRAM_BASE + (48 * 1024))
/*#define CONFIG_SPL_DISPLAY_PRINT*/
#define CONFIG_SPL_BLOCK_SUPPORT
#define BOOT_DEVICE_BLOCK		860202
#define CONFIG_SYS_BLOCK_RAW_MODE_U_BOOT_SECTOR		1024
#define CONFIG_SYS_BLOCK_RAW_MODE_KERNEL_SECTOR		4096
#define CONFIG_SYS_BLOCK_RAW_MODE_ARGS_SECTOR		0
#define CONFIG_SYS_BLOCK_RAW_MODE_ARGS_SECTORS		1
#define CONFIG_SYS_SPL_ARGS_ADDR			(CONFIG_SYS_SDRAM_BASE + 0x100)

/* boot */
#define CONFIG_IDENT_STRING		" for OXNAS"
#define CONFIG_MACH_TYPE		MACH_TYPE_OXNAS
/* Enable devicetree support */
#define CONFIG_OF_LIBFDT
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG
#define CONFIG_BOOTDELAY		3
#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_DEFAULT_CONSOLE		"console=ttyS0,115200n8\0"
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
/* memtest works on */
#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE)
#define CONFIG_BOOTCOMMAND		"run ideboot"

#define CONFIG_EXTRA_ENV_SETTINGS	\
	"ideboot=" \
                "setenv bootargs root=ubi0!rootfs rootfstype=ubif ${console};" \
                "fatload ide 0 60000000 uImage;" \
                "bootm\0" \
	"updboot=" \
				"bootp;" \
				"tftp 60000000 u-boot.img;" \
				"ide write 60000000 400 400\0" \
	"console=" CONFIG_DEFAULT_CONSOLE \
	"bootargs=" CONFIG_DEFAULT_CONSOLE

/* env */
#define CONFIG_ENV_IS_IN_FAT
#define CONFIG_START_IDE
#define FAT_ENV_INTERFACE 		"ide"
#define FAT_ENV_DEVICE			0
#define FAT_ENV_PART			1
#define FAT_ENV_FILE			"u-boot.env"
#define CONFIG_ENV_SIZE			(16 * 1024)
/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_SYS_MONITOR_LEN		(512 * 1024)
#define CONFIG_SYS_TEXT_BASE		0x64000000
#define CONFIG_SYS_INIT_SP_ADDR		0x65000000
/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(1 * 1024 * 1024)

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER		/* use "hush" command parser	*/
#define CONFIG_SYS_PROMPT		"OX820 # "
#define CONFIG_SYS_CBSIZE		1024	/* Console I/O Buffer Size*/
#define CONFIG_SYS_PBSIZE		1024	/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS		32	/* max number of command args */
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE

/* cmds */
#include <config_cmd_default.h>

#define CONFIG_CMD_SAVEENV

#define CONFIG_CMD_NET
#define CONFIG_CMD_NFS
#define CONFIG_CMD_PING
#define CONFIG_CMD_ELF
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PXE

#define CONFIG_CMD_NAND
#define CONFIG_CMD_NAND_YAFFS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS

#define CONFIG_SYS_NO_FLASH
#undef CONFIG_CMD_IMLS

#define CONFIG_CMD_IDE
#define CONFIG_CMD_FAT
#define CONFIG_FAT_WRITE
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_EXT4_WRITE
#define CONFIG_CMD_ZIP
#define CONFIG_CMD_UNZIP
#define CONFIG_CMD_TIME
#define CONFIG_CMD_TERMINAL
#define CONFIG_CMD_SETEXPR
#define CONFIG_CMD_MD5SUM
#define CONFIG_CMD_HASH
#define CONFIG_CMD_INI
#define CONFIG_CMD_GETTIME
#define CONFIG_CMD_BOOTMENU

#define CONFIG_DOS_PARTITION

/* for CONFIG_CMD_MTDPARTS */
#define CONFIG_MTD_DEVICE
/* for CONFIG_CMD_UBI */
#define CONFIG_MTD_PARTITIONS
/* for CONFIG_CMD_UBIFS */
#define CONFIG_RBTREE
/* optional, for CONFIG_CMD_BOOTM */

#define CONFIG_LZO
#define CONFIG_LZMA
#define CONFIG_BZIP2
/* for CONFIG_CMD_ZIP */
#define CONFIG_GZIP_COMPRESSED
/* for CONFIG_CMD_MD5SUM */
#define CONFIG_MD5
#define CONFIG_MD5SUM_VERIFY
/* enable CONFIG_CMD_HASH's verification feature */
#define CONFIG_HASH_VERIFY
#define CONFIG_REGEX
/* for CONFIG_CMD_BOOTMENU */
#define CONFIG_MENU

#endif	/* __CONFIG_H */
