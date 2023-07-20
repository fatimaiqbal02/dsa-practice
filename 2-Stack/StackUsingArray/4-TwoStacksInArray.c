#include<stdio.h>
    #define SIZE 8
    int arr[SIZE];
    int top1 = -1, top2 = SIZE;
int isEmptySt1(){
    if(top1 < 0 ){
        return 1;
    }return 0;
}
int isEmptySt2(){
    if(top2 == SIZE ){
        return 1;
    }return 0;
}
int isFull(){
    if(top1 == top2-1){
        return 1;
    }return 0;
}  
void pushSt1(int value){
    if(isFull()){
        printf("Stack 1 Overflow:\n %d Cannot be pushed into stack 1\n",value);
    }else{
        top1++;
        arr[top1] = value;
        printf("%d is pushed successfully into stack 1\n",value);
    }
}
void pushSt2(int value){
    if(isFull()){
        printf("Stack 2 Overflow:\n %d Cannot be pushed into stack 2\n",value);
    }else{
        top2--;
        arr[top2] = value;
        printf("%d is pushed successfully into stack 2\n",value);
    }
}
int popSt1(){
    int value;
    if(isEmptySt1()){
         printf("Stack 1 Underflow:\n Pop operation not possible:\n");
    }else{
        value = arr[top1];
        top1--;
        printf("%d is popped successfully fromt stack 1\n",value);
    }
    return value;
}
int popSt2(){
    int value;
    if(isEmptySt2()){
         printf("Stack 1 Underflow:\n Pop operation not possible:\n");
    }else{
        value = arr[top2];
        top2++;
        printf("%d is popped successfully fromt stack 2\n",value);
    }
    return value;
}
void displayStacks(){
    printf("First Stack:\n");
    for(int i = 0; i<=top1;i++){
        printf("%d \t",arr[i]);
    }
    printf("\nSecond Stack:\n");
    for(int i = SIZE-1; i>=top2;i--){
        printf("%d \t",arr[i]);
    }
}
int main(){
    if(isEmptySt1()){
        printf("Stack 1 is empty:\n");
    }else{
        printf("Stack 1 is not Empty:\n");
    }
    if(isEmptySt2()){
        printf("Stack 2 is empty:\n");
    }else{
        printf("Stack 2 is not Empty:\n");
    }
    pushSt1(2);
    printf("Value of Top1 = %d\n",top1);
    pushSt1(4);
    printf("Value of Top1 = %d\n",top1);
    pushSt1(6);
    printf("Value of Top1 = %d\n",top1);
    pushSt1(8);
    printf("Value of Top1 = %d\n",top1); 
   
    pushSt2(0);
    printf("Value of Top2 = %d\n",top2);
    pushSt2(3);
    printf("Value of Top2 = %d\n",top2);
    pushSt2(5);
    printf("Value of Top2 = %d\n",top2);
    pushSt2(7);
    printf("Value of Top2 = %d\n",top2);
    
    pushSt2(9);
    printf("Value of Top2 = %d\n",top2);
    pushSt1(10);
    printf("Value of Top1 = %d\n",top1);
    
/*     popSt2();
    pushSt1(10);
    printf("Value of Top1 = %d\n",top1); */

    popSt1();
    pushSt2(9);
    printf("Value of Top2 = %d\n",top2);
    displayStacks();
}
