#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Elevator.h"
#include "Queue.h"



void take_orders(bool floorButtonArray[N_FLOORS][N_BUTTONS],int f,int b);

void activate_elevator(Elevator* p_ElevatorInstance, bool floorButtonArray[N_FLOORS][N_BUTTONS]);
