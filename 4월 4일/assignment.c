#include <stdio.h>

int main() {
    int num;
    int i, count = 0;
    int binary[8];  // 8비트 저장할 배열

    // 입력 받기
    printf("0~255 사이의 숫자를 입력하세요: ");
    scanf("%d", &num);

    // 범위 확인
    if (num < 0 || num > 255) {
        printf("입력값이 범위를 벗어났습니다. 0~255 사이의 수를 입력해주세요.\n");
        return 1;
    }

    // 2진수로 변환
    for (i = 7; i >= 0; i--) {
        binary[i] = num % 2;
        if (binary[i] == 1)
            count++;
        num /= 2;
    }

    // 8비트 출력
    printf("8비트 2진수: ");
    for (i = 0; i < 8; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");

    // 1의 개수 출력
    printf("1의 개수: %d\n", count);

    // 상위 4비트 출력
    printf("상위 4비트: ");
    for (i = 0; i < 4; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}

