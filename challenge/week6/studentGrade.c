#include <stdio.h>
#define STUDENTS 5 //전역변수 STUDENTS 선언

void classifyStudents(int scores[], char targetGrade) {
	printf("학생 성적 분류:\n");
	char grade = ' ';
	//i가 0~4(STUDENTS는 전역변수 5)까지 반복되는 반복문 설정
	for (int i = 0; i < STUDENTS; i++) {
		if (scores[i] >= 90) {
			grade = 'A'; //socre배열의 i번째 점수가 90점 이상이면 grade는 A가 된다
		}
		else if (scores[i] >= 80) {
			grade = 'B';//socre배열의 i번째 점수가 80점 이상이면 grade는 B가 된다
		}
		else if (scores[i] >= 70) {
			grade = 'C';//socre배열의 i번째 점수가 70점 이상이면 grade는 C가 된다
		}
		else if (scores[i] >= 60) {
			grade = 'D';//socre배열의 i번째 점수가 60점 이상이면 grade는 D가 된다
		}
		else {
			grade = 'F'; //score배열의 i번째 점수가 그외의 60점 미만의 점수일 경우 grade는 F가 된다
		}
		if (targetGrade == grade) {
			printf("%d 학생은 %c 점수를 받았습니다.\n", i + 1, targetGrade);
		}
	}
}

//점수 총합을 구하는 함수sumSocres정의
int sumScores(int scores[]) {
	int sum = 0; //sum을 0으로 초기화
	for (int i = 0; i < STUDENTS; i++) {
		sum += scores[i];//sum에 score배열 값을 차례대로 더함
	}
	return sum;
}

//점수의 평균을 구하는 averageScores함수 정의
double averageScores(int scores[]) {
	double avg; //double형 avg 변수 선언
	int sum = 0;
	for (int i = 0; i < STUDENTS; i++) {
		sum += scores[i];
	}
	avg = (double)sum / (sizeof(scores) / sizeof(int)); //(sizeof(scores) / sizeof(int)식으로 배열의 길이 즉 점수의 총 갯수를 구한다음 총합을 나누어서 평균 구하기
	return avg;
}

//학생들의 점수 순위를 출력하는 printRanks함수 정의
void printRanks(int scores[]) {
	int rank[STUDENTS];
	int cnt; //socre배열의 i번째 수보다 큰수가 몇개인지 구하는 변수
	for (int i = 0; i < STUDENTS; i++) {
		cnt = 0; //반복문 매 사이클마다 0으로 초기화
		for (int j = 0; j < STUDENTS; j++) {
			if (scores[i] < scores[j]) {
				cnt++;
			}
		}
		rank[i] = cnt + 1;
	}
	//실제 순위를 문장으로 출력하는 반복문
	for (int i = 0; i < STUDENTS; i++) {
		printf("%d 학생의 순위는 %d 입니다.\n", i+1,rank[i]);
	}
}

int main() {
	//길이가 5인 score배열 선언
	int scores[STUDENTS];
	//학생의 성적을 입력해서 socre배열에 저장하는 반복문
	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 %d의 성적을 입력하세요: ", i + 1);
		scanf_s("%d", &scores[i]);
	}
	char ch = getchar(); //엔터를 지우기 위한 버퍼 임시 저장 변수
	char target;
	printf("특정 점수 (A, B, C, D, F)를 입력하시오");
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target);

	int sum = sumScores(scores); //점수 총합을 구하는 sumScores함수 호출
	double average = averageScores(scores); //점수 평균을 구하는 averageScores함수 호출
	printf("학생들 점수의 총 합은 %d이고 평균 값은 %lf입니다.\n", sum, average);

	printRanks(scores); //학생들의 순위를 출력하는 printRanks함수 호출

	return 0;
}