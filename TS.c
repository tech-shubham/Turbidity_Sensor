/***************************************************************************
*
*
* TS.c
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#include "TS.h"


/////////////////////////////////// Turbitity ///////////////////////
void AB_STEM_init_TS()
{
		enableADC();
}
int AB_STEM_Read_TS(unsigned int ADC_PIN)// ADC pin
{	
	unsigned int v_value=0;
	float v_voltage = 0.00;
	int v_turbidity = 0.00;
	float Vclear = 5.0; // Output voltage to calibrate (with clear water).
	
	v_value= readAnalogValue(ADC_PIN, AB_INTERNAL);
	v_voltage = v_value * (5.000 / 1023.000);
	v_turbidity = (int)(100.00 - (v_voltage / Vclear) * 100.00);
	return v_turbidity;
	
}


int main()
{
	int turbvalue=0;
	AB_STEM_init_TS();
	
	while(1)
	{
		turbvalue=AB_STEM_Read_TS(AB_CHANNEL_2)	;	///// Gives the turbidity Value in NTS
	}

		return 0;
}

