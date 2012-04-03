
#define PIN 11
#define MAX_DUTY_CYCLE 254
#define MIN_DUTY_CYCLE 132
#define MAX_SPEED_LEVEL 122
#define TIME_ELAPSE 100
#define RATE 1

struct motor{
  char * name;
  int state;
};
  
void manage_motor();
int initialise_propelsion();
int getSpeedLevel();
void change_pro_speed(int level);
//void decrease_pro_fan(int level);
void stop_pro_fan();
void init_motor();
int get_motor_status();
