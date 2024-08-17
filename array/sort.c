
#include "ft_array.h"
#include <stdlib.h>

static void	swap(void *arr, size_t a, size_t b, size_t element_size)
{
	ft_memswap(arr + (a * element_size),
			arr + (b * element_size), element_size);
}

static int32_t	cmp(void *arr, size_t a, size_t b, t_qsort_state *st)
{
	return (st->cmp(arr + (a * st->element_size),
				arr + (b * st->element_size)));
}

static void	get_pivot(void *arr, size_t len, t_qsort_state *st)
{
	size_t	mid;

	if (len > 2)
	{
		mid = len / 2;
		if (cmp(arr, 0, mid, st) > 0)
			swap(arr, 0, mid, st->element_size);
		if (cmp(arr, 0, len - 1, st) > 0)
			swap(arr, 0, len - 1, st->element_size);
		if (cmp(arr, mid, len - 1, st) > 0)
			swap(arr, mid, len - 1, st->element_size);
		swap(arr, mid, len - 1, st->element_size);
	}
	ft_memcpy(st->pivot, arr + (len - 1) * st->element_size, st->element_size);
}

static t_mid_partition	partition(void *arr, size_t len, t_qsort_state *st)
{
	uint32_t	lt;
	uint32_t	eq;
	uint32_t	gt;

	lt = 0;
	eq = 0;
	gt = len - 1;
	get_pivot(arr, len, st);
	while (eq <= gt)
	{
		if (st->cmp(arr + (eq * st->element_size), st->pivot) < 0)
		{
			swap(arr, lt, eq, st->element_size);
			lt++;
			eq++;
		}
		else if (st->cmp(arr + (eq * st->element_size), st->pivot) > 0)
		{
			swap(arr, eq, gt, st->element_size);
			gt--;
		}
		else
			eq++;
	}
	return ((t_mid_partition){lt, gt});
}

static void	quicksort(void *arr, size_t len, t_qsort_state *st)
{
	t_mid_partition	mid;

	if (len < 2)
		return ;
	mid = partition(arr, len, st);
	quicksort(arr, mid.lt, st);
	quicksort(arr + (mid.gt + 1) * st->element_size, len - mid.gt - 1, st);
}

/// @brief Sorts an array using the quicksort algorithm.
/// @param arr The array to sort.
/// @param len The number of elements in the array.
/// @param element_size The size of each element in the array.
/// @param cmp The comparator function used to compare elements.
/// @return TRUE if the array was successfully sorted, otherwise FALSE.
/// @note May fail due to malloc failure.
t_bool	arr_qsort(void *arr, size_t len, size_t element_size, t_comparator cmp)
{
	t_qsort_state	st;

	st.cmp = cmp;
	st.element_size = element_size;
	st.pivot = malloc(element_size);
	if (!st.pivot)
		return (FALSE);
	quicksort(arr, len, &st);
	free(st.pivot);
	return (TRUE);
}

t_bool	arr_is_sorted(void *arr, size_t len, size_t element_size,
			t_comparator cmp)
{
	size_t	i;

	i = 1;
	while (i < len)
	{
		if (cmp(arr + (i - 1) * element_size, arr + i * element_size) > 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
