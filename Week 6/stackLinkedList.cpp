#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = NULL;
        }

        void push(int item) {
            Node* new_node = new Node(item);
            new_node->next = top;
            top = new_node;
        }

        int pop() {
            if (top == NULL) {
                cout << "Stack is empty\n";
                return -1;
            }
            Node* temp = top;
            int item = temp->data;
            top = top->next;
            delete temp;
            return item;
        }

        void stackTop() {
            if (top == NULL) {
                cout << "Stack is empty\n";
                return;
            }
            cout << top->data << "\n";
            return;
        }

        bool is_empty() {
            return top == NULL;
        }


        void display() {
            Node* current = top;
            Node* temp;

            if (top == NULL) {
                cout << "Stack is empty\n";
                return;
            }

            while (current != NULL) {
                int item = current->data;
                cout << item << " ";
                temp = current->next;
                current = temp;
            }
            cout << "\n";
            return;
        
        }

};

int main() {
    
    srand(time(NULL));
    auto start = high_resolution_clock::now();

    Stack s;

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop() ;
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
