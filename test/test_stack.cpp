#include "../include/depend.h"
//#include "../stack/ArrayStack.h"
#include "../stack/LinkStack.h"
//#include "../stack/SharedArrayStack.h"

using std::cout;
using std::endl;

static int stackSize = 20;

int test_ArrayStack(Stack<int>& checkStack)
{
    for(int i = 0; i < stackSize; ++i)
    {
        checkStack.push(i);
    }

    if(stackSize != checkStack.size())
    {
        cout << "stack size error" << endl;
        return -1;
    }
    
    for(int i = 0; i < 9; ++i)
    {
        checkStack.pop();
    }

    if( (stackSize - 10) != checkStack.top() )
    {
        cout << "stack top error" << endl;
        return -1;
    }

    for(int i = 0; i < 11; ++i)
    {
        checkStack.pop();
    }

    if( !checkStack.empty() )
    {
        cout << "stack empty check error" << endl;
        return -1;
    }

    return 0;
}

int main()
{
    //ArrayStack<int> intStack;
    LinkStack<int> intStack;
    
    int ret = test_ArrayStack(intStack);
    if(0 == ret)
    {
        cout << "check Stack successfully" << endl;
    }
    
    return 0;
}


