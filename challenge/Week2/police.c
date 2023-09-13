#include <stdio.h> //stdio.h 컴파일

int main(void) {
	int age;
	float weight;
	float height;
	char name[256];
	char crime[256];
	printf("이름?");
	scanf_s("%s", name, sizeof(name));
	printf("나이?");
	scanf_s("%d", &age);
	printf("몸무게?");
	scanf_s("%f", &weight);
	printf("키?");
	scanf_s("%f", &height);
	printf("범죄?");
	scanf_s("%s", crime, sizeof(crime));
	printf("----범죄자정보----");
	printf("이름: %s\n", name);
	printf("나이: %d\n", age);
	printf("몸무게: %f\n", weight);
	printf("키: %f\n", height);
	printf("죄목: %s\n", crime);
	return 0;
}
