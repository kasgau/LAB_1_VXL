/*
 * EX6.h
 *
 *  Created on: Sep 17, 2024
 *      Author: kanza
 */

#ifndef INC_EX6_H_
#define INC_EX6_H_

#include "main.h"

void clearAllClock();
void setAllClock();
void setNumberOnClock(int num);
void clearNumberOnClock(int num_clear);
void EX6_run();
void EX9_run();
void EX10_run();

extern int num;
extern int num_clear;
extern int hour ;
extern int minute;
extern int second;
extern int sec_count;
extern int min_location;
extern int sec_location;

#endif /* INC_EX6_H_ */
