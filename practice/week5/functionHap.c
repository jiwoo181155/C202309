#include <stdio.h>
int hapf(int value);
void main()
{
	printf("1부터		10까지의 합은 %d\n", hapf(10));
	printf("1부터	100까지의 합은 %d\n", hapf(100));
	printf("1부터 1000까지의 합은 %d\n", hapf(1000));
}
//hapf함수시작=>int형 value값을 입력받는 함수
int hapf(int value)
{
	//i와 hap 변수 초기화
	int i=1;
	int hap = 0;
	//while반복문으로 i초기값 1부터 value값까지 반복되도록 반복문 설정
	while (i <= value)
	{
		//hap에다가 i값을 더함
		hap = hap + i;
		//i값이 1증가
		i++;
		//다시 while처음으로 돌아가서 반복
	}
	//hap반환
	return hap;
}


/*원래 합 for문
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
