#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include <stdbool.h>

typedef struct Elevator{
    int  currentFloor;
    int  previousFLoor;
    int  nextFloor;
    MotorDirection elevatorDirection;
    bool isMoving;

    bool doorsOpen;
    int  buttonPressed;
    int  buttonFloor;
    ButtonType buttonTypeRequested;
    bool stopButtonIsPressed;
    
    int outside_requests[4]; //0=> no request, 1 => UP at [floor], 2=> DOWN at [floor]
    int CAB_requests[4]; // 0 => no request, 1 => request TO [floor]


}Elevator;

bool is_between_floors(Elevator* p_ElevatorInstance);

void initialize_elevator(Elevator* p_ElevatorInstance);

void pause_x_seconds(int x);

void lamps(Elevator* p_ElevatorInstance, int floor, int button);







