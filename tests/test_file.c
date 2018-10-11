/**
  ******************************************************************************
  * @file test_file.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2018-10-6 11:10:44
  * @brief  This file provides all the test_file functions. 
  ******************************************************************************
  * @attention
  *
  * File For Yunin Software Team Only
  *
  * Copyright (C), 2017-2027, Yunin Software Team
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <string.h>

#include "file.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

typedef struct student_info_s{
	int age;
	char name[128];
	int level;
}student_info_t;

int main(int argc, char *argv[])
{
	student_info_t s;
	memset(&s,0,sizeof(s));
	s.age = 10;
	strncpy(s.name,"peter",sizeof(s.name));
	s.level = 6;

	file_write("./students.bin",&s,sizeof(s));

	//
	memset(&s,0,sizeof(s));

	file_read("./students.bin",&s,sizeof(s));

	printf("name: %s , age: %d ,level : %d\n",
	s.name,s.age,s.level);
	
	return 0;
}


#ifdef  __cplusplus
}
#endif


