#include "Control.h"


void take_orders(bool floorButtonArray[N_FLOORS][N_BUTTONS],int f,int b){
    int btnPressed = elevio_callButton(f, b);
    if (btnPressed){
        floorButtonArray[f][b] = true;
    }
}

void should_elevator_stop(Elevator* p_ElevatorInstance, bool floorButtonArray[N_FLOORS][N_BUTTONS]){
    int currentFloorLocal
    
    if (elevio_stopButton() == 1){
        elevio_motorDirection(DIRN_STOP);
        printf("Stop button was pressed, elevator stopped\n");
    }
    if(p_ElevatorInstance->currentFloor == -1){
        currentFloorLocal = 10; //
        if(){

        }
        else if((elevio_motorDirection(DIRN_DOWN)) &&){

        }
    }
    
}


void activate_elevator(Elevator* p_ElevatorInstance, bool floorButtonArray[N_FLOORS][N_BUTTONS]){

};

