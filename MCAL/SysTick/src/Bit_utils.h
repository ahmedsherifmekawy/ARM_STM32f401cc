#ifndef BIT_UTILS_H_
#define BIT_UTILS_H_

#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=~(1<<bit)
#define GET_BIT(reg,bit) (1&(reg>>bit))
#define RSHIFT_REG(reg,no) reg>>=no
#define LSHIFT_REG(reg,no) reg<<=no
#define CRSHIFT_REG(reg,no) reg=(reg>>no)|(reg<<(8-no))
#define CLSHIFT_REG(reg,no) reg=(reg<<no)|(reg>>(8-no))
#define ASSIGN_REG(reg,value) reg=value
#define SET_REG(reg) reg=0xFF
#define CLR_REG(reg) reg=0
#define TGL_BIT(reg,bit) reg^=(1<<bit)
#define TGL_REG(reg) reg^=0xFF
#define SET_H_NIB(reg) reg|=0xF0
#define SET_L_NIB(reg) reg|=0x0F
#define CLR_H_NIB(reg) reg&=0x0F
#define CLR_L_NIB(reg) reg&=0xF0
#define GET_H_NIB(reg) reg>>4
#define GET_L_NIB(reg) reg&0x0F
#define TGL_H_NIB(reg) reg^=0xF0
#define TGL_L_NIB(reg) reg^=0x0F
#define ASSIGN_H_NIB(reg,value) reg=(reg&0x0F)|(value<<4)
#define ASSIGN_L_NIB(reg,value) reg=(reg&0xF0)|(value&0x0F)
#define SWAP_NIB(reg) reg=(reg<<4)|(reg>>4)

#endif
