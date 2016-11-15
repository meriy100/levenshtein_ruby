#include "distance.h"
#include <stdio.h>
#include <stdlib.h>

int* get_point(int** double_pointer, int x, int y)
{
  return *(double_pointer + sizeof(int*) * x) + sizeof(int) * y;
}

void set_point(int** double_pointer, int x, int y, int value)
{
  *(*(double_pointer + sizeof(int*) * x) + sizeof(int) * y) = value;
}

int distance(const char* word1, const char* word2)
{
  int i;
  int len1 = strlen(word1);
  int len2 = strlen(word2);
  int result;
  int** matrix;
  matrix = (int**)malloc((len1+1) * sizeof(int*));
  for(i = 0; i <= len1; i++) {
    *(matrix + i*sizeof(int*)) = (int*)malloc((len2+1) * sizeof(int));
  }
  fprintf(stderr, "len1: %d\n", len1);
  fprintf(stderr, "len2: %d\n", len2);

  for (i = 0; i <= len1; i++) {
    set_point(matrix, i, 0, i);
    fprintf(stderr, "%d\n", *get_point(matrix, i, 0));
  }

  fprintf(stderr, "ok\n");
  for (i = 0; i <= len2; i++) {
    set_point(matrix, 0, i, i);
    fprintf(stderr, "%d\n", *get_point(matrix, 0, i));
  }
  fprintf(stderr, "ok\n");

  /* for (i = 1; i <= len1; i++) { */
  /*   int j; */
  /*   char c1; */
  /*  */
  /*   c1 = word1[i-1]; */
  /*   for (j = 1; j <= len2; j++) { */
  /*     char c2; */
  /*  */
  /*     c2 = word2[j-1]; */
  /*     if (c1 == c2) { */
  /*       matrix[i][j] = matrix[i-1][j-1]; */
  /*     } */
  /*     else { */
  /*       int delete; */
  /*       int insert; */
  /*       int substitute; */
  /*       int minimum; */
  /*  */
  /*       delete = matrix[i-1][j] + 1; */
  /*       insert = matrix[i][j-1] + 1; */
  /*       substitute = matrix[i-1][j-1] + 1; */
  /*       minimum = delete; */
  /*       if (insert < minimum) { */
  /*         minimum = insert; */
  /*       } */
  /*       if (substitute < minimum) { */
  /*         minimum = substitute; */
  /*       } */
  /*       matrix[i][j] = minimum; */
  /*     } */
  /*   } */
  /* } */
  /* result = matrix[len1][len2]; */
  /* free(matrix); */
  result = 1;
  return result;
}

int main(){
  char word1[256];
  char word2[256];
  scanf("%s", word1);
  scanf("%s", word2);
  printf("%d\n", distance(word1, word2));
}

