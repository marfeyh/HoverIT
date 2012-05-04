#define PI 3.14159265358979323846
#define R 6371   // earth's radius in km

double DEG_TO_RAD(double degree);
double RAD_TO_DEG(double radian);
double round_down (double val);


double find_distance(double lat1, double lon1, double lat2, double lon2);
double find_bearing(double lat1, double lon1, double lat2, double lon2);


void begin_main();

