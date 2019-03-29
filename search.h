#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include "types.h"

extern u32 binary_search(const u32 array[], const u32 size, u32 hero);
extern u32 binary_search_lmost(const u32 array[], const u32 size, u32 hero);
extern u32 binary_search_rmost(const u32 array[], const u32 size, u32 hero);
extern void display_array(const u32 array[], const u32 size);

#endif
