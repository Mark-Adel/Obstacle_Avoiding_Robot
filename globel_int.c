/*
 * globel_int.c
 *
 *  Created on: Aug 9, 2021
 *      Author: Eng-Ahmed Shalaby
 */

#include "globel_int_interface.h"
#include "bit_math.h"
#include "std_types.h"
#include "globel_inte.h"
void GLOBEL_INTENABEL(void)
{

	SET_BIT( SREG , SREG_EIG);
}
