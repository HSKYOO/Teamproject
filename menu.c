#include "setting.h"

struct Menu{ 
    char foodName[SIZE];    //���� �̸�
    int foodPrice;          //���� ����
    int count;              //���� �ȸ� Ƚ�� --> ���� ���� �м� �� ���           
};

typedef struct Menu ChickenSkewer;
typedef struct Menu Ramen;
typedef struct Menu Gimbob;
typedef struct Menu Tteokbokki;

// ChickenSkewer | Ramen | Gimbob | Tteokbokki
