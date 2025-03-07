#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Elevator.h"
#include "Control.h"




int main()
{

    elevio_init(); //IKKE RØR


    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    // elevio_motorDirection(DIRN_UP);

    Elevator ElevatorInstance = {0, false, false, false,false};
    Elevator* p_ElevatorInstance = &ElevatorInstance;
    initialize_elevator(p_ElevatorInstance);

    
    while (1)
    {
        for (int f = 0; f < N_FLOORS; f++)
        {
            for (int b = 0; b < N_BUTTONS; b++)
            {
                printf("ELevatorInstanceCurrent Floor: %i\n", p_ElevatorInstance->currentFloor);
                check_to_add_order(p_ElevatorInstance,f,b);
                lamps(p_ElevatorInstance,f,b);
                elevator_control(p_ElevatorInstance);



            }
            
        }

        

        // printf("%d\n",floor);

        // int callButton = elevio_callButton(0, BUTTON_CAB);
        // printf("callbutton: %d\r\n", callButton);

        // printf("%d\n",floor);

        /*for (int f = 0; f < N_FLOORS; f++)
        {
            for (int b = 0; b < N_BUTTONS; b++)
            {
                // printf("button %i floor %i\n", b, f);
                btnPressed = elevio_callButton(f, b);
                // //printf(".\r\n");
                // elevio_buttonLamp(f, b, btnPressed);
                // if (btnPressed == 1) {
                //     //printf("hei\r\n");
                //     printf("button %i floor %i\n", b, f);
                // }
                if (btnPressed)
                {
                    printf("Button pressed: %d\n", btnPressed);
                    current_floor_request = f;
                    button_number = b;
                    printf("current floor: %d button_number: %d\n", current_floor_request, button_number);
                    printf("Sensor floor: %d\n", floor);

                    if (floor - f > 0)
                    {
                        elevio_motorDirection(DIRN_DOWN);
                    }
                    //

                    else if ((floor - f < 0) && (floor!=-1))
                    {
                        elevio_motorDirection(DIRN_UP);
                    }
                    break;
                }
            }
        }
        // printf("Button pressed: %d", btnPressed);
        // if(btnPressed!=999){
        //     printf("YES\n");
        //     elevio_buttonLamp(current_floor_request, button_number, btnPressed);
        // }
        // elevio_buttonLamp(current_floor_request, button_number, btnPressed);
        // elevio_buttonLamp(2, 0, 1);

        // printf("%d\n",floor);
        // elevio_motorDirection(DIRN_UP);
        //     printf("Floor %d Current floor request: %d\n",floor, current_floor_request);
        // elevio_buttonLamp(2,0,1);

        if (floor == current_floor_request)
        {
            elevio_motorDirection(DIRN_STOP);
            printf("%d\n", floor);
        }

        if (elevio_obstruction())
        {
            elevio_stopLamp(1);
        }
        else
        {
            elevio_stopLamp(0);
        }

        if (elevio_stopButton())
        {
            elevio_motorDirection(DIRN_STOP);
            break;
        }

        
    }
    */
    nanosleep(&(struct timespec){0, 20}, NULL);
    }
    return 0;  
}