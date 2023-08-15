#ifndef _NOR_LIST_H
#define _NOR_LIST_H
#include "root_list.h"
//购票结构体-定义
struct Buy_tickets
{
    char name[20];           //乘客姓名
    char telephone[20];     //联系方式
    char flight_number[16];  //航班号
    char Seat_Number[16];    //座位号
    char departure[32];      //出发地
    char destination[32];    //目的地
    char take_off_time[16];  //起飞时间
    char arrival_time[16];   //到达时间
    int buy_num;              //购票数量
    char buy_time[20];        //购票时间
};
//普通人-购票系统
struct fticke_sys
{
    struct Buy_tickets tickes;//数据域，存放的数据内容
    struct fticke_sys *prev;//指针域，存放上一个数据的地址
    struct fticke_sys *next;//指针域，存放下一个数据的地址
};
//函数声明
//获取当前时间
char *get_time();
//初始化(头节点)
struct fticke_sys *list_init();
//申请节点-购票结构体节点
struct fticke_sys *node();
//添加数据-购票
int add_data(struct fticke_sys *list,struct flight_list *mylist);
//修改数据 - 改签 - 》 修改飞行时间、目的地、航班号
int up_data(char *up_name,void *newdata,int key,struct fticke_sys *list);
//删除数据-退票
int del_data(char *update_name,struct fticke_sys *list);
//退票
int del_fticke(struct fticke_sys *list,struct flight_list *mylist);
//查询购买的航票信息 
int inquire(char *Name,int key,struct fticke_sys *list);
//打印数据
int show_data(struct fticke_sys *list);
//将文件的内容保存进链表中
void read_list_to_flie(struct fticke_sys *list); 
//文件内容保存链表
void fticke_add_tail(char *name,char *telephone,char *flight_number,char *Seat_Number,char *departure,char *destination,char *take_off_time,\
                                char *arrival_time,int buy_num,char *buy_time,struct fticke_sys *list);
//将信息写入txt文件中保存
void save_list_to_file(struct fticke_sys *list);
#endif