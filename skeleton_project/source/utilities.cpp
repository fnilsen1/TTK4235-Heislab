#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Elevator.h"

/* 
typedef struct e{
int current_floor;
int floor_requested;
int button_pressed;
int button_floor_requested;
int button_type_requested;
int outside_requests[4];
int inside_requests[4];

}e;
 */

void elevator_control(Elevator* e){
    printf("button %i floor %i\n", e->button_type_requested, e->floor_requested);
    
/*                     printf("Button pressed: %d\n", btnPressed); */

/*                     button_number = b;
    printf("current floor: %d button_number: %d\n", current_floor_request, button_number);
    printf("Sensor floor: %d\n", floor); */




    if (e->current_floor - e->floor_requested > 0)
    {
        elevio_motorDirection(DIRN_DOWN);
    }
    //

    else if ((floor - f < 0) && (current_floor!=-1))
    {
        elevio_motorDirection(DIRN_UP);
    }
    //break stod her
                }

