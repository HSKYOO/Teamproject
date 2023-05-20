#include "setting.h"

//day [0][0] ~ [11][30] ���� 1���� ����
//day �ȿ� customer[0] ~ customer[11]���� 1���� ����
//���� customer[n]�� �մ��� customer[n+1]�� �����ϴٸ� customer[n+2]�� �Ѿ��
//customer[n]�� ������ �մ��� price ������ ���δ��ϱ�
//�ش� ������ ���� �׷����� ����� (1���� ����)

void calProfit(day *day){
    int month = 0;
    //�ּ���(�� ����)
    int w1_profit = 0;  //1��
    int w2_profit = 0;  //2��
    int w3_profit = 0;  //3��
    int w4_profit = 0;  //4��
    int w5_profit = 0;  //5��

    printf("Ȯ���ϰ� ���� ���� �Է��ϼ���: ");
    scanf("%d", &month);

    for(int j = 0; j < 7; j++){
        //���� customer[n]�� �մ��� customer[n+1]�� �����ϴٸ� customer[n+2]�� �Ѿ��(continue)
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(m > 0 && strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }

    for(int j = 7; j < 14; j++){
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }

    for(int j = 14; j < 21; j++){
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }

    for(int j = 21; j < 28; j++){
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }

    for(int j = 28; j < 31; j++){
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }
}

void showGraph(day day) {
    int month;
    printf("Ȯ���ϰ� ���� ���� �Է��ϼ���: ");
    scanf("%d", &month);
    printf("%d�� ���� ���� (����: ����)\n", month);

    // ���� ���� �׷��� ���
    int weekly_profit[5] = {0};  // �ֺ� ���� �迭 �ʱ�ȭ

    for (int j = 0; j < 31; j++) {
        // �ش� ���� ���� ���
        int week = j / 7;

        // ���� �մ��� �������� ������ ��� �ǳʶٱ�
        for (int n = 0; n < 16; n++) {
            for (int m = 0; m < 11; m++) {
                if (strcmp(day[month][j].table[n]->customer[m], day[month][j].table[n]->customer[m + 1]) == 0) {
                    m++;  // ���� �մ����� �ǳʶٱ�
                } else {
                    weekly_profit[week] += day[month][j].table[n]->customer[m]->price;
                }
            }
        }
    }

    // �׷��� ���
    for (int i = 0; i < 5; i++) {
        printf("���� %d |", i + 1);
        for (int j = 0; j < weekly_profit[i]; j += 10000) {     //���� ����
            printf("��");
        }
        printf("|");
        printf(" %d\n", weekly_profit[i]);
    }
}

