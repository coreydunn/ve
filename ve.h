#pragma once
#include<stdio.h>
#include"vec.h"
#include"str.h"

enum { MODE_NORM, MODE_INSERT };

char*getl(FILE*f);
void print_buffer(Vec*v);
void sh(int s);
void pi(int m);
