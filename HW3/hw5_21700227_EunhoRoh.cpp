#include <iostream>
#include <string>
#include <algorithm>
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
    op_stack stack1;
    string word;
    // cin>>word;
    cout << "Insert the word to check palindrome: ";
    getline(cin, word);
    // std::remove 함수는 문자열 내의 공백을 검색해서 지우지만, 길이가 그대로 유지된다.
    // *첫 번째와 두 번째 매개변수는, 문자를 제거할 범위를 의미하고
    // 세 번째 매개변수는, 제거할 문자를 의미한다.
    // 따라서, std::erase 함수를 이용해서, 비어있는 문자열까지 삭제해야한다.
    // *첫 번째와 두 번째 매개변수는, 문자를 제거할 범위를 의미한다.
    word.erase(remove(word.begin(), word.end(), ' '), word.end());
    // cout<<word;
    int word_size = word.size();
    // word_size를 2만큼 나눈 것만큼 stack에 push 한다.
    for (int i = 0; i < word_size / 2; i++)
    {
        stack1.push(word[i]);
    }

    // word의 길이가 짝수일때
    if (word_size % 2 == 0)
    {
        for (int i = (word_size / 2); i < word_size; i++)
        {
            char top_element = stack1.pop();
            if (top_element != word[i])
            {
                cout << "\nNo, It's not a palindrome.";
                return 0;
            }
        }
    }
    // word의 길이가 홀수 일때
    else
    {
        for (int i = (word_size / 2 + 1); i < word_size; i++)
        {
            char top_element = stack1.pop();
            if (top_element != word[i])
            {
                cout << "\nNo, It's not a palindrome.";
                return 0;
            }
        }
    }
    cout << "\nYes, it's a palindrome." << endl;
    return 0;
}
