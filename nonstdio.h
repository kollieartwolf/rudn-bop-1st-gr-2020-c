#ifndef LABS_NONSTDIO_H
#define LABS_NONSTDIO_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEFAULT_STR_LENGTH 1024
#define and &&
#define or ||
#define not !

/*
 * NONstdio - комплект из заголовочного файла и файла исходных текстов
 * nonstdio.h и nonstdio.c
 * Обеспечивает безопасный ввод числа с плавающей запятой.
 * Автор: Титов Климентий
 *
 * API: чтобы получить число, необходимо получить структуру:
 * "struct xNumber".
 *
 * Чтобы узнать, прошёл ли ввод числа успешно, нужно условие:
 * "if (<struct xNumber>.status == true") ...".
 */

typedef enum { false, true } bool;

typedef struct {
  float num;
  bool status;
} float_nstd;

typedef struct {
  int num;
  bool status;
} int_nstd;

typedef struct {
  double num;
  bool status;
} double_nstd;

bool isEqual(char *str1, char *str2);
bool containsChar(char *str, char sym);

// Прикладные функции для определения типа символа
bool isPartOfFloat(char sym);
bool isPartOfInt(char sym);
bool isEndOfString(char sym);

// Прикладные функции ввода чисел
int *countSplits(char in[]);
float_nstd *splitFloats(char in[], int numberCounter, int stringLength);
float_nstd scanFloat();
float_nstd *scanFloats(); // через пробел, в первом элементе - количество чисел
int_nstd *splitInts(char in[], int numberCounter, int stringLength);
int_nstd scanInt();
int_nstd *scanInts(); // через пробел, в первом элементе - количество чисел
double_nstd *splitDoubles(char in[], int numberCounter, int stringLength);
double_nstd scanDouble();
double_nstd *
scanDoubles(); // через пробел, в первом элементе - количество чисел

// Прикладные функции для получения псевдослучайных наборов чисел
int uniform(int min, int max);
double dUniform(double min, double max);

#endif // LABS_NONSTDIO_H
