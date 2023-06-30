/*
21700227 노은호
linked list에서 작은 값 제거하는 함수 구현
*/

#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class my_list
{
    node *head, *tail;

public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    int remove_a_node(string t_name);
    bool list_empty();
    void show_all_data();
    void delete_low_score(double n);
};

my_list::my_list()
{
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if (tail == NULL)
        tail = p;
}

node my_list::delete_from_head()
{
    node temp;
    node *t;
    t = head;
    temp = *head;      // head값을 temp에 저장
    head = head->link; // 헤드는 헤드 다음값을 가리킨다.
    delete t;
    if (head == NULL)
        tail = NULL;
    return temp;
}

int my_list::num_nodes()
{
    node *t;
    int count = 0;
    for (t = head; t != NULL; t = t->link)
        count++;
    return count;
}

void my_list::delete_low_score(double n)
{
    node *t2; // return할 node이다. 값을 저장해준다.
    node *t;  // 제거할 node이다. 값이 작으면 node를 t에 준다.
    node *t3;
    node *t4;
    node *t_follow;
    node temp;
    t = head;

    if (t == NULL)
    {
        cout << "Node가 1개 밖에 없습니다.";
        return;
    }
    t = head->link;
    t_follow = head;
    while (true)
    {
        if (t == NULL) //다음 노드가 null이면 노드가 하나밖에 없다는 거지?
        {
            break;
        }
        if (t->score < n) //만약 노드가 점수가 낮으면
        {
            t2 = t->link; //앞에 노드를 t2에 저장
            t_follow->link = t2; //뒤에 따라오는 노드를 t2에 연결시킴
            t3 = t; //그리고 점수가 작은 노드를 t3로 가르킴, 제거하려고
            t = t2; //그리고 t2를 t로 가르킴
            delete t3;
            continue; //밑에 논리 실행 안시킴
        }
        t = t->link; //한칸씩 전진
        t_follow = t_follow->link;
    }
    if (head->score < n) //맨 앞에 점수가 n보다 작으면 이제 제거해주자.
        temp = delete_from_head();

    // for (t = head->link; t != NULL; t = t->link)
    // { // 다음 노드부터 시작해서 하나씩 체크

    //     if (t->score < n)
    //     { // 만약 t의 score 값이 n보다 작으면
    //         // 앞뒤 node를 어떻게 연결하지?
    //         t3=t;
    //         t2 = t->link;
    //         // t=t2->link;

    //         head->link = t2; // 앞뒤의 node를 연결
    //         // t3=t->link;
    //         t=head;
    //         delete t3;
    //     }
    // }
}

bool my_list::list_empty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

int my_list::remove_a_node(string t_name)
{
    node *lead_node;
    lead_node = new node;
    node *follow_node;
    follow_node = new node;
    for (lead_node = head; lead_node != NULL; lead_node = lead_node->link)
    {
    }
}

void my_list::show_all_data()
{
    node *p;
    for (p = head; p != NULL; p = p->link)
        cout << p->name << ":" << p->score << endl;
}

int main()
{
    my_list a;
    node tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 58.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 55.1);
    a.add_to_head(tmp);
    tmp.set_data("Ryu", 77.1);
    a.add_to_head(tmp);
    tmp.set_data("Yang", 41.3);
    a.add_to_head(tmp);
    tmp.set_data("Hong", 78.2);
    a.add_to_head(tmp);
    cout << "The list before deletion \n";
    a.show_all_data();
    a.delete_low_score(60.0);
    cout << "\n\nThe list after deletion \n";
    a.show_all_data();
    return 0;
}