//
//  phoneData.h
//  PhoneBook prject 2
//
//  Created by hyungwook on 2021/02/21.
//

#ifndef __PHONEDATA_H__
#define __PHONEDATA_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __phoneData
{
    char name[NAME_LEN];
    char phoneNum[PHONE_LEN];
} phoneData;

#endif
