#include <stdio.h>
#include <stdarg.h>

int somme (int a, ...)
{
	int sum;
	int i = 0;
	int j = a;
	int c = 0;

	va_list ap;
	va_start(ap, a);
	while (i < j)
	{
		c = va_arg(ap,int);
		sum += c;
		i++;
	}
	va_end(ap);
	return(sum);
}

int main()
{
	printf("sum = %d\n", somme(8,1,2,4,8,16,32,64,128));
	return(0);
}
