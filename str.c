#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include"str.h"

int str_cpystr(Str*s,Str*s2)
{
	size_t n=s2->len;

	if(s->len<n)
		if(str_grow(s,n))
			return 1;
	memcpy(s->b,s2->b,n);
	return 0;
}

int str_cpy(Str*s,char*c)
{
	size_t n=strlen(c);

	if(s->len<n)
		if(str_grow(s,n))
			return 1;
	memcpy(s->b,c,n);
	return 0;
}

int str_grow(Str*s,size_t n)
{
	if(!s)return 1;
	if(!s->b)
		s->b=malloc(n);
	else
		s->b=realloc(s->b,n);
	s->len=n;
	return 0;
}

Str*str_new(void)
{
	Str*s=NULL;

	s=malloc(sizeof(Str));
	return s;
}

void str_free(Str*s)
{
	if(s)
	{
		if(s->b)
		{
			free(s->b);
			s->b=NULL;
			s->len=0;
		}
		//free(s);
	}
}

void str_print(Str*s)
{
	write(1,s->b,s->len);
	fflush(stdout);
}
