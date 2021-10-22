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

int main(void)
{
	Vec*v=vec_new();
	Str*s=str_new();

	str_cp(s,"what is this please");
	printf("%s (%lu)\n",s->b,s->n);

	str_cp(s,"why oh why");
	printf("%s (%lu)\n",s->b,s->n);

	str_cp(s,"___________________________________ok");
	printf("%s (%lu)\n",s->b,s->n);

	str_cp(s,"no");
	printf("%s (%lu)\n",s->b,s->n);

	str_free(s);
	vec_free(v);
}
