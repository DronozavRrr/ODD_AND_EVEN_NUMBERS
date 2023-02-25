#pragma once

#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int IsUniqNumber(int* UniqNumbers, int n, int RandRows, int RandCol);
int TwoPlayers(int* UniqNumbers, int* game, int& n, int& RandRows, int& RandCol, int& wrong1, int& wrong2);
int OnePlayer(int* UniqNumbers, int* game, int& n, int& RandRows, int& RandCol, int& wrong1, int& wrong2);
void AmountsRowsColumns(int* game, int n, int side, int choose);
void OutputReadyGame(int* game, int n);