# include "test.h"

#if defined(__APPLE__)
#include <stdlib.h> // For arc4random_buf

uint32_t	rndm()
{
	return (arc4random());
}

void rndm_bytes(uint8_t *bytes, size_t n) {
    arc4random_buf(bytes, n);
}

void rndm_bytes_close()
{}

#else
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

uint32_t	rndm()
{
	uint32_t	val;

	rndm_bytes((uint8_t *)&val, sizeof(uint32_t));
	return val;
}

static void _rndm_bytes(uint8_t *bytes, size_t n, t_bool close)
{
	static int fd = open("/dev/urandom", O_RDONLY);
	if (close)
	{
		close(fd);
		fd = -1;
		return;
	}
	if (fd == -1) {
		perror("open");
		return;
	}
	ssize_t result = read(fd, bytes, length);
	if (result < 0) {
		perror("read");
	} else if ((size_t)result != length) {
		fprintf(stderr, "partial read\n");
	}
	close(fd);
}

void rndm_bytes(uint8_t *bytes, size_t n)
{
    _rndm_bytes(bytes, n, FALSE);
}

void rndm_bytes_close()
{
	_rndm_bytes(0, 0, TRUE);
}
#endif
