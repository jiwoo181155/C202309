#include <stdio.h>

void summation(double *a, double *b, double *result) {
	*result = *a + *b; //덧셈을 수행하는 함수
}
void substraction(double *a, double *b, double *result) {
	*result = *a - *b; //뺄셈을 수행하는 함수
}
void multification(double *a, double *b, double *result) {
	*result = *a * *b; //곱셈을 수행하는 함수
}
void division(double *a, double *b, double *result) {
	*result = *a / *b; //나눗셈을 수행하는 함수
}

int main() {
	double a = 2, b = 3;
	double result;
	summation(&a, &b, &result); //a와b의 덧셈을 출력하는 함수 호출
	printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

	substraction(&a, &b, &result);  //a와b의 뺄셈을 출력하는 함수 호출
	printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

	multification(&a, &b, &result);  //a와b의 곱셈을 출력하는 함수 호출
	printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

	division(&a, &b, &result);  //a와b의 나눗셈을 출력하는 함수 호출
	printf("%.0lf / %.0lf = %.2lf \n", a, b, result);

	return 0;
}

