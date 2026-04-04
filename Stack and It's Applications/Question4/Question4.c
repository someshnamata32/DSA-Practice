#include <stdio.h>

#define max 100

char stack[max];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int main(){
    char exp[max];
    int i;
    char ch;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(i = 0; exp[i] != '\0'; i++){

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }

        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){

            if(top == -1){
                printf("Expression is Invalid");
                return 0;
            }

            ch = pop();

            if(exp[i] == ')' && ch == '('){
                continue;
            }
            else if(exp[i] == '}' && ch == '{'){
                continue;
            }
            else if(exp[i] == ']' && ch == '['){
                continue;
            }
            else{
                printf("Expression is Invalid");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("Expression is Valid");
    else
        printf("Expression is Invalid");

    return 0;
}