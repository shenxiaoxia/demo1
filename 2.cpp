#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* �����������������Ϣ */
typedef struct Sum_Node
{
    /* ѧ����Ϣ */
    char stuNo[20][20];
    char stuName[20][20];
    char stuSex[20][20];
    /* �γ���Ϣ */
    char CourseNum[20];
    char CourseName[20];
    char CourseTeacher[20];
    struct Sum_Node *next;
}TotalNode;

/* �������Ա������ʱ����Ҫ */
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

/* ����ṹ��ָ�� */
TotalNode *pTeacher;
TotalNode *pStudent;


/* ���������� */
void checkPerson_Msg(TotalNode *phead,int n);
void CreateTeacherNode(TotalNode *head);

/* ѧ����Ϣ�����-���� */
void OutStudentNode(TotalNode *head,char *Account)
{
    TotalNode *p;
    int num=0;
    int i,j;
    int flag=0;
    char Account_random[20]="";
    pStudent=pTeacher;  // ѧ������ʦ�õ�������ͬһ��
    p=pStudent;

    puts("******��ѡ�γ���Ϣ******");
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    if(pStudent==NULL)
    {
        puts("û������!");
        puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        return;
    }
    printf("��������Ҫ��ѯ�˵�����:");
    gets(Account_random);   //  ��ȡ��Ҫ��ѯ��ѧ������
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
                printf("�γ̴���:%s\t",p->CourseNum);
                printf("�γ�����:%s\t",p->CourseName);
                printf("�γ���ʦ:%s\t",p->CourseTeacher);
                for(i=0;i<20;i++)
                {
                    if(p->stuNo[i][0]!='\0')
                    {
                        num++;
                    }
                }
                printf("ѡ��ѧ��:%d\t",num);
                num=0;  //  ��0����
                putchar('\n');
                flag=1;
            }
        }
        p=p->next;
    }
    if(0 == flag)
    {
        puts("û�и�ѧ��ѡ����Ϣ!!!!");
    }
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    putchar('\n');  
}

/* ѧ����Ϣ�Ĳ���-���� */
void InsertStudentNode(TotalNode *head,char *Account)
{
    TotalNode *p;
    int i;
    char courseCode[20]="";
    pStudent=pTeacher;  // ѧ������ʦ�õ�������ͬһ������������ͷ
    p=pStudent;
    if(p==NULL)
    {
        puts("�ȴ���ʦ¼��ѡ����Ϣ�����´��ٽ���ѡ��!!");
        return;
    }
    printf("����������ȷ�Ŀγ̴��롿");
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
                    printf("������ѧ��:");
                    gets(p->stuNo[i]);
                    printf("����������:");
                    gets(p->stuName[i]);
                    printf("�������Ա�:");
                    gets(p->stuSex[i]);
                    puts("ѡ�γɹ�!!!!");
                    return;
                }
            }
        }
        p=p->next;
    }
    puts("$$$$$$ѡ��ʧ�ܣ�������ѡ��$$$$$$");

}

/* ɾ����ѡ�γ� */
void DeleteStudentNode(TotalNode *head,char *Account)
{
    char coursNo[20]="";    //  �γ̴���
    char student[20]="";    //  ѧ������
    TotalNode *p;
    int i;
    int flag=0;
    pStudent=pTeacher;  // ѧ������ʦ�õ�������ͬһ������������ͷ
    p=pStudent;
    if(pStudent==NULL)
    {
        puts("ûѡ�ÿγ̣�ɾ��ʧ��!!!!");
        return;
    }

    printf("������ѧ��������");
    gets(student);
    if(0 == student[0])
    {
        gets(student);
    }

    printf("��������ɾ���Ŀγ̴��롿");
    gets(coursNo);
    if(0 == coursNo[0])
    {
        gets(coursNo);
    }
    while(p!=NULL)
    {
        if(0==strcmp(p->CourseNum,coursNo)) //  ��ѯ��Ҫɾ���Ŀγ̴���
        {
            for(i=0;i<20;i++)
            {
                if(0==strcmp(p->stuName[i],student))
                {
                    /* ��ʼ����0���� */
                    p->stuNo[i][0]='\0';
                    p->stuName[i][0]='\0';
                    p->stuSex[i][0]='\0';
                    puts("ɾ���ɹ�!!!!");
                    flag=1;     //  ɾ����־λ
                }
            }   
        }
        p=p->next;
    }
    if(0 == flag)   //  ���ɾ���ɹ���־λ��1
    {
        puts("ɾ��ʧ��!!!!");
    }

}


