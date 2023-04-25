#include "sort.h"

/**
 * heapify - ensures that heap is a max heap
 * @array: array to check
 * @size: size of the array
 * @heap_size: size of the heap
 * @position: current position of the array
 *
 * Return: nothing
 */
void heapify(int *array, size_t size, size_t heap_size, int position)
{
	size_t l, r;
	int temp, largest;

	largest = position;
	l = 2 * position + 1;
	r = 2 * position + 2;

	if (l < heap_size && array[l] > array[position])
		largest = l;

	if (r < heap_size && array[r] > array[position] && array[r] > array[l])
		largest = r;

	if (largest != position)
	{
		temp = array[position];
		array[position] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, heap_size, largest);
	}
}

/**
 * heap_sort - sorts an array of integers using Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i > -1; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
