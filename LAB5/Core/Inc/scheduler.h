/*
 * scheduler.h
 *
 *  Created on: Dec 3, 2023
 *      Author: TVB09
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"

void SCH_Init();
void SCH_Update();
void SCH_Add_Task(void (*PFunction)(), uint32_t DELAY, uint32_t PERIOD, uint8_t taskID);
void SCH_Delete_Task();
void SCH_Dispatch_Task();

void task1();
void task2();
void task3();
void task4();
void task5();

#endif /* INC_SCHEDULER_H_ */
