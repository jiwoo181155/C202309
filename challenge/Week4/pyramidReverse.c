#include <stdio.h>

int main() {
	int floor;
	printf("몇층을 쌓으시겠습니까? (5~100)");
	//몇층을 쌓을지 입력하는 scanf_s문
	scanf_s("%d", & floor);
	int i, j;
	//반복할 층 for문=>총 floor줄 쌓음
	for (i = floor; i >=1; --i) {
		//floor-i만큼 S를 출력하므로 S가 0개,1개,2개....순으로 줄이 바뀔때마다 1개씩늘어나면서 출력
		for (j = 0; j < floor - i; ++j)
			printf("S");
		//2Xfloor-i만큼 *을 출력하므로 11,9,7,...순으로 줄이 바뀔때마다 2개씩 줄어서 *을 출력
		for (j = 0; j < 2*i - 1; ++j)
			printf("*");
		printf("\n");
	}
	return 0;
}