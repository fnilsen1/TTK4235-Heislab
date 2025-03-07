#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include <stdbool.h>
/* 
member variables:
current floor
latest floor requested
button pressed
floor of button pressed
type of button pressed

//0: not requested, 1: requested
outside_requests[]
inside_requests[]

 */

typedef struct Elevator{
int current_floor;
int current_directon;
int button_pressed;
int button_floor;
int button_type_requested;
int next_floor;
int elevator_active;
//index 0 and 7 don't exist
int outside_requests[8];
int inside_requests[4];

}Elevator;

void initializeElevator();
