#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Elevator.h"
#include <unistd.h>

/* int button_pressed;
typedef struct Elevator{
int current_floor;
int current_directon;
int button_pressed;
int button_floor;
int button_type_requested;
int next_floor;

//0: none, 1: up, 2: down
int outside_requests[4];

//0: not requested, 1: requested
int inside_requests[4];

}Elevator;


 */

void button_manager(Elevator *e)
{
    printf("button %i floor %i\n", e->button_type_requested, e->button_floor);

    if (e->button_type_requested == 0)
    {
        printf("outside button pressed\n");
        e->outside_requests[e->button_floor] = 1;
    }

    else if (e->button_type_requested == 1)
    {
        e->outside_requests[e->button_floor] = -1;
    }
    // inside button
    else
    {
        e->inside_requests[e->button_floor] = 1;
    }

    /*                     printf("Button pressed: %d\n", btnPressed); */

    /*                     button_number = b;
        printf("current floor: %d button_number: %d\n", current_floor_request, button_number);
        printf("Sensor floor: %d\n", floor); */
}

void set_next_floor(Elevator *e)
{
   
    int outside_order_count = 0;
    int one_order_index = 0;
    for (int i = 0; i < 4; i++)
    {
        if (e->outside_requests[i] != 0)
        {
            outside_order_count++;
            one_order_index = i;
        }
    }
    // Only 1 order in queue
    if (outside_order_count == 1)
    {
        e->next_floor = one_order_index;
        // printf("Next floor %d", one_order_index);
    }

    else{
        
    }

    // Fortsett her
}

void elevator_control(Elevator *e)
{
    set_next_floor(e);
    // printf("Current floor: %d, next floor: %d\n", e->current_floor, e->next_floor);
    
    if (e->current_floor - e->next_floor > 0 && (e->current_floor != -1) && (e->next_floor<4))
    {
        elevio_motorDirection(DIRN_DOWN);
    }
    //

    else if ((e->current_floor - e->next_floor < 0) && (e->current_floor != -1) && (e->next_floor<4))
    {
        elevio_motorDirection(DIRN_UP);
    }

    else if(e->current_floor == e->next_floor)
    {
        elevio_motorDirection(DIRN_STOP);
        // clear requests from this floor
        e->outside_requests[e->current_floor] = 0;
        e->inside_requests[e->current_floor] = 0;
        set_next_floor(e);
        // printf("Waiting for 3 seconds...\n");
        // sleep(3);
    }
}