#include <stdio.h>
#include <ruby.h>

VALUE cLevenshtein; /* Fooクラス */


VALUE distance_func(VALUE self, VALUE s_word1, VALUE s_word2)
{
    char* word1 = StringValuePtr(s_word1);
    char* word2 = StringValuePtr(s_word2);
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int matrix[len1 + 1][len2 + 1];
    int i;
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }
    for (i = 1; i <= len1; i++) {
        int j;
        char c1;

        c1 = word1[i-1];
        for (j = 1; j <= len2; j++) {
            char c2;

            c2 = word2[j-1];
            if (c1 == c2) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                int delete;
                int insert;
                int substitute;
                int minimum;

                delete = matrix[i-1][j] + 1;
                insert = matrix[i][j-1] + 1;
                substitute = matrix[i-1][j-1] + 1;
                minimum = delete;
                if (insert < minimum) {
                    minimum = insert;
                }
                if (substitute < minimum) {
                    minimum = substitute;
                }
                matrix[i][j] = minimum;
            }
        }
    }
    return INT2NUM(matrix[len1][len2]);
}

void Init_levensthein()
{
  /* Fooクラスを定義 */
  cLevenshtein = rb_define_class("Levenshtein", rb_cObject);

  /*
    Fooクラスに引数0個のbarメソッドを定義
    barメソッドが呼ばれると、bar_funcが実行される
  */
  rb_define_method(cLevenshtein, "distance", RUBY_METHOD_FUNC(distance_func), 2);
}
