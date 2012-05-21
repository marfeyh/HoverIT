/* Create object in the header file */
typedef struct obj{
   char* moduleName;     /*work_package name or ID*/
   char* functionName;    /*function name in that work package*/
   char* message;  /* status, warning, error*/
   
}log_obj;

char* send_info(char* moduleName, char* functionName, char* message);

char* send_warning(char* moduleName, char* functionName, char* message);

char* send_error(char* moduleName, char* functionName, char* message);


