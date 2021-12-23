/*Made by MRSlouzk*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20 //最大信息录入量
//库以及常量定义
struct Worker{
    int num; //职工号
    char name[10]; //名字
    char sex[10]; //性别
    int age; //年龄
    long long int tele; //电话
    int sala; //工资
    int rank; //评级
    } work[N],*p=work; //结构体定义

int main(){
    int menu(); //主菜单函数
    void input(struct Worker b[],int i); //输入函数
    void read(int c); //查看函数
    int del(int d); //删除函数
    void chg(); //修改函数
    void file(int n); //文件函数
    //函数定义
    int con,i,delj,c=0; //定义变量

    printf("======================Student Information======================\n");
    printf("Name:    ,Number:    ,Class:    \n");
    while((con=menu())!=6){
        if(con==1){
            for(i=c;i<N;i++) {
                input(p,i);
                if(work[i].num==0) break;
                c++;  //保存上次录入位置
            }
        } //主函数:信息录入
        if(con==2){
            read(c);
        }
        if(con==3){
            delj=del(c); //全部删除
            if(delj==0){
                c=0;
            }
        }
        if(con==4){
            chg();
        }
        if(con==5){
            file(c);
        }
    }
    printf("Thanks for using.\n");
    return 0;
}

int menu(){
    int cons;
    printf("\n==============Workers\' Information Manager System==============\n");
    printf("1:Input workers\' Information   2:Read workhers\' Information\n");
    printf("3:Delete workers\' Information  4:Change workers\' Information\n");
    printf("5:Output Information to files  6:Exit the system\n");
    printf("Please iuput one number to continue:");
    scanf("%d",&cons);
    while(cons<1||cons>6){
        printf("Wrong number!Please input again:");
        scanf("%d",&cons);
    } //判断数字是否合规
    return (cons);
} //菜单函数

void input(struct Worker work[],int i){
    printf("Please input the information of worker:\n");
    printf("Input number(If this is 0,the input will exit!):");
    scanf("%d",&work[i].num);
    if(work[i].num!=0){
        printf("Input name:");
        scanf("%s",work[i].name);
        printf("Input sex:");
        scanf("%s",work[i].sex);
        printf("Input age:");
        scanf("%d",&work[i].age);
        printf("Input telephone:");
        scanf("%lld",&work[i].tele);
        printf("Input salary:");
        scanf("%d",&work[i].sala);
        printf("Input rank(1-10):");
        scanf("%d",&work[i].rank);
    }
    printf("Worker No.%d is completed!\n",i+1);
    // work[0].num=12;
    // work[1].num=15;
    // strcpy(work[0].name,"Ling");
    // strcpy(work[1].name,"Mei");
    // strcpy(work[0].sex,"Male");
    // strcpy(work[1].sex,"Female");
    // work[0].age=22;
    // work[1].age=28;
    // work[0].tele=12394193;
    // work[1].tele=12321412;
    // work[0].sala=5000;
    // work[1].sala=6000;
    // work[0].rank=8;
    // work[1].rank=9; //调试用语句
} //录入函数

void read(int c){
    int i;
    for(i=0;i<=c-1;i++){ //i<=c-1
        if(work[i].num!=0){
        printf("Worker No.%-2d:Number:%-5d Name:%-5s Sex:%-6s Age:%-2d Telephone:%-10lld salary:%-5d Rank:%-2d\n",i+1,work[i].num,work[i].name,work[i].sex,work[i].age,work[i].tele,work[i].sala,work[i].rank);
        }
    }
} //输出函数

int del(int d){
    int i0,jud,cho,ret=1;
    printf("0:Delete all data 1:Delete chosen data\n");
    printf("Your choice:");
    scanf("%d",&jud);
    if(jud){
        printf("Please input order of worker:");
        scanf("%d",&cho);
        if(cho<=d+1){
            work[cho-1].num=0,strcpy(work[cho-1].name," "),strcpy(work[cho-1].sex," "),work[cho-1].age=0,work[cho-1].tele=0,work[cho-1].sala=0,work[cho-1].rank=0;
        } else printf("Wrong order!!!");
    } else{
        for(i0=0;i0<=d;i0++){
        work[i0].num=0,strcpy(work[i0].name," "),strcpy(work[i0].sex," "),work[i0].age=0,work[i0].tele=0,work[i0].sala=0,work[i0].rank=0;
        ret=0;
        }
    }
    return(ret);
} //删除(清空)函数

void chg(){
    int ch=0,value,judge=0;
    long long int telp;
    char atr[10];
    while(1){
        printf("Please input Workers\' order and attribution\n");
        printf("(Attribution contains num,name,sex,age,tele,sala,rank)\n");
        printf("Input 0 to exit,");
        printf("Please input order:");
        scanf("%d",&ch);
        if(ch==0) break; //跳出修改函数
        printf("Please input attribution:");
        scanf("%s",atr);
        ch-=1;
        if(!strcmp(atr,"num")){
            printf("Please input new num:");
            scanf("%d",&value);
            work[ch].num=value;
            judge=1;
        }
        else if(!strcmp(atr,"name")){
            printf("Please input new name:");
            scanf("%s",atr);
            strcpy(work[ch].name,atr);
            judge=1;
        }
        else if(!strcmp(atr,"sex")){
            printf("Please input new sex:");
            scanf("%s",atr);
            strcpy(work[ch].sex,atr);
            judge=1;
        }
        else if(!strcmp(atr,"age")){
            printf("Please input new age:");
            scanf("%d",&value);
            work[ch].age=value;
            judge=1;
        }
        else if(!strcmp(atr,"tele")){
            printf("Please input new telephone:");
            scanf("%lld",&telp);
            work[ch].tele=telp;
            judge=1;
        }
        else if(!strcmp(atr,"sala")){
            printf("Please input new salary:");
            scanf("%d",&value);
            work[ch].sala=value;
            judge=1;
        }
        else if(!strcmp(atr,"rank")){
            printf("Please input new rank:");
            scanf("%d",&value);
            work[ch].rank=value;
            judge=1;
        }
        if(!judge) printf("No such attribution!!!\n");
    }
} //数据修改函数

void file(int n){
    FILE *fp0;
    int i0;
    char name[15];
    printf("Please input file name:");
    scanf("%s",name);
    if(fp0=fopen(name,"w")==NULL){
        printf("Failed to open file!\n");
        exit(0);
    } //异常处理语句
    for(i0=0;i0<=n;i0++){ //i0<=n
        if(work[i0].num!=0){
            fprintf(fp0,"Number:%-5d Name:%-5s Sex:%-7s Age:%-2d Telephone:%-10u salary:%-5d Rank:%-2d\n",work[i0].num,work[i0].name,work[i0].sex,work[i0].age,work[i0].tele,work[i0].sala,work[i0].rank);
        }
    }  //数据输出
    printf("Data had been successfully derived to %s!\n",name);
    fclose(fp0);
} //文件导出函数