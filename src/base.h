#ifndef _BASE_H_
#define _BASE_H_

#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float  f32;
typedef double f64;

typedef struct {
  size_t count;
  size_t capacity;
  char *buffer;
} StringBuilder;

typedef struct {
  size_t count;
  const char *buffer;
} StringView;

static inline bool is_alpha(char c) {
  // Looking at the ascii table, we can simply just or with 32 to upgrade 'A' to 'a'.
  char new_c = c | 32;
  return new_c >= 'a' && new_c <= 'z';
}

static inline bool is_number(char c) {
  return c >= '0' && c <= '9';
}

static inline bool is_alpha_numeric(char c) {
  // Looking at the ascii table, we can simply just or with 32 to upgrade 'A' to 'a'.
  return is_alpha(c) || is_number(c);
}

static inline bool is_whitespace(char c) {
  return isspace(c);
}

// StringBuilder string_builder_create(size_t capacity);
// void string_builder_free(StringBuilder *string);
//
// void string_builder_reserve_size(StringBuilder *string, size_t size);
//
// void string_builder_append_char(StringBuilder *string, char c);
// void string_builder_append_null(StringBuilder *string);
// void string_builder_append_cstr(StringBuilder *string, const char *cstring);
// void string_builder_append_fmt(StringBuilder *string, const char *cstring, ...);
// void string_builder_append_strview(StringBuilder *string, StringView view);
//
// StringView cstr_to_str_view(const char *string);
// StringView str_to_str_view(StringBuilder string);
// StringView str_view_null();

#endif // _BASE_H_

