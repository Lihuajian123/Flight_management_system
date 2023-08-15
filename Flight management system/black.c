#include <stdio.h>
#include <string.h>

// 设置黑名单的函数
void Set_blacklist()
{
    FILE *file = fopen("blacklist.txt", "a+");
    
    if (file == NULL)
    {
        printf("无法打开黑名单文件\n");
        return;
    }
    
    char name[20] = {0};
    printf("请输入要加入黑名单的用户名：");
    scanf("%s", name);
    
    // 写入黑名单
    fprintf(file, "%s\n", name);
    fflush(file);
    fclose(file);
    
    printf("已成功添加黑名单\n");
}

// 取消黑名单的函数
void re_blacklist()
{
    FILE *file = fopen("blacklist.txt", "r");
    
    if (file == NULL)
    {
        printf("无法打开黑名单文件\n");
        return;
    }
    
    char name[20] = {0};
    printf("请输入要取消黑名单的用户名：");
    scanf("%s", name);
    
    FILE *tempFile = fopen("temp_blacklist.txt", "w");
    
    if (tempFile == NULL)
    {
        printf("无法创建临时文件\n");
        fclose(file);
        return;
    }
    
    char currentName[20] = {0};
    int found = 0;//标志位
    
    while (fgets(currentName, sizeof(currentName), file) != NULL)
    {
        currentName[strcspn(currentName, "\n")] = '\0';
        
        if (strcmp(currentName, name) == 0)
        {
            found = 1;//找到了要取消的用户名
        }
        else
        {
            fprintf(tempFile, "%s\n", currentName);//不是的，就写入临时黑名单中
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    if (!found)
    {
        printf("未找到要取消的用户名\n");
        remove("temp_blacklist.txt");//删除文件
        return;
    }
    
    remove("blacklist.txt");//删除原来黑名单文件
    rename("temp_blacklist.txt", "blacklist.txt");//临时黑名单重命名为黑名单的txt文件名
    
    printf("已成功取消黑名单\n");
}
// 检查用户名是否在黑名单中
int is_in_blacklist(const char *username) 
{
    FILE *file = fopen("blacklist.txt", "r");
    if (file == NULL) {
        printf("无法打开黑名单文件\n");
        return 0; // 假设黑名单文件不存在
    }

    char currentName[20];
    while (fgets(currentName, sizeof(currentName), file) != NULL) //分行读取比较
    {
        currentName[strcspn(currentName, "\n")] = '\0';//最后一位\n换位\0
        if (strcmp(currentName, username) == 0) 
        {
            fclose(file);
            return 1; // 找到用户名在黑名单中
        }
    }

    fclose(file);
    return 0; // 用户名不在黑名单中
}
/* int main()
{
    int ret=is_in_blacklist("liejiajie");
    if(ret==1)
    {
        printf("存在\n");
    }
    return 0;
} */