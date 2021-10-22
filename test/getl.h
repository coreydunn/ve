#pragma once

#include<stdio.h>
#include<string.h>
#include<unistd.h>

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
