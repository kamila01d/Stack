#include <iostream>
#include "MyStack.h"

int main() {

    MyStack<int> myStack;
    std::cout << "\n\tCreated stack myStack" << std::endl;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    std::cout << "\n\tmyStack after push(1), push(2), push(3): ";
    myStack.display();

    int a = 4;
    myStack.push(a);
    std::cout << "\n\tmyStack po after push(a): ";
    myStack.display();

    std::cout << "\n\tNumber of elements of the stack is: ";
    std::cout<<myStack.size()<<std::endl;

    std::cout << "\n\tLast added element is: ";
    std::cout<<myStack.top()<<std::endl;

    myStack.pop();
    std::cout << "\n\tmyStack after pop(): ";
    myStack.display();

    MyStack<int> myStack1(myStack); // konstruktor kopiujacy
    std::cout << "\n\tmyStack1 fter copy constructor MyStack<int> myStack1(myStack): ";
    myStack1.display();

    MyStack<int> myStack3(std::move(myStack1));
    std::cout << "\n\tmyStack3 MyStack<int> myStack3(std::move(myStack1)): ";
    myStack3.display();

    MyStack<int> myStack4;
    myStack4 = myStack3;
    std::cout << "\n\tCopy assigmnet opearotr myStack4 = myStack3: ";
    myStack4.display();

    MyStack<int> myStack5;
    myStack5 = std::move(myStack4);
    std::cout << "\n\tMove assigment opearator myStack5 = std::move(myStack4): ";
    myStack5.display();

    myStack5.clear();
    std::cout << "\n\tAfter myStack5.clear(), number of elements is: " << myStack5.size() << std::endl;


    return 0;
}
