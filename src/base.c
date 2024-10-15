#include "base.h"
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

StringBuilder string_builder_create(size_t capacity) {
  return (StringBuilder) {
    .count = 0,
    .capacity = capacity,
    .buffer = capacity != 0 ? malloc(capacity * sizeof(char)) : NULL,
  };
}

void string_builder_free(StringBuilder *string) {
  assert(string);
  free(string->buffer);
  *string = (StringBuilder){0}; // zero out for reuse
}

void string_builder_reserve_size(StringBuilder *string, size_t size) {
  assert(string);
  if(size > string->capacity) {
    while(size > string->capacity) {
      string->capacity = string->capacity ? string->capacity * 2 : 1;
    }
    string->buffer = realloc(string->buffer, string->capacity);
  }
}

void string_builder_append_char(StringBuilder *string, char c) {
  assert(string);
  if(string->count + 1 > string->capacity) {
    string->capacity = string->capacity ? string->capacity * 2 : 1;
    string->buffer = realloc(string->buffer, string->capacity);
  }
  string->buffer[string->count++] = c;
}

void string_builder_append_null(StringBuilder *string) {
  assert(string);
  string_builder_append_char(string, 0);
  string->count--;
}

void string_builder_append_cstr(StringBuilder *string, const char *cstring) {
  assert(string);
  assert(cstring);
  const char *c = cstring;
  for(;*c != 0; ++c) string_builder_append_char(string, *c);
  string_builder_append_null(string);
}


void string_builder_append_fmt(StringBuilder *string, const char *cstring, ...) {
  va_list list_for_length;
  va_list list_for_print;

  va_start(list_for_length, cstring);
  va_copy(list_for_print, list_for_length);

  int length = vsnprintf(NULL, 0, cstring, list_for_length);
  string_builder_reserve_size(string, string->count + length + 1);
  vsnprintf(string->buffer + string->count, length + 1, cstring, list_for_print);
  string->count += length;

  va_end(list_for_length);
  va_end(list_for_print);
}

void string_builder_append_strview(StringBuilder *string, StringView view) {
  assert(string);
  for(size_t i = 0; i < view.count; ++i) string_builder_append_char(string, view.buffer[i]);
  string_builder_append_null(string);
}

StringView cstr_to_str_view(const char *string) {
  return (StringView) { .count = strlen(string), .buffer = string, };
}

StringView str_to_str_view(StringBuilder string) {
  return (StringView) { .count = string.count, .buffer = string.buffer, };
}

StringView strview_null() {
  return (StringView) {0};
}


