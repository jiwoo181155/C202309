#include <stdio.h> //stdio.h ������

int main(void) {
	int x = 1;
	printf("x= %d\n", x++);
	printf("x= %d\n", x++);
	printf("x= %d\n", ++x);
	printf("x= %d\n", x--);
	printf("x= %d\n", x--);
	printf("x= %d\n", --x);
	return 0;
}
