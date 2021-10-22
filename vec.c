#include<stdio.h>
#include<unistd.h>
#include"vec.h"
#include"str.h"

Vec*vec_new(void)
{
	Vec*v=NULL;
	v=malloc(sizeof(Vec));
	return v;
}

int vec_push(Vec*v,char*c)
{
	if(v->len < v->cap-1)
		if(vec_grow(v,v->cap+VEC_BUFSIZE))
			return 1;
	str_cpy(v->b+v->len,c);
	++v->len;
	return 0;
}

int vec_grow(Vec*v,size_t n)
{
	if(!v)return 1;
	if(!v->b)
		v->b=malloc(n*sizeof(Str));
	else
		v->b=realloc(v->b,n*sizeof(Str));
	if(!v->b)
	{
		v->len=0;
		v->cap=0;
		return 2;
	}

	v->cap=n;
	return 0;
}

void vec_free(Vec*v)
{
	if(!v)return;
	for(size_t i=0;i<v->len;++i)
	{
		str_free(v->b+i);
		v->b[i].b=NULL;
	}
	free(v);
}

void vec_print(Vec*v)
{
	for(size_t i=0;i<v->len;++i)
	{
		printf("v[%lu/%lu:%lu] => '",i,v->len,v->cap);
		fflush(stdout);
		write(1,v->b[i].b,v->b[i].len);
		printf("'\n");
	}
}
