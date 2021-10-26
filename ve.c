#include<stdio.h>
#include"term.h"
#include"ve.h"

void sh(int s)
{
	s=s;
}

char*getl(FILE*f)
{
	const size_t buflen=1024;
	char*s=malloc(buflen);
	size_t n=buflen;
	size_t i=0;

	if(!s)return NULL;

	while(!feof(f) && i<n)
	{
		if(i>=n-1)
		{
			s=realloc(s,n+buflen);
			memset(s+n,0,buflen);
			if(!s)return NULL;
			n+=buflen;
		}

		fread(s+i,1,1,f);

		if(feof(f) && i==0)
		{
			if(s)free(s);
				return NULL;
		}

		if(s[i]=='\n')
		{
			s[i]='\0';
			break;
		}
		++i;
	}

	return s;
}

void print_buffer(Vec*v)
{
	for(size_t i=0;i<v->len;++i)
	{
		printf("%lu: ",i);
		fflush(stdout);
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
	if(m<0 || (size_t)m>sizeof(list))return;
	printf("%s",list[m]);
}