/* ��ʦ��Ϣ�����-���� */
void OutTeacherNode(TotalNode *head)
{
    TotalNode *p;
    int num=0;
    int i;
    p=pTeacher;
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    if(pTeacher==NULL)
    {
        puts("û������!");
        puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        return;
    }
    while(p!=NULL)
    {
        printf("�γ̴���:%s\t",p->CourseNum);
        printf("�γ�����:%s\t",p->CourseName);
        printf("�γ���ʦ:%s\t",p->CourseTeacher);
        for(i=0;i<20;i++)
        {
            if(p->stuNo[i][0]!='\0')
            {
                num++;
            }
        }
        printf("ѡ��ѧ��:%d\t",num);
        num=0;  //  ��0����
        putchar('\n');
        p=p->next;
    }
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    putchar('\n');  
}

/* ��ʦ��Ϣ�Ĳ���-���� */
void InsertTeacherNode(TotalNode *head)
{
    TotalNode *p;
    TotalNode *q;
    int i;
    p=pTeacher;  // ��ʦ�����ͷ
    if(pTeacher==NULL)
    {
        CreateTeacherNode(head);
        puts("��ӳɹ�!");
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
            printf("������γ̴���:");
            gets(q->CourseNum);
            if(0 == *q->CourseNum)
            {
                gets(q->CourseNum);
            }
            printf("������γ�����:");
            gets(q->CourseName);
            printf("������γ̽�ʦ:");
            gets(q->CourseTeacher);
            puts("��ӳɹ�!");
            break;
        }
        p=p->next;
    }
    //pTeacher=head;
}

/* ��ʦ��Ϣ�Ĳ���-���� */
void CreateTeacherNode(TotalNode *head)
{
    int i;
    pTeacher=(TotalNode *)malloc(sizeof(TotalNode));
    pTeacher->next=NULL;
    for(i=0;i<20;i++)
    {
        pTeacher->stuNo[i][0]='\0';
    }
    printf("������γ̴���:");
    gets(pTeacher->CourseNum);
    if(0 == *pTeacher->CourseNum)
    {
        gets(pTeacher->CourseNum);
    }
    printf("������γ�����:");
    gets(pTeacher->CourseName);
    printf("������γ̽�ʦ:");
    gets(pTeacher->CourseTeacher);
    //pTeacher=head;
}

/* ɾ��ָ������ */
void DeleteTeacherNode(TotalNode *phead)
{
    char coursNo[20]="";    //  �γ̴���
    TotalNode *p;
    TotalNode *s;
    p=pTeacher; // ��ʦ�����ͷ
    s=pTeacher;
    if(NULL==pTeacher)
    {
        puts("û�пγ���Ϣ!!!!");
        return;
    }
    printf("��������ɾ���Ŀγ̴��롿");
    gets(coursNo);
    if(0 == coursNo[0])
    {
        gets(coursNo);
    }
    if(0 == strcmp(p->CourseNum,coursNo))
    {
        pTeacher=p->next;
        puts("ɾ���ɹ�!!");
        return;
    }
    while(p != NULL)
    {
        if(0 == strcmp(p->CourseNum,coursNo))
        {
            s->next=p->next;
            puts("ɾ���ɹ�!!");
            return;
        }
        s=p;
        p=p->next;
    }
}

/* ������ʾ */
void display(TotalNode *phead)
{
    int n;
    while(1)
    {
        puts("=========��ѡ���¼ҳ��=========");
        puts("[1]ѧ����¼");
        puts("[2]��ʦ��¼");
        puts("[3]����Ա��¼");
        puts("[4]�˳�ϵͳ");
        while(1)    //  ѭ����������ֵ�Ƿ���ȷ
        {
            printf("����ѡ��");
            scanf("%d",&n);
            if(n>4 || n<1)
            {
                puts("����������ѡ����ȷ��ѡ�");
                continue;       //  ���벻��ȷ����������
            }
            else
            {
                break;  //  ������ȷ���˳�ѭ��
            }
        }
        if( 1 == n )  //    ѧ����¼ϵͳ
        {
            puts("=========��ӭ��¼ѧ��ϵͳ=========");
            printf("�������˺ź�����\n");
            checkPerson_Msg(phead,1);


        }
        if( 2 == n )  //    ��ʦ��¼ϵͳ
        {
            puts("=========��ӭ��¼��ʦϵͳ=========");
            printf("�������˺ź�����\n");
            checkPerson_Msg(phead,2);

        }
        if( 3 == n )  //    ����Ա��¼ϵͳ
        {
            puts("=========��ӭ��¼����Աϵͳ=========");
            printf("�������˺ź�����\n");
            checkPerson_Msg(phead,3);

        }
        if( 4 == n )  //    �˳�ϵͳ
        {
            puts("@@@@@@@@@��ӭ�´ε�¼���ټ�!!!@@@@@@@@@");
            exit(0);        
        }
    }
}

