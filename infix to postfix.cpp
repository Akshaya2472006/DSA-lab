#include <iostream>
using namespace std;

char stack[100];
int top = -1;
char post[100];
char infix[100];

int pre(char sy) {
    switch (sy) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

bool isEmpty() {
    return (top == -1);
}

void push(char val) {
    stack[++top] = val;
}

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return ' ';
}

char peek() {
    return stack[top];
}

int main() {
    cout << "Enter the Expression: ";
    cin >> infix;

    int i = 0, j = 0;
    char temp;

    while (infix[i] != '\0') {
        char sy = infix[i];

        switch (sy) {
            case '(': 
                push(sy);
                break;

            case ')':
                while (!isEmpty() && (temp = pop()) != '(')
                    post[j++] = temp;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && pre(peek()) >= pre(sy))
                    post[j++] = pop();
                push(sy);
                break;

            default: // Operand
                post[j++] = sy;
        }
        i++;
    }

    while (!isEmpty()) {
        post[j++] = pop();
    }

    post[j] = '\0';

    cout << "Postfix Expression: " << post << endl;

    return 0;
}
