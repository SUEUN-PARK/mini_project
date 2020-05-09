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

        count = loadData(c);
        curcount = count;

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
			int more;
			int choice = 0;
			no = selectIndex(c, curcount);
			if(no == 0){
				printf("=> 취소됨!\n");
			}
                        else{
			        do{
					choice = updateCorona(c[no-1]);

					if(choice == 0) break; 
                                        do
                                        {
					        printf("\n%d번 내역을 추가수정하시겠습니까?\n수정(1) | 종료(0): ", no);
					        scanf(" %d", &more);

                                                if(!(more == 1 || more == 0))
                                                {
                                                        printf("Error: 잘못된 입력!\n");
                                                        continue;
                                                }
                                        }while(more !=0 );

                                        if(more == 0)
                                                break;

				}while(choice != 8);
				
                	}
		}

                else if(menu == 4){
			no = selectIndex(c, curcount);
			if(no == 0){
				printf("=> 취소됨!\n");
			}
			else
                                count -= deleteCorona(c, no-1);
                }

                else if(menu == 5){
			saveData(c, curcount);
                }

                else if(menu == 6){
			int choice;
			do{
				no = selectSearchMenu();
                        	switch(no)
                        	{
                        	case 0:
                                	printf("검색 취소!\n");
                                	break;
                       	 	case 1: 
                                	searchByName(c, curcount);
                                	break;
                        	case 2: 
                        	        searchByGender(c, curcount);
                        	        break;
                        	case 3: 
                               	 	searchByAge(c, curcount);
                                	break;
                        	case 4: 
                                	searchByResidence(c, curcount);
                                	break;
                        	case 5: 
                                	searchByDate(c, curcount);
                                	break;
                        	case 6: 
                                	searchByHospital(c, curcount);
                               	 	break;
                        	case 7: 
                        	        searchByDomestic(c, curcount);
                        	        break;
                        	default:
                        	        printf("Error : 잘못된 입력!\n");
                        	        break;
                        	}
				
				printf("추가 검색 하시겠습니까(Yes:1 | No:0)? ");
				scanf(" %d", &choice);

			}while(choice == 1);
                }
        }

        printf("종료됨!\n");

        return 0;
}

