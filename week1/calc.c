#include <cs50.h>
#include <stdio.h>

int main(void)
{
	long x, y;
	x = get_long("x: ");
	y = get_long("y: ");

	double z = (double) x / (double) y;

	printf("%.20f\n", z);
}
