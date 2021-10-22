#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Str
{
	char*b;
	size_t n;
} Str;

Str*str_new(void);
int str_cp(Str*s,const char*c);
int str_grow(Str*s,size_t n);
void str_free(Str*s);
