#include <stdio.h>

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
	// 구조체 선언 후 포인터 배열 정의하기
	int curcount = 0;
	int count = 0;
	int menu;

	// count, curcount 값 할당하기
	
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
			
		}

		else if(menu == 2){
			
		}
 
		else if(menu == 3){
			
		}

		else if(menu == 4){
			
		}
 
		else if(menu == 5){
			
		} 

		else if(menu == 6){
			
		} 
	}
	
	printf("종료됨!\n");

	return 0;
}
