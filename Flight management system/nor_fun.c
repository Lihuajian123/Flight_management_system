#include "nor_list.h"
//普通用户的界面选择
#include "myhead.h"
#include "root_list.h"
#include "root_fun.h"
//4.查询
int inquire_fticke(struct fticke_sys *list)
{
    char iq_message[20];
    int key=0;
    printf("请输入你要查询谁的信息：1、姓名 2、航班号：");
    scanf("%d",&key);
    printf("你要查询的信息：");
    scanf("%s",iq_message);
    switch (key)
    {
        case 1:
            printf("查询姓名成功！\n");
            inquire(iq_message,key,list);
            break;
        case 2:
            printf("查询航班号成功！\n");
            inquire(iq_message,key,list);
            break;
    default:
        printf("输入的信息有误！\n");
        break;
    }   
}
//3.修改航票信息
int Revising_ftice(struct fticke_sys *list)
{
    int flgs=0;
    char up_name[20];
    printf("你要改签票据姓名是：");
    scanf("%s",up_name);
    int key=0;
    printf("请输入你要修改的内容：1、姓名 2、航班号 3、起飞时间 4、目的地 5、座位号  6、联系方式");
    scanf("%d",&key);
    switch (key)
    {
        case 1:
            printf("修改后的姓名是：\n");
            char temp[20]={0};
            scanf("%s",temp);
            flgs=1;
            up_data(up_name,temp,key,list);
            break;
        case 2:
            printf("修改后的航班号是：\n");
            char temp1[20]={0};
            scanf("%s",temp1);
            flgs=1;
            up_data(up_name,temp1,key,list);
            break;
        case 3:
            printf("修改后的起飞时间是：\n");
            char temp2[20]={0};
            scanf("%s",temp2);
            flgs=1;
            up_data(up_name,temp2,key,list);
            break;
        case 4:
            printf("修改后的目的地是：\n");
            char temp3[20]={0};
            scanf("%s",temp3);
            flgs=1;
            up_data(up_name,temp3,key,list);
            break;
        case 5:
            printf("修改后的座位号是：\n");
            char temp4[20]={0};
            scanf("%s",temp4);
            flgs=1;
            up_data(up_name,temp4,key,list);
            break;
        case 6:
            printf("修改后的联系方式是：\n");
            char temp6[20]={0};
            scanf("%s",temp6);
            flgs=1;
            up_data(up_name,temp6,key,list);
            break;
    default:
        printf("输入的信息有误！\n");
        break;
    
    }    
    if(flgs==0)
        printf("没有找到有要修改的航票！,请重新输入\n");
} 
//显示普通用户界面
void interface_nor()
{
    printf("**************************** 用户系统 **********************************\n");
    printf("                                                                        \n");
    printf("                                                                       \n");
    printf("      1、购票                            2、查询航班信息                 \n");
    printf("      3、改签                            4、退票                        \n");
    printf("      0、退出                                                           \n");
    printf("                                                                        \n");
    printf("************************************************************************\n");
}
//普通用户的功能实现
void nor_funtion(struct fticke_sys *list,struct flight_list *mylist)
{
    while (1)
    {
        int key;
        printf("请选择你想要功能：");
        scanf("%d",&key);
        switch (key)
        {
            case 1://购票
                while (1)
                {
                    system("clear");
                    add_data(list,mylist);
                    save_list_to_file(list); 
                    save_flist_to_file(mylist); 
                    printf("是否需要继续购买：y-继续,n-退出");
                    char temp;
                    getchar();
                    scanf("%c",&temp);
                    getchar();
                    if(temp=='n')
                        break;
                }
                system("clear");
                interface_nor();
                break;
            case 2://查询
                /* while (1)
                {
                    system("clear");
                    inquire_fticke(list);
                    printf("是否需要继续查询航班: y-继续查询 n-退出查询\n");
                    char temp='0';
                    getchar();
                    scanf("%c",&temp);
                    getchar();
                    system("clear");
                    if(temp == 'n')
                        break;
                } */
                 while (1)
                {
                    system("clear");
                    printf("1、查询目前已购买的航班信息 2、索引航班信息 0、退出功能  ");
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
                                show_data(list);
                                printf("是否要退出这个界面：y-是 n-否");
                                char temp;
                                getchar();
                                scanf("%c",&temp);
                                getchar();
                                if(temp=='y')
                                    break;
                            }
                            system("clear");
                            interface_nor();
                            break;
                        case 2://索引航票信息
                        while (1)
                            {
                                system("clear");
                                inquire_fticke(list);
                                printf("是否需要继续查询航班: y-继续查询 n-退出查询\n");
                                char temp='0';
                                getchar();
                                scanf("%c",&temp);
                                getchar();
                                system("clear");
                                if(temp == 'n')
                                    break;
                            }
                            system("clear");
                            interface_nor();
                            break; 
                        case 0:
                            system("clear");
                            interface_nor();
                            break;
                        default:
                            break;
                    } 
                    if(skey==0)
                        break;
                }
                break;
            case 3://改签
                system("clear");
                while (1)
                {
                    Revising_ftice(list);
                    save_list_to_file(list); 
                    printf("是否需要继续修改: y-继续修改 n-退出修改\n");
                    char flgs='0';
                    getchar();
                    scanf("%c",&flgs);
                    getchar();
                    system("clear");
                    if(flgs == 'n')
                        break;
                }
                system("clear");
                interface_nor();
                break;
            case 4://退票
                system("clear");
                while (1)
                {
                    del_fticke(list,mylist);
                    save_list_to_file(list);
                    save_flist_to_file(mylist);
                    printf("是否需要继续退票: y-继续退票 n-退出\n");
                    char flgs='0';
                    getchar();
                    scanf("%c",&flgs);
                    getchar();
                    system("clear");
                    if(flgs == 'n')
                        break;
                }
                system("clear");
                interface_nor();
                break;
            case 0://退出功能
                printf("退出购票系统成功！\n");
                break;
        }
        if(key == 0)
            break;
    }  
}

