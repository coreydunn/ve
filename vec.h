#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"str.h"
#include"vec.h"

#define VEC_BUFSIZE 16

typedef struct Vec
{
	size_t len;
	size_t cap;
	Str*b;
} Vec;

Vec*vec_new(void);
int vec_grow(Vec*v,size_t n);
int vec_push(Vec*v,char*c);
void vec_free(Vec*v);
void vec_print(Vec*v);
