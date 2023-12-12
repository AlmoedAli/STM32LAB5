/*
 * softwareTimer.c
 *
 *  Created on: Nov 21, 2023
 *      Author: TVB09
 */


#include "softwareTimer.h"

int counter1;
int flag1= 0;

void setTimer(int duration)
{
	counter1= duration;
	flag1= 0;
}

void runTimer()
{
	if (counter1 > 0)
	{
		counter1--;
		if (counter1 <= 0)
		{
			flag1= 1;
		}
	}
}
