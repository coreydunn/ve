#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"getl.h"

int main(void)
{
	FILE*f=fopen("read_this_file.c","r");
	char*s=NULL;

	if(!f)return 1;
	s=getl(f);
	puts(s);

	free(s);
	fclose(f);
}
