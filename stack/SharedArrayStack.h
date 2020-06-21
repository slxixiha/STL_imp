//两栈共享存储空间,主要为了提示
//TODO 未完成

#include <vector>

using std::vector;

template<typename T>
class SharedArrayStack
{
private:
    vector<T> data;
    int topIndex1;
    int topIndex2;
    size_t totalSize;
public:
    SharedArrayStack(size_t totalSize);
    ~SharedArrayStack();
    void push(int stacknum, T element);
    void pop(int stacknum);
};

template<typename T>
SharedArrayStack<T>::SharedArrayStack(size_t tSize)
{
    totalSize = tSize;
    data.resize(tSize);
    topIndex1 = -1;
    topIndex2 = tSize;
}

template<typename T>
void SharedArrayStack<T>::push(int stacknum, T element)
{
    if(topIndex1 + 1 == topIndex2)
    {
        cout << "no mem to push" << endl;
        abort();
    }

    if(1 == stacknum)
    {
        data[++topIndex1] = element;
    }

    if(2 == stacknum)
    {
        data[--topIndex2] = element;
    }

    return;
}

template<typename T>
void SharedArrayStack<T>::pop(int stacknum)
{
    if(1 == stacknum)
    {
        if( topIndex1 < 0 )
        {
            cout << "no element to pop" << endl;
            abort();
        }

        --topIndex1;
    }

    if(2 == stacknum)
    {
        if( topIndex2 >= totalSize )
        {
            cout << "no element to pop" << endl;
            abort();
        }

        ++topIndex2;
    }

    return;
}


