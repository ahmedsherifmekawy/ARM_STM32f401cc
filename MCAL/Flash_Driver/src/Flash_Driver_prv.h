/*
 * Flash_Driver_prv.h
 *
 *  Created on: May 14, 2022
 *      Author: WINDOWS
 */

#ifndef FLASH_DRIVER_PRV_H_
#define FLASH_DRIVER_PRV_H_

typedef struct{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 OPTCR;
}FD_tstr;

#define      FD_BASE_ADD             (u32)0x40023C00

#define      FD                      (( volatile FD_tstr *)FD_BASE_ADD)

#define      FD_KEY1                 (u32)0x45670123
#define      FD_KEY2                 (u32)0xCDEF89AB

#define      FD_OPTKEY1              (u32)0x08192A3B
#define      FD_OPTKEY2              (u32)0x4C5D6E7F


#define      FD_CR_SNB_MSK           (u32)0x78
#define      FD_CR_SER_MSK           (u32)0x2
#define      FD_CR_PG_MSK            (u32)0x1
#define      FD_CR_MER_MSK           (u32)0x4
#define      FD_CR_LOCK_MSK          (u32)0x80000000
#define      FD_CR_STRT_MSK          (u32)0x10000
#define      FD_CR_PSIZE_MSK         (u32)0x00000300

#define      FD_CR_PSIZE_32          (u32)0x00000200

#define      FD_SR_BSY_MSK           (u32)0x10000

#endif /* FLASH_DRIVER_PRV_H_ */
