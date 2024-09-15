#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10
void menu();
void Init_hide(char hide_mine[ROWS][COLS], int rows, int cols);
void Init_show(char show_mine[ROWS][COLS], int rows, int cols);
void Display_mine(char board[ROWS][COLS], int row, int col);
void Set_mine(char hide_mine[ROWS][COLS], int row, int col);
void Fine_mine(char hide_mine[ROWS][COLS], char show_mine[ROWS][COLS], int row, int col);