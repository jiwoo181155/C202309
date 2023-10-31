#include <stdio.h>  //컴파일러의 라이브러리에서 stdio.h 헤더파일을 찾아서 포함시킨다

//main함수 시작
int main(void) {
	int age; //age변수 선언
	float weight;  //weight 변수 선언
	float height;   //height 변수 선언
	char name[256];  //크기가 256인 문자열 배열 name 선언
	char crime[256]; //크기가 256인 문자열 배열 crime 선언
	printf("이름?");  
	scanf_s("%s", name, sizeof(name));  //scanf_s문으로 입력받은 단어를 name배열에 저장
	printf("나이?"); 
	scanf_s("%d", &age);  //scanf_s문으로 입력받은 숫자를 int형 변수age에 저장
	printf("몸무게?");
	scanf_s("%f", &weight);  //scanf_s문으로 입력받은 숫자를 float형 변수weight에 저장
	printf("키?");
	scanf_s("%f", &height); //scanf_s문으로 입력받은 숫자를 float형 변수height에 저장
	printf("범죄?");
	scanf_s("%s", crime, sizeof(crime)); //scanf_s문으로 입력받은 단어를 배열 crime에 저장
	printf("----범죄자정보----");  //위에서 입력받아 저장한 값들을 한번에 출력해서 보여준다.
	printf("이름: %s\n", name);
	printf("나이: %d\n", age);
	printf("몸무게: %f\n", weight);
	printf("키: %f\n", height);
	printf("죄목: %s\n", crime);
	return 0;
}
