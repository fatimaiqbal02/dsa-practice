#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define MAX 120
void capital_alphabet();
void small_alphabet();
void digital();
void gotoxy(int x, int y);
int randX();
int search(int x);
void insert(int num, int x, int y);
void delete_element(int x);
void delay(int delay);
int randomCapital();
int randomSmall();
int randomDigits();
void beginner();
void learner();
void expert();
int random1();
int random2();
int random3();

struct node
{
    int info;
    int x;
    int y;
    struct node *next;
} * list, *p, *q;

int score = 0;
int wrong = 0;
int t = 100;
int z;
int x = 0;
int a = 0;
int b[100];
int main()
{
    system("cls");
    int choice, x = 0;
    char A[] = "\n\t\t\tTyping Tutor\n\n\nThis game helps to improve your typing speed and sharpens your brain.Game has  three modes for the players. First is Begineers mode which is for basic typing,  next one is Learner mode which is designed for Medium typing speed and last one  is Expert Mode which is designed to sharpen your skills at their best \n \n Speed Level 1 : 10 - 99 milisecond delay \nSpeed Level 2 : 100 - 999 milisecond delay\nSpeed level 3 : 1 - 10 second delay\n\nGame consits of Capital Alphabets, Small Alphabets, and Numbers (0-9) which varies with different difficulty level\n\nThis game also consist of Score Card which displays your currant Score and also Consists of Missing Alphabets Counter displayed in the game.\n\n\t\t\tBackSpace to return to Main Menu.\n\n\t\t\t\tESC to Exit Game.\n\n\t";
    char E[] = "\n\n\t\t\tGame Developed by |*| Hashir Tariq |*| \n\n\n\t\t\t";
    for (int i = 0; E[i] != '\0'; i++)
    {
        printf("%c", E[i]);
        delay(100);
    }

    printf("|=========|      |===========================|       |=========|\n\t\t\t");
    printf("|<*><*><*>|      |<*><*><*><*><*><*><*><*><*>|       |<*><*><*>|\n\t\t\t");
    printf("|<*><*><*>|      |---------Main Menu---------|       |<*><*><*>|\n\t\t\t");
    printf("|<*><*><*>|      |<*><*><*><*><*><*><*><*><*>|       |<*><*><*>|\n\t\t\t");
    printf("|=========|      |===========================|       |=========|\n\t\t\t");
    printf("|<*><*><*>|      |1.  Capital Alphabets Mode |       |<*><*><*>|\n\t\t\t");
    printf("|<*><*><*>|      |2.  Small Alphabets Mode   |       |<*><*><*>|\n\t\t\t");
    printf("|<*><*><*>|      |3.  Digital  Mode          |       |<*><*><*>|\n\t\t\t");
    printf("|<*><*><*>|      |4.  Beginner  Mode         |       |<*><*><*>|\n\t\t\t");
    printf("|<*><*><*>|      |5.  Learner  Mode          |       |<*><*><*>|\n\t\t\t");
    printf("|<*><*><*>|      |6.  Expert  Mode           |       |<*><*><*>|\n\t\t\t");
    printf("|<*><*><*>|      |7.  Exit To Screen         |       |<*><*><*>|\n\t\t\t");
    printf("|--------------------------------------------------------------|\n\t\t\t");
    printf("|<*><*><*><*><*><*><*><*><*><*><*><*><*><*><*><*><*><*><*><*><*|\n\t\t\t");
    printf("|--------------------------------------------------------------|\n\t");

    while (1)
    {
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        system("cls");
        /* for (int i = 0; A[i] != '\0'; i++)
        {
            printf("%c", A[i]);
            delay(10);
        } */
        printf("Enter Speed value:\n\t");
        printf("Warning :: Enter speed range from 10 - 10,000\n\t\t");
        scanf("%d", &z);
        switch (choice)
        {
        case 1:
            capital_alphabet();
            break;
        case 2:
            small_alphabet();
            break;
        case 3:
            digital();
            break;
        case 4:
            beginner();
            break;
        case 5:
            learner();
            break;
        case 6:
            expert();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\n Invalid Choice \n");
            break;
        }
    }

    return 0;
}
void insert(int num, int x, int y)
{
    if (list == NULL)
    {
        list = (struct node *)malloc(sizeof(struct node));
        list->info = num;
        list->x = x;
        list->y = y;
        list->next = NULL;
        p = list;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        q = (struct node *)malloc(sizeof(struct node));
        q->info = num;
        q->x = x;
        q->y = y;
        q->next = NULL;
        p->next = q;
        p = q;
    }
}
int randX()
{
    int x = (rand() % 160) + 1;
    return x;
}
int randomCapital()
{
    int x = (rand() % 26) + 65;
    return x;
}
int randomSmall()
{
    int x = (rand() % 26) + 97;
    return x;
}
int randomDigits()
{
    int x = (rand() % 10) + 48;
    return x;
}
int random1()
{
    int x = (rand() % 47) + 65;
    while ((x > 90 && x < 97) || (x > 57 && x < 65))
        x = (rand() % 47) + 65;
    return x;
}
int random3()
{
    int x = (rand() % 64) + 48;
    while ((x > 90 && x < 97) || (x > 57 && x < 65))
        x = (rand() % 64) + 48;
    return x;
}
int random2()
{
    int x = (rand() % 64) + 48;
    while ((x > 90 && x < 97) || (x > 57 && x < 90))
        x = (rand() % 64) + 48;
    return x;
}
void delete_element(int x)
{
    q = p = list;
    while (p)
    {
        if (p->info == x)
        {
            if (p == list)
            {
                list = list->next;
                p = NULL;
                p = list;
            }
            else if (p->next != NULL)
            {
                q->next = p->next;
                p = NULL;
                p = q->next;
            }
            else
            {
                q->next = NULL;
                p = NULL;
                p = q;
            }
        }
        q = p;
        p = p->next;
    }
}
void traverse()
{
    system("cls");
    p = list;
    while (p->next)
    {
        gotoxy(p->x, p->y++);
        printf("%c", p->info);
        if (p->y <= 40)
        {
            p = p->next;
        }
        else
        {
            b[a++] = p->info;
            delete_element(p->info);
            traverse();
        }
    }
    gotoxy(p->x, p->y++);
    printf("%c\n", p->info);
    gotoxy(1, 40);
    printf("_______________________________________________________________________________________________________________________________________________________________________");
    gotoxy(1, 41);
    printf("Score: %d", score);
    gotoxy(70, 41);
    printf("Wrong Key Hits : %d", wrong);
    gotoxy(30, 41);
    printf("Time Left : %d ", t--);
    gotoxy(100, 41);
    printf("Digits Missed : %d", a);
    gotoxy(130, 41);
    printf("Characters Missed : ");
    for (int i = 0; i < a; i++)
    {
        printf("%c ", b[i]);
    }
}
void delay(int delay)
{
    int now = clock();
    int later = now + delay;
    while (now <= later)
    {
        now = clock();
    }
}
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void capital_alphabet()
{
    printf("hello");
    system("cls");
    printf("hello");
    do
    {
        if (kbhit())
        {
            char ch;
            scanf("%c", &ch);
            x = ch;
            if (search(ch) == 1)
            {
                score++;
                delete_element(ch);
            }
            else
            {
                wrong++;
            }
        }
        if (z >= 10 && z < 100)
        {
            printf("a");
            insert(randomCapital(),randX(), 0);
            traverse();
            delay(z);
        }
        else if (z >= 100 && z < 1000)
        {
            insert(randomCapital(),
                   randX(), 0);
            traverse();
            delay(z);
        }
        else if (z >= 1000 && z < 10000)
        {
            insert(randomCapital(),
                   randX(), 0);
            traverse();
            delay(z);
        }
        delay(z);
    } while (x != 27 && t > 0);
}
int search(int x)
{
    struct node *p;
    struct node *q;
    p = list;
    q = list;
    while (1)
    {
        if (x == p->info)
        {
            printf("%d", p->info);
            return p->info;
        }
        else
        {
            p = p->next;
            q = q + 1;
        }
    }
    return p->info;
}
void small_alphabet()
{
    system("cls");
    do
    {
        if (kbhit())
        {   
            char ch;
            scanf("%c", &ch);
            x = ch;
            if (search(x) == 1)
            { 
                score++;
                delete_element(ch);
            }
            else
            {
                wrong++;
            }
        }
        if (z >= 10 && z < 100)
        {
            insert(randomSmall(), randX(), 0);
            traverse();
            delay(z);
        }
        else if (z >= 100 && z < 1000)
        {
            insert(randomSmall(), randX(), 0);
            traverse();
            delay(z);
        }
        else if (z >= 1000 && z < 10000)
        {
            insert(randomSmall(), randX(), 0);
            traverse();
            delay(z);
        }
        delay(z);
    } while (x != 27 && t > 0);
}
void digital()
{
    system("cls");
    do
    {
        if (kbhit())
        {
            char ch;
            scanf("%c", &ch);
            x = ch;
            if (search(ch) == 1)
            {
                score++;
                delete_element(ch);
            }
            else
            {
                wrong++;
            }
        }
        if (z >= 10 && z < 100)
        {
            insert(randomDigits(), randX(), x);
            traverse();
            delay(z);
        }
        else if (z >= 100 && z < 1000)
        {
            insert(randomDigits(), randX(), x);
            traverse();
            delay(z);
        }
        else if (z >= 1000 && z < 10000)
        {
            insert(randomDigits(), randX(), x);
            traverse();
            delay(z);
        }
        delay(z);
    } while (x != 27 && t > 0);
}
void beginner()
{
    system("cls");
    do
    {
        if (kbhit())
        {
            char ch;
            scanf("%c", &ch);
            x = ch;
            if (search(ch) == 1)
            {
                score++;
                delete_element(ch);
            }
            else
            {
                wrong++;
            }
        }
        if (z >= 10 && z < 100)
        {
            insert(random1(), randX(), x);
            traverse();
            delay(z);
        }
        else if (z >= 100 && z < 1000)
        {
            insert(random1(), randX(), x);
            traverse();
            delay(z);
        }
        else if (z >= 1000 && z < 10000)
        {
            insert(random1(), randX(), x);
            traverse();
            delay(z);
        }
        delay(z);
    } while (x != 27 && t > 0);
}
void learner()
{
    system("cls");
    do
    {
        if (kbhit())
        {
            char ch;
            scanf("%c", &ch);
            x = ch;
            if (search(ch) == 1)
            {
                score++;
                delete_element(ch);
            }
            else
            {
                wrong++;
            }
        }
        if (z >= 10 && z < 100)
        {
            insert(random2(), randX(), x);
            traverse();
            delay(z);
        }
        else if (z >= 100 && z < 1000)
        {
            insert(random2(), randX(), x);
            traverse();
            delay(z);
        }
        else if (z >= 1000 && z < 10000)
        {
            insert(random2(), randX(), x);
            traverse();
            delay(z);
        }
        delay(z);
    } while (x != 27 && t > 0);
}
void expert()
{
    system("cls");
    do
    {
        if (kbhit())
        {
            char ch;
            scanf("%c", &ch);
            x = ch;
            if (search(ch) == 1)
            {
                score++;
                delete_element(ch);
            }
            else
            {
                wrong++;
            }
        }
        if (z >= 10 && z < 100)
        {
            insert(random3(), randX(), x);
            traverse();
            delay(z);
        }
        else if (z >= 100 && z < 1000)
        {
            insert(random3(), randX(), x);
            traverse();
            delay(z);
        }
        else if (z >= 1000 && z < 10000)
        {
            insert(random3(), randX(), x);
            traverse();
            delay(z);
        }
        delay(z);
    } while (x != 27 && t > 0);
}

