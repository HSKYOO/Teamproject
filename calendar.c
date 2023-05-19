#include "CRUD.h"
#include "setting.h"

void drawCalendar(day calendar) {
    int mm; // ��
    printf("�� �� ���� Ķ������ ���ðڽ��ϱ�? ");
    scanf("%d", &mm);

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // �� ���� �ϼ�

    printf("     ��   ��   ȭ   ��   ��   ��   ��\n");
    printf("------------------------------------\n");

    int dayOfWeek = 0; // 0���� 6����, 0�� �Ͽ���

    for (int day = 0; day < daysInMonth[mm - 1]; day++) {
        if (dayOfWeek == 0) {
            printf(" ");
        }

        if (day + 1 < 10) {
            printf(" ");
        }

        printf("  %d", day + 1);

        if (dayOfWeek == 6) {
            printf("\n");
        }

        // ������ ���� �� ���� ��� ����� �ִ� ���·� ǥ��
        if (calendar[mm - 1][day].full == 1) {
            printf("     ");
        }

        dayOfWeek = (dayOfWeek + 1) % 7;
    }

    printf("\n");
}

