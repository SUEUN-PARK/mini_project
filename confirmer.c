#include <stdio.h>
#include "corona.h"

// 코로나 확진자 명단 한 칸 추가
int createCorona(Corona* c)
{
    printf("이름 : ");
    scanf("%s", c->name);

    printf("나이 : ");
    scanf("%d", &c->date);

    printf("성별[M/F] : ");
    scanf("%c", &c->age);

    printf("거주지 : ");
    scnaf("%s", c->residence);

    printf("확진날짜 : ");
    scanf("%s", c->date);

    printf("격리시설 : ");
    scanf("%[^\n]s", c->hospital);

    printf("국내감염[Y/N] : ");
    scanf("%c", &c->domestic);

    printf("\n=> 추가 성공!\n");
    return 1;
}