/* ѧ����¼��Ĳ�������ѯ���޸� */
void Student_Mng(TotalNode *phead, char *Account,int n)
{
    switch(n)
    {
    case 1:     //  ��ѯ
        OutStudentNode(phead,Account);
        break;
    case 2:     //  ���
        InsertStudentNode(phead,Account);
        break;
    case 3:     //  ɾ��
        DeleteStudentNode(phead,Account);
        break;
    case 4: ;   //  ������ҳ��,�ϲ��Ѿ�ʵ�֣��˴�����Ҫ����
        break;
    default:
        puts("�쳣!");
        break;
    }
}

/* ��ʦ��¼��Ĳ�������ѯ���޸� */
void Teacher_Mng(TotalNode *phead, char *Account,int n)
{

    switch(n)
    {
    case 1: //  ��ѯѧ��ѡ�����
        OutTeacherNode(phead);
        break;
    case 2: //  ��Ӻ�ɾ���γ���Ϣ
        InsertTeacherNode(phead);
        break;
    case 3:     
        DeleteTeacherNode(phead);
        break;
    case 4:
        break;  //  �ϲ�ʵ���书��
    default:
        puts("�쳣!");
        break;
    }
}

/* ����Ա��¼��Ĳ�������ѯ���޸� */
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
        puts("�쳣!");
        break;
    }
}
/* ��ʾ�����ܵ�¼�����Ϣ */
void display_Detailed(TotalNode *phead ,char *Account,int n)
{
    int in;
    switch(n)
    {
    case 1:
        while(1)
        {
            printf("=========��ӭ%sͬѧ=========\n",Account);
            puts("[1]��ѯ��ѡ�γ�");  //  ��ѯ�Լ���ѡ�����пγ̰������γ̴��롢�γ����ơ��ο���ʦ
            puts("[2]��ӿγ�");        //  ������ѡ�γ�
            puts("[3]ɾ����ѡ�γ�");  //  ɾ����ѡ�γ�
            puts("[4]������ҳ��");
            printf("����ѡ��");
            scanf("%d",&in);
            if(4 == in)
            {
                return; //  �����ϲ��¼ҳ��
            }
            Student_Mng(pStudent,Account, in);
            //puts("[4]");
        }
        break;
    case 2:
        while(1)
        {
            printf("=========��ӭ%s��ʦ=========\n",Account);
            puts("[1]��ѯѧ��ѡ����Ϣ");    //  
            puts("[2]�����ʦ�γ���Ϣ");    //  
            puts("[3]ɾ����ʦ�γ���Ϣ");    //
            puts("[4]������ҳ��");
            printf("����ѡ��");
            scanf("%d",&in);
            if(4 == in)
            {
                return; //  �����ϲ��¼ҳ��
            }
            Teacher_Mng(pTeacher,Account, in);
        }
        //puts("[4]");
        break;
    case 3:
        printf("=========��ӭ%sͬ־=========\n",Account);
        puts("[1]��ѯѧ����ѡ�γ���Ϣ");
        puts("[2]�޸�ѡ����Ϣ");
        puts("[3]������ҳ��");
        scanf("%d",&in);
        Manager_Mng(Account, in);
        //puts("[4]");
        break;
    default:
        puts("�쳣!");
        break;
    }

}

/* ��֤�˺����� */
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
                printf("����������:");
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
            printf("�������˺�:");
        }
    }
}

/* У��ѧ������ʦ������Ա���˺� ���� */
void checkPerson_Msg(TotalNode *phead , int n)
{
    switch(n)
    {
        case 1: //  ѧ����¼    char studentAccount[20]; char studentPassword[20];  
            checkAccountandPassword(phead, studentAccount,studentPassword,n);
            break;
        case 2: //  ��ʦ��¼    char teacherAccount[20]; char teacherPassword[20];      
            checkAccountandPassword(phead, teacherAccount,teacherPassword,n);
            break;
        case 3: //  ����Ա��¼  char managerAccount[20]; char managerPassword[20];       
            checkAccountandPassword(phead, managerAccount,managerPassword,n);
            break;
        default:
            puts("�쳣!");
            break;
    }
}

/*  */

void main()
{
    TotalNode *phead=NULL;
    display(phead);}