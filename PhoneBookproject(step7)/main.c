//
//  main.c
//  PhoneBook prject 7
//
//  Created by hyungwook on 2021/03/03.
//

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT };

int main(void)
{
    LoadDataFromFileInStruct();
    int inputMenu = 0;

    while (1)
    {
        ShowMenu();
        fputs("선택하세요 : ", stdout);
        scanf("%d", &inputMenu);
        fflush(stdin);

        switch (inputMenu)
        {
        case INPUT:
            InputPhoneData();
            break;

        case SHOWALL:
            ShowAllData();
            break;
    
        case SEARCH:
            SearchPhoneData();
            break;
                
        case DELETE:
            DeletePhoneData();
            break;
                
        case CHANGE:
            ChangePhoneData();
            break;
        }

        if (inputMenu == QUIT)
        {
            puts("이용해 주셔서 고마워요~");
            StoreDataToFileInStruct();
            break;
        }
    }
    return 0;
}
