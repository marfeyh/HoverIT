#include "embedded_log.h"
#include "pc_log.h"
void main(){
	
	init_log_file();
	send_info("Moter","increse_speed()","increase speed");
	sleep(1);
    send_warning("Barrier", "barrier_level()","warn low level");
    sleep(1);
    send_error("Bluetooh","connection()","connection faile");
	sleep(1);
	close_log_file();
	//delet_log_file();
}
