#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 100

typedef struct main
{
    char person[STR_LEN];
    char format;
    char numbers[STR_LEN];
    char email[STR_LEN];
} LIST;


void look(int n , LIST s[] , char choice1);
void add(LIST *s , int *p);
void correct();
void delete();

int main()
{
    LIST temp[STR_LEN];
    int choice = -1;
    int peo_num = 0;
    int *p = &peo_num;
    printf("欢迎使用手机通讯录管理程序!\n");

    while(choice)
    {
        printf("请选择您要选择的服务类型:\n");
        printf("1.查看已有联系人\n2.添加联系人\n3.修改联系人\n4.删除联系人\n如果您想退出程序,请按“0”\n请在此输入您想要的操作:");
    
        scanf("%d",&choice);
        
        char choice1;

        switch (choice)
        {
        case 1:  
            scanf("%c",&choice1);
            look(peo_num,temp,choice1);
            break;
        case 2:
            add(temp,p);
            break;
        case 3:
            correct;
            break;
        case 4:
            delete;
            break;
        case 0:
            return 0;
        default:
            printf("前面的区域，以后再来探索吧~");
            break;
        }
    }
}

/*void look(int n,LIST s[],char choice1)
{
    FILE *fp = fopen("people.dat","r");
    if(fp == NULL)
    {
        printf("通讯录数据读取失败！\n");
        exit(0);
    }

    if(feof)
        printf("您还未添加任何联系人\n");
    
    int i = 0;
    while(i < n)
    {
        fscanf(fp,"%s %s %c %s",s[i].person[i],s[i].numbers,s[i].format,s[i].email);
        printf("%s %s",s[i].person,s[i].numbers);

        /*为了输入既可以输大写又可以输小写*/
        /*if(s[i].format >= 'a' && s[i].format <= 'c')
        {
            s[i].format -= 32;
        }

        switch (s[i].format)
        {
        case 'A':
            printf(" 办公类");
            break;
        case 'B':
            printf(" 个人类");
            break;
        case 'C':
            printf(" 商务类");
            break;
        }

        printf(" %s",s[i].email);
    }
}*/

void look(int n , LIST s[] , char choice1)
{
    FILE *fp = fopen("people.dat","r");
    if(fp == NULL)
    {
        printf("通讯录数据读取失败！\n");
        exit(0);
    }

    long int now = ftell(fp);
    if(now == 0)
        printf("您还未添加任何联系人\n");

    if(choice1 >= 'a' && choice1 <= 'c')
    {
        choice1 -= 32;
    }

    int i = 0;
    while(i < n)
    {
        fscanf(fp,"%s %s %c %s",s[i].person[i],s[i].numbers,s[i].format,s[i].email);
        if(s[i].format == choice1)
        {
            printf("%s %s",s[i].person,s[i].numbers);

            /*为了输入既可以输大写又可以输小写*/
            if(s[i].format >= 'a' && s[i].format <= 'c')
            {
                s[i].format -= 32;
            }

            switch (s[i].format)
            {
            case 'A':
                printf(" 办公类");
                break;
            case 'B':
                printf(" 个人类");
                break;
            case 'C':
                printf(" 商务类");
                break;
            }

            printf(" %s",s[i].email);
        }
    }

    int a = fclose(fp);
    if(a)
    {
        printf("啊哦，好像出了点状况导致我们没有正确关闭储存文件呢。。。");
        exit(0);
    }
}

void add(LIST s[] , int *p)
{
    FILE *fp = fopen("people.dat","a");
    if(fp == NULL)
    {
        printf("哎呀！信息文件出了问题，读入初始化失败！");
        exit(0);
    }

    printf("请输入联系人姓名：");
    scanf(" ");
    fgets(s[*p].person,STR_LEN,stdin);
    printf("请输入联系人电话：");
    scanf(" ");
    fgets(s[*p].numbers,STR_LEN,stdin);
    printf("请输入联系人所属分类：");
    scanf(" ");
    char sp[STR_LEN];
    fgets(sp,STR_LEN,stdin);
    if(strcmp(sp ,"办公类\n") == 0)
        s[*p].format = 'A';
    else if(strcmp(sp,"个人类\n") == 0)
        s[*p].format = 'B';
    else if(strcmp(sp,"商务类\n") == 0)
        s[*p].format = 'C';
    
    printf("请输入联系人的邮箱地址：");
    scanf(" ");
    fgets(s[*p].email,STR_LEN,stdin);
    
    fprintf(fp,"%s %s %c %s",s[*p].person,s[*p].numbers,s[*p].format,s[*p].email);
    *p ++;

    int a = fclose(fp);
    if(a)
    {
        printf("啊哦，好像储存文件出了点问题。。。\n");
        exit(0);
    }
}