#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Elevator.h"
#include "utilities.h"

int main()
{
    elevio_init();

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    // elevio_motorDirection(DIRN_UP);

    initializeElevator();

    // Initialize struct with some default values
    Elevator elevator_instance = {999, 999, 999, 999, 999, 999, {0, 0, 0, 0}, {0, 0, 0, 0}};
    Elevator *e = &elevator_instance;

    while (1)
    {
        e->current_floor = elevio_floorSensor(); // keep this
        elevator_control(e);
        // printf("%d\n",floor);

        // int callButton = elevio_callButton(0, BUTTON_CAB);
        // printf("callbutton: %d\r\n", callButton);

        // printf("%d\n",floor);

        for (int f = 0; f < N_FLOORS; f++)
        {
            for (int b = 0; b < N_BUTTONS; b++)
            {
                // printf("button %i fxloor %i\n", b, f);
                e->button_pressed = elevio_callButton(f, b);
                if (e->button_pressed)
                {
                    e->button_floor = f;
                    e->button_type_requested = b;
                    button_manager(e);
                }
            }
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

        nanosleep(&(struct timespec){0, 20}, NULL);
    }

    return 0;
}
