#include<stdio.h>
#include"term.h"
#include"ve.h"

void sh(int s)
{
	
}

char*getl(FILE*f)
{
	char*s=malloc(1024);
	size_t n=1024;
	size_t i=0;

	if(!s)return NULL;

	while(!feof(f) && i<n)
	{
		if(i>=n-1)
		{
			s=realloc(s,n+1024);
			memset(s+n,0,1024);
			if(!s)return NULL;
			n+=1024;
		}

		fread(s+i,1,1,f);
		++i;
	}

	return s;
}

void print_buffer(Vec*v)
{
	for(size_t i=0;i<v->len;++i)
	{
		str_print(v->b+i);
		printf("\n");
	}
}

void pi(int m)
{
	const char*list[]={
		"normal",
		"insert",
	};

	term_gotoxy(20,0);
	term_clearline();
	if(m<0 || m>sizeof(list))return;
	printf("%s",list[m]);
}
