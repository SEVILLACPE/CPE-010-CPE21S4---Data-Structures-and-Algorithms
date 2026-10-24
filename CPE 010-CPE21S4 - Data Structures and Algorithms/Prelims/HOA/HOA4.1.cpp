#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() { return top == -1; }
};

bool isBalanced(const string &expr) {
    Stack s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return s.isEmpty();
}

int main() {
    string expressions[] = {"(A+B)+(C-D)", "((A+B)+(C-D)", "(A+B)+(C-D))", "((A+B)+(C-D))"};
    for (string expr : expressions) {
        cout << expr << " -> " << (isBalanced(expr) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}
