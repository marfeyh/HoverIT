void main(){
	
	init_log_file();
	sleep(1);		
	log_to_file("Info","moter controll","increase_speed()","increase");
	sleep(1);
	log_to_file("Error","scheduel controll", "jump_queen()","smothing error");
	sleep(1);
	log_to_file("Warning","skirt","increase_pressure()", "data is over range");
	close_log_file();
	//delet_log_file();
}
