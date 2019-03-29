#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include "types.h"

extern void sort(u32 array[], const u32 size);
extern void bubble_sort(u32 array[], const u32 size);
extern void selection_sort(u32 array[], const u32 size);
extern void merge_sort(u32 array[], const u32 size);
extern void quick_sort(u32 array[], const u32 size);
extern void insertion_sort(u32 array[], const u32 size);
extern void swap(u32 *d1, u32 *d2);

#endif