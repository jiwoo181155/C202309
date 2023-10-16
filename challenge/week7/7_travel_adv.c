#include <stdio.h>
//전역변수 선언
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10];
char cities[NUMCITY][10];
void calculateTravelDays();

int main() {
	//사용자로부터 도시 이름 입력받는 반복문
	printf("%d개의 도시명을 차례대로 입력해주세요.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}
	//사용자로부터 사람 이름 받는 반복문
	printf("%d개의 여행자 이름을 차례대로 입력해주세요.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}
	//미리 정의한 함수 호출
	calculateTravelDays();
	return 0;
}
//각 도시에서 보낸 총 일수를 계산하는 함수 정의
int getSum(int travelDays[], int a) {
	int sum = 0;
	//도시에서 보낸 총일수를 sum변수에 저장
	for (int j = 0; j < a; j++) {
		sum += travelDays[j];
	}
	return sum;
}
//각 도시에서 보낸 평균 일수를 계산하는 함수 정의
double getAverage(int numArray[], int a) {
	int sum = 0;
	for (int j = 0; j < a; j++) {
		sum += numArray[j];
	}
	double avgDay = (double)sum / a;
	return avgDay;
}
//평균일 기준으로 가장 높은 도시를 출력하는 함수 정의
void printFamousCity(double dayArray[],int a) {
	double max = dayArray[0];
	int indexmax;
	//평균일이 가장 높은 도시를 구하는 반복문
	for (int j = 1; j < NUMCITY; j++) {
		if (max < dayArray[j]) {
			max = dayArray[j];
			indexmax = j;
		}
	}
	printf("평균일 기준으로 가장 인기있었던 도시는 %s 입니다. (평균머문일: %.2f)\n",cities[indexmax], max);
}

void calculateTravelDays() {
	int travelDays[NUMCITY][NUMPEOPLE];
	//각 도시에서 각 사람이 보낸 일 수 입력받는 반복문 작성
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("도시 %s에서 사람 %s가 보낸 일 수를 입력하세요: ", cities[i], names[j]);
			scanf_s("%d", &travelDays[i][j]);
		}
	}
	double averageDays[NUMCITY]; //각 도시별 평균일을 저장 하는 double배열 선언
	//각 도시별 총 일 수 및 평균 일 수 계산하고 출력하는 반복문 작성
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = getSum(travelDays[i], NUMPEOPLE);
		double averageDay = getAverage(travelDays[i], NUMPEOPLE);
		printf("도시 %s에서 보낸 총 일수: %d, 평균 일 수 : %2.f\n", cities[i], totalDays, averageDay);
		averageDays[i] = averageDay;
	}
	printFamousCity(averageDays, NUMCITY);
}