#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


class Stack {
    private:
        int *stack;
        int top;
        int capacity;

    public:
        Stack(int size = 100) {
            stack = new int[size];
            capacity = size;
            top = -1;
        }

        void push(int item) {
            if (top == capacity - 1) {
                cout << "Stack is full\n";
                return;
            }
            top++;
            stack[top] = item;
        }

        int pop() {
            if (top == -1) {
                cout << "Stack is empty\n";
                return -1;
            }
            int item = stack[top];
            top--;
            return item;
        }

        int stackTop() {
            if (top == -1) {
                cout << "Stack is Empty\n";
                return -1;
            }
            return stack[top];
        }

        bool is_empty() {
            return top == -1;
        }

        bool is_full(){
            return top == capacity - 1;
        }

        void display() {
            
            for(int i = top; i >= 0 ; i--){
                cout << stack[i] << " ";
            }
            cout << "\n";
        }
};

int main() {

    srand(time(NULL));
    auto start = high_resolution_clock::now();

    Stack s(10);

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
