#include "Elevator.h"

void button_manager(Elevator *e);
void set_direction(Elevator *e);
void stop_routine(Elevator *e);
void elevator_control(Elevator *e);
bool one_in_queue(Elevator *e);
bool should_stop(Elevator *e);
MotorDirection up_or_down(Elevator *e);
void print_arrays(Elevator *e);