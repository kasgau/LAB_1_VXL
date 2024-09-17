/*
 * EX1.c
 *
 *  Created on: Sep 15, 2024
 *      Author: kanza
 */


#include "EX1.h"


int led_status = 0;
int counter = 2;
void EX1_Run()
{
    switch(led_status)
    {
    case 0:
    	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin,GPIO_PIN_SET);
    	led_status = 1;
    	break;
    case 1:
    	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin,GPIO_PIN_SET);
    	led_status = 0;
    	break;
    default:
    	led_status = 0;
    	break;


    }


}
