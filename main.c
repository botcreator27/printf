#include "main.h"

int main(void)
{
	_printf("the number is : %d\n", 234);
	int result = _printf("%d\n", -1);
	_printf("%d\n", result);
	_printf("%d, %d, %d\n", 0, 100, -222);
	_printf("my name is:%s, the first letter is %c\n", "isa", 'i');
	return (0);
}

