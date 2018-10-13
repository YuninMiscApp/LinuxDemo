/**
  ******************************************************************************
  * @file main.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2018-10-6 11:07:03
  * @brief  This file provides all the main functions. 
  ******************************************************************************
  * @attention
  *
  * File For Yunin Software Team Only
  *
  * Copyright (C), 2017-2027, Yunin Software Team
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include<stdlib.h>

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
struct student_type
{
int num;
char name[10];
char addr[15];
}student={1001,"liangbin","yuanchunroad"};
FILE *fp;
void save()
{
if((fp=fopen("stu.dat","wb"))==NULL)
{
printf("can not open file\n");
return;
}
if(fwrite(&student,sizeof(struct student_type),1,fp)!=1)
	printf("file write error\n");
fclose(fp);
}
void print_file()
{
if((fp=fopen("stu.dat","rb"))==NULL)
{
 printf("can not open file\n");
 exit(0);
}
fread(&student,sizeof(struct student_type),1,fp);
printf("%d,%s,%s",student.num,student.name,student.addr);
fclose (fp);
}



int main(int argc, char *argv[])
{
save();
print_file();
return 0;
}


#ifdef  __cplusplus
}
#endif


