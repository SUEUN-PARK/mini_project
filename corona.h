//CRUD mini team project
//주제: 코로나 19_국내 현황
#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
    printf("Debuging test\n");
#endif

typedef struct _corona
{
    char    name[20];       //이름
    char    gender;         //성별
    int     age;            //나이
    char    residence[20];  //거주지
    char    date[20];       //확진날짜 (20XX.XX.XX)와 같이 표시(String)
    char    hospital[20];   //격리시설
    char    domestic;       //국내 감염여부 (Y/N)
} Corona; //구조체

// 포인터 배열로 다중 데이터 처리!

#define CORONA "corona19.txt"       //데이터 저장에 사용할 파일 이름

// 메뉴 함수
int selectMenu();

// 코로나 확진자 명단 한 칸 추가
int createCorona(Corona* c);

// 코로나 확진자 명단 조회(단일 데이터)
void readCorona(Corona c);

// 코로나 확진자 명단 조회(다중 데이터) (readCorona 활용)
void listCorona(Corona* c[], int count);

// 수정, 삭제 시에 리스트를 보여주고 명단을 선택해서 return 하는 함수
int selectIndex(Corona* c[], int count);

// 코로나 확진자 명단 수정 (selectIndex 활용)
void updateCorona(Corona* c);

// 코로나 확진자 명단 삭제 (selectIndex 활용)
// 삭제 방식은 해당 memory를 free() 후 NULL
int deleteCorona(Corona* c[], int no);

// 명단 저장
void saveData(Corona* c[], int count);

// 명단 로딩
int loadData(Corona* c[]);
