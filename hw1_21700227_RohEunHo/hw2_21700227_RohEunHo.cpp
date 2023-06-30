#include <iostream>
using namespace std;
#define SIZE 100

class mystack {
    int s[SIZE];
    int top;

    public:
        void init();
        void push(int x);
        int pop();
        bool stack_full();
        bool stack_empty();
};

void mystack::init(){
    top=0;
}

void mystack::push(int x){
    s[top]=x;
    top++;
}

int mystack::pop(){
    top--;
    return s[top];
}

bool mystack::stack_full(){
    if (top>=SIZE)
        return true;
    else
        return false;
}

bool mystack::stack_empty(){
    if(top==0)
        return true;
    else
        return false;
}

int main()
{
    mystack s1;
    int list[5] = {32, 123, 27, 131, 242}, i ,x;
    s1.init();
    for (i=0; i<5; i++)
        if(list[i]>100)
            s1.push(list[i]);
    while(!s1.stack_empty())
    {
        x=s1.pop();
        cout<<x<<endl;
    }
    return 0;
}