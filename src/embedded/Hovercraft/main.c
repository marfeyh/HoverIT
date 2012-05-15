#include <Arduino.h>
#include <searduino.h>
#include <Theta-API.h>
#include <API_communication_controler.h>
#include <propulsion_api.h>
#include <hover_api.h>
#include <hovercraft_pin.h>
#include <steering.h>
#include <calculateSpeed.h>

Speed *g_speed_p;

int main(void) {
	init();
	communication_serial_setup();
	start_propulsion_fan();
	start_hover();
	control_rudder(0);
	pinMode(0, INPUT);
	pinMode(1, INPUT);
	g_speed_p = create_speed();

	for (;;) {
		control();
	}
	return 0;
}

