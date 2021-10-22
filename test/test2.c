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

char*r(void)
{
	static char s[16];

	memset(s,0,16);
	for(int i=0;i<16;++i)
		s[i]='a'+rand()%23;
	return s;
}

int main(void)
{
	Vec*v=vec_new();
	const size_t n=200;
	int e=0;

	printf("n: %lu\n",n);
	vec_print(v);

	for(size_t i=0;i<n;++i)
		e|=vec_push(v,r());

	vec_print(v);

	//for(size_t i=0;i<v->n;++i)
		//printf("%lu: %s\n",i,v->b[i].b);

	vec_free(v);
	return e;
}
