#include <iostream>
#include <string>
using namespace std;
#define SIZE 100

class op_stack
{
private:
    char s[SIZE];
    int top;

public:
    op_stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
    int return_top();
};

op_stack::op_stack()
{
    top = 0;
}

void op_stack::push(char x)
{
    s[top] = x;
    top++;
}

char op_stack::pop()
{
    top--;
    return (s[top]);
}

bool op_stack::empty()
{
    return (top == 0);
}
char op_stack::top_element()
{
    return (s[top - 1]);
}

int op_stack::return_top()
{
    return top;
}

int main()
{
    string input, output;
    op_stack stack1;

    cout << "Input an infix expression to check error : ";
    cin >> input;
    int open_count = 0;  // count 변수는
    int close_count = 0; // 여는 괄호하고 닫는 괄호 갯수가 맞아야 한다.
    for (int i = 0; i < input.size(); i++)
    {
        // 만약 input[i]의 token이 '(','[','{'라면 stack에 push
        if (input[i] == '(' || input[i] == '[' || input[i] == '{')
        {
            stack1.push(input[i]);
            open_count += 1;
        }
        // 만약 input[i]의 token이 ')',']','}'라면 stack에서 pop하여 type을 비교
        else if (input[i] == ')' || input[i] == ']' || input[i] == '}')
        {
            // match 과정중 stack1이 empty가 되면 여는 괄호 부족
            if (stack1.empty())
            {
                if (input[i] == ')')
                {
                    cout << "Error: An extra close parenthesis \')\' is found";
                    return 0;
                }
                else if (input[i] == '}')
                {
                    cout << "Error: An extra close parenthesis \'}\' is found";
                    return 0;
                }
                else if (input[i] == ']')
                {
                    cout << "Error: An extra close parenthesis \']\' is found";
                    return 0;
                }
            }

            char top_element = stack1.pop();
            // stack에서 pop한 값과 input[i]가 match가 된다면
            if (top_element == '(')
            {
                if (input[i] == ')')
                    close_count += 1;
                else
                {
                    cout << "Error: mis-matched parenthesis, \')\' is expected.";
                    return 0;
                }
            }
            else if (top_element == '[')
            {
                if (input[i] == ']')
                    close_count += 1;
                else
                {
                    cout << "Error: mis-matched parenthesis, \']\' is expected.";
                    return 0;
                }
            }
            else if (top_element == '{')
            {
                if (input[i] == '}')
                    close_count += 1;
                else
                {
                    cout << "Error: mis-matched parenthesis, \'}\' is expected.";
                    return 0;
                }
            }

        }
    }
    string stack_elements;
    // input size만큼 반복했는데 stack에 아직 여는 괄호가 남아있다. -> 닫는괄호 부족
    if (!stack1.empty())
    {
        for (int i = 0; i < stack1.return_top(); i++)
        {
            stack_elements = stack_elements + stack1.pop() + " ";
        }
        cout << "Error: An extra open parenthesis \'" << stack_elements << "\' is found";
        return 0;
    }
    else if (open_count == close_count)
    {
        cout << "It's a normal expression";
    }
    else
        cout << "Undefined Error";
    return 0;
}