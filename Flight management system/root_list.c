#include "myhead.h"
#include "root_list.h"

//初始化(头节点)
struct flight_list *flist_init()
{
    //定义结构体指针，申请堆空间
    struct flight_list *list=malloc(sizeof(struct flight_list));
    //指针指向哪里
    list->next= NULL; 
    list->prev= NULL;
    return list;
}
//申请新节点(航班系统)
struct flight_list *request_node()
{
    //定义结构体指针，申请堆空间
    struct flight_list *newnode=malloc(sizeof(struct flight_list));

    char flight_number[16]; //航班号
    char departure[32];     //出发地
    char destination[32];   //目的地
    char take_off_time[16]; //起飞时间
    char arrival_time[16];  //到达时间
    float price;            //价格
    int num;                //票的数量

    printf("请输入增加的航班号：");
    scanf("%s",flight_number);
    printf("请输入出发地：");
    scanf("%s",departure);
    printf("请输入目的地：");
    scanf("%s",destination);
    printf("请输入起飞时间：");
    scanf("%s",take_off_time);
    printf("请输入预计到达时间：");
    scanf("%s",arrival_time);
    printf("请输入航票的价格：");
    scanf("%f",&price);
    printf("请输入票的数量：");
    scanf("%d",&num);
   //数据
    strcpy(newnode->F_light.flight_number,flight_number); //航班号
    strcpy(newnode->F_light.departure,departure);      //出发地 
    strcpy(newnode->F_light.destination,destination);   //目的地
    strcpy(newnode->F_light.take_off_time,take_off_time); //出发时间
    strcpy(newnode->F_light.arrival_time,arrival_time); //到达时间
    newnode->F_light.price=price;       //票价
    newnode->F_light.num=num;          //票的数量
    //指针指向哪里
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
//尾插数据 文件内容放链表
int flist_add_tail(char *flight_number,char *departure,char *destination,char *take_off_time,char *arrival_time,float price,int num,struct flight_list *list)
{
    struct flight_list *newnode=malloc(sizeof(struct flight_list));
    //赋值
    strcpy(newnode->F_light.flight_number,flight_number); //航班号
    strcpy(newnode->F_light.departure,departure);      //出发地 
    strcpy(newnode->F_light.destination,destination);   //目的地
    strcpy(newnode->F_light.take_off_time,take_off_time); //出发时间
    strcpy(newnode->F_light.arrival_time,arrival_time);//到达时间
    newnode->F_light.price=price;       //票价
    newnode->F_light.num=num;          //票的数量
     //指针指向哪里
    newnode->next=NULL;
    newnode->prev=NULL;

    struct flight_list *p=list;
    while (p->next!=NULL)
        p=p->next;

    p->next=newnode;
    newnode->prev=p;
    newnode->next=NULL;
    
    return 0;
}
//插入数据
int flist_add(struct flight_list *list)
{
    //申请节点
    struct flight_list *newnode=request_node();
    struct flight_list *p=list;
    while (p->next!=NULL)
        p=p->next;
    p->next=newnode;
    newnode->prev=p;
}
//删除数据-->取消航班
int list_delete(char *deldata, struct flight_list *list)
{
    int flgs = 0;
    struct flight_list *p=list->next;
    struct flight_list *prev = list; 
    while (p!=NULL)
    {
        //寻找要删除的数据-根据航班号
        if(strcmp(p->F_light.flight_number,deldata)==0)
        {
           
            struct flight_list *temp = p;
            p->prev->next = p->next;
            if (p->next != NULL) 
                p->next->prev = p->prev;
            p = p->next;
            free(temp);
            flgs =1;//已经删除数据
        }
        else
            p=p->next;
    }
    if(flgs==0)
        printf("未找到%s的航班!\n",deldata);
     // 更新链表的头指针
    list->next = prev->next;
    return 0;
    
}
//实现取消航班
int del_flight( struct flight_list *list)
{
    int flgs=0;
    char str[20]; //航班号
    printf("请输入要取消的航班是：");
    scanf("%s",str);
     struct flight_list *p=list;
    while (p->next!=NULL)
    {
        p=p->next;
        if(strcmp(p->F_light.flight_number,str)==0)//寻找到要取消的航班
        {
            list_delete(str,list);
            flgs=1;
        }
    }
    if(flgs==0)
        printf("要取消的航班不存在.\n");
    else
        printf("已经取消航班.\n");
    return 0;
} 
//修改数据
int flist_update(char *update,void *newdata,int key,struct flight_list *list)
{
    //通过航班号寻找要修改的位置
    struct flight_list *p=list->next;
    //遍历
    while (p!=NULL)
    {
        if (strcmp(p->F_light.flight_number,update)==0)//找到位置
        {
            //判断你要修改的信息是什么
            switch(key)
            {
                case 1://航班号
                    strcpy(p->F_light.flight_number,newdata);
                    printf("修改成功!\n");
                    break;
                case 2://出发地
                    strcpy(p->F_light.departure,newdata);
                    printf("修改成功!\n");
                    break;
                case 3://目的地
                    strcpy(p->F_light.destination,newdata);
                    printf("修改成功!\n");
                    break;
                case 4://起飞时间
                    strcpy(p->F_light.take_off_time,newdata);
                    printf("修改成功!\n");
                    break;
                case 5://到达时间
                    strcpy(p->F_light.arrival_time,newdata);
                    printf("修改成功!\n");
                    break;
                case 6://价格
                    p->F_light.price=*(float *)newdata;
                    printf("修改成功!\n");
                    break;
                case 7://数量
                    p->F_light.num=*(int *)newdata;
                    printf("操作成功!\n");
                    break;
            default:
                break;
            }
        }
        p=p->next;
    }
    
}
//修改航班信息
int Revising_flight(struct flight_list *list)
{
    int flgs=0;
    char up_name[20];
    printf("你要修改哪个航班的信息：");
    scanf("%s",up_name);
    int key=0;
    printf("请输入你要修改的内容：1、航班号 2、出发地 3、目的地 4、起飞时间 5、到达时间  6、价格 7、数量 ");
    scanf("%d",&key);
    switch (key)
    {
        case 1:
            printf("修改后的航班号是：\n");
            char temp[20]={0};
            scanf("%s",temp);
            flgs=1;
           flist_update(up_name,temp,key,list);
            break;
        case 2:
            printf("修改后的出发地是：\n");
            char temp3[20]={0};
            scanf("%s",temp3);
            flgs=1;
            flist_update(up_name,temp3,key,list);
            break;
        case 3:
            printf("修改后的目的地是：\n");
            char temp4[20]={0};
            scanf("%s",temp4);
            flgs=1;
            flist_update(up_name,temp4,key,list);
            break;
        case 4:
            printf("修改后的起飞时间是：\n");
            char temp5[20]={0};
            scanf("%s",temp5);
            flgs=1;
            flist_update(up_name,temp5,key,list);
            break;
        case 5:
            printf("修改后的到达时间是：\n");
            char temp6[20]={0};
            scanf("%s",temp6);
            flgs=1;
            flist_update(up_name,temp6,key,list);
            break;
        case 6:
            printf("修改后的价格是：\n");
            float temp1=0;
            scanf("%f",&temp1);
            flgs=1;
            flist_update(up_name,&temp1,key,list);
            break;
        case 7:
            printf("修改后的数量是：\n");
            int temp2 =0;
            scanf("%d",&temp2);
            flgs=1;
            flist_update(up_name,&temp2,key,list);
            break;
        default:
            printf("输入的信息有误！\n");
            break;
    }    
    if(flgs==0)
        printf("没有找到有要修改的航班信息！,请重新输入\n");
} 
//查询全部航班数据
int flist_show(struct flight_list *list)
{
    //定义一个结构体指向指向链表结构体
    struct flight_list *p=list->next;
    if(p==NULL)
    {
        printf("目前航班系统为空！\n");
        return -1;
    }
    char flight_number[20]="航班号";
    char departure[20]="出发地";
    char destination[20]="目的地";
    char take_off_time[20]="起飞时间";
    char arrival_time[20]="到达时间";
    char price[20]="价格";
    char num[20]="数量";
    //定义一个结构体指向指向链表结构体
    printf("%s\t%s\t%s\t%s\t%s\t%s\t\t%s\n",flight_number,departure,destination,take_off_time,arrival_time,price,num);
    while(p!=NULL)
    {
        printf("%s\t%s\t%s\t%s\t\t%s\t\t%.2f\t\t%d\n",p->F_light.flight_number,p->F_light.departure,p->F_light.destination,p->F_light.take_off_time,p->F_light.arrival_time,p->F_light.price,p->F_light.num);
        p=p->next;//循环结束时p指向最后一个节点打的位置 
    }
}
//查询航班信息 
int inquire_fliht(char *Name,int key,struct flight_list *list)
{
    int flgs=0;//标志位
    char flight_number[20]="航班号";
    char departure[20]="出发地";
    char destination[20]="目的地";
    char take_off_time[20]="起飞时间";
    char arrival_time[20]="到达时间";
    char price[20]="价格";
    char num[20]="数量";
    printf("%s\t%s\t%s\t%s\t%s\t%s\t\t%s\n",flight_number,departure,destination,take_off_time,arrival_time,price,num);
    //定义一个结构体指向指向链表结构体
    struct flight_list *p=list->next;
    while (p!=NULL)
    {
        switch (key)
        {
             case 1://航班号
                if(strcmp(p->F_light.flight_number,Name)==0)
                   printf("%s\t%s\t%s\t%s\t\t%s\t\t%.2f\t\t%d\n",p->F_light.flight_number,p->F_light.departure,\
                                p->F_light.destination,p->F_light.take_off_time,p->F_light.arrival_time,\
                                p->F_light.price,p->F_light.num);
            case  2: //出发地
                if(strcmp(p->F_light.departure,Name)==0)
                   printf("%s\t%s\t%s\t%s\t\t%s\t\t%.2f\t\t%d\n",p->F_light.flight_number,p->F_light.departure,\
                                p->F_light.destination,p->F_light.take_off_time,p->F_light.arrival_time,\
                                p->F_light.price,p->F_light.num);
             case  3: //目的地
                if(strcmp(p->F_light.destination,Name)==0)
                   printf("%s\t%s\t%s\t%s\t\t%s\t\t%.2f\t\t%d\n",p->F_light.flight_number,p->F_light.departure,p->F_light.destination,\
                                p->F_light.take_off_time,p->F_light.arrival_time,\
                                p->F_light.price,p->F_light.num);
                break;
        }
        p=p->next;
    }
}
 //索引功能
int inquire_flights(struct flight_list *list)
{
    
    int flgs=0;
    int key=0;
    printf("请输入你要索引的信息是：1、航班号 2、出发地 3、目的地 ");
    scanf("%d",&key);
    switch (key)
    {
        case 1:
            printf("索引的航班号是：\n");
            char temp[20]={0};
            scanf("%s",temp);
            flgs=1;
            inquire_fliht(temp,key,list);
            break;
        case 2:
            printf("索引的出发地是：\n");
            char temp3[20]={0};
            scanf("%s",temp3);
            flgs=1;
            inquire_fliht(temp,key,list);
            break;
        case 3:
            printf("索引的目的地是：\n");
            char temp4[20]={0};
            scanf("%s",temp4);
            flgs=1;
            inquire_fliht(temp,key,list);
            break;
        default:
            printf("输入的信息有误！\n");
            break;
    }    
    if(flgs==0)
        printf("没有找到有要索引的航班信息！,请重新输入\n");
}
//将文件的内容保存进链表中
void read_ffile_to_list(struct flight_list *list) 
{
    FILE *file = fopen("flight.txt", "r");
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    // 跳过第一行
    char skip_line[100];
    fgets(skip_line, sizeof(skip_line), file);//分行读取 光标到第二行
    char line[100];
    while (fgets(line, sizeof(line), file)) //按行读取
    {
        // 解析行内容为图书信息
        char flight_number[20];
        char departure[20];
        char destination[20];
        char take_off_time[20];
        char arrival_time[20];
        float price;
        int num;
        sscanf(line, "%s %s %s %s %s %f %d",flight_number, departure, destination, take_off_time, arrival_time,&price, &num);
        // 将图书信息保存到链表中
        flist_add_tail(flight_number, departure, destination, take_off_time, arrival_time,price, num,list);
        bzero(line,100);
    }

    fclose(file);
}
//将航班信息写入txt文件中保存
void save_flist_to_file(struct flight_list *list) 
{
    FILE *file = fopen("flight.txt", "w+");
    char flight_number[20]="航班号";
    char departure[20]="出发地";
    char destination[20]="目的地";
    char take_off_time[20]="起飞时间";
    char arrival_time[20]="到达时间";
    char price[20]="价格";
    char num[20]="数量";
    if (file == NULL) 
    {
        printf("无法打开文件\n");
        return;
    }
    fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",flight_number,departure,destination,take_off_time,arrival_time,price,num);
    struct flight_list *p = list->next;
    while (p != NULL) 
    {
        fprintf(file, "%s\t%s\t%s\t%s\t\t%s\t%.2f\t\t%d\n", p->F_light.flight_number, p->F_light.departure, p->F_light.destination,\
                                     p->F_light.take_off_time, p->F_light.arrival_time,p->F_light.price, p->F_light.num);
        p = p->next;
    }

    fclose(file);
}
/*int main()
{
    
    struct flight_list *mylist=flist_init();
    //read_file_to_list(mylist);
    //插入数据
    flist_add(mylist);
    save_list_to_file(mylist);
    
    flist_show(mylist);
    
    //flist_add(mylist);
    //修改
    //Revising_flight(mylist);
    //save_list_to_file(mylist);
    //删除数据
    del_fticke(mylist);
    //打印数据
    flist_show(mylist);
    return 0;
}  */
