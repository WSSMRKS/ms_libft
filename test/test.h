#ifndef FT_TEST_H
#define FT_TEST_H
# pragma once

# include "../libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>

typedef	t_bool (*test_fn)(void);

# define ARR_QSORT_U8_TCOUNT 5000

typedef struct s_test
{
	char		*name;
	test_fn		test;
}				t_test;

void		rndm_bytes(uint8_t *bytes, size_t n);
uint32_t	rndm();
void 		rndm_bytes_close();

t_bool	test_arr_qsort();

#endif
