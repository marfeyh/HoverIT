#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rando(){
	int a;
	srand((unsigned)time(NULL));
	a = rand()%255;
	return a;
}

int hspeed, hspeed, rdirect, x; //x is random number

void set_FS(int fspeed){
	int result,left;
	left=x&120;
	result=left|fspeed;	/*Fspeed 0-7*/
}

void set_HS(int hspeed){
	int result,left;
	left=((x>>5)&3)|(x&7);
	result=left|(hspeed<<3);	/*Hspeed 0-3*/
}

void set_RD(int rdirect){
	int result,left;
	left=x&31;
	result=left|(rdirect<<5);	/*Rdirect 0-3*/
}


int extract(){
	int b,bs,c,cs,d,ds,e,es;
	int x = rando();
	int y;

		printf("%d\n",x);
			b=x&7;
			scanf("%d",&bs);
			b=bs;

			c=(x>>3)&3;
			scanf("%d",&cs);
			c=cs;

			d=(x>>5)&3;
			scanf("%d",&ds);
			d=ds;

			e=(x>>7)&0;
			scanf("%d",&es);
			e=es;

		y = (b|(c<<3)|(d<<5)|(e<<7));

		printf("%d\n",y);

	return y;
}

int board_info(){
	int a,b,c,y;
	
	srand((unsigned)time(NULL));
	
	a=rand()%15;
	b=rand()%3;
	c=rand()%3;

	y = (a|(b<<4)|(c<<6));
	
	printf("%d\n",y);
	return y;
}

void loop(){
	while (1) {
		rando();	
		//printf("%d\n",rando());
		sleep(1);
	}
}

//void main(){
	//int x;
  	//x=extract()|(board_info()<<8);
	//printf("%d\n",x);

//}	
