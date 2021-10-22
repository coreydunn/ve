#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"str.h"

#define VEC_BUFSIZE 16

typedef struct Vec
{
	size_t n;
	size_t c;
	Str*b;
}Vec;

Vec*vec_new(void);
int vec_grow(Vec*v);
int vec_push(Vec*v,const char*s);
void vec_free(Vec*v);
void vec_print(Vec*v);
