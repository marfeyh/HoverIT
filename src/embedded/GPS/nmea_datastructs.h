/*Here goes Data structures based on NMEA*/
#pragma once

#ifndef __nmea_datastructs_h_
#define __nmea_datastructs_h_

struct Position {
  /* unsigned int *latitude; */
  /* unsigned int *longitude; */
  float *latitude;
  float *longitude;
  signed char *nsew;
  unsigned short int *altitude;
}

  struct Data{

    struct * Position ;
    unsigned short int * velocity;
    

}

#endif
