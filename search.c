#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CRUD.h"

void search(day *day){
    char sname[50]; //�� �̸�
    int mm; // ��
    int dd; //��

    printf("��¥�� �Է��ϼ���. ");
    scanf("%d", &mm, &dd);
    printf("���� �̸��� �Է��ϼ���. ");
    scanf("%c",&sname);
    printf("���� ��ȭ���θ� �Է��ϼ���. ");
    
    

    for(int i=0; i<16; i++){
        for(int j=0; j<12; i++){
        if(strcmp(day[mm-1][dd-1]->table[i]->customer[j]->name, sname) == 0)
        printf("%s %d %d %d %d\n", day[mm-1][dd-1]->table[i]->customer[j]->name, day[mm-1][dd-1]->table[i]->customer[j]->people, day[mm-1][dd-1]->table[i]->customer[j]->phoneNum, day[mm-1][dd-1]->table[i]->customer[j]->price,day[mm-1][dd-1]->table[i]->customer[j]->isPaid);
        }
    }
}