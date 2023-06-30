#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define SIZE 100
class node
{
public:
    char alphabet;
    node *link;
    void set_data(char alpha);
};

void node::set_data(char alpha)
{
    alphabet = alpha;
}

class p_stack
{
    node *top;

public:
    p_stack();
    void push(node t);
    node pop();
    bool stack_empty();
    int num_nodes();
    bool list_empty();
};

p_stack::p_stack()
{
    top = NULL;
}

void p_stack::push(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = top;
    top = p;
}

node p_stack::pop()
{
    node temp; // for return
    node *t;
    t = top; // for delete
    temp = *top;
    top = top->link;
    delete t; // 할당된 메모리 반환
    return temp;
}

int p_stack::num_nodes()
{
    node *t;
    int count = 0;
    for (t = top; t != NULL; t = t->link)
        count++;
    return count;
}

bool p_stack::list_empty()
{
    if (top == NULL)
        return true;
    else
        return false;
}



int main()
{
    p_stack linked_stack;
    string word;
    node alp;
    cout << "Insert the word to check palindrome: ";
    getline(cin, word);
    word.erase(remove(word.begin(), word.end(), ' '), word.end());
    int word_size = word.size();
    for (int i = 0; i < word_size / 2; i++)
    {
        // stack1.push(word[i]);
        alp.set_data(word[i]);
        linked_stack.push(alp);
    }
    // word의 길이가 짝수일때
    if (word_size % 2 == 0)
    {
        for (int i = (word_size / 2); i < word_size; i++)
        {
            node alp2 = linked_stack.pop();
            char node_element = alp2.alphabet;
            if (node_element != word[i])
            {
                cout << "\nNo, It's not a palindrome.";
                return 0;
            }
        }
    }
    else
    {
        for (int i = (word_size / 2 + 1); i < word_size; i++)
        {
            node alp2 = linked_stack.pop();
            char node_element = alp2.alphabet;
            if (node_element != word[i])
            {
                cout << "\nNo, It's not a palindrome.";
                return 0;
            }
        }
    }
    cout << "\nYes, it's a palindrome." << endl;
    return 0;
}