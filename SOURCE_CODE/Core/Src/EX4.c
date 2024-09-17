/*
 * EX4.c
 *
 *  Created on: Sep 17, 2024
 *      Author: kanza
 */

#include "EX4.h"

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
