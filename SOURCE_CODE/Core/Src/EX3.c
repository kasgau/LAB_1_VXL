/*
 * EX3.c
 *
 *  Created on: Sep 17, 2024
 *      Author: kanza
 */

#include "EX3.h"

int led_status = 0;
int count_r =5000000;

void EX3_Run()
{
	switch(led_status)
	{
	     case 0: // xanh dọc + đỏ ngang
	         HAL_GPIO_WritePin(GPIOB, LED_RED_ABOVE_Pin|LED_RED_BELOW_Pin| LED_YELLOW_ABOVE_Pin| LED_YELLOW_BELOW_Pin, SET);
	         HAL_GPIO_WritePin(GPIOB, LED_YELLOW_LEFT_Pin| LED_YELLOW_RIGHT_Pin|LED_GREEN_LEFT_Pin|LED_GREEN_RIGHT_Pin, SET);
	         count_r -= 10000;
	         if(count_r <=2000000)
	         {
		         HAL_GPIO_WritePin(GPIOB, LED_YELLOW_ABOVE_Pin| LED_YELLOW_BELOW_Pin| LED_RED_LEFT_Pin|LED_RED_RIGHT_Pin , RESET);
		         HAL_GPIO_WritePin(GPIOB, LED_GREEN_ABOVE_Pin| LED_GREEN_BELOW_Pin, SET);
	        	 led_status = 1;
	         }

	       break;

	     case 1: // vàng dọc + đỏ ngang
	    	 count_r -= 10000;
	         if(count_r <= 0)
	         {
		         HAL_GPIO_WritePin(GPIOB, LED_RED_ABOVE_Pin| LED_RED_BELOW_Pin| LED_GREEN_LEFT_Pin|LED_GREEN_RIGHT_Pin , RESET);
		         HAL_GPIO_WritePin(GPIOB, LED_YELLOW_ABOVE_Pin| LED_YELLOW_BELOW_Pin |LED_RED_LEFT_Pin| LED_RED_RIGHT_Pin, SET);
	        	 led_status = 2;
	        	 count_r = 5000000;
	         }
	       break;

	     case 2: // đỏ dọc + xanh ngang
	    	 count_r -= 10000;
	         if(count_r <= 2000000)
	         {
		         HAL_GPIO_WritePin(GPIOB, LED_YELLOW_LEFT_Pin|LED_YELLOW_RIGHT_Pin , RESET);
		         HAL_GPIO_WritePin(GPIOB, LED_GREEN_LEFT_Pin| LED_GREEN_RIGHT_Pin, SET);
	        	 led_status = 3;
	          }

	    	 break;

	     case 3: // đỏ dọc + vàng ngang
	    	 count_r -= 10000;
	         if(count_r <= 0)
	         {
		         HAL_GPIO_WritePin(GPIOB, LED_GREEN_ABOVE_Pin|LED_GREEN_BELOW_Pin|LED_RED_LEFT_Pin| LED_RED_RIGHT_Pin, RESET);
		         HAL_GPIO_WritePin(GPIOB, LED_RED_ABOVE_Pin| LED_RED_BELOW_Pin|LED_YELLOW_LEFT_Pin|LED_YELLOW_RIGHT_Pin, SET);
		         count_r = 5000000;
	        	 led_status =0;
	         }
	    	 break;

	     default:
	    	 led_status = 0;
	    	 break;

	}
}
