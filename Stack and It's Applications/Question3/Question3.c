#include <stdio.h>
#include <stdlib.h>

#define max 20

int top = -1;
int stack[max];

void push(int data){ 
    stack[++top] = data;
}

int pop(){
    return stack[top--];
}

int isDigit(char c){
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int main(){
    char postfix[20];
    int i = 0;
    int a, b, res, num;

    printf("Enter a postfix expression: ");
    scanf("%[^\n]", postfix);

    while(postfix[i] != '\0'){
        
        if(postfix[i] == ' ' || postfix[i] == '\n'){
            i++;
            continue;
        }
        
        if(isDigit(postfix[i])){
            num = 0;

            while(isDigit(postfix[i])){
                num = (num * 10) + (postfix[i] - '0');
                i++;
            }

            push(num);
        }
        else{
            b = pop();
            a = pop();

            switch(postfix[i]){
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '%': res = a % b; break;
            }

            push(res);
            i++;
        }
    }

    printf("Final result : %d\n", pop());
    return 0;
}
