#include <stdio.h>

void summation(double *a, double *b, double *result) {
	*result = *a + *b; //������ �����ϴ� �Լ�
}
void substraction(double *a, double *b, double *result) {
	*result = *a - *b; //������ �����ϴ� �Լ�
}
void multification(double *a, double *b, double *result) {
	*result = *a * *b; //������ �����ϴ� �Լ�
}
void division(double *a, double *b, double *result) {
	*result = *a / *b; //�������� �����ϴ� �Լ�
}

int main() {
	double a = 2, b = 3;
	double result;
	summation(&a, &b, &result); //a��b�� ������ ����ϴ� �Լ� ȣ��
	printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

	substraction(&a, &b, &result);  //a��b�� ������ ����ϴ� �Լ� ȣ��
	printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

	multification(&a, &b, &result);  //a��b�� ������ ����ϴ� �Լ� ȣ��
	printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

	division(&a, &b, &result);  //a��b�� �������� ����ϴ� �Լ� ȣ��
	printf("%.0lf / %.0lf = %.2lf \n", a, b, result);

	return 0;
}

