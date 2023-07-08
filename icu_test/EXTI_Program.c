/*
 * EXTI_Program.c
 *
 *  Created on: Jun 16, 2023
 *      Author: armmw
 */

#include "EXTI_Interface.h"

static void (*pf[3]) (void)={NULL_PTR,NULL_PTR,NULL_PTR};


void EXTI_voidEXTIEnable(u8 EXTI_u8Num, u8 EXTI_u8Sense)
{
	if( (EXTI_u8Num > EXTI_u8_EXTI2) || (EXTI_u8Sense > EXTI_u8_RISING_EDGE) )
	{

	}
	else if ((EXTI_u8Num == EXTI_u8_EXTI2) && (EXTI_u8Sense < 2))
	{

	}
	else
	{
		switch(EXTI_u8Num)
		{
			case EXTI_u8_EXTI0: SET_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT0);
			switch(EXTI_u8Sense)
			{
				case EXTI_u8_LOW_LEVEL:
					CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
					CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
					break;
				case EXTI_u8_ANY_LOGICAL_CHANGE:
					SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
					CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
					break;
				case EXTI_u8_FALLING_EDGE:
					CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
					SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
					break;
				case EXTI_u8_RISING_EDGE:
					SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
					SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
					break;
			}
			break;
			case EXTI_u8_EXTI1: SET_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT1);

			switch(EXTI_u8Sense)
			{
				case EXTI_u8_LOW_LEVEL:
					CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
					CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
					break;
				case EXTI_u8_ANY_LOGICAL_CHANGE:
					SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
					CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
					break;
				case EXTI_u8_FALLING_EDGE:
					CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
					SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
					break;
				case EXTI_u8_RISING_EDGE:
					SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
					SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
					break;
			}
			break;
			case EXTI_u8_EXTI2:
				SET_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT2);
				switch(EXTI_u8Sense)
				{
				case EXTI_u8_FALLING_EDGE:
					CLEAR_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_MCUCSR_ISC2);
					break;
				case EXTI_u8_RISING_EDGE:
					SET_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_MCUCSR_ISC2);
					break;
				}
				break;
		}
	}
}




void EXTI_voidEXTIDisable(u8 EXTI_u8Num)
{
	if(EXTI_u8Num > EXTI_u8_EXTI2)
	{

	}
	else
	{
		switch(EXTI_u8Num)
		{
		case EXTI_u8_EXTI2 : CLEAR_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT2); break;
		case EXTI_u8_EXTI1 : CLEAR_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT1); break;
		case EXTI_u8_EXTI0 : CLEAR_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT0); break;


		}
	}


}



void EXTI_voidSetCallBack( void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex)
{
    pf[Copy_u8EXTIIndex] = Copy_PtrToFunc;
}

/***********************************EXTI0 ISR***********************************/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
    if(pf[EXTI_u8_EXTI0] != NULL_PTR)
    {
        pf[EXTI_u8_EXTI0]();
    }
}

/***********************************EXTI1 ISR***********************************/
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{
    if(pf[EXTI_u8_EXTI1] != NULL_PTR)
    {
        pf[EXTI_u8_EXTI1]();
    }
}

/***********************************EXTI2 ISR***********************************/
void __vector_3(void)   __attribute__((signal));
void __vector_3(void)
{
    if(pf[EXTI_u8_EXTI2] != NULL_PTR)
    {
        pf[EXTI_u8_EXTI2]();
    }
}
