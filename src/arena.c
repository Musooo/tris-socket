#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char *data;
  size_t length;
  size_t offset;
}Arena;

Arena arena_alloc(size_t sz){
  unsigned char *memory = malloc(sz);
  Arena arena = {
    .data = memory,
    .length = sz,
    .offset = 0
  };

  return arena;
}

void *arena_push(Arena *arena, size_t sz){
  if(arena->offset+sz <= arena->length){
    void *p = &arena->data[arena->offset];
    arena->offset += sz;
    memset(p, 0, sz);
    return p;
  }
  printf("No memory");
  return NULL;
}

void arena_free(Arena *arena){
    if (arena->data != NULL) {
        free(arena->data);
        arena->data = NULL;
    }
    arena->offset = 0;
    arena->length = 0;
}
