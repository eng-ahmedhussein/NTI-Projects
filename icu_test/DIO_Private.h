/*
 * DIO_Private.h
 *
 *  Created on: Jun 14, 2023
 *      Author: armmw
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
#include "STD_Types.h"


#define DIO_u8_PORTA_REG		*((volatile u8 *)(0x3B))
#define DIO_u8_DDRA_REG	    	*((volatile u8 *)(0x3A))
#define DIO_u8_PINA_REG		    *((volatile u8 *)(0x39))

#define DIO_u8_PORTB_REG		*((volatile u8 *)(0x38))
#define DIO_u8_DDRB_REG			*((volatile u8 *)(0x37))
#define DIO_u8_PINB_REG			*((volatile u8 *)(0x36))

#define DIO_u8_PORTC_REG		*((volatile u8 *)(0x35))
#define DIO_u8_DDRC_REG			*((volatile u8 *)(0x34))
#define DIO_u8_PINC_REG			*((volatile u8 *)(0x33))

#define DIO_u8_PORTD_REG		*((volatile u8 *)(0x32))
#define DIO_u8_DDRD_REG			*((volatile u8 *)(0x31))
#define DIO_u8_PIND_REG			*((volatile u8 *)(0x30))



#endif /* DIO_PRIVATE_H_ */