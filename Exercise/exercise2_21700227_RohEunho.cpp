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
    node *head;

public:
    my_list();
    void add_to_head(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    void show_all_data();
    void insert_node(node t);
};

my_list::my_list()
{
    head = NULL;
}

void my_list::add_to_head(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
}

node my_list::delete_from_head()
{
    node temp;
    node *t;
    t = head;
    temp = *head;      // head값을 temp에 저장
    head = head->link; // 헤드는 헤드 다음값을 가리킨다.
    delete t;
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

bool my_list::list_empty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

void my_list::show_all_data()
{
    node *p;
    for (p = head; p != NULL; p = p->link)
        cout << p->name << ":" << p->score << endl;
}

void my_list::insert_node(node t)
{
    node *p; // parameter t를 저장할 node
    node *a_follow;
    node *a;
    a_follow = NULL; // head가르키는 한칸 뒤쳐져서 따라오는 노드
    a = head;        // head 다음 노드 가르키는 head 다음 노드

    // a = new node;
    p = new node;
    // a_follow = new node;
    (*p) = t; // p에 parameter t 저장
    p->link = NULL;

    if (head == NULL) // head가 null이면 첫 node로 추가
    {
        // (*p) = t;
        // p->link = head;
        // head = p;
        head = p;
        return;
    }

    while (a != NULL && a->score < t.score)
    {
        // 만약 a(다음 link)는 null이거나 또는 p의 score가 a_follow 보다 작을떼
        a_follow = a;
        a = a->link;
        // if (a != NULL && p->score > a_follow->score)
        // {
        //     // if (p->score <= a->score)
        //     // {
        //     //     a_follow->link = p;
        //     //     p->link = a;
        //     //     break;
        //     // }
        //     a_follow = a;
        //     a = a->link;
        //     continue;
        // }
        // else
        // {
        //     break;
        // }
        // // else
        // // {
        // //     a_follow->link = p;
        // //     p->link = a;
        // //     break;
        // // }
        // // if (a_follow == head->link)
        // // {
        // //     a_follow_follow = head;
        // // }

        // // if (a != NULL && p->score >= a_follow->score)
        // // {
        // // }

        // // else
        // // {
        // //     a_follow->link = p;
        // //     p->link = a;
        // //     break;
        // // }
    }
    if (a_follow == NULL)//노드가 한개밖에 없을때
    {
        p->link = head;
        head = p;
    }
    else//노드가 여러개이면
    {
        a_follow->link = p;
        p->link = a;
        return;
    }

    // return;

    // else if (p->score <= head->score) // 첫 노드보다 작은 값이면, 첫 노드로 추가
    // {
    //     // p->link = head;
    //     // head = p;
    //     add_to_head(t);
    //     return;
    // }
}

int main()

{

    my_list thelist;

    node tmp;

    tmp.set_data("Kim", 73.5);

    thelist.insert_node(tmp);

    tmp.set_data("Lee", 82.2);

    thelist.insert_node(tmp);

    tmp.set_data("Park", 51.3);

    thelist.insert_node(tmp);

    tmp.set_data("Choi", 95.1);

    thelist.insert_node(tmp);

    tmp.set_data("Ryu", 71.3);

    thelist.insert_node(tmp);

    tmp.set_data("Yang", 58.2);

    thelist.insert_node(tmp);

    tmp.set_data("Hong", 83.5);

    thelist.insert_node(tmp);

    cout << " The list after insertions \n";

    thelist.show_all_data();

    return 0;
}