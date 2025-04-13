#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array and prints the array
 * @array: The array
 * @i: Index of first element
 * @j: Index of second element
 * @size: Size of array
 */
void swap_elements(int *array, int i, int j, size_t size)
{
	int tmp;

	if (i != j && array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array
 *
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_elements(array, i, j, size);
		}
	}
	swap_elements(array, i + 1, high, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_idx - 1, size);
		quick_sort_recursive(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * Description: Uses the Quick sort algorithm with Lomuto partition scheme.
 * The pivot is always the last element of the partition being sorted.
 * Prints the array after each swap of two elements.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
