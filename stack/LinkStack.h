//链栈

#include "Stack.h"

typedef struct StackNode
{
    int data;
    StackNode* next;
}StackNode, *StackNodePtr;

template<typename T>
class LinkStack : public Stack<T>
{
public:
    LinkStack();
    ~LinkStack();
    void clear() override;
    bool empty() override;
    T& top() override;
    void push(T element) override;
    void pop() override;
    size_t size() override;
private:
    StackNodePtr topPtr;
    size_t count;
};

template<typename T>
LinkStack<T>::LinkStack()
{
    count = 0;
    topPtr = nullptr;
}

template<typename T>
LinkStack<T>::~LinkStack()
{
    clear();
}

template<typename T>
void LinkStack<T>::clear()
{
    StackNodePtr tmp = nullptr;
    while(topPtr)
    {
        tmp = topPtr->next;
        delete topPtr;
        topPtr = tmp;
        --count;
    }
}

template<typename T>
bool LinkStack<T>::empty()
{
    return (nullptr == topPtr && 0 == count);
}

template<typename T>
T& LinkStack<T>::top()
{
    return topPtr->data;
}

template<typename T>
void LinkStack<T>::push(T element)
{
    StackNodePtr newNode = new StackNode();
    newNode->data = element;
    newNode->next = topPtr;
    topPtr = newNode;
    ++count;

    return;
}

template<typename T>
void LinkStack<T>::pop()
{
    StackNodePtr tmp = topPtr->next;
    delete topPtr;
    topPtr = tmp;
    --count;
}

template<typename T>
size_t LinkStack<T>::size()
{
    return count;
}