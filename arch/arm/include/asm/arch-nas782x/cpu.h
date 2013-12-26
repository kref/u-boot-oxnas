#ifndef _NAS782X_CPU_H
#define _NAS782X_CPU_H

#if !(defined(__KERNEL_STRICT_NAMES) || defined(__ASSEMBLY__))
#include <asm/types.h>
#include <asm/io.h>
#endif /* !(__KERNEL_STRICT_NAMES || __ASSEMBLY__) */

#include <asm/arch/hardware.h>
#include <asm/arch/timer.h>

#ifndef __KERNEL_STRICT_NAMES
#ifndef __ASSEMBLY__

#define BIT(x)                  (1 << (x))

#endif /* __ASSEMBLY__ */
#endif /* __KERNEL_STRICT_NAMES */

#endif /* _NAS782X_CPU_H */
