/*
 * Lin_cfg.c
 *
 *  Created on: May 16, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Lin.h"
#include "Lin_cfg.h"

u8 data [5]={1,2,3,4,5};

Lin_tstrInfo Lin_Info [ LIN_u8TIME_SLOTS ] = {

		[0]= {
				.ID = 5,
				. Data = {
							.Data = data ,
							.Size = 5,
							.Used = 0
						 },
				. Sender = 6,
				. Receiver = 8
		     },
		 [1]= {
				.ID = 9,
				. Data = {
							.Data = data ,
							.Size = 5,
							.Used = 0
						 },
				. Sender = 2,
				. Receiver = 7
			  },
		  [2]= {
						.ID = 7,
						. Data = {
									.Data = data ,
									.Size = 5,
									.Used = 0
								 },
						. Sender = 6,
						. Receiver = 2
					   },
};

Buffer_t Data[ LIN_u8MESSAGES_NUMBER ] ={
		[LIN_u8ID_TEMP] = {
				.Data = data,
				.Size = 2,
				.Used = 0,
		},
		[LIN_u8ID_START] ={
				.Data = data,
				.Size = 2,
				.Used = 0,
		}
};

