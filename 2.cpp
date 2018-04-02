#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 总链表——存放所有信息 */
typedef struct Sum_Node
{
    /* 学生信息 */
    char stuNo[20][20];
    char stuName[20][20];
    char stuSex[20][20];
    /* 课程信息 */
    char CourseNum[20];
    char CourseName[20];
    char CourseTeacher[20];
    struct Sum_Node *next;
}TotalNode;

/* 链表管理员——暂时不需要 */
/*typedef struct Node
{
    char Num[20];
    char Name[20];
    char Sex[10];
    struct Node *next;
}Manager_Node;*/

char studentAccount[20];
char studentPassword[20];
char teacherAccount[20];
char teacherPassword[20];
char managerAccount[20];
char managerPassword[20];

/* 定义结构体指针 */
TotalNode *pTeacher;
TotalNode *pStudent;


/* 函数的声明 */
void checkPerson_Msg(TotalNode *phead,int n);
void CreateTeacherNode(TotalNode *head);

/* 学生信息的输出-链表 */
void OutStudentNode(TotalNode *head,char *Account)
{
    TotalNode *p;
    int num=0;
    int i,j;
    int flag=0;
    char Account_random[20]="";
    pStudent=pTeacher;  // 学生和老师用的链表是同一个
    p=pStudent;

    puts("******所选课程信息******");
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    if(pStudent==NULL)
    {
        puts("没有数据!");
        puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        return;
    }
    printf("请输入所要查询人的姓名:");
    gets(Account_random);   //  获取所要查询的学生姓名
    if(0 == Account_random[0])
    {   
        gets(Account_random);
    }
    while(p!=NULL)
    {
        for(j=0;j<20;j++)
        {
            if(0 == strcmp(p->stuName[j],Account_random))
            {
                printf("课程代码:%s\t",p->CourseNum);
                printf("课程名称:%s\t",p->CourseName);
                printf("课程老师:%s\t",p->CourseTeacher);
                for(i=0;i<20;i++)
                {
                    if(p->stuNo[i][0]!='\0')
                    {
                        num++;
                    }
                }
                printf("选课学生:%d\t",num);
                num=0;  //  清0操作
                putchar('\n');
                flag=1;
            }
        }
        p=p->next;
    }
    if(0 == flag)
    {
        puts("没有该学生选课信息!!!!");
    }
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    putchar('\n');  
}

/* 学生信息的插入-链表 */
void InsertStudentNode(TotalNode *head,char *Account)
{
    TotalNode *p;
    int i;
    char courseCode[20]="";
    pStudent=pTeacher;  // 学生和老师用的链表是同一个，都是链表头
    p=pStudent;
    if(p==NULL)
    {
        puts("等待教师录入选课信息，请下次再进行选择!!");
        return;
    }
    printf("【请输入正确的课程代码】");
    gets(courseCode);
    if(0 == courseCode[0])
    {
        gets(courseCode);
    }
    while(p!=NULL)
    {
        if(0 == strcmp(p->CourseNum, courseCode))
        {
            for(i=0;i<20;i++)
            {   
                if(p->stuNo[i][0] == '\0')
                {
                    printf("请输入学号:");
                    gets(p->stuNo[i]);
                    printf("请输入姓名:");
                    gets(p->stuName[i]);
                    printf("请输入性别:");
                    gets(p->stuSex[i]);
                    puts("选课成功!!!!");
                    return;
                }
            }
        }
        p=p->next;
    }
    puts("$$$$$$选课失败，请重新选择$$$$$$");

}

/* 删除所选课程 */
void DeleteStudentNode(TotalNode *head,char *Account)
{
    char coursNo[20]="";    //  课程代码
    char student[20]="";    //  学生姓名
    TotalNode *p;
    int i;
    int flag=0;
    pStudent=pTeacher;  // 学生和老师用的链表是同一个，都是链表头
    p=pStudent;
    if(pStudent==NULL)
    {
        puts("没选该课程，删除失败!!!!");
        return;
    }

    printf("【输入学生姓名】");
    gets(student);
    if(0 == student[0])
    {
        gets(student);
    }

    printf("【请输入删除的课程代码】");
    gets(coursNo);
    if(0 == coursNo[0])
    {
        gets(coursNo);
    }
    while(p!=NULL)
    {
        if(0==strcmp(p->CourseNum,coursNo)) //  查询所要删除的课程代码
        {
            for(i=0;i<20;i++)
            {
                if(0==strcmp(p->stuName[i],student))
                {
                    /* 初始化清0操作 */
                    p->stuNo[i][0]='\0';
                    p->stuName[i][0]='\0';
                    p->stuSex[i][0]='\0';
                    puts("删除成功!!!!");
                    flag=1;     //  删除标志位
                }
            }   
        }
        p=p->next;
    }
    if(0 == flag)   //  如果删除成功标志位置1
    {
        puts("删除失败!!!!");
    }

}


