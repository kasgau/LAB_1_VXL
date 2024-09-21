/*
 * EX6.c
 *
 *  Created on: Sep 17, 2024
 *      Author: kanza
 */

#include "EX6.h"
int num =-1;
int num_clear = -1;

void clearAllClock()
{
	HAL_GPIO_WritePin(GPIOB,LED_RED_ABOVE_Pin|LED_RED_BELOW_Pin|LED_RED_LEFT_Pin|LED_RED_RIGHT_Pin|
						    LED_YELLOW_ABOVE_Pin|LED_YELLOW_BELOW_Pin|LED_YELLOW_LEFT_Pin|LED_YELLOW_RIGHT_Pin|
							LED_GREEN_ABOVE_Pin|LED_GREEN_BELOW_Pin|LED_GREEN_LEFT_Pin|LED_GREEN_RIGHT_Pin, SET);
}

void setAllClock()
{
	HAL_GPIO_WritePin(GPIOB,LED_RED_ABOVE_Pin|LED_RED_BELOW_Pin|LED_RED_LEFT_Pin|LED_RED_RIGHT_Pin|
						    LED_YELLOW_ABOVE_Pin|LED_YELLOW_BELOW_Pin|LED_YELLOW_LEFT_Pin|LED_YELLOW_RIGHT_Pin|
							LED_GREEN_ABOVE_Pin|LED_GREEN_BELOW_Pin|LED_GREEN_LEFT_Pin|LED_GREEN_RIGHT_Pin, RESET);
}

void setNumberOnClock(int num)
{
	switch(num)
	{
	case 0:
			HAL_GPIO_WritePin(GPIOB,LED_YELLOW_ABOVE_Pin,RESET);
			break;
	case 1:
			HAL_GPIO_WritePin(GPIOB,LED_GREEN_ABOVE_Pin,RESET);
		    break;
	case 2:
			HAL_GPIO_WritePin(GPIOB,LED_RED_RIGHT_Pin,RESET);
			break;
	case 3:
	     	HAL_GPIO_WritePin(GPIOB,LED_YELLOW_RIGHT_Pin,RESET);
			break;
	case 4:
			HAL_GPIO_WritePin(GPIOB,LED_GREEN_RIGHT_Pin,RESET);
			break;
	case 5:
			HAL_GPIO_WritePin(GPIOB,LED_GREEN_BELOW_Pin,RESET);
			break;
	case 6:
			HAL_GPIO_WritePin(GPIOB,LED_YELLOW_BELOW_Pin,RESET);
			break;
	case 7:
			HAL_GPIO_WritePin(GPIOB,LED_RED_BELOW_Pin,RESET);
			break;
	case 8:
			HAL_GPIO_WritePin(GPIOB,LED_GREEN_LEFT_Pin,RESET);
			break;
	case 9:
			HAL_GPIO_WritePin(GPIOB,LED_YELLOW_LEFT_Pin,RESET);
			break;
	case 10:
			HAL_GPIO_WritePin(GPIOB,LED_RED_LEFT_Pin,RESET);
			break;
	case 11:
			HAL_GPIO_WritePin(GPIOB,LED_RED_ABOVE_Pin,RESET);
			break;
	default:
		num = 0;
		break;
	}
}

void EX6_run()
{

	if (num >=12)
		   num = -1;
		  setNumberOnClock( num++);
		  HAL_Delay(1000);
}

void clearNumberOnClock(int num_clear)
{

	switch(num_clear)
	{
	case 0:
			HAL_GPIO_WritePin(GPIOB,LED_YELLOW_ABOVE_Pin,SET);
			break;
	case 1:
			HAL_GPIO_WritePin(GPIOB,LED_GREEN_ABOVE_Pin,SET);
		    break;
	case 2:
			HAL_GPIO_WritePin(GPIOB,LED_RED_RIGHT_Pin,SET);
			break;
	case 3:
	     	HAL_GPIO_WritePin(GPIOB,LED_YELLOW_RIGHT_Pin,SET);
			break;
	case 4:
			HAL_GPIO_WritePin(GPIOB,LED_GREEN_RIGHT_Pin,SET);
			break;
	case 5:
			HAL_GPIO_WritePin(GPIOB,LED_GREEN_BELOW_Pin,SET);
			break;
	case 6:
			HAL_GPIO_WritePin(GPIOB,LED_YELLOW_BELOW_Pin,SET);
			break;
	case 7:
			HAL_GPIO_WritePin(GPIOB,LED_RED_BELOW_Pin,SET);
			break;
	case 8:
			HAL_GPIO_WritePin(GPIOB,LED_GREEN_LEFT_Pin,SET);
			break;
	case 9:
			HAL_GPIO_WritePin(GPIOB,LED_YELLOW_LEFT_Pin,SET);
			break;
	case 10:
			HAL_GPIO_WritePin(GPIOB,LED_RED_LEFT_Pin,SET);
			break;
	case 11:
			HAL_GPIO_WritePin(GPIOB,LED_RED_ABOVE_Pin,SET);
			break;
	default:
		num_clear =0;
		break;
	}
}

void EX9_run()
{

	if (num_clear >=12)
		   num_clear = -1;
	clearNumberOnClock( num_clear++);
		  HAL_Delay(1000);
}


int hour = 0;
int minute = 0;
int second = 0;

int sec_count = 0;

int sec_location =0;
int min_location = 0;
int hour_location = 0;

void EX10_run()
{
	sec_count += 1000000;

	   if(sec_count >= 5000000) // 5S
	   {
		   second++;
		   sec_count = 0;
		   if(second >= 60)
		   {
			   minute++;
			   second = 0;
			   if(minute >= 60)
			   {
				   minute = 0;
	               clearNumberOnClock(hour);
	               hour++;
	               if(hour >= 12)
	               {
	            	   hour = 0;
	               }
			   }
		   }
	   }

	   setNumberOnClock(hour);
	   hour_location = hour;


	   if(second % 5 == 0)
	   	   {
	   		   if( second / 5 ==0 && min_location != 11 && hour_location != 11)
	   			   clearNumberOnClock(11);

	   		   if(second / 5 != 0 && second /5 != (min_location+1) && second /5 != (hour_location+1))
	   			   clearNumberOnClock(second / 5 - 1);
	   		   setNumberOnClock(second / 5);
	   		   sec_location = (second /5);
	   	   }



	   	if(minute % 5 == 0)
	   		   {
	   			   if(minute / 5 == 0 && hour_location != 11 )
	   				   {
	   				   clearNumberOnClock(11);

	   				   }
	   			   if(minute /5 != 0 && min_location != (hour_location+1))
	   			   {
	   				   clearNumberOnClock(minute / 5 - 1);

	   			   }
	   			   setNumberOnClock(minute / 5);
	   			   min_location = minute / 5;

	   		   }




}
