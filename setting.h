#ifndef SETTING_H
#define SETTING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

int count = 0; // �� ���� ����


struct CUSTOMER{
    char name[SIZE];
    int people;
    int phoneNum;
    int price;
    int isPaid;
    char time[SIZE];
    char Menu[SIZE];
    char extra[SIZE]; 
    
    int nop;
};

struct Table{
    int s_index; //0�̸� ���¼� 1�̸� ������ �� �¼�
  //  int time[12] = {0}; // �ð�: 12���� ĭ���� �������� ����
  //  char order[100]; // �ֹ�
    struct CUSTOMER *customer[12]; // CUSTOMER ����ü ������  12���� �ð����� �ɰ��� ����
};

typedef struct Day{
    struct Table *table[16];
    int full; // �� ���� ������ �� ���� 1�� �ٲ�.
} day[12][31];

typedef struct Table tableForm[SIZE];
typedef struct CUSTOMER customer[SIZE];
typedef struct Day day[12][31];

#endif
