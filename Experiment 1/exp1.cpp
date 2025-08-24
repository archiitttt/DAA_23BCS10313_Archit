#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    int top;
    int capacity;
    T* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T data) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = data;
        cout << data << " pushed" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top--] << " popped" << endl;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }
};

int main() {
    Stack<int> st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top element: " << st.peek() << endl;
    st.pop();
    st.pop();
    cout << "Top element: " << st.peek() << endl;
    st.pop();
    st.pop();
    return 0;
}
