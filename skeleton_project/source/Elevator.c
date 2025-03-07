#include "Elevator.h"
 
void pause_x_seconds(int x){
    
    clock_t start_time = clock();

    while ((clock() - start_time) < x * CLOCKS_PER_SEC);

    printf("4 seconds have passed '\n");
}   

void maintainPreviousFloor(Elevator* p_ElevatorInstance,int floor){
    
    if ((p_ElevatorInstance->outside_requests[floor] != 0) && p_ElevatorInstance->CAB_requests[floor] != 0){
        p_ElevatorInstance->nextFloor = floor;
    }
}



bool is_between_floors(Elevator* p_ElevatorInstance){
    if (p_ElevatorInstance->isMoving || p_ElevatorInstance->currentFloor == -1){
        return true;
    }
    else {
        return false;
    }
        
};


void initialize_elevator(Elevator* p_ElevatorInstance){
    


    elevio_doorOpenLamp(0); //Closing door if open at initialized state
    p_ElevatorInstance->doorsOpen = false;  //doors open set to closed(false) after setting lamp to 0

    
    elevio_motorDirection(DIRN_STOP);
    p_ElevatorInstance->isMoving = false;

    while(elevio_floorSensor() != 0){
        

        elevio_motorDirection(DIRN_DOWN);
        printf("Elevator going down \n");
        p_ElevatorInstance->isMoving = true;
    
        
    }
    p_ElevatorInstance->currentFloor = elevio_floorSensor(); //assigning currentFloor as floorSensor
    elevio_motorDirection(DIRN_STOP);
    p_ElevatorInstance->isMoving = false;
    printf("Elevator is currently at floor %i\n", p_ElevatorInstance->currentFloor);
}; 

void lamps(Elevator* p_ElevatorInstance, int floor, int button){
   //same floor call from outside 
    int btnPressed = elevio_callButton(floor,button);
        if (btnPressed && (p_ElevatorInstance->currentFloor == floor))
        {  //logic for opening door when button pressed and elevator idle at same floor
            printf("*Doors opening...*\n");
            pause_x_seconds(2); //door opening
            elevio_doorOpenLamp(1);
            p_ElevatorInstance->doorsOpen = true;
            printf("door lamp should be on\n");

            pause_x_seconds(4); // closing if no activity, interrupt may have to be here or interupt the lamp itself...
            elevio_doorOpenLamp(0);
            p_ElevatorInstance->doorsOpen = false;
            printf("door lamp should be off 4 sec after lamp on\n");
        }

    //floor light (outer)
    switch(p_ElevatorInstance->currentFloor){
        case (0):
            elevio_floorIndicator(0);
            break;
        case(1):
            elevio_floorIndicator(1);
            break;
        case(2):
            elevio_floorIndicator(2);
        case(3):
            elevio_floorIndicator(3);
        default:


    }
};


