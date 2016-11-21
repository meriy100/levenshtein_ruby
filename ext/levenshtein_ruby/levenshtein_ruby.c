#include <stdio.h>
#include <ruby.h>
#include "distance.h"

VALUE cLevenshtein;


VALUE distance_func(VALUE self, VALUE s_word1, VALUE s_word2)
{

    char* word1 = StringValuePtr(s_word1);
    char* word2 = StringValuePtr(s_word2);
    return INT2NUM(distance(word1, word2));
}

void Init_levenshtein_ruby()
{
  cLevenshtein = rb_define_module("Levenshtein");
  rb_define_module_function(cLevenshtein, "distance", RUBY_METHOD_FUNC(distance_func), 2);
}
