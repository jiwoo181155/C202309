#include <stdio.h>
int multiF(int value);
void main()
{
	printf("1부터 2까지의 곱은 %d\n", multiF(2));
	printf("1부터 3까지의 곱은 %d\n", multiF(3));
	printf("1부터 5까지의 곱은 %d\n", multiF(5));
}

//hapf함수시작=>int형 value값을 입력받는 함수
int multiF(int value)
{
	//i와 multi 변수 초기화, 곱셈이기에 multi초기값을 1로 초기화
	int i = 1;
	int multi = 1;
	//while반복문으로 i초기값 1부터 value값까지 반복되도록 반복문 설정
	while (i <= value)
	{
		//multi에다가 i값을 곱함
		multi = multi * i;
		//i값이 1증가
		i++;
		//다시 while처음으로 돌아가서 반복
	}
	//multi반환
	return multi;
}
