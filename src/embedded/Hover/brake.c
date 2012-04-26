#include <hover_api.h>
#include <stdlib.h>
#include <hover_api.h>
#include <hovering_motor.h>
#include <hovering_control.h>
#include <pressure_check.h>
#include <pin.h>

int hovrining_brake(void){
	hover_min();
	return 0;
}

int propulsion_brake(void){
	stop_propulsion_fan();
	delay(3000);
	change_polarity(5000);
	max_propulsion_fan(5000);
	delay(3000);

	return 0;
}

int change_pol_
