#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char          u8;
typedef unsigned short int     u16;
typedef unsigned long int 	   u32;
typedef unsigned long long     u64;   

typedef signed char 	       s8;
typedef signed short int       s16;
typedef signed long int        s32;
typedef signed long long       s64;   

typedef float                  f32;
typedef double                 f64;
typedef long double            f128;

typedef unsigned char *        pu8;
typedef unsigned short int *   pu16;
typedef unsigned long int *    pu32;
typedef unsigned long long *   pu64;


typedef const unsigned char          ku8;
typedef const unsigned short int     ku16;
typedef const unsigned long int 	 ku32;
typedef const unsigned long long     ku64;

#define NULL                   (void *) 0x0

#endif
