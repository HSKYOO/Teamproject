#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CRUD.h"




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


int numRe = 0; 

void search(day *day){
    char sname[50]; //�� �̸�
    int mm; // ��

    printf("�ش� ���� �Է��ϼ���. ");
    scanf("%d", &mm);
    printf("���� �̸��� �Է��ϼ���. ");
    scanf("%c",&sname);
    

    // for(int i=0; i<numRe; i++){
    //     if(strcmp(list[i].name, sname) == 0)
    //     printf("%s %d %s %d %d %s %s\n", list[i].name, list[i].num_people, list[i].phone, list[i].price, list[i].check, list[i].time, list[i].notes);
    // }

    for(int i=0; i<31; i++){
        for(int j=0; j<12)
        if(strcmp(day[mm-1][i], sname) == 0)
    }
}