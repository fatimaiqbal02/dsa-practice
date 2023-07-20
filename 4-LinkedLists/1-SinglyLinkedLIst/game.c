#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void insert(char value, int n);
int len();
void deleteElement (char ch);
void display(int choice);
void scoreBoard(char ch);
int searchInLinkList(int data);

struct node
{
  char data;
  int x;
  struct node *next;
};

void gotoxy(int x, int y)
{
  COORD crd;
  crd.X = x;
  crd.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}
int score = 0;
int wrongCounter = 0;
int miss = 0;
struct node *head;

int main()
{
  int choice;
  gotoxy(60, 5);
  printf("======================");
  gotoxy(69, 6);
  printf("MENU");
  gotoxy(60, 7);
  printf("======================");
  gotoxy(60, 9);
  printf("1: DIGITS");
  gotoxy(60, 10);
  printf("2: CAPITAL ALPHABETS");
  gotoxy(60, 11);
  printf("3: SMALL ALPHABETS");
  gotoxy(60, 13);
  printf("======================");
  gotoxy(60, 14);
  printf("You Selected: ");
  gotoxy(60, 15);
  printf("======================");
  gotoxy(74, 14);
  scanf("%d", &choice);

  display(choice);
  return 0;
}

int searchInLinkList(int data)
{
  int search = 0;
  struct node *l = head;
  while (l){
    if (l->data == data){
      search = 1;
      return search;
    }
    l = l->next;
  }
  return search;
}
void insert(char value, int n)
{
  char ch;
  struct node *link = (struct node *)malloc(sizeof(struct node));
  link->data = value;
  link->x = n;
  link->next = head;
  head = link;
}

int len()
{
  int length = 0;
  struct node *temp;
  temp = head;
  while (temp != NULL)
  {
    length++;
    temp = temp->next;
  }
  return length;
}

void display(int choice)
{
  int i;
  int X;
  char ch, character;
  X = 0;
  char element;

  while (miss != 1)
  {
    ch = '0';
    if (choice == 1)
    {
      element = (rand() % (57 - 48 + 1)) + 48;
    }
    else if (choice == 2)
    {
      element = (rand() % (90 - 65 + 1)) + 65;
    }
    else if (choice == 3)
    {
      element = (rand() % (122 - 97 + 1)) + 97;
    }
    else
    {
      printf("you Entered Wrong key");
    }
    X = (rand() % (90 - 5 + 1)) + 5;
    insert(element, X);
    if (kbhit())
    {
      ch = getch();
      if (searchInLinkList(ch) == 1)
      {
        score++;
      }
      else if (searchInLinkList(ch) != 1)
      {
        wrongCounter++;
      }
    }
    else if (kbhit() == 0 && len() >= 25)
    {
      miss++;
    }
    if (score == 10)
    {
      gotoxy(40, 30);
      printf("===================");
      gotoxy(41, 31);
      printf("You Won the Game");
      gotoxy(40, 32);
      printf("===================");
      gotoxy(40, 33);
      Sleep(1000);
      exit(0);
    }
    else if (wrongCounter == 3)
    {
      gotoxy(40, 30);
      printf("====================");
      gotoxy(41, 31);
      printf("You loose the Game");
      gotoxy(40, 32);
      printf("====================");
      gotoxy(40, 33);
      Sleep(1000);
      exit(0);
    }
    character = (int)ch;
    scoreBoard(character);
    Sleep(1000);
  }
  gotoxy(40, 30);
  printf("=================");
  gotoxy(43, 31);
  printf("Game Over");
  gotoxy(40, 32);
  printf("=================");
  gotoxy(40, 33);
  Sleep(1000);
  exit(0);
}

void scoreBoard(char ch)
{
  int i;
  int y = 1;
  struct node *list;
  list = head;
  system("cls");
  gotoxy(9, 25);
  printf("=================================================================================\n");
  gotoxy(10, 26);
  printf("SCORES : %d", score);
  gotoxy(30, 26);
  printf("NO OF WRONG HITS : %d", wrongCounter);
  gotoxy(62, 26);
  printf("NO OF MISSED DIGITS: %d", miss);
  gotoxy(9, 27);
  printf("=================================================================================\n");
  while (list != NULL){
    gotoxy(list->x, y);
    printf("%c", list->data);
    y++;
    if (ch != '0'){
      deleteElement(ch);
    }
    list = list->next;
  }
}
void deleteElement(char ch){
  struct node *temp;
  temp = head;
  int i = 1;
  while (i < len() - 1){
    temp = temp->next;
    i++;
  }
  if (ch == temp->next->data){
    temp->next = NULL;
  }
}
