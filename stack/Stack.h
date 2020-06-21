#include<iostream>

template<typename T>
class Stack
{
private:

public:
    Stack() {}
    ~Stack() {}
    //virtual Status destroy() = 0;
    virtual void clear() = 0;
    virtual bool empty() = 0;
    virtual T& top() = 0;
    virtual void push(T element) = 0;
    virtual void pop() = 0;
    virtual size_t size() = 0;
};
