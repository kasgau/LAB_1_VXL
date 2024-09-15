/*
 * EX1.c
 *
 *  Created on: Sep 15, 2024
 *      Author: kanza
 */


#include "EX1.h"


int led_status = 0;
void EX1_Run()
{
    if(led_status == 0)
    {

    	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin,GPIO_PIN_SET);
    	HAL_Delay(2000);
    	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin,GPIO_PIN_SET);
    	HAL_Delay(2000);


    }


}
