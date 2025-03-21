#include<stdio.h>
int main()
{
	int num;
	char name[100];
	printf("학번을 입력하세요: ");
	scanf("%d", &num);
	printf("이름을 입력하세요: ");
	scanf("%s", name);
	printf("학번: %d, 이름: %s", num, name);
	return 0;
}
