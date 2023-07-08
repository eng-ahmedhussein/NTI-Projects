/*
 * GIE_Program.c
 *
 *  Created on: Jun 16, 2023
 *      Author: armmw
 */

#include "GIE_Private.h"
#include "GIE_Interface.h"
#include "GIE_Config.h"


void GIE_voidGIEEnable(void)
{

	SET_BIT(GIE_u8_SREG_REG , 7);
}


void GIE_voidGIEDisable(void)
{
	CLEAR_BIT(GIE_u8_SREG_REG , 7);
}



