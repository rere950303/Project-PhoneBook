//
//  phoneFunc.c
//  PhoneBook prject 1
//
//  Created by hyungwook on 2021/02/22.
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
