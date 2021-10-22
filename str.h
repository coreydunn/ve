#pragma once
#include<stdio.h>
#include<stdlib.h>
#define STR_BUFSIZE

typedef struct Str
{
	size_t len;
	char*b;
} Str;

Str*str_new(void);
int str_cpy(Str*s,char*c);
int str_cpystr(Str*s,Str*s2);
int str_grow(Str*s,size_t n);
void str_free(Str*s);
void str_print(Str*s);
