#include "sort.h"
#include<time.h>

void sort(u32 array[], const u32 size)
{
	u32 option;
	u8 success;
	clock_t start, end;
	f64 actual_time;
	printf("Which sort option you want to choose :\n1) Bubble sort\n2) Selection sort\n3) Merge sort\n4) Quick sort\n5) Insertion sort\n");

	do {
		scanf_s("%u", &option);
		switch (option)
		{
		case 1:
		{
			start = clock();
			bubble_sort(&array[0], size);
			end = clock();
			success = TRUE;
			break;
		}
		case 2:
		{
			start = clock();
			selection_sort(&array[0], size);
			end = clock();
			success = TRUE;
			break;
		}
		case 3:
		{
			start = clock();
			merge_sort(&array[0], size);
			end = clock();
			success = TRUE;
			break;
		}
		case 4:
		{
			start = clock();
			quick_sort(&array[0], size);
			end = clock();
			success = TRUE;
			break;
		}
		case 5:
		{
			start = clock();
			insertion_sort(&array[0], size);
			end = clock();
			success = TRUE;
			break;
		}
		default:
		{
			printf("Incorrect option !! Please choose correct option(1..5) : ");
			success = FALSE;
			break;
		}
		}
	} while (!success);
	actual_time = (f64)(end - start) / CLOCKS_PER_SEC;
	printf("Time to sort : %lf\n",actual_time);
}

void bubble_sort(u32 array[], const u32 size)
{
	u32 i, j;
	u8 choose = 1;
	if (choose) /* Ascending*/
	{
		for (i = 1; i < size; i++)
		{
			for (j = 0; j < size - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
				}
			}
		}
	}
	else /* Descending*/
	{
		for (i = 1; i < size; i++)
		{
			for (j = 0; j < size - i; j++)
			{
				if (array[j] < array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
				}
			}
		}
	}
}

void selection_sort(u32 array[], const u32 size)
{
	u32 i, j;
	u8 choose = 1;
	if (choose)  /* Ascending */
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = i + 1; j < size; j++)
			{
				if (array[i] > array[j])
				{
					swap(&array[i], &array[j]);
				}
			}
		}
	}
	else /* Descending */
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = i + 1; j < size; j++)
			{
				if (array[i] < array[j])
				{
					swap(&array[i], &array[j]);
				}
			}
		}
	}
}

void merge_sort(u32 array[], const u32 size)
{

}

void quick_sort(u32 array[], const u32 size)
{

}

void insertion_sort(u32 array[], const u32 size)
{

}

void swap(u32 *d1, u32 *d2)
{
	*d1 = *d1 + *d2;
	*d2 = *d1 - *d2;
	*d1 = *d1 - *d2;
}