/*
 * Flash_Driver.h
 *
 *  Created on: May 14, 2022
 *      Author: WINDOWS
 */

#ifndef FLASH_DRIVER_H_
#define FLASH_DRIVER_H_

typedef enum{
	FDOk,
	FDNok
}FD_tenuErrorStatus;


#define     FD_USR_CFG_SECTOR         (u32)0x68
#define     FD_SECTOR_0		          (u32)0x00000000
#define     FD_SECTOR_1		          (u32)0x00000008
#define     FD_SECTOR_2		          (u32)0x00000010
#define     FD_SECTOR_3		          (u32)0x00000018
#define     FD_SECTOR_4		          (u32)0x00000020
#define     FD_SECTOR_5		          (u32)0x00000028

FD_tenuErrorStatus FD_Init();
FD_tenuErrorStatus FD_EraseSector(u32 Copy_enuSectorNumber );
FD_tenuErrorStatus FD_ProgramPage( u32 Copy_u32PageAddress , u32 Copy_u32PageData);
void FD_LockCR();

#endif /* FLASH_DRIVER_H_ */
