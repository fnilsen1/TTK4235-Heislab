#include "Order.h"


void check_to_add_order(Elevator* p_ElevatorInstance,int f,int b){
    int btnPressed = elevio_callButton(f, b);
    if (btnPressed){
        printf("Floor: %d, Button number: %d\n", 
            f, b);
        switch (b) {
            case 0: //ButtonType is BUTTON_HALL_UP
                p_ElevatorInstance->outside_requests[f] = 1; //1 in outside_request array means UP
                
                printf("request made outside from floor: [ %i ] to go [ UP ]\n",f);

                break;
            case 1: //ButtonType is BUTTON_HALL_DOWN
                p_ElevatorInstance->outside_requests[f] = 2; //2  in -||- array means DOWN
                
                printf("request made outside from floor: [ %i ] to go [ DOWN ]\n",f);
                break;
            case 2: //ButtonType is BUTTON_CAB
                p_ElevatorInstance->CAB_requests[f] = 1;
                printf("request made INSIDE CAB to go to FLOOR [ %i ] \n",f);     
            }
            

    }
}