/* 教师信息的输出-链表 */
void OutTeacherNode(TotalNode *head)
{
    TotalNode *p;
    int num=0;
    int i;
    p=pTeacher;
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    if(pTeacher==NULL)
    {
        puts("没有数据!");
        puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        return;
    }
    while(p!=NULL)
    {
        printf("课程代码:%s\t",p->CourseNum);
        printf("课程名称:%s\t",p->CourseName);
        printf("课程老师:%s\t",p->CourseTeacher);
        for(i=0;i<20;i++)
        {
            if(p->stuNo[i][0]!='\0')
            {
                num++;
            }
        }
        printf("选课学生:%d\t",num);
        num=0;  //  清0操作
        putchar('\n');
        p=p->next;
    }
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    putchar('\n');  
}

/* 教师信息的插入-链表 */
void InsertTeacherNode(TotalNode *head)
{
    TotalNode *p;
    TotalNode *q;
    int i;
    p=pTeacher;  // 教师链表的头
    if(pTeacher==NULL)
    {
        CreateTeacherNode(head);
        puts("添加成功!");
        return;
    }
    while(p!=NULL)
    {
        if(p->next == NULL)
        {
            q=(TotalNode *)malloc(sizeof(TotalNode));
            p->next=q;
            q->next=NULL;
            for(i=0;i<20;i++)
            {
                q->stuNo[i][0]='\0';
            }
            printf("请输入课程代码:");
            gets(q->CourseNum);
            if(0 == *q->CourseNum)
            {
                gets(q->CourseNum);
            }
            printf("请输入课程名称:");
            gets(q->CourseName);
            printf("请输入课程教师:");
            gets(q->CourseTeacher);
            puts("添加成功!");
            break;
        }
        p=p->next;
    }
    //pTeacher=head;
}

/* 教师信息的插入-链表 */
void CreateTeacherNode(TotalNode *head)
{
    int i;
    pTeacher=(TotalNode *)malloc(sizeof(TotalNode));
    pTeacher->next=NULL;
    for(i=0;i<20;i++)
    {
        pTeacher->stuNo[i][0]='\0';
    }
    printf("请输入课程代码:");
    gets(pTeacher->CourseNum);
    if(0 == *pTeacher->CourseNum)
    {
        gets(pTeacher->CourseNum);
    }
    printf("请输入课程名称:");
    gets(pTeacher->CourseName);
    printf("请输入课程教师:");
    gets(pTeacher->CourseTeacher);
    //pTeacher=head;
}

/* 删除指定数据 */
void DeleteTeacherNode(TotalNode *phead)
{
    char coursNo[20]="";    //  课程代码
    TotalNode *p;
    TotalNode *s;
    p=pTeacher; // 教师链表的头
    s=pTeacher;
    if(NULL==pTeacher)
    {
        puts("没有课程信息!!!!");
        return;
    }
    printf("【请输入删除的课程代码】");
    gets(coursNo);
    if(0 == coursNo[0])
    {
        gets(coursNo);
    }
    if(0 == strcmp(p->CourseNum,coursNo))
    {
        pTeacher=p->next;
        puts("删除成功!!");
        return;
    }
    while(p != NULL)
    {
        if(0 == strcmp(p->CourseNum,coursNo))
        {
            s->next=p->next;
            puts("删除成功!!");
            return;
        }
        s=p;
        p=p->next;
    }
}

/* 功能显示 */
void display(TotalNode *phead)
{
    int n;
    while(1)
    {
        puts("=========请选择登录页面=========");
        puts("[1]学生登录");
        puts("[2]教师登录");
        puts("[3]管理员登录");
        puts("[4]退出系统");
        while(1)    //  循环检查输入的值是否正确
        {
            printf("【请选择】");
            scanf("%d",&n);
            if(n>4 || n<1)
            {
                puts("输入有误，请选择正确的选项：");
                continue;       //  输入不正确，重新输入
            }
            else
            {
                break;  //  输入正确，退出循环
            }
        }
        if( 1 == n )  //    学生登录系统
        {
            puts("=========欢迎登录学生系统=========");
            printf("请输入账号和密码\n");
            checkPerson_Msg(phead,1);


        }
        if( 2 == n )  //    老师登录系统
        {
            puts("=========欢迎登录教师系统=========");
            printf("请输入账号和密码\n");
            checkPerson_Msg(phead,2);

        }
        if( 3 == n )  //    管理员登录系统
        {
            puts("=========欢迎登录管理员系统=========");
            printf("请输入账号和密码\n");
            checkPerson_Msg(phead,3);

        }
        if( 4 == n )  //    退出系统
        {
            puts("@@@@@@@@@欢迎下次登录，再见!!!@@@@@@@@@");
            exit(0);        
        }
    }
}

