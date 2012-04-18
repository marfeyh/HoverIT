typedef struct obj{
	char* tag;
	char* info;
	char* function;
}log_obj;

void init_log_file();
char* get_time();
void log_file_writer();
void log_to_file(char* tag ,char* message, char* function);
void close_log_file();
void delet_log_file();
