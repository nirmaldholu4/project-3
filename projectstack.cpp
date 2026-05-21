#include <iostream>
#include <string>
using namespace std;


class StackBase
{
public:
    virtual void push(string value) = 0;
    virtual void pop() = 0;
    virtual void topElement() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;
    virtual void display() = 0;
};

class Stack : public StackBase
{
private:
    string arr[100];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }

    void push(string value) override
    {
        if (topIndex == sizeof(arr) / sizeof(string) - 1)
        {
            cout << "Stack Is OverFlow..." << endl;
            return;
        }

        arr[++topIndex] = value;

        cout << "Stack Element Inserted Successfully..!!" << endl;
    }

    void pop() override
    {
        if (topIndex == -1)
        {
            cout << "Stack Is Empty...." << endl;
            return;
        }

        cout << "Stack Element Removed Successfully..!!" << endl;
        topIndex--;
        return;
    }

    void topElement() override
    {
        if (topIndex == -1)
        {
            cout << "Stack Is Empty...." << endl;
            return;
        }

        cout << "Top Element :- " << arr[topIndex] << endl;
    }

    void isEmpty() override
    {
        if (topIndex == -1)
        {
            cout << "Stack Is Empty...." << endl;
            return;
        }
        else
        {
            cout << "Stack Is Not Empty..." << endl;
        }
    }

    void isFull() override
    {
        if (topIndex == sizeof(arr) / sizeof(string) - 1)
        {
            cout << "Stack Is Full..." << endl;
            return;
        }
        else
        {
            cout << "Stack Is Not Full..." << endl;
        }
    }

    void display() override
    {
        if (topIndex == -1)
        {
            cout << "Stack Is Empty...." << endl;
            return;
        }

        cout << "==== Stack ELements ====" << endl;

        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};

int main()
{
    StackBase *stack = new Stack();

    while (true)
    {
        cout << endl;
        cout << "======== STACK MENU ========" << endl;
        cout << endl;

        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. TopElement" << endl;
        cout << "4. IsEmpty" << endl;
        cout << "5. IsFull" << endl;
        cout << "6. Display Data" << endl;
        cout << "0. Exit" << endl;

        cout << endl;

        int choice;
        cout << "Enter Your Choice :- ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            string name;

            cout << "Enter The String Value :- ";
            cin >> name;

            stack->push(name);
        }
        break;
        case 2:
            stack->pop();
            break;
        case 3:
            stack->topElement();
            break;
        case 4:
            stack->isEmpty();
            break;
        case 5:
            stack->isFull();
            break;
        case 6:
            stack->display();
            break;
        case 0:
            cout << "Exit Programme..." << endl;
            return 0;
            break;
        default:
            cout << "Invalid Choice..." << endl;
            break;
        }
    }
}