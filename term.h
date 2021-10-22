#pragma once
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

void term_clear(void);
void term_clearline(void);
void term_gotoxy(int x,int y);
void term_setcanon(int b);
void term_setecho(int b);
