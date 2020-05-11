#include <stdio.h>
#include "corona.h"

// 검색 메뉴 함수, 어떤 방식으로 검색할 것인지 사용자에게 물어 return
int selectSearchMenu()
{
	int command;

	printf("\n*** 검색 항목***\n");
	printf("1. 이름\n");
	printf("2. 성별\n");
	printf("3. 나이대[10단위]\n");
	printf("4. 지역\n");
	printf("5. 확진일\n");
	printf("6. 격리시설\n");
	printf("7. 국내감염여부\n");
	printf("0. 검색 취소\n\n");
	printf("=> 검색할 항목은? ");
	scanf(" %d", &command);
	getchar();

	return command;
}

// 이름으로 검색
void searchByName(Corona* c[], int count){
	int scount = 0;
	char search[20];
	
	printf("검색할 이름? ");
	scanf(" %s", search);

	for(int i = 0; i < count; i++){

		if(c[i] != NULL){
			if(strstr(c[i]->name, search)){
				scount++;
				if(scount == 1) listContents();

				printf("%2d ", i + 1);
				readCorona(*c[i]);
			}
		}
	}
	
	if(scount == 0)
		printf("\n=> 검색된 정보가 없습니다!\n");

	printf("\n");
}

// 성별로 검색
void searchByGender(Corona* c[], int count){
	int scount = 0;
	char search;

	printf("검색할 성별(M/F)? ");
	scanf(" %c", &search);

	for(int i = 0; i < count; i++){

		if(c[i] != NULL){
			if(c[i]->gender == search){
				scount++;
				if(scount == 1) listContents();

				printf("%2d ", i + 1);
				readCorona(*c[i]);
			}
		}
	}

	if(scount == 0)
		printf("\n=> 검색된 정보가 없습니다!\n");

	printf("\n");
}

// 나이로 검색
void searchByAge(Corona* c[], int count)
{
	int scount = 0;
	int search;

	printf("검색할 나이대[10단위]? ");
	scanf(" %d", &search);

	for(int i = 0; i < count; i++){

		if(c[i] != NULL)
		{
			if(c[i]->age >= search || c[i]->age < search+10)
			{
				scount++;
				if(scount == 1) 
					listContents();

				printf("%2d ", i + 1);
				readCorona(*c[i]);
			}
		}
	}

	if(scount == 0)
		printf("\n=> 검색된 정보가 없습니다!\n");

	printf("\n");
}

// 지역으로 검색
void searchByResidence(Corona* c[], int count){
	int scount = 0;
	char search[20];

	printf("검색할 지역? ");
	scanf(" %s", search);

	for(int i = 0; i < count; i++){
		if(c[i] != NULL){
			if(strstr(c[i]->residence, search)){
				scount++;
				if(scount == 1)
					listContents();

				printf("%2d ", i + 1);
				readCorona(*c[i]);
			}
		}
	}

	if(scount == 0)
		printf("\n=> 검색된 정보가 없습니다!\n");

	printf("\n");
}

// 확진일로 검색
void searchByDate(Corona* c[], int count)
{
	int scount = 0;
	char search[20];

	printf("검색할 확진일? ");
	scanf(" %s", search);

	for(int i = 0; i < count; i++)
	{
		if(c[i] != NULL)
		{
			if(strstr(c[i]->date, search))
			{
				scount++;
				if(scount == 1)
					listContents();

				printf("%2d ", i + 1);
				readCorona(*c[i]);
			}
		}
	}

	if(scount == 0)
		printf("\n=> 검색된 정보가 없습니다!\n");

	printf("\n");
}

// 격리시설로 검색
void searchByHospital(Corona* c[], int count)
{
	int scount = 0;
	char search[20];

	printf("검색할 격리시설? ");
	scanf("%s", search);

	for(int i = 0; i < count; i++){
		if(c[i] != NULL){
			if(strstr(c[i]->hospital, search)){
				scount++;
				if(scount == 1)
					listContents();

				printf("%2d ", i + 1); 
				readCorona(*c[i]);
			}
		}
	}

	if(scount == 0)
		printf("\n=> 검색된 정보가 없습니다!\n");

	printf("\n");
}

// 국내감염여부로 검색
void searchByDomestic(Corona* c[], int count){

}
