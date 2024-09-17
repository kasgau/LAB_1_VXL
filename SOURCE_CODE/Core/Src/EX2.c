/*
 * EX2.c
 *
 *  Created on: Sep 17, 2024
 *      Author: kanza
 */


#include "EX2.h"
int led_status = 0;
int count = 5;
void EX2_Run()
{
	switch(led_status)
	{
	     case 0:
	         HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	         HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	         HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	         count--;
	    	 if(count <= 0)
	    	 {
	    		 HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	    		 HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	    		 HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
	    		 count = 3;
	    		 led_status = 2;
	    	 }
	       break;
	     case 1:
	    	 HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	    	 HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	    	 HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	    	 count--;
	    	 if(count <= 0)
	    	 {
	    		 HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	    		 HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	    		 HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	    		 count = 5;
	    		 led_status = 0;
	    	 }
	       break;
	     case 2:
	    	 HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	    	 HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	    	 HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
	    	 count--;
	    	 if(count <= 0)
	    	 {
	    		 HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	    		 HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	    	     HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	    		 count = 2;
	    		 led_status = 1;
	    	 }
	    	 break;
	     default:
	    	 led_status = 0;
	    	 break;

	}



}
