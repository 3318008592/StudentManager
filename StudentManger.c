#include "StudentMager.h"
int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head ->next = NULL;
    localStudent (head);
    while ( 1 )
    {
    welcom();
    char c;
    c = _getch();
    switch ( c )
    {
    case '1':
        CreatStudent(head);
        /* code */
        break;
    case '2':
        Print(head);
        break;
    case '3':
        CountStudent(head);
        break;
    case '4':
        FindStudent(head);
        break;
    case '5':
        modiyStudent(head);
        break;
    case '6':
        deleteStudent(head);
        break;
    case '7':
        bubbleStudent(head);
        break;
    case '8':
    
        system("cls");
        printf("ByeBye");
        return 0;
    default:
    printf("请输入其他数字");
        break;
    }
        /* code */
    }
    
    return 0;
}
void welcom(){
    printf("1: 录入学生信息\n");
    printf("2 输出学生信息\n");
    printf("3 统计学生人数\n");
    printf("4 查照学生信息\n");
    printf("5 修改学生信息\n");
    printf("6 删除学生信息\n");
    printf("7 对学生进行排序\n");
    printf("8 退出系统\n");
}
void CreatStudent(Node*head){
    Node *fresh = (Node*)malloc(sizeof(Node));
    fresh ->next =NULL;
    Node *move = head;
    printf("输入学生的学号，姓名，成绩");
    scanf("%lld%s%d",&fresh->stu.number,fresh->stu.name,&fresh->stu.score);
    while ( move ->next != NULL)
    {
        move = move ->next;
        /* code */
    }
    move ->next = fresh;
    saveStudent(head);
    system ("cls");
}
void Print(Node *head){
    Node *move;
    move = head ->next;
    while ( move != NULL)
    {
        printf("%lld%s%d\n",move->stu.number,move->stu.name,move->stu.score);
        move = move->next;
        /* code */
    }
    system("pause");
    system("cls");
    
}
void CountStudent(Node *head){
    int count = 0;
    Node *move;
    move = head ->next;
    while(move != NULL) {
        move = move->next;
        count ++;
    }
    printf("%d",count);

}
void FindStudent(Node *head){
    long long number;
    printf("输入学神学号：\n");
    scanf("%lld",&number);
    Node* move;
    move = head ->next;
    while ( move  != NULL)
    {
        if ( move ->stu.number == number )
        {
            printf("%lld %s %d",move->stu.number,move->stu.name,move->stu.score);
            printf("找到了\n");
            system("pause");
            system("cls");
            return;
        }
        /* code */
        move = move ->next;
    }
    printf("没找到");
    system("pause");
    system("cls");
    
}
void saveStudent(Node* head){
    FILE *file = fopen("./stuinfo.txt","w");
    if ( file == NULL){
        printf("没有打开");
        return;
    }
    Node *move;
    move = head ->next;
    while (move != NULL)
    {
        if (fwrite (&move->stu,sizeof(Student),1,file) != 1)
        {
            printf("保存%s错误",move->stu.name);
            /* code */
        }
        move = move ->next;
        
        /* code */
    }
    fclose(file);
    
}
void localStudent (Node *head){
    FILE *file = fopen("stuinfo.txt","r");
    if ( !file){
        printf("没有这个文件\n");
        return;
    }
    Node *move;
    Node *fresh;
    move = head;
    fresh = (Node *)malloc(sizeof(Node));
        fresh ->next = NULL;
    
    while (fread(&fresh->stu,sizeof(Student),1,file) == 1)
    {
        
        move ->next = fresh;
        move = move ->next;
        fresh = (Node *)malloc(sizeof(Node));
        fresh ->next = NULL;

        /* code */
    }
    free (fresh);
    fclose(file);
    printf("读取成功\n"); 
    

}
void modiyStudent(Node *head){
    printf("输入想要修改的学生的学号\n");
    long long number;
    scanf("%lld",&number);
    Node* move;
    move = head ->next;
    while (move!= NULL )
    {
        if ( move->stu.number == number){
            printf(" 修改的姓名，成绩\n");
            scanf("%s%d",move->stu.name,&move->stu.score);
            printf("修改完成！\n");
            saveStudent(head);
            system("pause");
            system("cls");
            return;
        }
        move = move ->next;
        /* code */
    }
    printf("没找到你要修改的学生\n");
    system("pause");
    system("cls");
    
}
void deleteStudent(Node *head){

    printf("输入你要删除的学生学号\n");
    long long number;
    scanf("%lld",&number);
    Node *move;
    move = head;
    while ( move ->next != NULL)
    {
        if ( move ->next->stu.number == number)
        {
            Node *temp;
            temp = move ->next;
            move->next = move ->next ->next;
            free(temp);
            temp = NULL;
            printf("删除成功!\n");
            saveStudent(head);
            system("pause");
            system("cls");
            return;
        }
        move = move ->next;
        /* code */
    }
    printf("没有找到删除的学生!\n");
    system("pause");
    system("cls");
    
}
void bubbleStudent(Node *head){
    
    Node* move;
    Node *save = NULL;
    for (Node *turn = head ->next;turn ->next != NULL;turn = turn->next)
    {
        for( move = head ;move->next->next != save; move= move ->next)
        {
            if ( move ->next ->next->stu.score >move ->next->stu.score){
                Node *temp;
                temp = move ->next->next;
                move ->next->next = temp ->next;
                temp ->next = move->next;
                move ->next = temp;


            }

        }
        save = move->next;
    }
    printf("排序完成!\n");
    saveStudent(head);
    system("pause");
    system("cls");
}

