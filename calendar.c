#include "CRUD.h"

void printCalendar(day *day) {

    int mm; //��
    printf("��� ���� Ķ������ ���ǰǰ���?");
    scanf("�� �Է�=> %d", &mm);
    printf("+--------------------------------+\n");
    printf("|           Reservation          |\n");
    printf("+--------------------------------+\n");
    printf("| Sun | Mon | Tue | Wed | Thu | Fri | Sat |\n");
    printf("+--------------------------------+\n");

    
        for (int j = 0; j < 12; j++) {
            if (j == 0 && i < 9) {
                printf("| ");
            }

            if (day[mm]->full == 1) {
                // ���ڰ� ���� �������� ���
                printf("\033[1;30m");
            } else {
                // ���ڰ� ���� �������� ���
                printf("\033[0;37m");
            }

            printf("%3d ", i + 1); // ���� ���

            printf("\033[0m"); // ANSI �̽������� �������� ����Ͽ� �ؽ�Ʈ ������ �⺻������ ����

            if (j == 11) {
                printf("|\n");
            }
        }
    

    printf("+--------------------------------+\n");
}