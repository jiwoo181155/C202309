#include <stdio.h>
int hapf(int value);
void main()
{
	printf("1����		10������ ���� %d\n", hapf(10));
	printf("1����	100������ ���� %d\n", hapf(100));
	printf("1���� 1000������ ���� %d\n", hapf(1000));
}
//hapf�Լ�����=>int�� value���� �Է¹޴� �Լ�
int hapf(int value)
{
	//i�� hap ���� �ʱ�ȭ
	int i=1;
	int hap = 0;
	//while�ݺ������� i�ʱⰪ 1���� value������ �ݺ��ǵ��� �ݺ��� ����
	while (i <= value)
	{
		//hap���ٰ� i���� ����
		hap = hap + i;
		//i���� 1����
		i++;
		//�ٽ� whileó������ ���ư��� �ݺ�
	}
	//hap��ȯ
	return hap;
}


/*���� �� for��
int hapf(int value)
{
	int i;
	int hap = 0;
	for (i = 1; i <= value; i = i + 1)
	{
		hap = hap + i;
	}
	return hap;
}*/