/* 学生登录后的操作，查询、修改 */
void Student_Mng(TotalNode *phead, char *Account,int n)
{
    switch(n)
    {
    case 1:     //  查询
        OutStudentNode(phead,Account);
        break;
    case 2:     //  添加
        InsertStudentNode(phead,Account);
        break;
    case 3:     //  删除
        DeleteStudentNode(phead,Account);
        break;
    case 4: ;   //  返回主页面,上层已经实现，此处不需要考虑
        break;
    default:
        puts("异常!");
        break;
    }
}

/* 教师登录后的操作，查询、修改 */
void Teacher_Mng(TotalNode *phead, char *Account,int n)
{

    switch(n)
    {
    case 1: //  查询学生选课情况
        OutTeacherNode(phead);
        break;
    case 2: //  添加和删除课程信息
        InsertTeacherNode(phead);
        break;
    case 3:     
        DeleteTeacherNode(phead);
        break;
    case 4:
        break;  //  上层实现其功能
    default:
        puts("异常!");
        break;
    }
}

/* 管理员登录后的操作，查询、修改 */
void Manager_Mng(char *Account, int n)
{
    switch(n)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        puts("异常!");
        break;
    }
}
/* 显示各功能登录后的信息 */
void display_Detailed(TotalNode *phead ,char *Account,int n)
{
    int in;
    switch(n)
    {
    case 1:
        while(1)
        {
            printf("=========欢迎%s同学=========\n",Account);
            puts("[1]查询已选课程");  //  查询自己所选的所有课程包括：课程代码、课程名称、任课老师
            puts("[2]添加课程");        //  增加所选课程
            puts("[3]删除所选课程");  //  删除所选课程
            puts("[4]返回主页面");
            printf("【请选择】");
            scanf("%d",&in);
            if(4 == in)
            {
                return; //  返回上层登录页面
            }
            Student_Mng(pStudent,Account, in);
            //puts("[4]");
        }
        break;
    case 2:
        while(1)
        {
            printf("=========欢迎%s老师=========\n",Account);
            puts("[1]查询学生选课信息");    //  
            puts("[2]添加老师课程信息");    //  
            puts("[3]删除老师课程信息");    //
            puts("[4]返回主页面");
            printf("【请选择】");
            scanf("%d",&in);
            if(4 == in)
            {
                return; //  返回上层登录页面
            }
            Teacher_Mng(pTeacher,Account, in);
        }
        //puts("[4]");
        break;
    case 3:
        printf("=========欢迎%s同志=========\n",Account);
        puts("[1]查询学生所选课程信息");
        puts("[2]修改选课信息");
        puts("[3]返回主页面");
        scanf("%d",&in);
        Manager_Mng(Account, in);
        //puts("[4]");
        break;
    default:
        puts("异常!");
        break;
    }

}

/* 验证账号密码 */
void checkAccountandPassword(TotalNode *phead ,char *Account, char *Password,int n)
{
    while(1)
    {
        gets(Account);
        /**/
        if(0 == strcmp(Account,"wantin"))
        {
            while(1)
            {
                printf("请输入密码:");
                gets(Password);
                if(0 == strcmp(Password,"123456"))
                {
                    display_Detailed(phead,Account, n);
                    return;
                }
            }
        }
        else
        {
            printf("请输入账号:");
        }
    }
}

/* 校验学生、教师、管理员的账号 密码 */
void checkPerson_Msg(TotalNode *phead , int n)
{
    switch(n)
    {
        case 1: //  学生登录    char studentAccount[20]; char studentPassword[20];  
            checkAccountandPassword(phead, studentAccount,studentPassword,n);
            break;
        case 2: //  教师登录    char teacherAccount[20]; char teacherPassword[20];      
            checkAccountandPassword(phead, teacherAccount,teacherPassword,n);
            break;
        case 3: //  管理员登录  char managerAccount[20]; char managerPassword[20];       
            checkAccountandPassword(phead, managerAccount,managerPassword,n);
            break;
        default:
            puts("异常!");
            break;
    }
}

/*  */

void main()
{
    TotalNode *phead=NULL;
    display(phead);}