#include <stdio.h>
int main()
{
	char input;
	char output;
	while(1){
		printf("문자 입력: ");
		scanf(" %c", &input);
		if(input=='0') break;
		else if(input >= 'A' && input <= 'Z')
		{
			output=input+32;
			printf("%c의 소문자는 %c입니다.\n",input, output);
		}
		else if(input >= 'a' && input <= 'z')
		{
			output=input-32;
			printf("%c의 대문자는 %c입니다.\n",input, output);
		}
	}
	return 0;}
