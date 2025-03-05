    #include "Elevator.h"
 


    void initialize_elevator(Elevator* p_ElevatorInstance){
        


        elevio_doorOpenLamp(0); //Closing door if open at initialized state
        p_ElevatorInstance->doorsOpen = false;  //doors open set to closed(false) after setting lamp to 0

        p_ElevatorInstance->currentFloor = elevio_floorSensor(); //assigning currentFloor as floorSensor

        elevio_motorDirection(DIRN_STOP);
        p_ElevatorInstance->isMoving = false;

        while(elevio_floorSensor() != 0){
            elevio_motorDirection(DIRN_DOWN);
            printf("Elevator going down \n");
            p_ElevatorInstance->isMoving = true;
     
            
        }
        elevio_motorDirection(DIRN_STOP);
        p_ElevatorInstance->isMoving = false;
        p_ElevatorInstance->isBetweenFloors = false;
        printf("Elevator is currently at floor %i\n", p_ElevatorInstance->currentFloor);
    }; 
    
