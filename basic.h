#ifndef BASIC_H
#define BASIC_H

#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "stdbool.h"
#include "stdint.h"
#include "assert.h"

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

//--------------------------------------------------------------------------------------------------

static inline void print(char* text, ...) {
  va_list arguments;
  va_start(arguments, text);
  vprintf(text, arguments);
}

#endif
