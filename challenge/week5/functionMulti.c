#include <stdio.h>
long multiF(int value);
int main()
{
	printf("1���� 2������ ���� %ld\n", multiF(2));
	printf("1���� 3������ ���� %ld\n", multiF(3));
	printf("1���� 5������ ���� %ld\n", multiF(5));
	return 0;
}

//hapf�Լ�����=>int�� value���� �Է¹޴� �Լ�
long multiF(int value)
{
	//i�� multi ���� �ʱ�ȭ, �����̱⿡ multi�ʱⰪ�� 1�� �ʱ�ȭ
	int i = 1;
	long multi = 1;
	//while�ݺ������� i�ʱⰪ 1���� value������ �ݺ��ǵ��� �ݺ��� ����
	while (i <= value)
	{
		//multi���ٰ� i���� ����
		multi = multi * i;
		//i���� 1����
		i++;
		//�ٽ� whileó������ ���ư��� �ݺ�
	}
	//multi��ȯ
	return multi;
}
