#include <main_test.h>
#include <stdlib.h>

int main (void){
	int number_failed;
	SRunner* suite_runner = srunner_create(info_test());
	srunner_run_all(suite_runner, CK_NORMAL);
	number_failed = srunner_ntests_failed(suite_runner);
	srunner_free(suite_runner);
	return (number_failed ==0) ? EXIT_SUCCESS : EXIT_FAILURE;
	
}

