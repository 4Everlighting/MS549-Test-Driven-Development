// MS549 Test Driven Development.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <Windows.h>

class Stack 
{
private:
    int* array;
    int size;
    int top;

public:
    Stack(int size) 
    {
        this->size = size;
        array = new int[size];
        top = -1;
    }

    ~Stack() 
    {
        delete[] array;
    }

    void push(int data) 
    {
        if (top == size - 1) 
        {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        array[++top] = data;
    }

    int pop() 
    {
        if (top == -1) 
        {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        return array[top--];
    }

    int peek() {
        if (top == -1) 
        {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return array[top];
    }

    bool isEmpty() 
    {
        return (top == -1);
    }
};

int main() 
{
    clock_t start, end;
    int length[] = {100000,1000000,10000000};
    for (auto size : length)
    {
        std::cout << "Length: " << size << std::endl;
        Stack stack(size);
        start = clock();
        for (int i = 0; i < size;i++)
        {
            stack.push(i);
        }
        end = clock();
        std::cout << "Push time: " << (end - start) << std::endl;
        start = clock();
        for (int i = 0; i < size; i++)
        {
            stack.pop();
        }
        end = clock();
        std::cout << "Pop time: " << (end - start) << std::endl;
    }
    return 0;
    // Test the push method
    //stack.push(1);
    //stack.push(10);
    //stack.push(45);
    //stack.push(80);
    // Test the peek method
    // std::cout << "Top element is: " << stack.peek() << std::endl;
    // Test the pop method
    // std::cout << "Popped element is: " << stack.pop() << std::endl;
    // end = clock();
    // std::cout << (end - start) / 1000;
    // return 0;
}