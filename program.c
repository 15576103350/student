#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void function();
void add();
void display();
void empty(int *node);
void display_name();
void del_name(int *node);
void mathmax();
void chmax();
void engmax();
void idrank(int node);
void scrank(int node);
void save(int node);
void read(int *node);
struct student
{
    int student_id;
    char name[10];
    char sex[10];
    int age;
    float height;
    float weight;
    int chinese;
    int math;
    int english;
    int total;
    struct student *next;
};

struct student *Lstu = NULL;
int main()
{
    function();
}
void function()
{
    char string[100];
    char str[100];
    int command = 0;
    int node = 0;
    while (1)
    {
        if (command == 10)
        {
            break;
        }
        printf("请输入'start'或'exit'：");
        scanf("%s", string);
        if (strcmp(string, "start") == 0)
        {
            printf("\t/*************************学生成绩管理系统***********************/\t\n");
            printf("\t/****************************************************************/\t\n");
            printf("\t/*****    add..............添加学生信息                     *****/\t\n");
            printf("\t/*****    display..........展示学生信息                     *****/\t\n");
            printf("\t/*****    empty....... ....清空数据                         *****/\t\n");
            printf("\t/*****    display_name.....打印指定学生信息                 *****/\t\n");
            printf("\t/*****    del_name.........删除指定学生信息                 *****/\t\n");
            printf("\t/*****    mathmax..........输出数学成绩最好的学生信息       *****/\t\n");
            printf("\t/*****    chmax............输出语文成绩最好的学生信息       *****/\t\n");
            printf("\t/*****    engmax...........输出英语成绩最好的学生信息       *****/\t\n");
            printf("\t/*****    idrank...........根据学号大小从大到小输出学生信息 *****/\t\n");
            printf("\t/*****    scrank...........根据总成绩从大到小输出学生信息   *****/\t\n");
            printf("\t/*****    exit.............退出系统                         *****/\t\n");
            printf("\t/****************************************************************/\t\n");
            printf("\t/****************************************************************/\t\n");
            printf("\n");
            read(&node);
            while (1)
            {
                printf("|add|display|empty|display_name|del_name|\n");
                printf("|mathmax|chmax|engmax|idrank|scrank|exit|\n");
                printf("请输入您的选项：");
                scanf("%s", str);
                if (strcmp(str, "add") == 0)
                {
                    add(&node);
                    save(node);
                    printf("\n");
                }
                else if (strcmp(str, "display") == 0)
                {
                    display();
                    printf("\n");
                }
                else if (strcmp(str, "empty") == 0)
                {
                    empty(&node);
                    save(node);
                    printf("\n");
                }
                else if (strcmp(str, "display_name") == 0)
                {
                    display_name();
                    printf("\n");
                }
                else if (strcmp(str, "del_name") == 0)
                {
                    del_name(&node);
                    save(node);
                    printf("\n");
                }
                else if (strcmp(str, "mathmax") == 0)
                {
                    mathmax();
                    printf("\n");
                }
                else if (strcmp(str, "chmax") == 0)
                {
                    chmax();
                    printf("\n");
                }
                else if (strcmp(str, "engmax") == 0)
                {
                    engmax();
                    printf("\n");
                }
                else if (strcmp(str, "idrank") == 0)
                {
                    idrank(node);
                    printf("\n");
                }
                else if (strcmp(str, "scrank") == 0)
                {
                    scrank(node);
                    printf("\n");
                }
                else if (strcmp(str, "exit") == 0)
                {
                    printf("退出系统！\n");
                    command = 10;
                    break;
                }
                else
                {
                    printf("非法输入！\n");
                }
                printf("\n");
            }
        }
        else if (strcmp(string, "exit") == 0)
        {
            printf("退出\n");
            break;
        }
        else
        {
            printf("非法输入！\n");
        }
    }
}
void add(int *node)
{
    struct student *stu;
    int n;
    printf("请输入要录入数据的个数：\n");
    scanf("%d", &n);
    printf("请输入要录入的学生的信息：\n");
    while (n--)
    {
        if (stu == NULL)
        {
            return;
        }
        stu = malloc(sizeof(struct student));
        printf("\t/*******************************/\t\n");
        printf("\t请输入学号：");
        scanf("%d", &stu->student_id);
        printf("\t请输入姓名：");
        scanf("%s", stu->name);
        printf("\t请输入性别：");
        scanf("%s", stu->sex);
        printf("\t请输入年龄：");
        scanf("%d", &stu->age);
        printf("\t请输入身高：");
        scanf("%f", &stu->height);
        printf("\t请输入体重：");
        scanf("%f", &stu->weight);
        printf("\t请输入数学成绩：");
        scanf("%d", &stu->math);
        printf("\t请输入语文成绩：");
        scanf("%d", &stu->chinese);
        printf("\t请输入英语成绩：");
        scanf("%d", &stu->english);
        printf("\t/*******************************/\t\n");
        stu->total = stu->math + stu->chinese + stu->english;
        stu->next = Lstu;
        Lstu = stu;
        (*node)++;
    }
    printf("录入数据成功！\n");
    printf("现在有%d个学生\n", *node);
}
void display()
{
    if (Lstu == NULL)
    {
        printf("对不起，您没有输入数据！\n");
        return;
    }
    struct student *p = Lstu;
    while (p)
    {
        printf("\t/*******************************/\t\n");
        printf("\t学号：%d 姓名：%s 性别：%s \n", p->student_id, p->name, p->sex);
        printf("\t年龄：%d 身高：%.1f  体重：%.1f\n", p->age, p->height, p->weight);
        printf("\t数学成绩：%d 语文成绩：%d 英语成绩：%d\n", p->math, p->chinese, p->english);
        printf("\t总成绩：%d\t\n", p->total);
        printf("\t/*******************************/\t\n");
        p = p->next;
    }
}
void empty(int *node)
{
    struct student *p = Lstu;
    while (p)
    {
        struct student *q = p->next;
        free(p);
        p = q;
    }
    Lstu = NULL;
    (*node) = 0;
    printf("学生信息已清空！\n");
}
void display_name()
{
    char name[20];
    printf("请输入要查询的学生姓名：");
    scanf("%s", name);
    struct student *p = Lstu;
    while (p)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("\t学号：%d 姓名：%s 性别：%s \n", p->student_id, p->name, p->sex);
            printf("\t年龄：%d 身高：%.1f  体重：%.1f\n", p->age, p->height, p->weight);
            printf("\t数学成绩：%d 语文成绩：%d 英语成绩：%d\n", p->math, p->chinese, p->english);
            printf("\t总成绩：%d\t\n", p->total);
            return;
        }
        p = p->next;
    }
    printf("没有找到该学生！\n");
}
void del_name(int *node)
{
    char name[20];
    printf("请输入要删除信息的学生姓名：");
    scanf("%s", name);
    struct student *p = Lstu;
    struct student *q = NULL;
    int count = 0;
    while (p)
    {
        if (strcmp(p->name, name) == 0)
        {
            if (q == NULL)
            {
                Lstu = p->next;
                free(p);
                p = Lstu;
            }
            else
            {
                q->next = p->next;
                free(p);
                p = q->next;
            }
            count++;
            (*node)--;
            printf("已删除姓名为 %s 的学生信息！\n", name);
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    if (count == 0)
    {
        printf("没有找到该学生！\n");
    }
}
void mathmax()
{
    struct student *p = Lstu;
    struct student *max = Lstu;
    while (p)
    {
        if (max->math < p->math)
        {
            max = p;
        }
        p = p->next;
    }
    printf("数学成绩最高的学生是：%s, 数学成绩为：%d", max->name, max->math);
}
void chmax()
{
    struct student *p = Lstu;
    struct student *max = Lstu;
    while (p)
    {
        if (max->chinese < p->chinese)
        {
            max = p;
        }
        p = p->next;
    }
    printf("语文成绩最高的学生是：%s, 语文成绩为：%d", max->name, max->chinese);
}
void engmax()
{
    struct student *p = Lstu;
    struct student *max = Lstu;
    while (p)
    {
        if (max->english < p->english)
        {
            max = p;
        }
        p = p->next;
    }
    printf("英语成绩最高的学生是：%s, 英语成绩为：%d", max->name, max->english);
}
void idrank(int node)
{
    printf("%d\n", node);
    struct student *q = Lstu;
    struct student *stu = malloc(sizeof(struct student) * node);
    for (int i = 0; i < node; i++)
    {
        stu[i] = *q;
        q = q->next;
    }
    struct student temp;
    for (int i = 0; i < node - 1; i++)
    {
        for (int j = 0; j < node - i - 1; j++)
        {
            if (stu[j].student_id < stu[j + 1].student_id)
            {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    printf("按学号从大到小排序后为\n");
    for (int i = 0; i < node; i++)
    {
        printf("\t/*******************************/\t\n ");
        printf("\t学号：%d 姓名：%s 性别：%s \n", stu[i].student_id, stu[i].name, stu[i].sex);
        printf("\t年龄：%d 身高：%.1f  体重：%.1f\n", stu[i].age, stu[i].height, stu[i].weight);
        printf("\t数学成绩：%d 语文成绩：%d 英语成绩：%d\n", stu[i].math, stu[i].chinese, stu[i].english);
        printf("\t总成绩：%d\t\n", stu[i].total);
        printf("\t/*******************************/\t\n");
    }
    free(stu);
}
void scrank(int node)
{
    printf("%d\n", node);
    struct student *q = Lstu;
    struct student *stu = malloc(sizeof(struct student) * node);
    for (int i = 0; i < node; i++)
    {
        stu[i] = *q;
        q = q->next;
    }
    struct student temp;
    int max = 0;
    for (int i = 0; i < node - 1; i++)
    {
        max = i;
        for (int j = i; j < node; j++)
        {
            if (stu[j].total > stu[max].total)
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = stu[i];
            stu[i] = stu[max];
            stu[max] = temp;
        }
    }
    printf("按总成绩从大到小排序后为\n");
    for (int i = 0; i < node; i++)
    {
        printf("\t/*******************************/\t\n ");
        printf("\t学号：%d 姓名：%s 性别：%s \n", stu[i].student_id, stu[i].name, stu[i].sex);
        printf("\t年龄：%d 身高：%.1f  体重：%.1f\n", stu[i].age, stu[i].height, stu[i].weight);
        printf("\t数学成绩：%d 语文成绩：%d 英语成绩：%d\n", stu[i].math, stu[i].chinese, stu[i].english);
        printf("\t总成绩：%d\t\n", stu[i].total);
        printf("\t/*******************************/\t\n");
    }
    free(stu);
}
void save(int node)
{
    FILE *fp;
    fp = fopen("data.txt", "w+");
    struct student *p = Lstu;
    if ((fp = fopen("data.txt", "w+")) == NULL)
    {
        printf("打开失败");
        return;
    }
    int i = 0;
    fprintf(fp, "%d", node);
    fprintf(fp, "\n");
    while (p != NULL)
    {
        fprintf(fp, "%d %s %s ", p->student_id, p->name, p->sex);
        fprintf(fp, "%d %.1f %.1f ", p->age, p->height, p->weight);
        fprintf(fp, "%d %d %d ", p->math, p->chinese, p->english);
        fprintf(fp, "%d", p->total);
        fprintf(fp, "\n");
        p = p->next;
    }
    printf("信息已保存！\n");
    fclose(fp);
}
void read(int *node)
{
    FILE *fp;
    fp = fopen("data.txt", "r+");
    if (fp == NULL)
    {
        printf("打开失败！\n");
        return;
    }
    struct student *stu;
    fscanf(fp, "%d", node);
    fscanf(fp, "\n");
    int a = *node;
    while (a)
    {
        stu = malloc(sizeof(struct student));
        fscanf(fp, "%d %s %s ", &stu->student_id, stu->name, stu->sex);
        fscanf(fp, "%d %f %f ", &stu->age, &stu->height, &stu->weight);
        fscanf(fp, "%d %d %d ", &stu->math, &stu->chinese, &stu->english);
        fscanf(fp, "%d", &stu->total);
        fscanf(fp, "\n");
        stu->next = Lstu;
        Lstu = stu;
        a--;
    }
    fclose(fp);
}
