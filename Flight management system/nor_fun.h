#ifndef _NOR_FUN_H
#define _NOR_FUN_H
#include "nor_list.h"
#include "root_list.h"
//查询
int inquire_fticke(struct fticke_sys *list);
//修改航票信息
int Revising_ftice(struct fticke_sys *list);
//显示普通用户界面
void interface_nor();
//功能的实现-普通用户
void nor_funtion(struct fticke_sys *list,struct flight_list *mylist);
#endif