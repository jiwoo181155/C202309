#include <stdio.h>
int multiF(int value);
void main()
{
	printf("1���� 2������ ���� %d\n", multiF(2));
	printf("1���� 3������ ���� %d\n", multiF(3));
	printf("1���� 5������ ���� %d\n", multiF(5));
}

//hapf�Լ�����=>int�� value���� �Է¹޴� �Լ�
int multiF(int value)
{
	//i�� multi ���� �ʱ�ȭ, �����̱⿡ multi�ʱⰪ�� 1�� �ʱ�ȭ
	int i = 1;
	int multi = 1;
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
