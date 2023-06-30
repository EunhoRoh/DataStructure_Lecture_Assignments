// 21700227 노은호
// Inflix -> Postfix

#include<iostream>
#include <string>
using namespace std;
#define SIZE 100
#define EOS '$'

class op_stack{
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

op_stack::op_stack(){
    top=0;
}

void op_stack::push(char x){
    s[top]=x;
    top++;
}

char op_stack::pop(){
    top--;
    return(s[top]);
}

bool op_stack::empty(){
    return (top==0);
}
char op_stack::top_element(){
    return(s[top-1]);
}

int op_stack::return_top(){ //stack의 top을 return하는 함수
    return top;
}

// bool is_operand(char ch){
//     if ((ch=='(')||(ch==')')||
//     (ch=='+')||(ch=='-')||
//     (ch=='*')||(ch=='/')||
//     (ch=='%')||(ch=='$'))
//         return false;
//     else
//         return true;
// }
bool is_operand(char ch){ //operand인지 확인하는 함수
    if((ch>='a')&&(ch<='z')||(ch>='A')&&(ch<='Z')){
        return true;
    }
    else   
        return false;
}

int get_precedence(char op)
{
    if((op=='$')||(op=='('))
        return(0);
    if((op=='+')||(op=='-'))
        return(1);
    if((op=='*')||(op=='/')||(op=='%'))
        return(2);
    return(-1);
}

int main(){
    string input, output;
    op_stack stack1;
    cout << "Input an infix expression to convert : ";
    cin >> input;
    // input += EOS;// input 끝에 eos 추가
    stack1.push(EOS);
    for (int i=0; i<input.size(); i++){ //들어가는 input 사이즈 만큼 반복
        if(is_operand(input[i])) //들어가는 수식의 index가 알파벳 즉, operand인지 파악
            output += input[i]; //operand이면 output string에 알파벳 하나를 추가한다.
        else //operand가 아니면
        {//(이나 )이나 $이나 + 이나 - 이나 * 이나 /이나 %일것이다. 
            if(input[i]=='(') {//'(' 이면 stack에 넣는다.
                stack1.push('(');
                continue;
            }
            else if (input[i]==')') //')'이면
            {
                while(1){//stack에서 '('이 나올때까지 pop하여 출력한다.
                    char pop_element = stack1.pop(); //stack1에서 pop해서 
                    if(pop_element=='(') // pop_element가 '('이라면 stack1에서 삭제
                        break;
                    output+=pop_element;
                }
            }
            else // input[i]가 operator라면 stack1 top 원소의 우선순위가 자신의 우선순위보다
            //낮아질때까지 pop하여 출력한다. 그리고 나서 해당 token을 stack에 넣느다. 
            {
                while(1){
                    char top_element = stack1.top_element();
                    if(get_precedence(input[i])<=get_precedence(top_element))
                        output+=stack1.pop();
                    else{
                        // output+=input[i];
                        stack1.push(input[i]);
                        break;
                    }
                }
            }
            
        }
        
    }
    //stack에 남아있는 것을 다 output에 저장하기
    for(int i=0; i<stack1.return_top(); i++ )
        output+=stack1.pop();
    //output 출력
    cout<<output;
}
