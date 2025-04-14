#include "sort.h"
/**
 * swap - Swap 2 elements of array
 * @in1: element 1
 * @in2: element 2
 *
 * Description: This function swaps two numbers of array
 *
 * Return: Nothing.
 */
void swap(int *in1, int *in2, int arr[], size_t size)
{
	if (*in1 != *in2)
	{
		int temp = *in1;
		*in1 = *in2;
		*in2 = temp;
		print_array(arr, size);
	}
}
/**
 * partition - order a partition of array
 * @arr: array of disordered numbers
 * @low: min index of partition
 * @high: max index of partition
 * @size: size of array
 *
 * Description: order a partition and return index of pivot
 *
 * Return: index of pivot.
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int contEx = (low - 1), contIn;

	for (contIn = low; contIn < high; contIn++)
	{
		if (arr[contIn] <= pivot)
		{
			contEx++;
			swap(&arr[contEx], &arr[contIn], arr, size);
		}
	}
	swap(&arr[contEx + 1], &arr[high], arr, size);
	return (contEx + 1);
}
/**
 * qSort_recursive - Sort an array using quick algorithm
 * @arr: array of disordered numbers
 * @low: min index of array
 * @high: max index of array
 * @size: size of array
 *
 * Description: This function calls partition and calls themselve to subarrays
 *
 * Return: Nothing.
 */
void qSort_recursive(int arr[], int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, size);

		qSort_recursive(arr, low, pi - 1, size);
		qSort_recursive(arr, pi + 1, high, size);
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

	qSort_recursive(array, 0, size - 1, size);
}
