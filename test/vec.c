#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"vec.h"

void vec_print(Vec*v)
{
	printf("%s %p => c:%lu n:%lu\n",
		__func__,
		v,v->c,v->n);
}

int vec_grow(Vec*v)
{
	if(!v)return 1;
	if(!v->b)
		v->b=malloc(VEC_BUFSIZE*sizeof(Str));
	else
	{
		v->b=realloc(v->b,(v->c+VEC_BUFSIZE)*sizeof(Str));
		if(v->b)
			for(size_t i=v->c;i<v->c+VEC_BUFSIZE;++i)
			{
				v->b[i].b=NULL;
				v->b[i].n=0;
			}
	}

	if(!v->b)
	{
		v->c=0;
		v->n=0;
		return 2;
	}

	v->c+=VEC_BUFSIZE;
	return 0;
}

Vec*vec_new(void)
{
	Vec*v=malloc(sizeof(Vec));
	*v=(Vec){.n=0,.c=0,.b=NULL};
	return v;
}

void vec_free(Vec*v)
{
	if(v)
	{
		if(v->b)
		{
			free(v->b);
			v->b=NULL;
			v->n=0;
			v->c=0;
		}
		free(v);
	}
}

int vec_push(Vec*v,const char*s)
{
	if(!v)return 1;
	if(!v->b || v->n>=v->c-1)
		vec_grow(v);
	if(!v->b || v->n>=v->c-1)
		return 2;

	++v->n;
	str_cp(v->b+v->n-1,s);
	return 0;
}
