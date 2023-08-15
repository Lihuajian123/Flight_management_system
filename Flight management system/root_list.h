#ifndef _ROOT_LIST_H
#define _ROOT_LIST_H

// 航班信息结构体
struct flight
{
    char flight_number[16]; //航班号
    char departure[32];     //出发地
    char destination[32];   //目的地
    char take_off_time[16]; //起飞时间
    char arrival_time[16];  //到达时间
    float price;            //价格
    int num;                //票的数量
};
//定义双向链表(系统管理员的)
struct flight_list
{
    struct flight F_light;//数据域，存放的数据内容
    struct flight_list *prev;//指针域，存放上一个数据的地址
    struct flight_list *next;//指针域，存放下一个数据的地址
};
//初始化(头节点)
struct flight_list *flist_init();
//申请新节点(航班系统)
struct flight_list *request_node();
//尾插
int flist_add_tail(char *flight_number,char *departure,char *destination,char *take_off_time,char *arrival_time,float price,int num,struct flight_list *list);
//插入数据
int flist_add(struct flight_list *list);
//删除数据-->取消航班
int list_delete(char *deldata, struct flight_list *list);
//实现取消航班
int del_flight( struct flight_list *list);
//修改数据
int flist_update(char *update,void *newdata,int key,struct flight_list *list);
//修改航班信息
int Revising_flight(struct flight_list *list);
//查询全部航班数据
int flist_show(struct flight_list *list);
//查询航班信息 
int inquire_fliht(char *Name,int key,struct flight_list *list);
 //索引功能
int inquire_flights(struct flight_list *list);
//将文件的内容保存进链表中
void read_ffile_to_list(struct flight_list *list);
//将航班信息写入txt文件中保存
void save_flist_to_file(struct flight_list *list);
#endif