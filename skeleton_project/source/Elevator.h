#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include <stdbool.h>

typedef struct Elevator{
    int  currentFloor;
    bool isMoving;
    bool isBetweenFloors;
    bool doorsOpen;
    bool stopButtonIsPressed;

}Elevator;

void initialize_elevator(Elevator* p_ElevatorInstance);