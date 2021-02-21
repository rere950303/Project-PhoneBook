//
//  phoneFunc.c
//  PhoneBook prject 2
//
//  Created by hyungwook on 2021/02/21.
//

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM   100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

void InputPhoneData(void)
{
    if (numOfData >= LIST_NUM)
        printf("메모리 공간이 부족합니다.");
    else
    {
        printf("이름을 입력하세요:");
        scanf("%s", phoneList[numOfData].name);
        printf("번호을 입력하세요:");
        scanf("%s", phoneList[numOfData].phoneNum);
        numOfData++;
    }
}

void ShowAllData(void)
{
    for (int i = 0; i < numOfData; i++)
        ShowPhoneInfo(phoneList[i]);
}

void SearchPhoneData(void)
{
    char s[NAME_LEN] = "";
    printf("찾는 이름은? ");
    scanf("%s", s);
    
    for(int i = 0; i < numOfData; i++)
    {
        if(strcmp(phoneList[i].name, s) == 0)
        {
            ShowPhoneInfo(phoneList[i]);
            printf("검색이 완료되었습니다.\n");
            return;
        }
    }
    
    printf("찾는 이름의 데이터가 없습니다.\n");

}

void DeletePhoneData(void)
{
    char s[NAME_LEN] = "";
    printf("찾는 이름은? ");
    scanf("%s", s);
    
    for(int i = 0; i < numOfData; i++)
    {
        if(strcmp(phoneList[i].name, s) == 0)
        {
            for(int j = i; j < numOfData - 1; j++)
        {
            phoneList[j] = phoneList[j + 1];
        }
            numOfData--;
            printf("삭제가 완료되었습니다.\n");
        }
    }
    
    printf("찾는 이름의 데이터가 없습니다.\n");

}
