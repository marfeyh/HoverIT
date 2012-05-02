#include <stdlib.h>
#include <stdio.h>

int main(void){
srandom((unsigned)time(NULL));
int a=random() %25 +100;
// srandom((unsigned)time(NULL));	
int b=random() %25 +100;
printf ("A= %d  %d \n", a,b);
}
