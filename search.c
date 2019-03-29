#include <stdio.h>
#include "search.h"
#include "sort.h"
#include <math.h>

#define SIZE 1000

int main()
{
	u32 array[SIZE], index, hero;
	u32 i;
	printf("Enter %u elements : ",(u32)SIZE);
	for(i=0;i<SIZE;i++)	scanf_s("%u", &array[i]);
	printf("Element to be searched : ");
	scanf_s("%u",&hero);
	sort(&array[0], (u32)SIZE);
	display_array(&array[0], (u32)SIZE);
	index = binary_search_rmost(&array[0],(u32)SIZE,hero);
	printf("Index = %u\n",index);
	return (int)0;
}

u32 binary_search(const u32 array[], const u32 size, u32 hero)
{
	u32 index;
	u32 li, ri, mi, found = FALSE;
	li = 0, ri = size;
	do {
		mi = (u32)floor((li + ri) / 2);
		if (array[mi] > hero)
		{
			ri = mi - 1;
		}
		else if (array[mi] < hero)
		{
			li = mi + 1;
		}
		else
		{
			found = TRUE;
			index = mi;
		}
		if ((li > ri) && !found)
		{
			printf("\nElement not found in the list. Zero index returned\n");
			index = 0;
			break;
		}
	} while (!found);
	return index;
}

u32 binary_search_lmost(const u32 array[], const u32 size, u32 hero)
{
	u32 li, ri, mi;
	li = 0, ri = size;
	while (li < ri)
	{
		mi = (u32)floor((li + ri) / 2);
		if (array[mi] < hero)
		{
			li = mi + 1;
		}
		else
		{
			ri = mi;
		}
	}
	return li;
}

u32 binary_search_rmost(const u32 array[], const u32 size, u32 hero)
{
	u32 li, ri, mi;
	li = 0, ri = size;
	while (li < ri)
	{
		mi = (u32)floor((li + ri) / 2);
		if (array[mi] <= hero)
		{
			li = mi + 1;
		}
		else
		{
			ri = mi;
		}
	}
	return (li-1);
}

void display_array(const u32 array[], const u32 size)
{
	u32 i;
	for (i = 0; i < size; i++)
	{
		printf("%u=%u ,",i,array[i]);
	}
	putchar('\n');
}