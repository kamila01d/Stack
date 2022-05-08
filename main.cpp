#include <iostream>
#include "MyStack.h"

int main() {

    MyStack<int> myStack;
    std::cout << "\n\tUtworzono stos myStack" << std::endl;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    std::cout << "\n\tmyStack po operacji push(1), push(2), push(3): ";
    myStack.display();

    int a = 4;
    myStack.push(a);
    std::cout << "\n\tmyStack po operacji push(a): ";
    myStack.display();

    std::cout << "\n\tIlość elementów na stosie to: ";
    std::cout<<myStack.size()<<std::endl;

    std::cout << "\n\tOstatnio dodany element stosu: ";
    std::cout<<myStack.top()<<std::endl;

    myStack.pop();
    std::cout << "\n\tmyStack po operacji pop(): ";
    myStack.display();

    MyStack<int> myStack1(myStack); // konstruktor kopiujacy
    std::cout << "\n\tPo wywołaniu konstruktora kopiujacego MyStack<int> myStack1(myStack): ";
    myStack1.display();

    MyStack<int> myStack3(std::move(myStack1));
    std::cout << "\n\tPo wywołaniu konstruktora przenoszącego MyStack<int> myStack3(std::move(myStack1)): ";
    myStack3.display();

    MyStack<int> myStack4;
    myStack4 = myStack3;
    std::cout << "\n\tPo wywolaniu kopiujacego operatora przypisania myStack4 = myStack3: ";
    myStack4.display();

    MyStack<int> myStack5;
    myStack5 = std::move(myStack4);
    std::cout << "\n\tPo wywolaniu przenoszacego operatora przypisania myStack5 = std::move(myStack4): ";
    myStack5.display();

    myStack5.clear();
    std::cout << "\n\tPo operacji myStack5.clear(), liczba elementow na stosie wynosi: " << myStack5.size() << std::endl;


    return 0;
}
