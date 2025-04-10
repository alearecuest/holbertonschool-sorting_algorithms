#include "sort.h"
/**
 * bubble_sort - Sort an array using bubble algorithm
 * @array: array of disordered numbers
 * @size: size of array
 *
 * Description: This function sort an array of numbers using bubble algortihm
 *
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{

	int aux = 0;
	unsigned long int cont = 0, ordered = 0;

	while (ordered < size - 1)
	{
		for (cont = 0; cont < size - 1 - ordered; cont++)
		{
			if (array[cont] > array[cont + 1])
			{
				aux = array[cont];
				array[cont] = array[cont + 1];
				array[cont + 1] = aux;
				print_array(array, size);
			}

		}
		ordered++;
	}
}
