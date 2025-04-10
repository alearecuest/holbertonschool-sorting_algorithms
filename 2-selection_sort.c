#include "sort.h"
/**
 * selection_sort - Sort an array using selection algorithm
 * @array: array of disordered numbers
 * @size: size of array
 *
 * Description: This function sort an array of numbers using select algortihm
 *
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	unsigned long int cont, actual, min = 0;
	int aux = 0;

	for (cont = 0; cont < size - 1; cont++)
	{
		min = cont;
		for (actual = cont; actual < size; actual++)
		{
			if (array[actual] < array[min])
				min = actual;
		}
		if (cont !=  min)
		{
			aux = array[min];
			array[min] = array[cont];
			array[cont] = aux;
			print_array(array, size);
		}

	}
}
