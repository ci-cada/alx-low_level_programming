#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: contains the bits to be flipped
 * @m: we are flipping to get here
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int a;
	unsigned long int x = 0;

	a = n ^ m;

	for (x = 0; a != 0; x += 1)
		a &= (a - 1);
	return (x);
}
