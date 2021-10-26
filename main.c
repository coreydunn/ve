#include<fcntl.h>
#include<signal.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include"str.h"
#include"term.h"
#include"ve.h"
#include"vec.h"

int main(int argc,char**argv)
{
	Vec*v=vec_new();
	int running=true;
	int mode=MODE_NORM;

	// Init terminal, etc
	signal(SIGINT,sh);
	term_clear();
	term_gotoxy(0,0);
	term_setecho(false);
	term_setcanon(false);
	//print_buffer(v);

	// Open file, fill line vector
	if(argc>1)
	{
		//for(size_t i=1;argv[i];++i)
		for(size_t i=1;i<2;++i)
		{
			FILE*f=fopen(argv[i],"r");
			if(!f)break;

			while(!feof(f))
			{
				char*cs=getl(f);

				if(cs!=NULL)
					vec_push(v,cs);

				if(cs)
					free(cs);
			}
		}

		// Input loop
		print_buffer(v);
		term_gotoxy(0,0);
		while(running)
		{
			char c=0;
			read(0,&c,1);

			// Get keyboard input
			// We _should_ check mode here
			switch(mode)
			{

				/*****
				* Normal mode -----
				*****/
				case MODE_NORM:
				{
					switch(c)
					{

						case '0':
							printf("\033[1G");
							fflush(stdout);
							break;

						case 'K':
							printf("\033[1T");
							fflush(stdout);
							break;

						case 'J':
							printf("\033[1S");
							fflush(stdout);
							break;

						case 'h':
							printf("\033[1D");
							fflush(stdout);
							break;

						case 'j':
							{
								Point p=term_curpos();

								if((size_t)p.y<v->len)
								{
									printf("\033[1B");
									fflush(stdout);
								}
							}
							break;

						case 'k':
							printf("\033[1A");
							fflush(stdout);
							break;

						case 'l':
							printf("\033[1C");
							fflush(stdout);
							break;

						case 'q':
							running=false;
							break;

						case 'g':
							{
								Point p=term_curpos();
								term_gotoxy(p.x,1);
							}
							break;

						case 'G':
							{
								Point p=term_curpos();
								term_gotoxy(p.x,v->len);
							}
							break;

						case 'a':
							if(mode==MODE_NORM)
							{
								mode=MODE_INSERT;
								pi(mode);
							}
							break;

						default:
							break;
					}
					break;
				}


				/*****
				* Insert mode -----
				*****/
				case MODE_INSERT:
				{
					switch(c)
					{
						case ':':
							if(mode==MODE_INSERT)
							{
								mode=MODE_NORM;
								pi(mode);
							}
							break;
						default:
							break;
					}
				}
				usleep(20000);
			}

		}
	}

	// Exit, free resources
	term_gotoxy(0,0);
	term_clear();
	term_setecho(true);
	term_setcanon(true);
	vec_free(v);
	return 0;
}
