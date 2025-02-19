#include "Elevator.h"

static int previousFloorSensorSignal = 0;



int get_previous_floor(Elevator *elevator){
    
    int temp = elevio_floorSensor();
    if (temp != -1){
        previousFloorSensorSignal = temp;
    }
}

int get_current_direction(Elevator *elevator){

}; //-1 for down, 0 for stopped, 1 for up

void get_


