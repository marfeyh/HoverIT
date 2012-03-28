#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rando(){
	int a;
	srand((unsigned)time(NULL));
	a = rand()%255;
	return a;
}

int extract(){
	int b,bs,c,cs,d,ds,e,es;
	int x = rando();
	int y;

		printf("%d\n",x);
			b=x&7;
			scanf("%d",&bs);
			b=bs;
			printf("%d\n",b);

			c=(x>>3)&3;
			scanf("%d",&cs);
			c=cs;
			printf("%d\n",c);

			d=(x>>5)&3;
			scanf("%d",&ds);
			d=ds;
			printf("%d\n",d);

			e=(x>>7)&0;
			scanf("%d",&es);
			e=es;
			printf("%d\n",e);

		y = (b|(c<<3)|(d<<5)|(e<<7));

		printf("%d\n",y);

	return 0;
}

void loop(){
	while (1) {
		rando();
		sleep(1);
	}
}

void main(){

	//printf("%d\n",rando());
	extract();
}	
