#include <stdio.h>
#include "corona.h"

// 코로나 확진자 명단 조회(다중 데이터) (readCorona 활용)
void listCorona(Corona* c[], int count){
	printf("\nNo 지역 이름 성별 나이 확진일 격리시설 감염경로(국내: Y)\n");
	printf("========================================================\n");

	for(int i = 0; i < count; i++){
		if(c[i] != NULL){
			printf("%2d ", i+1);
			readCorona(*c[i]);
		}
	}
	
	printf("\n");
}

// 수정, 삭제 시에 리스트를 보여주고 명단을 선택해서 return 하는 함수
int selectIndex(Corona* c[], int count){ }
