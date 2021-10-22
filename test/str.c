#include<stdio.h>
#include<string.h>
#include"str.h"

int str_cp(Str*s,const char*c)
{
	size_t n=strlen(c);

	if(!s)return 1;
	if(!s->b || s->n < strlen(c))
		str_grow(s,n);
	if(!s->b)return 2;

	strcpy(s->b,c);
	return 0;
}

int str_grow(Str*s,size_t n)
{
	if(!s)return 1;
	if(!s->b)
		s->b=malloc(n);
	else
		s->b=realloc(s->b,n);
	if(!s->b)
	{
		s->n=0;
		return 2;
	}

	s->n=n;
	return 0;
}

Str*str_new(void)
{
	Str*s=malloc(sizeof(Str));
	if(s)
	{
		s->b=NULL;
		s->n=0;
	}
	return s;
}

void str_free(Str*s)
{
	if(s)
	{
		if(s->b)
		{
			free(s->b);
			s->n=0;
			s->b=NULL;
		}
		free(s);
	}
}
