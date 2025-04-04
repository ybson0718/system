#include <stdio.h>

int main() {
    int num;
    int i, count = 0;
    int binary[8];  // 8��Ʈ ������ �迭

    // �Է� �ޱ�
    printf("0~255 ������ ���ڸ� �Է��ϼ���: ");
    scanf("%d", &num);

    // ���� Ȯ��
    if (num < 0 || num > 255) {
        printf("�Է°��� ������ ������ϴ�. 0~255 ������ ���� �Է����ּ���.\n");
        return 1;
    }

    // 2������ ��ȯ
    for (i = 7; i >= 0; i--) {
        binary[i] = num % 2;
        if (binary[i] == 1)
            count++;
        num /= 2;
    }

    // 8��Ʈ ���
    printf("8��Ʈ 2����: ");
    for (i = 0; i < 8; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");

    // 1�� ���� ���
    printf("1�� ����: %d\n", count);

    // ���� 4��Ʈ ���
    printf("���� 4��Ʈ: ");
    for (i = 0; i < 4; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}

