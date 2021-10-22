#include<unistd.h>
#include<termios.h>
#include"term.h"

void term_clear(void)
{
	printf("\033[2J");
	fflush(stdout);
}

void term_gotoxy(int x,int y)
{
	printf("\033[%d;%dH",y,x);
	fflush(stdout);
}

void term_clearline(void)
{
	printf("\r\033[K");
	fflush(stdout);
}

void term_setecho(int b)
{
	struct termios state;

	tcgetattr(0,&state);
	if(b)
		state.c_lflag|=ECHO;
	else
		state.c_lflag&=~ECHO;
	tcsetattr(0,TCSAFLUSH,&state);
}

void term_setcanon(int b)
{
	struct termios state;

	tcgetattr(0,&state);
	if(b)
		state.c_lflag|=ICANON;
	else
		state.c_lflag&=~ICANON;
	tcsetattr(0,TCSAFLUSH,&state);
}
