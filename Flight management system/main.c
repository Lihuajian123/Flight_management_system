#include "myhead.h"      //系统函数的头文件
#include "register.h"   //账号注册登录头文件
#include "nor_fun.h"   //普通用户功能头文件
#include "nor_list.h"  //普通用户链表头文件
#include "root_list.h" //管理员链表头文件
#include "root_fun.h" //管理员功能实现头文件
#include "black.h" //黑名单
//主函数
int main()
{
    //用户链表
    struct fticke_sys *usr_list=list_init();
    //管理员链表
    struct flight_list *mylist=flist_init();
    //读取文件内容，保存对应的链表中
    read_list_to_flie(usr_list);
    read_ffile_to_list(mylist);
    //管理员链表
    while (1)
    {
        //显示登录界面
        login_inter();
        int key;
        printf("请输入选择的功能是：");
        scanf("%d",&key);
        switch (key)
        {
            case 1://普通用户登录 
                system("clear");
                key_login();
                sleep(1);
                system("clear");
                interface_nor();
                nor_funtion(usr_list,mylist);//普通用户的功能函数
                system("clear");
                break;
            case 2://管理员用户登录 
                system("clear");
                rkey_login();
                sleep(1);
                system("clear");
                //显示管理员函数
                root_funtion(mylist);//管理员用户的功能函数
                system("clear");
                break;
            case 3://普通用户注册 
                system("clear");
                register_user();
                system("clear");
                break;
            case 4://管理员用户注册
                system("clear");
                rkey_login();
            //管理员登录成功后才能进行注册管理员
                sleep(1);
                system("clear");
                register_manager();
                system("clear");
                break;
            case 0:
                break;
            default:
                break;
        }
        if(key==0)
        {
            printf("退出航班系统成功！\n");
            break;
        }
    }
    
}