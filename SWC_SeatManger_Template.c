/**
 *
 * \file SWC_SeatManger_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatManger
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/10/2023 07:04 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatManger.h"



/*The defintions below will be used to differinate between the button states*/

#define Multi_State_Btn_Int    0
#define Multi_State_Btn_Minus  1
#define Multi_State_Btn_Plus   2

/**
 *
 * Runnable RE_SeatManger_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_HeightState
 *
 */

void RE_SeatManger_SetHeight (void)
{
	Std_ReturnType status;
	Impl_HeightBnState DE_HeightState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_HeightState(&DE_HeightState);
	
	
	if(DE_HeightState == Multi_State_Btn_Minus)
	{
		Rte_Call_rpHeightMotor_Move(Motr_Step_Minus);
	}
	else if (DE_HeightState == Multi_State_Btn_Plus)
	{
		Rte_Call_rpHeightMotor_Move(Motr_Step_Plus);
		
	}
	else
	{
	/*Do nothing*/	
	}
	
}


/**
 *
 * Runnable RE_SeatManger_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_InclineState
 *
 */

void RE_SeatManger_SetIncline (void)
{
	Std_ReturnType status;
	Impl_InclineBnState DE_InclineState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_InclineState(&DE_InclineState);
	
	
		if(DE_InclineState == Multi_State_Btn_Minus)
	{
		Rte_Call_rpInclineMotor_Move(Motr_Step_Minus);
	}
	else if (DE_InclineState == Multi_State_Btn_Plus)
	{
		Rte_Call_rpInclineMotor_Move(Motr_Step_Plus);
		
	}
	else
	{
	/*Do nothing*/	
	}
}


/**
 *
 * Runnable RE_SeatManger_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_SlideState
 *
 */

void RE_SeatManger_SetSlide (void)
{
	Std_ReturnType status;
	Impl_SlidetBnState DE_SlideState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_SlideState(&DE_SlideState);
	
	
		if(DE_SlideState == Multi_State_Btn_Minus)
	{
		Rte_Call_rpSlideMotor_Move(Motr_Step_Minus);
	}
	else if (DE_SlideState == Multi_State_Btn_Plus)
	{
		Rte_Call_rpSlideMotor_Move(Motr_Step_Plus);
		
	}
	else
	{
	/*Do nothing*/	
	}
}

