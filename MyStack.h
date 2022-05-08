#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>// assert()
#include <stdexcept>

template<typename T>
class MyStack {
    T *tab;
    int msize; // najwieksza mozliwa liczba elementow
    int Top; // pierwsza wolna pozycja
public:
    MyStack(int s = 10) : msize(s), Top(0) {
        tab = new T[s];
        assert(tab != nullptr);
    } // default constructor
    ~MyStack() { delete[] tab; }
    MyStack(const MyStack &other)
    {
        Top = other.Top;
        msize = other.msize;
        tab = new T[msize];

        for(int  i = 0; i < msize; ++i)
            tab[i] = other.tab[i];
    }// copy constructor
    MyStack(MyStack &&other) {
        Top = other.Top;
        msize = other.Top;
        tab = other.tab;

        other.Top = 0;
        other.msize = 0;
        other.tab = nullptr;
    }// move constructor
    MyStack &operator=(const MyStack &other)
    {
        delete [] tab;
        Top = other.Top;
        msize = other.msize;

        tab = new T[msize];

        for(int  i = 0; i < msize; ++i)
            tab[i] = other.tab[i];

        return *this;
    }// copy assignment operator, return *this
    MyStack &operator=(MyStack &&other){
        delete tab;

        Top = other.Top;
        msize = other.Top;
        tab = other.tab;

        other.Top = 0;
        other.msize = 0;
        other.tab = nullptr;

        return *this;
    }// move assignment operator, return *this
    bool empty() const { return Top == 0; } // checks if the container has no elements
    bool full() const {return Top == msize;}

    int size() const { return Top; }

    int max_size() const { return msize; }

    void push(const T &item);

    void push(T &&item);

    T &top(); // zwraca koniec, nie usuwa
    void pop(); // usuwa koniec
    void clear();

    void display();
};

template <typename T>
void MyStack<T>::push(const T &item) {
    if(Top + 1 > msize)
    {
        std::cout<< "Stos jest przeplniony. Nie mozna dodac noweych elementow.";
        return;
    }
    if (Top == 0){
        tab[Top] = item;
        Top++;
        return;
    }
    tab[Top] = item;
    Top++;
}
template <typename T>
void MyStack<T>::push(T &&item) {
    if(Top + 1 > msize)
    {
        std::cout<< "Stos jest przepelniony. Nie mozna dodac noweych elementow.";
        return;
    }
    if (Top == 0){
        tab[Top] = item;
        Top++;
        return;
    }
    tab[Top] = std::move(item);
    Top++;
}

template <typename T>
T& MyStack<T>::top() {
    if( empty()) {
        int ret = -1;
        T& rett = static_cast<T&>(ret);
        return rett;
    } else {
        return tab[Top - 1];
    }
}
template <typename T>
void MyStack<T>::pop() {
    if(empty())
        std::cout<<"Stos jest pusty"<<std::endl;
    else
    {
        Top --;
    }
}
template <typename T>
void MyStack<T>::clear() {
    if(empty())
        std::cout<<"Stos jest pusty!"<<std::endl;
    else
    {
        Top = 0;
    }
}
template <typename T>
void MyStack<T>::display() {
    if(empty())
        std::cout<<"Stos jest pusty!"<<std::endl;
    else{
        for(int i = Top - 1; i >= 0; i--)
        {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }
}
