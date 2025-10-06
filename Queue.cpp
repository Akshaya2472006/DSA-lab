#include <iostream>
#include <cstdlib>
using namespace std;

struct lnode {
    int data;
    struct lnode* next; 
};

typedef struct lnode node;

node* f = NULL; 
node* r = NULL; 

bool isEmpty() {
    return (f == NULL && r == NULL);
}

void enqueue(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        cout << "Out of memory\n";
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty()) {
        f = r = newNode;
    } else {
        r->next = newNode;
        r = newNode;
    }
    cout << val << " is enqueued.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        node* del = f;
        cout << f->data << " is dequeued\n";
        f = f->next;
        if (f == NULL) r = NULL; 
        free(del);
    }
}

void peek() {
    if (!isEmpty()) {
        cout << "Top Element: " << f->data << endl;
    } else {
        cout << "Queue is empty\n";
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty..\n";
        return;
    }
    node* temp = f;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    peek();
    display();
    dequeue();
    display();
    return 0;
}
