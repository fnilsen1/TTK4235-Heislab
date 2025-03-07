#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Elevator.h"
#include <unistd.h>
#include <stdbool.h>
#include "utilities.h"

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

/* 

[0,1,0,0,0,1,0,0], 0 and 7 don't exist
0-opp 1-ned 2-cab

f:0 b:0
f:0 b:1

f:1 b:0  ->2
f:1 b:1  ->3

f:3 b:0
f:3 b:1 

0 1 2 3 4 5 6 7


*/

void button_manager(Elevator *e)
{
    printf("button %i floor %i\n", e->button_type_requested, e->button_floor);
    e->elevator_active = 1;
    if (e->button_type_requested<2)
    {
        printf("outside button pressed\n");
        e->outside_requests[e->button_floor*2-e->button_type_requested+1] = 1;
        /* print_arrays(e); */
        if(one_in_queue(e)){
            /* printf("Next floor %d \n", e->next_floor); */
            elevio_motorDirection(up_or_down(e));
        }
        //Sjekk her om det er first request
    }

    // inside button
    else
    {
        //se på det her
        e->inside_requests[e->button_floor] = 1;
    }

    /*                     printf("Button pressed: %d\n", btnPressed); */

    /*                     button_number = b;
        printf("current floor: %d button_number: %d\n", current_floor_request, button_number);
        printf("Sensor floor: %d\n", floor); */
}


/* 
outside: [0,1,0,0,0,1,0,0]
inside: [0,1,0,1]
*/

void set_direction(Elevator *e)
{


    if(e->current_floor == 0 && e->elevator_active){
        elevio_motorDirection(DIRN_UP);
        e->current_directon = 1;
    }

    else if(e->current_floor == 3 && e->elevator_active){
        elevio_motorDirection(DIRN_DOWN);
        e->current_directon = -1;

    }


    // Fortsett her
}



void stop_routine(Elevator *e){
    elevio_motorDirection(DIRN_STOP);
    e->elevator_active = 0;
}

void elevator_control(Elevator *e)
{
    if(should_stop(e)){
        stop_routine(e);
    }


}

bool should_stop(Elevator *e){
    //må adde inside også
    /* print_arrays(e); */
    printf("%d\n", one_in_queue(e) && e->current_floor==e->next_floor);
    printf("%d\n", (e->outside_requests[e->current_floor*2]*-1 || e->current_directon==e->outside_requests[e->current_floor*2+1]));
    
    if(((e->current_directon==e->outside_requests[e->current_floor*2]*-1 || e->current_directon==e->outside_requests[e->current_floor*2+1]) && e->current_floor!=-1)
        || (one_in_queue(e) && e->current_floor==e->next_floor)
){
        return true;
    }
    if((e->current_floor == 0 && e->elevator_active) || (e->current_floor == 3 && e->elevator_active)){
        return true;
    }

    return false;
    
}

void start_moving(Elevator *e){


}

bool one_in_queue(Elevator *e){
    int outside_request_count = 0;
    int request_index = 0;
    for (int i = 1; i < 7; i++)
    {
        if (e->outside_requests[i] != 0)
        {
            outside_request_count++;
            request_index = i;
        }
    }
    // Only 1 order in queue
    printf("Request index %d \n", request_index);
    if(outside_request_count == 1){
        e->next_floor = request_index/2;
        printf("Next floor %d \n", e->next_floor);
        return true;
    }
        return false;
        /* e->next_floor = request_index/2; */

        // printrequestxt floor %d", one_order_index);
    
}




MotorDirection up_or_down(Elevator *e){
    if (e->current_floor - e->next_floor < 0)
    {
        e->current_directon = 1;
        return DIRN_UP;
    }
    
    else if (e->current_floor - e->next_floor > 0)
    {
        e->current_directon = -1;
        return DIRN_DOWN;
      
    }

}

void print_arrays(Elevator *e){
    printf("Outside requests: \n");
    for(int i=0; i<8; i++){
        if(i==0 || i==7){
            printf("X ");
        }
        else{
            printf("%d ", e->outside_requests[i]);
        }
        
    }
    printf("\n");
    printf("Inside requests: \n");
    for(int i=0; i<4; i++){

            printf("%d ", e->inside_requests[i]);
    }
    printf("\n");
}

/* void set_next_floor(Elevator *e)
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
} */

/* void elevator_control(Elevator *e)
{
    set_next_floor(e);
    printf("Current direction %d, current floor direction: %d\n",e->current_directon, e->outside_requests[e->current_floor]);
    
    // printf("Current floor: %d, next floor: %d\n", e->current_floor, e->next_floor);


    if(e->current_floor == e->next_floor || e->current_directon == e->outside_requests[e->current_floor])
    {
        elevio_motorDirection(DIRN_STOP);
        // clear requests from this floor
        e->outside_requests[e->current_floor] = 0;
        e->inside_requests[e->current_floor] = 0;
        // set_next_floor(e);
        // printf("Waiting for 3 seconds...\n");
        // sleep(3);
    }
    
    else if ((e->current_floor - e->next_floor < 0) && (e->current_floor != -1) && (e->next_floor<4))
    {
        elevio_motorDirection(DIRN_UP);
        e->current_directon = 1;
    }
    
    else if (e->current_floor - e->next_floor > 0 && (e->current_floor != -1) && (e->next_floor<4))
    {
        elevio_motorDirection(DIRN_DOWN);
        e->current_directon = 2;
    }
    //



} */