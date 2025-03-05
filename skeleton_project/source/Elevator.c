#include "Elevator.h"

static int previousFloorSensorSignal = 0;

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

