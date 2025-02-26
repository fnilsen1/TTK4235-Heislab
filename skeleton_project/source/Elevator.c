#include "Elevator.h"

static int previousFloorSensorSignal = 0;


void initializeElevator(){
    int floor = elevio_floorSensor();
    if (floor != 0){
        elevio_motorDirection(DIRN_DOWN);
    }

}
