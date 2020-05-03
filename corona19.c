#include <stdio.h>
#include <stdlib.h>
#include "corona.h" // 구조체와 함수가 포함된 헤더파일

int main(void){
        Corona *c[100];

        int curcount = 0;
        int count = 0;
        int menu;
        int no;		
	int deleteok;

        //count = loadData(c);
        //curcount = count;

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
			count += createCorona(c[curcount++]);
                }

                else if(menu == 3){
			no = selectIndex(c, curcount);
			if(no == 0){
				printf("=> 취소됨!\n");
			}
                        else
			        updateCorona(c[no-1]);
                }

                else if(menu == 4){
			no = selectIndex(c, curcount);
			if(no == 0){
				printf("=> 취소됨!\n");
			}
			else
                                count -= deleteCorona(c[no-1]);
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

