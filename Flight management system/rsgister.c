#include "myhead.h"
//主登录界面
void login_inter()
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~航班管理系统~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                                                           \n");
    printf("      1.普通用户登录                   2.管理员登录           \n");
    printf("      3.普通用户注册                   4.管理员注册           \n");
    printf("      0.退出系统                                             \n");
    printf("                                                             \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
//管理员注册
void register_manager()
{
    FILE *file = fopen("key.txt", "a+");
    if (file == NULL)
    {
        printf("无法打开密码文件\n");
        return;
    }
    char name[20] = {0};
    char key[20] = {0};
    printf("请输入要注册管理员账号的用户名：");
    scanf("%s", name);
    printf("请输入密码：");
    scanf("%s", key);
    char temp[40] = {0};
    sprintf(temp, "%s#%s\n", name, key);
    //写入文件中
    fprintf(file, "%s", temp);  // 将数据写入文件
    fclose(file); // 关闭文件
    
    printf("管理员账号注册成功\n");
}
//用户注册
void register_user()
{
    FILE *file = fopen("key.txt", "a+");
    if (file == NULL)
    {
        printf("无法打开密码文件\n");
        return;
    }
    char name[20] = {0};
    char key[20] = {0};
    printf("请输入要注册账号的用户名：");
    scanf("%s", name);
    printf("请输入密码：");
    scanf("%s", key);
    char temp[40] = {0};
    sprintf(temp, "%s@%s\n", name, key);
    //写入文件中
    fprintf(file, "%s", temp);  // 将数据写入文件
    fclose(file); // 关闭文件
    
    printf("账号注册成功\n");
}
//密码登录-管理员登录
void rkey_login()
{
    while (1)
    {
        FILE *file = fopen("key.txt", "r");
        if (file == NULL)
        {
            printf("无法打开密码文件\n");
            return;
        }
        
        char name[20] = {0};
        char key[20] = {0};
        printf("请输入管理员账号的用户名：");
        scanf("%s", name);
        printf("请输入密码：");
        scanf("%s", key);

        char temp[40] = {0};
        sprintf(temp, "%s#%s\n", name, key);
        int found = 0; //标志位
        char temp1[40] = {0};
        while (fgets(temp1, sizeof(temp1), file) != NULL)
        {
            if (strcmp(temp1, temp) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(file); //关闭文件
        if (found)
        {
            printf("登录成功\n");
            break;
        }     
        else
            printf("登录失败，请重新输入\n");
    }
    
}
//密码登录-用户登录
void key_login()
{
    while (1)
    {
        FILE *file = fopen("key.txt", "r");
        if (file == NULL)
        {
            printf("无法打开密码文件\n");
            return;
        }
        
        char name[20] = {0};
        char key[20] = {0};
        printf("请输入用户名：");
        scanf("%s", name);
        printf("请输入密码：");
        scanf("%s", key);

        char temp[40] = {0};
        sprintf(temp, "%s@%s\n", name, key);
        int found = 0; //标志位
        char temp1[40] = {0};
        while (fgets(temp1, sizeof(temp1), file) != NULL)
        {
            if (strcmp(temp1, temp) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(file); //关闭文件
        if (found)
        {
            printf("登录成功\n");
            break;
        }     
        else
            printf("登录失败，请重新输入\n");
    }
    
    
}