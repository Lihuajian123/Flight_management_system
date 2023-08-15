#include "root_list.h"
#include "black.h"
//#include "nor_fun.h"
//#include "nor_list.h"
#include "myhead.h"
// 管理员登录界面
void root_screen()
{
    printf("**************************** 管理员系统 **********************************\n");
    printf("                                                                        \n");
    printf("                                                                       \n");
    printf("      1、修改航班信息                     2、查询航班信息                 \n");
    printf("      3、增加黑名单/取消黑名单             4、增加航班                     \n");
    printf("      0、退出管理员系统                                                  \n");
    printf("************************************************************************\n");
}
//管理员功能函数
int root_funtion(struct flight_list *list)
{
    root_screen();
    while (1)
    {
       int key;
       printf("请输入要选择的功能：");
       scanf("%d",&key);
       switch (key)
       {
            case 1://修改信息
                while (1)
                {
                   system("clear");
                    printf("1、修改航班信息   2、取消航班   0、退出");
                    int skey;
                    printf("请输入要选择的功能：");
                    scanf("%d",&skey);
                    switch (skey)
                    {
                        case 1://修改航班信息
                            while (1)
                            {
                                system("clear");
                                Revising_flight(list);
                                save_flist_to_file(list);
                                printf("是否要继续修改信息：y-是 n-否");
                                char temp;
                                getchar();
                                scanf("%c",&temp);
                                getchar();
                                if(temp=='n')
                                    break;
                            }
                            system("clear");
                            root_screen();
                            break;
                        case 2://取消航班信息
                        while (1)
                            {
                                system("clear");
                                del_flight(list);
                                save_flist_to_file(list);
                                printf("是否要继续取消航班：y-是 n-否");
                                char temp;
                                getchar();
                                scanf("%c",&temp);
                                getchar();
                                if(temp=='n')
                                    break;
                            }
                            system("clear");
                            root_screen();
                            break; 
                        case 0:
                            system("clear");
                            root_screen();
                            break;
                        default:
                            break;
                    } 
                    if(skey==0)
                        break;
                }
                break;
            case 4://增加航班信息
                while (1)
                {
                    system("clear");
                    flist_add(list);
                    printf("增加航班成功！\n");
                    save_flist_to_file(list); 
                    printf("是否需要继续购买：y-继续,n-退出");
                    char temp;
                    getchar();
                    scanf("%c",&temp);
                    getchar();
                    if(temp=='n')
                        break;
                }
                system("clear");
                root_screen();
                break;
            case 2://查询航班信息
                //可以查乘坐这个航班的全部乘客
                while (1)
                {
                    system("clear");
                    printf("1、查询目前在线的航班信息 2、索引航班信息 0、退出功能  ");
                    int skey;
                    printf("\n请输入要选择的功能：");
                    scanf("%d",&skey);
                    switch (skey)
                    {
                        case 1://查看全部航班信息
                            while (1)
                            {
                                system("clear");
                                //查看全部航班信息
                                flist_show(list);
                                printf("是否要退出这个界面：y-是 n-否");
                                char temp;
                                getchar();
                                scanf("%c",&temp);
                                getchar();
                                if(temp=='y')
                                    break;
                            }
                            system("clear");
                            root_screen();
                            break;
                        case 2://索引航班信息
                        while (1)
                            {
                                system("clear");
                                //查询一个航班信息
                                inquire_flights(list);
                                printf("是否要继续索引航班信息：y-是 n-否");
                                char temp;
                                getchar();
                                scanf("%c",&temp);
                                getchar();
                                if(temp=='n')
                                    break;
                            }
                            system("clear");
                            root_screen();
                            break; 
                        case 0:
                            system("clear");
                            root_screen();
                            break;
                        default:
                            break;
                    } 
                    if(skey==0)
                        break;
                }
                
                break;
            case 3://设置黑/白名单
                while (1)
                {
                    system("clear");
                    printf("1、增加黑名单   2、取消黑名单   0、退出  ");
                    int skey;
                    printf("\n请输入要选择的功能：");
                    scanf("%d",&skey);
                    switch (skey)
                    {
                        case 1://增加黑名单
                            while (1)
                            {
                                system("clear");
                                Set_blacklist();
                                printf("是否要继续增加黑名单：y-是 n-否");
                                char temp;
                                getchar();
                                scanf("%c",&temp);
                                getchar();
                                if(temp=='n')
                                    break;
                            }
                            system("clear");
                            root_screen();
                            break;
                        case 2://取消黑名单
                            while (1)
                            {
                                system("clear");
                                re_blacklist();
                                printf("是否要继续取消黑名单：y-是 n-否");
                                char temp;
                                getchar();
                                scanf("%c",&temp);
                                getchar();
                                if(temp=='n')
                                    break;
                            }
                            system("clear");
                            root_screen();
                            break; 
                        case 0:
                            system("clear");
                            root_screen();
                            break;
                        default:
                            break;
                    } 
                    if(skey==0)
                        break;
                }
                break;
            case 0://退出
                break;
       }
    if(key == 0)
        break;
    }
}
/* int main()
{
    struct flight_list *mylist=flist_init();
    read_file_to_list(mylist);
    root_funtion(mylist);
} */