//基于数组的栈
//适用于元素个数大体固定的情况

#include "Stack.h"
#include <vector>

using std::vector;

template<typename T>
class ArrayStack : public Stack<T>
{
private:
    vector<T> data;
    size_t topIndex;
public:
    explicit ArrayStack();
    ~ArrayStack();

    void clear() override;
    bool empty() override;
    T& top() override;
    void push(T element) override;
    void pop() override;
    size_t size() override;
};

template<typename T>
ArrayStack<T>::ArrayStack()
{
    topIndex = -1;
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
    clear();
}

template<typename T>
void ArrayStack<T>::clear()
{
    //释放vector中的内存
    vector<T> tmp;
    data.swap(tmp);
    topIndex = -1;

    return;
}

template<typename T>
bool ArrayStack<T>::empty()
{   
    return (-1 == topIndex);
}

template<typename T>
T& ArrayStack<T>::top()
{
    //TODO return null quote
    if( topIndex >= data.size() )
    {
        cout << "no element to top" << endl;
        abort();
    }

    return data[topIndex];
}

template<typename T>
void ArrayStack<T>::push(T element)
{
    data.push_back(element);
    topIndex += 1;

    return;
}

template<typename T>
void ArrayStack<T>::pop()
{
    if(topIndex < 0)
    {
        cout << "no element to pop" << endl;
        abort();
    }

    topIndex-=1;
    return;
}

template<typename T>
size_t ArrayStack<T>::size()
{
    return topIndex+1;
}


