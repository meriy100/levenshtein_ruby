#include "distance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* get_point(int** double_pointer, int x, int y)
{
    return *(double_pointer + x) + y;
}

void set_point(int** double_pointer, int x, int y, int value)
{
    *(*(double_pointer + x) + y) = value;
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
      *(matrix + i) = (int*)malloc((len2+1) * sizeof(int));
    }

    for (i = 0; i <= len1; i++) {
      set_point(matrix, i, 0, i);
    }

    for (i = 0; i <= len2; i++) {
      set_point(matrix, 0, i, i);
    }

    for (i = 1; i <= len1; i++) {
        int j;
        char c1;
        c1 = word1[i-1];
        for (j = 1; j <= len2; j++) {
            char c2;

            c2 = word2[j-1];
            if (c1 == c2) {
                set_point(matrix, i, j, *get_point(matrix, i-1, j-1));
            }
            else {
                int delete;
                int insert;
                int substitute;
                int minimum;

                delete = *get_point(matrix, i-1, j) + 1;
                insert = *get_point(matrix, i, j-1) + 1;
                substitute = *get_point(matrix, i-1, j-1) + 1;
                minimum = delete;
                if (insert < minimum) {
                    minimum = insert;
                }
                if (substitute < minimum) {
                    minimum = substitute;
                }
                set_point(matrix, i, j, minimum);
            }
        }
    }
      result = *get_point(matrix, len1, len2);
    free(matrix);
    return result;
}

int main(){
    char word1[256];
    char word2[256];
    scanf("%s", word1);
    scanf("%s", word2);
    printf("%d\n", distance(word1, word2));
}

