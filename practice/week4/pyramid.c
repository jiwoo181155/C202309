#include <stdio.h>
int main() {
	int floor;
	int i;
	int j;
	printf("몇 층으로 쌓을까요?(5~100)");
	//출력할 층을 입력받음
	scanf_s("%d", &floor);
	//반복할 층 for문=>총 floor줄 출력
	for (i = 0; i < floor; i++) 
	{
		//S가 최초 floor-1개가 나오고 다음줄로 넘어갈때마다 하나씩 줄어서 S가 출력
		for (j = 0; j < (floor - 1-i); j++)
		{
			printf("S");
		}
		//*이 1,3,5 등의 i*2+1만큼의 갯수로 각줄에 출력되도록 for문 설정
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*");
		}
		//반복문이 매 반복할때마다 줄바꾸기
		printf("\n");
	}
}