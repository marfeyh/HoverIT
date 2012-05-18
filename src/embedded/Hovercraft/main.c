#include <Arduino.h>
#include <searduino.h>
#include <Theta-API.h>
#include <API_communication_controler.h>
#include <propulsion_api.h>
#include <hover_api.h>
#include <hovercraft_pin.h>
#include <steering.h>
#include <calculateSpeed.h>
#include <battery_meter.h>
#include <wifi_wrapper.h>


Speed *g_speed_p;

int main(void) {
	// init for arduino
	init();
	// Bluetooth
	communication_serial_setup();
	// propulsion fan
	start_propulsion_fan();
	// hover fan
	start_hover();
	// rudder control
	control_rudder(0);
	// pressure which failed
	pinMode(0, INPUT);
	pinMode(1, INPUT);
	// speed
	g_speed_p = create_speed();
	// battery levels
	init_battery_meter();
	// wifi
//	wifi_begin();
	for (;;) {
		// Scheduler
		control();
	}
	return 0;
}

