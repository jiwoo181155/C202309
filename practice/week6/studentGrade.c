#include <stdio.h>
#define STUDENTS 5 //전역변수 STUDENTS 선언

//classifyStudents라는 성적을 ABCDF로 분류하는 함수 정의
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
			printf("%d 학생은 %c 점수를 받았습니다.", i + 1, targetGrade);
		}
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
}