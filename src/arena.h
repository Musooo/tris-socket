#ifndef ARENA_H
#define ARENA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char *data;
  size_t length;
  size_t offset;
}Arena;

Arena arena_alloc(size_t sz);
void *arena_push(Arena *arena, size_t sz);
void arena_free(Arena *arena);

#endif 