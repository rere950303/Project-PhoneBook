//
//  phoneFunc.c
//  PhoneBook prject 3
//
//  Created by hyungwook on 2021/02/21.
//

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM   100

int numOfData = 0;
phoneData *phoneList[LIST_NUM];

void InputPhoneData(void)
{
    if (numOfData >= LIST_NUM)
        printf("메모리 공간이 부족합니다.");
    else
    {
        phoneList[numOfData] = malloc(sizeof(phoneData) * 1);
        printf("이름을 입력하세요:");
        scanf("%s", phoneList[numOfData]->name);
        printf("번호을 입력하세요:");
        scanf("%s", phoneList[numOfData]->phoneNum);
        
        for(int i = 0; i < numOfData; i++)
        {
            if(!strcmp(phoneList[numOfData]->name, phoneList[i]->name) && !strcmp(phoneList[numOfData]->phoneNum, phoneList[i]->phoneNum))
            {
                printf("이미 입력된 데이터입니다.\n");
                free(phoneList[numOfData]);
                return;
            }
        }
        printf("입력이 완료되었습니다.\n");
        numOfData++;
    }
}

void ShowAllData(void)
{
    for (int i = 0; i < numOfData; i++)
    ShowPhoneInfoByPtr(phoneList[i]);
}

void SearchPhoneData(void)
{
    int count = 0;
    char s[NAME_LEN] = "";
    
    printf("찾는 이름은? ");
    scanf("%s", s);
    
    for(int i = 0; i < numOfData; i++)
    {
        if(strcmp(phoneList[i]->name, s) == 0)
        {
            ShowPhoneInfoByPtr(phoneList[i]);
            count++;
        }
    }
    
    if(count != 0)
        printf("검색이 완료되었습니다.\n");
    
    else if(count == 0)
        printf("찾는 이름의 데이터가 없습니다.\n");
}

void DeletePhoneData(void)
{
    int arr[LIST_NUM] = {0};
    int count = 0;
    int n = 0;
    char s[NAME_LEN] = "";
    int select = 0;
    
    printf("찾는 이름은? ");
    scanf("%s", s);
    
    for(int i = 0; i < numOfData; i++)
    {
        if(!strcmp(phoneList[i]->name, s))
        {
            count++;
            arr[n] = i;
            n++;
        }
    }
    
    if(count == 0)
    {
        printf("찾는 이름의 데이터가 없습니다.\n");
        return;
    }
    
    else if(count == 1)
    {
        free(phoneList[arr[0]]);
        for(int j = arr[0]; j < numOfData - 1; j++)
        {
            phoneList[j] = phoneList[j + 1];
        }
        numOfData--;
        printf("삭제가 완료되었습니다.\n");
        return;
    }
    
    else if(count >= 2)
    {
        for(int i = 0; i < n; i++)
        {
            printf("NUM %d\n", i + 1);
            ShowPhoneInfoByPtr(phoneList[arr[i]]);
        }
        printf("선택: ");
        scanf("%d", &select);
        free(phoneList[arr[select - 1]]);
        for(int j = arr[select - 1]; j < numOfData - 1; j++)
        {
            phoneList[j] = phoneList[j + 1];
        }
        numOfData--;
        printf("삭제가 완료되었습니다.\n");
        return;
    }
}

void StoreDataToFile(void)
{
    FILE *fp = fopen("PhoneData.txt", "w");
    
    if(fp == NULL)
    {
        printf("데이터를 저장할 수 없습니다.\n");
        return;
    }
    
    else
    {
        fprintf(fp, "%d\n", numOfData);
        for(int i = 0; i < numOfData; i++)
        {
            fprintf(fp, "%s\n%s\n", phoneList[i]->name, phoneList[i]->phoneNum);
            free(phoneList[i]);
        }
    }
    
    fclose(fp);
}

void LoadDataFromFile(void)
{
    FILE *fp = fopen("PhoneData.txt", "r");
    
    fscanf(fp, "%d", &numOfData);
    
    if(fp == NULL)
    {
        printf("데이터를 복사할 수 없습니다.\n");
        return;
    }
    
    else
    {
        for(int i = 0; i < numOfData; i++)
        {
            phoneList[i] = malloc(sizeof(phoneData));
            fgets(phoneList[i]->name, NAME_LEN, fp);
            phoneList[i]->name[strlen(phoneList[i]->name) - 1] = '\0';
            fgets(phoneList[i]->phoneNum, NAME_LEN, fp);
            phoneList[i]->name[strlen(phoneList[i]->phoneNum) - 1] = '\0';
        }
    }
    
    fclose(fp);
}
