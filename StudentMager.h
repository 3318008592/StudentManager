#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct  Student
{
    long long number;
    char name[20];
    int score;
    /* data */
} Student;
typedef struct  Node
{
    Student stu;
    struct Node *next;
    /* data */
} Node;

void welcom();
void CreatStudent(Node*head);
void Print(Node *head);
void CountStudent(Node *head);
void FindStudent(Node *head);
void saveStudent (Node *head);
void localStudent (Node *head);
void modiyStudent(Node *head);
void deleteStudent(Node *head);
void bubbleStudent(Node*head);