#include "myhead.h"
#include "nor_list.h"
#include "root_list.h"
#include "black.h"
#include "time.h"
//获取当前时间
char *get_time() 
{
    // 获取当前时间的时间戳
    time_t current_time;
    time(&current_time);
    // 将时间戳转换为本地时间结构
    struct tm *local_time = localtime(&current_time);
    // 定义一个缓冲区来存储格式化后的时间字符串
    char time_str[50];
    // 使用 strftime 函数将时间结构格式化为字符串
    strftime(time_str, sizeof(time_str), "%Y-%m-%d~%H:%M:%S", local_time);
    // 为存储时间字符串分配堆空间，利于返回值
    char *p = (char *)malloc(strlen(time_str) + 1); //用于存储字符串结束符 '\0'
    // 将格式化后的时间字符串复制到动态分配的内存中
    strcpy(p, time_str);
    return p;
}
//初始化(头节点)
struct fticke_sys *list_init()
{
    //定义结构体指针，申请堆空间
    struct fticke_sys *list=malloc(sizeof(struct fticke_sys));
    //指针指向哪里
    list->next= NULL; 
    list->prev= NULL;
    return list;
}
//申请节点-购票结构体节点
struct fticke_sys *node()
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
    //定义结构体指针，申请堆空间
    struct fticke_sys *newnode=malloc(sizeof(struct fticke_sys));
    printf("购票乘客姓名：");
    scanf("%s",name);
    printf("乘客联系方式：");
    scanf("%s",telephone);
    printf("航班号：");
    scanf("%s",flight_number);
    printf("座位号：(A 1-10 B 1-10 C 1-10 D 1-10):");
    scanf("%s",Seat_Number);
    printf("出发地：");
    scanf("%s",departure);
    printf("目的地：");
    scanf("%s",destination);
    printf("起飞时间：");
    scanf("%s",take_off_time);
    printf("到达时间：");
    scanf("%s",arrival_time);
    printf("购票数量：");
    scanf("%d",&buy_num);
    char *time=get_time(); //购票时间
   //数据
    strcpy(newnode->tickes.name,name); //乘客姓名
    strcpy(newnode->tickes.telephone,telephone); //联系方式
    strcpy(newnode->tickes.flight_number,flight_number); //航班号
    strcpy(newnode->tickes.Seat_Number,Seat_Number);//座位号
    strcpy(newnode->tickes.departure,departure);  //出发地 
    strcpy(newnode->tickes.destination,destination);   //目的地
    strcpy(newnode->tickes.take_off_time,take_off_time); //出发时间
    strcpy(newnode->tickes.arrival_time,arrival_time); //到达时间
    strcpy(newnode->tickes.buy_time,time); //购买时间
    newnode->tickes.buy_num=buy_num; //购票数量
    //指针指向哪里
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
//文件内容保存链表
void fticke_add_tail(char *name,char *telephone,char *flight_number,char *Seat_Number,char *departure,char *destination,char *take_off_time,\
                                char *arrival_time,int buy_num,char *buy_time,struct fticke_sys *list)
{
   struct fticke_sys *newnode=malloc(sizeof(struct fticke_sys));
    //赋值
    strcpy(newnode->tickes.name,name);
    strcpy(newnode->tickes.telephone,telephone);
    strcpy(newnode->tickes.flight_number,flight_number);
    strcpy(newnode->tickes.Seat_Number,Seat_Number);
    strcpy(newnode->tickes.departure,departure);
    strcpy(newnode->tickes.destination,destination);
    strcpy(newnode->tickes.take_off_time,take_off_time);
    strcpy(newnode->tickes.arrival_time,arrival_time);
    strcpy(newnode->tickes.buy_time,buy_time);
    newnode->tickes.buy_num=buy_num;
    //指针指向哪里
    newnode->next=NULL;
    newnode->prev=NULL;

    struct fticke_sys *p=list;
    while (p->next!=NULL)
        p=p->next;

    p->next=newnode;
    newnode->prev=p;
    newnode->next=NULL;
}
//添加数据-购票
int add_data(struct fticke_sys *list,struct flight_list *mylist)
{
    int flgs=0;
    //定义结构体指针，申请堆空间
    struct fticke_sys  *newnode=node();
    int ret=is_in_blacklist(newnode->tickes.name);
    if(ret == 1)//存在黑名单中
    {
        printf("你在系统的黑名单中，无法进行购票！\n");
        return -1;
    }
    
    struct flight_list *q=mylist;
    while (q->next!=NULL)
    {
        q=q->next;
        if(strcmp(q->F_light.flight_number,newnode->tickes.flight_number)==0)
        {
            q->F_light.num=(q->F_light.num)-(newnode->tickes.buy_num);
            flgs=1;//航班是存在的
            if(q->F_light.num<0)
            {
                printf("航票已经不足!\n");
            }
        }
    }
    if(flgs==0)
    {
        printf("你购买的航班的票不存在，你重新购买！\n");
        return -1;
    }
    //指针指向哪里
    struct fticke_sys  *p=list;
     while (p->next!=NULL)
     {
        p=p->next;
        if(strcmp(p->tickes.Seat_Number,newnode->tickes.Seat_Number)==0)
        {
            printf("你想购买的座位号已经买出，购买失败！");
            return -1;
        }
     }
       
    p->next=newnode;
    newnode->next=NULL;
    newnode->prev=p;
    return 0;
}
//修改数据 - 改签 - 》 修改飞行时间、目的地、航班号。。。
int up_data(char *up_name,void *newdata, int key,struct fticke_sys *list)
{
    struct fticke_sys *p=list->next;
    //遍历
    while (p!=NULL)
    {
        if (strcmp(p->tickes.name,up_name)==0)//找到位置
        {
            //判断你要修改的信息是什么
            switch(key)
            {
                case 1://姓名
                    strcpy(p->tickes.name,newdata);
                    printf("修改成功！\n");
                    break;
                case 2: //航班号
                    strcpy(p->tickes.flight_number,newdata);
                    printf("修改成功!\n");
                    break;
                case 3: //起飞时间
                    strcpy(p->tickes.take_off_time,newdata);
                    printf("操作成功!\n");
                    break;
                case 4: //目的地
                    strcpy(p->tickes.destination,newdata);
                    printf("修改成功!\n");
                    break;
                case 5: //座位号
                    strcpy(p->tickes.Seat_Number,newdata);
                    printf("修改成功!\n");
                    break;
                case 6: //联系方式
                    strcpy(p->tickes.telephone,newdata);
                    printf("修改成功!\n");
                    break;
                default:
                    break;
            }
        }
        p=p->next;
    }
    
}
//删除数据
int del_data(char *update_name, struct fticke_sys *list) 
{
    int flgs = 0;
    struct fticke_sys *p = list->next; // 跳过头结点
    struct fticke_sys *prev = list;

    while (p != NULL) 
    {
        if (strcmp(p->tickes.flight_number, update_name) == 0) 
        {
            prev->next = p->next; // 更新前一个节点的next指针

            if (p->next != NULL)
                p->next->prev = prev; // 更新下一个节点的prev指针

            free(p); // 释放节点内存
            flgs = 1; // 已经删除数据
            break; // 删除完成，退出循环
        } 
        else 
        {
            prev = p;
            p = p->next;
        }
    }

    if (flgs == 0)
        printf("没有找到要删除的 %s 航票信息\n", update_name);

    return 0;
}
//退票
int del_fticke(struct fticke_sys *list,struct flight_list *mylist)
{
    int flgs=0;
    char str[20]; //航班号
    printf("请输入要删除的票据：");
    scanf("%s",str);
    struct fticke_sys *p=list;
    while (p->next!=NULL)
    {
        p=p->next;
        if(strcmp(p->tickes.flight_number,str)==0)//寻找到要删除的票
        {
            if(p->tickes.buy_num==1)
            {
                printf("1\n");
                del_data(str,list);
                flgs=1;
            }
            if (p->tickes.buy_num > 1)
            {
                p->tickes.buy_num--;
                flgs=1;
            }
        }
    }
    struct flight_list *q=mylist;
    while (q->next!=NULL)
    {
        q=q->next;
        if(strcmp(q->F_light.flight_number,str)==0 && flgs == 1)
        {
            q->F_light.num++;
        }
    }
    
    if(flgs==0)
        printf("没有找到要删除的航票.\n");
    else
        printf("已经删除航票.\n");
    return 0;
}
//查询购买的航票信息 
int inquire(char *Name,int key,struct fticke_sys *list)
{
    int flgs=0;//标志位
    char name[20]="乘客姓名";
    char telephone[20]="联系方式"; 
    char flight_number[20]="航班号";
    char Seat_Number[20]="座位号";
    char departure[20]="出发地";
    char destination[20]="目的地";
    char take_off_time[20]="起飞时间";
    char arrival_time[20]="到达时间";
    char buy_num[20]="购票数量";
    char buy_time[20]="购票时间";
    //定义一个结构体指向指向链表结构体
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",name,telephone,flight_number,Seat_Number,departure,destination,take_off_time, arrival_time,buy_num,buy_time);
    struct fticke_sys *p=list->next;
    while (p!=NULL)
    {
        switch (key)
        {
             case 1://姓名
                if(strcmp(p->tickes.name,Name)==0)
                {
                   flgs=1;
                   printf("%s\t\t%s\t\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d\t\t%s\n",p->tickes.name,p->tickes.telephone,p->tickes.flight_number,\
                                    p->tickes.Seat_Number,p->tickes.departure,p->tickes.destination,p->tickes.take_off_time,\
                                    p->tickes.arrival_time,p->tickes.buy_num,p->tickes.buy_time);
                }
                break; 
            case  2: //航班号
                if(strcmp(p->tickes.flight_number,Name)==0)
                {
                    flgs=1;
                   printf("%s\t\t%s\t\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d\t\t%s\n",p->tickes.name,p->tickes.telephone,p->tickes.flight_number,\
                                    p->tickes.Seat_Number,p->tickes.departure,p->tickes.destination,p->tickes.take_off_time,\
                                    p->tickes.arrival_time,p->tickes.buy_num,p->tickes.buy_time);
                }
                break;
            default:
                break;
        }
        p=p->next;
    }
}
//打印数据
int show_data(struct fticke_sys *list)
{
    //定义一个结构体指向指向链表结构体
    struct fticke_sys *p=list->next;
    if(p==NULL)
    {
        printf("这个链表为空！\n");
        return -1;
    }
    while(p!=NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t\t%s\n",p->tickes.name,p->tickes.telephone,p->tickes.flight_number,\
                    p->tickes.Seat_Number,p->tickes.departure,p->tickes.destination,p->tickes.take_off_time,\
                    p->tickes.arrival_time,p->tickes.buy_num,p->tickes.buy_time);
        p=p->next;//循环结束时p指向最后一个节点打的位置 
    }
}
//读取txt文件中的票数据
//将文件的内容保存进链表中
void read_list_to_flie(struct fticke_sys *list) 
{
    FILE *file = fopen("fticke.txt", "r");
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    // 跳过第一行
    char skip_line[1000];
    fgets(skip_line, sizeof(skip_line), file);//分行读取 光标到第二行
    char line[1000];
    while (fgets(line, sizeof(line), file)) //按行读取
    {
        // 解析行内容为图书信息
        char name[20];
        char telephone[20]; 
        char flight_number[20];
        char Seat_Number[20];
        char departure[20];
        char destination[20];
        char take_off_time[20];
        char arrival_time[20];
        int buy_num;
        char buy_time[20];
        sscanf(line, "%s %s %s %s %s %s %s %s %d %s",name,telephone,flight_number,Seat_Number,departure,destination,take_off_time,arrival_time,&buy_num,buy_time);
        // 将信息保存到链表中
        fticke_add_tail(name,telephone,flight_number,Seat_Number,departure,destination,take_off_time,arrival_time,buy_num,buy_time,list);
        bzero(line,1000);
    }

    fclose(file);
}
//将票据信息写入txt文件中保存
void save_list_to_file(struct fticke_sys *list) 
{
    FILE *file = fopen("fticke.txt", "w+");
    char name[20]="乘客姓名";
    char telephone[20]="联系方式"; 
    char flight_number[20]="航班号";
    char Seat_Number[20]="座位号";
    char departure[20]="出发地";
    char destination[20]="目的地";
    char take_off_time[20]="起飞时间";
    char arrival_time[20]="到达时间";
    char buy_num[20]="购票数量";
    char buy_time[20]="购票时间";
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",name,telephone,flight_number,Seat_Number,departure,destination,take_off_time,arrival_time,buy_num,buy_time);
    struct fticke_sys *p=list->next;
    while (p != NULL) {
        fprintf(file, "%s\t\t%s\t\t%s\t%s\t\t%s\t%s\t%s\t\t%s\t\t%d\t\t%s\n",p->tickes.name,p->tickes.telephone,p->tickes.flight_number,p->tickes.Seat_Number,\
                                p->tickes.departure,p->tickes.destination,p->tickes.take_off_time,p->tickes.arrival_time,\
                                p->tickes.buy_num,p->tickes.buy_time);
        p = p->next;
    }

    fclose(file);
}

/* int main()
{
    struct fticke_sys *mylist=list_init();
    add_data(mylist);
    //up_data("李华","gz1234",1,mylist);
    //show_data(mylist);
   inquire("lihua",1,mylist);   
} */