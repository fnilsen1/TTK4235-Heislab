#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"

/* 
member variables:
current floor
latest floor requested
button pressed
floor of button pressed
type of button pressed
//0: none, 1: up, 2: down
outside_requests[]
//0: not requested, 1: requested
inside_requests[]

 */

typedef struct Elevator{
int current_floor;
int current_directon;
int button_pressed;
int button_floor;
int button_type_requested;
int next_floor;
int outside_requests[4];
int inside_requests[4];

}Elevator;

void initializeElevator();
