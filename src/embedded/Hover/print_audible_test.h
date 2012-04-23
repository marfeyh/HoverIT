#if !defined PRINT_AUDIBLE_TEST_H
	#define PRINT_AUDIBLE_TEST_H
	int test_start (int test_pin);
	int test_stop (int test_pin);
	int test_normal (int test_pin);
	int test_turbo (int test_pin);
	int test_analogwrite (int test_pin);
	int test_motor_already_started (int test_pin);
	int test_Too_low (int test_pin);
	int test_Too_high (int test_pin);
	#if defined STUB_TEST
		int test_throttle_Stick_is_bottom (int test_pin);
		int test_increase (int throttle_stick_level);
		int test_decrease (int throttle_stick_level);
		int test_set_level (int throttle_stick_level);
		int test_set_fixed_level (int throttle_stick_level);
		#endif
	int silent_delay(int test_pin);
	#endif
