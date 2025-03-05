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
    MotorDirection elevatorMotorDirection;
    int outside_requests[4]; //0=> no request, 1 => UP at [floor], 2=> DOWN at [floor]
    int CAB_requests[4]; // 0 => no request, 1 => request TO [floor]


}Elevator;

void initialize_elevator(Elevator* p_ElevatorInstance);



