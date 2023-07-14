/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/10/2023 07:04 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HMI.h"

#define Timout        1000
#define Not_updated   2


/*The defintions below will be used to differinate between the button states*/

#define Multi_State_Btn_Int    0
#define Multi_State_Btn_Minus  1
#define Multi_State_Btn_Plus   2

/**
 *
 * Runnable RE_HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_HMI_MainFunction_100ms
 *
 */

void RE_HMI_MainFunction (void)
{
	Std_ReturnType status;
	Impl_HeightBnState DE_HeightState;
	Impl_InclineBnState DE_InclineState;
	Impl_SlidetBnState DE_SlideState;
	Impl_Height DE_Height;
	Impl_Incline DE_Incline;
	Impl_Slide DE_Slide;


	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlData_DE_Height(&DE_Height);
	status = Rte_Read_rpSeatCtrlData_DE_Incline(&DE_Incline);
	status = Rte_Read_rpSeatCtrlData_DE_Slide(&DE_Slide);
	
	
	/* Asuming that the std_returnTpe could tell us if there was a time out or no update in the value*/

    if ((status == Timout )||(status == Not_updated)||(DE_Height== 0))
	{
		DE_HeightState=Multi_State_Btn_Int;
	}
	else if (DE_Height==1)
	{
		DE_HeightState=Multi_State_Btn_Minus;	
	}
    else if (DE_Height==2)
	{
		DE_HeightState=Multi_State_Btn_Plus;	
	}
	else
	{
		/*Reprot data out of range*/
	}
	
	
	    if ((status == Timout )||(status == Not_updated)||(DE_Incline== 0))
	{
		DE_InclineState=Multi_State_Btn_Int;
	}
	else if (DE_Incline==1)
	{
		DE_InclineState=Multi_State_Btn_Minus;	
	}
    else if (DE_Incline==2)
	{
		DE_InclineState=Multi_State_Btn_Plus;	
	}
	else
	{
		/*Reprot data out of range*/
	}
	
	
	    if ((status == Timout )||(status == Not_updated)||(DE_Slide== 0))
	{
		DE_SlideState=Multi_State_Btn_Int;
	}
	else if (DE_Slide==1)
	{
		DE_SlideState=Multi_State_Btn_Minus;	
	}
    else if (DE_Slide==2)
	{
		DE_SlideState=Multi_State_Btn_Plus;	
	}
	else
	{
		/*Reprot data out of range*/
	}
	
	
	
	/* Data Send Points */
	status = Rte_Write_ppSeatCtrlBtns_DE_HeightState(DE_HeightState);
	status = Rte_Write_ppSeatCtrlBtns_DE_InclineState(DE_InclineState);
	status = Rte_Write_ppSeatCtrlBtns_DE_SlideState(DE_SlideState);
	

	
}

