///*
// * scheduler.c
// *
// *  Created on: Dec 3, 2023
// *      Author: TVB09
// */
//
//#include "scheduler.h"
//#include "main.h"
//
//#define SCH_MAX_TASKS 40
//
//typedef struct
//{
//	void (*pTask)(void);
//	uint32_t Delay;
//	uint32_t Period;
//	uint8_t RunMe;
//	uint32_t TaskID;
//} sTask;
//
//static sTask SCH_Task_G[SCH_MAX_TASKS];
//
//void SCH_Init()
//{
//	for (int i= 0; i < SCH_MAX_TASKS; i++)
//	{
//		SCH_Task_G[i].pTask= 0x0000;
//		SCH_Task_G[i].Delay= 0;
//		SCH_Task_G[i].Period= 0;
//		SCH_Task_G[i].RunMe= 0;
//		SCH_Task_G[i].TaskID= 0;
//	}
//}
//
//void SCH_Update()
//{
//	if (SCH_Task_G[0].pTask != 0x0000)
//	{
//		if (SCH_Task_G[0].Delay)
//		{
//			SCH_Task_G[0].Delay-= 1;
//			if (SCH_Task_G[0].Delay== 0)
//				SCH_Task_G[0].RunMe+= 1;
//		}
//	}
//}
//
//void SCH_Delete_Task()
//{
//	for (int i= 0; i < SCH_MAX_TASKS; i++)
//	{
//		if (SCH_Task_G[i].pTask== 0x0000)
//		{
//			break;
//		}
//		else
//		{
//			SCH_Task_G[i].pTask= SCH_Task_G[i+ 1].pTask;
//			SCH_Task_G[i].Delay= SCH_Task_G[i+ 1].Delay;
//			SCH_Task_G[i].Period= SCH_Task_G[i+ 1].Period;
//			SCH_Task_G[i].RunMe= SCH_Task_G[i+ 1].RunMe;
//			SCH_Task_G[i].TaskID= SCH_Task_G[i+ 1].TaskID;
//		}
//	}
//}
//
//void SCH_Add_Task(void (*PFunction)(), uint32_t DELAY, uint32_t PERIOD, uint8_t taskID)
//{
//	uint32_t delayAddTask= DELAY;
//	int tempIndex= 0;
//	for (int i= 0; i < SCH_MAX_TASKS; i++)
//	{
//		if (SCH_Task_G[i].pTask)
//		{
//			if (SCH_Task_G[i].Delay <= delayAddTask)
//			{
//				delayAddTask-= SCH_Task_G[i].Delay;
//			}
//			else
//			{
//				tempIndex= i;
//				break;
//			}
//		}
//		else
//		{
//			tempIndex= i;
//			break;
//		}
//	}
//	for (int i= SCH_MAX_TASKS-1 ; i > tempIndex; i--)
//	{
//		SCH_Task_G[i].pTask = SCH_Task_G[i-1].pTask;
//		SCH_Task_G[i].Delay= SCH_Task_G[i-1].Delay;
//		SCH_Task_G[i].Period= SCH_Task_G[i-1].Period;
//		SCH_Task_G[i].RunMe= SCH_Task_G[i-1].RunMe;
//		SCH_Task_G[i].TaskID= SCH_Task_G[i-1].TaskID;
//	}
//	SCH_Task_G[tempIndex].pTask= PFunction;
//	SCH_Task_G[tempIndex].Delay= delayAddTask;
//	SCH_Task_G[tempIndex].Period= PERIOD;
//	SCH_Task_G[tempIndex].RunMe= 0;
//	SCH_Task_G[tempIndex].TaskID= taskID;
//	if (SCH_Task_G[tempIndex+ 1].pTask)
//	{
//		SCH_Task_G[tempIndex+ 1].Delay-= delayAddTask;
//	}
//}
//
//void SCH_Dispatch_Task()
//{
//	if (SCH_Task_G[0].pTask)
//	{
//		if (SCH_Task_G[0].RunMe)
//		{
//			(*SCH_Task_G[0].pTask)();
//			SCH_Task_G[0].RunMe-= 1;
//			sTask tempTask= SCH_Task_G[0];
//			SCH_Delete_Task();
//			if (tempTask.Period)
//			{
//				SCH_Add_Task(tempTask.pTask, tempTask.Period, tempTask.Period, tempTask.TaskID);
//			}
//		}
//
//
//	}
//}
//
//void task1()
//{
//	HAL_GPIO_TogglePin(task1_GPIO_Port, task1_Pin);
//}
//
//void task2()
//{
//	HAL_GPIO_TogglePin(task2_GPIO_Port, task2_Pin);
//}
//
//void task3()
//{
//	HAL_GPIO_TogglePin(task3_GPIO_Port, task3_Pin);
//}
//
//void task4()
//{
//	HAL_GPIO_TogglePin(task4_GPIO_Port, task4_Pin);
//}
//
//void task5()
//{
//	HAL_GPIO_TogglePin(task5_GPIO_Port, task5_Pin);
//}
