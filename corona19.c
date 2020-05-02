#include <stdio.h>
#include "corona.h" // 구조체와 함수가 포함된 헤더파일

int selectMenu(){

        int menu;

        printf("\n*** Corona-19 ***\n");
        printf("1. 확진자조회\n");
        printf("2. 확진자추가\n");
        printf("3. 확진자수정\n");
        printf("4. 확진자삭제\n");
        printf("5. 파일저장\n");
        printf("6. 확진자검색\n");
        printf("0. 종료\n\n");

        printf("=> 원하는 기능은? ");

        scanf("%d", &menu);

        return menu;
}

int main(void){
        Corona *c[100];

        int curcount = 0;
        int count = 0;
        int menu;

        while(1) {
                menu = selectMenu();

                if(menu == 0) break;

                if(menu == 1 || menu == 3 || menu == 4 || menu == 6){
                        if(count == 0){
                                printf("데이터가 없습니다!\n");
                                continue;
                        }
                }

                if(menu == 1){
			listCorona(c, curcount); // 코로나 확진자 명단 조회
                }

                else if(menu == 2){
			c[curcount] = (Corona *)malloc(sizeof(Corona));
			// return 1을 하여 count갑슬 올리고자함
			// createCorona의 반환형을 void -> int 로 변경 
			count += createCorona(cp[curcount++]);
                }

                else if(menu == 3){
			int no = selectIndex(c, curcount);
			if(no == 0){
				printf("=> 취소됨!\n");
				continue;
			}
			updateCorona(c[no-1]);
                }

                else if(menu == 4){

			int no = selectIndex(c, curcount);
			if(no == 0){
				printf("=> 취소됨!\n");
				continue;
			}

			int deleteok;
			printf("정말로 삭제하시겠습니까? (삭제:1) ");
			scanf(" %d", &deleteok);

			if(deleteok == 1){
				// deleteCorona() 함수 구현
				if(c[no-1]) free(c[no-1]);
				c[no-1] = NULL;
				count--;
				printf("=> 삭제됨!\n");
			}
			else{
				printf("=> 취소됨!\n");
				continue;
			}
                }

                else if(menu == 5){
			saveData(c, curcount);
                }

                else if(menu == 6){
			
                }
        }

        printf("종료됨!\n");

        return 0;
}

