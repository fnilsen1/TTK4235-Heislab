#pragma once


#define N_FLOORS 4

typedef enum { 
    DIRN_DOWN   = -1,
    DIRN_STOP   = 0,
    DIRN_UP     = 1
} MotorDirection;


#define N_BUTTONS 3

typedef enum { 
    BUTTON_HALL_UP      = 0, //oppknapp på PLS
    BUTTON_HALL_DOWN    = 1, //nedknapp på PLS
    BUTTON_CAB          = 2 //en av de grå under "Heispanel" i PLS
} ButtonType;


void elevio_init(void);

//set commands/functions
void elevio_motorDirection(MotorDirection dirn);
void elevio_buttonLamp(int floor, ButtonType button, int value);
void elevio_floorIndicator(int floor);
void elevio_doorOpenLamp(int value);
void elevio_stopLamp(int value);

//get commands/functions
int elevio_callButton(int floor, ButtonType button); //returnerer 1 når funksjonsargumenter samsvarer med riktig trykket knapp på panelet, null hvis ikke
int elevio_floorSensor(void);
int elevio_stopButton(void);
int elevio_obstruction(void);

