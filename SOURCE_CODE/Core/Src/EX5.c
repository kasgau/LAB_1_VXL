/*
 * EX5.c
 *
 *  Created on: Sep 17, 2024
 *      Author: kanza
 */


#include "EX5.h"

int led_status = 0;
int count_r =4;

void EX3_Run()
{
	switch(led_status)
	{
	     case 0: // xanh dọc + đỏ ngang
	         HAL_GPIO_WritePin(GPIOB, LED_RED_ABOVE_Pin|LED_RED_BELOW_Pin| LED_YELLOW_ABOVE_Pin| LED_YELLOW_BELOW_Pin, SET);
	         HAL_GPIO_WritePin(GPIOB, LED_YELLOW_LEFT_Pin| LED_YELLOW_RIGHT_Pin|LED_GREEN_LEFT_Pin|LED_GREEN_RIGHT_Pin, SET);
	         count_r--;
	         if(count_r <=1)
	         {
		         HAL_GPIO_WritePin(GPIOB, LED_YELLOW_ABOVE_Pin| LED_YELLOW_BELOW_Pin| LED_RED_LEFT_Pin|LED_RED_RIGHT_Pin , RESET);
		         HAL_GPIO_WritePin(GPIOB, LED_GREEN_ABOVE_Pin| LED_GREEN_BELOW_Pin, SET);
	        	 led_status = 1;
	         }

	       break;

	     case 1: // vàng dọc + đỏ ngang
	         count_r--;
	         if(count_r <= 0)
	         {
		         HAL_GPIO_WritePin(GPIOB, LED_RED_ABOVE_Pin| LED_RED_BELOW_Pin| LED_GREEN_LEFT_Pin|LED_GREEN_RIGHT_Pin , RESET);
		         HAL_GPIO_WritePin(GPIOB, LED_YELLOW_ABOVE_Pin| LED_YELLOW_BELOW_Pin |LED_RED_LEFT_Pin| LED_RED_RIGHT_Pin, SET);
	        	 led_status = 2;
	        	 count_r = 4;
	         }
	       break;

	     case 2: // đỏ dọc + xanh ngang
	         count_r--;
	         if(count_r <= 1)
	         {
		         HAL_GPIO_WritePin(GPIOB, LED_YELLOW_LEFT_Pin|LED_YELLOW_RIGHT_Pin , RESET);
		         HAL_GPIO_WritePin(GPIOB, LED_GREEN_LEFT_Pin| LED_GREEN_RIGHT_Pin, SET);
	        	 led_status = 2;
	          }

	    	 break;

	     case 3: // đỏ dọc + vàng ngang
	         count_r--;
	         if(count_r <= 0)
	         {
		         HAL_GPIO_WritePin(GPIOB, LED_GREEN_ABOVE_Pin|LED_GREEN_BELOW_Pin|LED_RED_LEFT_Pin| LED_RED_RIGHT_Pin, RESET);
		         HAL_GPIO_WritePin(GPIOB, LED_RED_ABOVE_Pin| LED_RED_BELOW_Pin|LED_YELLOW_LEFT_Pin|LED_YELLOW_RIGHT_Pin, SET);
		         count_r = 4;
	        	 led_status =0;
	         }
	    	 break;

	     default:
	    	 break;

	}
}


void display7SEG(int num)
{
	switch(num)
		{
		    case 0:
		    	HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, SET);
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin , RESET);
		    	break;
		    case 1:
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
		    	HAL_GPIO_WritePin(GPIOA, SEG_1_Pin | SEG_2_Pin, RESET);
		    	break;
		    case 2:
		    	HAL_GPIO_WritePin(GPIOA, SEG_2_Pin | SEG_5_Pin , SET);
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin | SEG_1_Pin |SEG_3_Pin | SEG_4_Pin | SEG_6_Pin, RESET);
		    	break;
		    case 3:
		    	HAL_GPIO_WritePin(GPIOA, SEG_4_Pin | SEG_5_Pin , SET);
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin | SEG_1_Pin |SEG_2_Pin | SEG_3_Pin | SEG_6_Pin, RESET);
		    	break;
		    case 4:
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin , SET);
		    	HAL_GPIO_WritePin(GPIOA, SEG_1_Pin |SEG_2_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    	break;
		    case 5:
		    	HAL_GPIO_WritePin(GPIOA, SEG_1_Pin | SEG_4_Pin , SET);
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    	break;
		    case 6:
		    	HAL_GPIO_WritePin(GPIOA, SEG_1_Pin , SET);
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    	break;
		    case 7:
		    	HAL_GPIO_WritePin(GPIOA, SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin, RESET);
		    	break;
		    case 8:
		    	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
		    	break;
		    case 9:
		    	HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
		        HAL_GPIO_WritePin(GPIOA, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
		    	break;
		    default:
		    	num = 0;
		    	break;
	    }
}
