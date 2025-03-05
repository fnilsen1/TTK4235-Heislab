#include "Elevator.h"

void initializeElevator()
{
    int floor = elevio_floorSensor();
    while (floor != 0)
    {
        floor = elevio_floorSensor();
        elevio_motorDirection(DIRN_DOWN);
    }
    elevio_motorDirection(DIRN_STOP);
}

