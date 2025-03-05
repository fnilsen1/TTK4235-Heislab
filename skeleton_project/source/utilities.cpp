#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Elevator.h"





/* int button_pressed;
typedef struct Elevator{
int current_floor;
int current_directon;
int button_pressed;
int button_floor;
int button_type_requested;

//0: none, 1: up, 2: down
int outside_requests[4];

//0: not requested, 1: requested
int inside_requests[4];

}Elevator;


 */

void button_manager(Elevator* e){
    printf("button %i floor %i\n", e->button_type_requested, e->button_floor);


    if (e->button_type_requested == 0){
        e->outside_requests[e->button_floor]=1;
    }
    
    else if(e->button_type_requested == 1){
         e->outside_requests[e->button_floor]=-1;
    }
    //inside button
    else{
        e->inside_requests[e->button_floor]=1;
    }
    



    
/*                     printf("Button pressed: %d\n", btnPressed); */

/*                     button_number = b;
    printf("current floor: %d button_number: %d\n", current_floor_request, button_number);
    printf("Sensor floor: %d\n", floor); */




                }

void elevator_control(Elevator* e){





    if (e->current_floor - e->button_floor > 0)
    {
        elevio_motorDirection(DIRN_DOWN);
    }
    //

    else if ((e->current_floor - e->button_floor < 0) && (e->current_floor!=-1))
    {
        elevio_motorDirection(DIRN_UP);
    }
    //break stod her
}