#include<fcntl.h>
#include<signal.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include"str.h"
#include"vec.h"
#include"getl.h"

//char*getl(FILE*f)
//{
	//char*s=NULL;
	//char c=-1;
	//const size_t inc=1024;
	//size_t n=inc;
	//size_t i=0;
//
	//s=malloc(n);
	//if(!s)return NULL;
//
	//while(!feof(f) && c!='\n' && c!='\0')
	//{
		//if(i>=n-1)
		//{
			//s=realloc(s,n+inc);
			//if(!s)return NULL;
			//n+=inc;
		//}
//
		//fread(&c,1,1,f);
		//s[i]=c;
		//if(c=='\n' || c==EOF)
		//{
			//s[i]='\0';
			//break;
		//}
		//++i;
	//}
//
	//return s;
//}

int main(void)
{
	Vec*v=vec_new();
	FILE*f=fopen("read_this_file.c","r");
	//FILE*f=fopen("test1.c","r");

	while(!feof(f))
	{
		char*s=getl(f);
		vec_push(v,s);
		if(s)
			free(s);
	}

	vec_print(v);

	vec_free(v);
	fclose(f);

	return 0;
}
