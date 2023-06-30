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
    my_list()
    {
        head = NULL;
    }
    void add_to_head(node t);
    void show_all_data();
    int node_count();                                         // 노드의 갯수 세는 함수
    double max_score();                                       // 노드의 최대 값 return
    void list_merge(my_list b);                               // linked list를 merge 시킨다.
    friend void make_array_fromlist(node array[], my_list a); // linked list를 array node list로 copy
};

void my_list::add_to_head(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
}

void my_list::show_all_data()
{
    node *p;

    for (p = head; p != NULL; p = p->link)
        cout << p->name << " : " << p->score << endl;
}

int my_list::node_count()
{
    node *p;
    int count = 0;
    for (p = head; p != NULL; p = p->link)
        count++;
    return count;
}
double my_list::max_score()
{
    // linked list의 최대값 출력
    node *p;
    // p = new node;
    // p=head;
    double high_score = 0.0;
    for (p = head; p != NULL; p = p->link)
    {
        if (high_score <= p->score)
        {
            high_score = p->score;
            p = p->link;
        }
    }

    // while(true){
    //     if(p==NULL)
    //         break;
    //     else{
    //         if(high_score<=p->score){
    //             high_score=p->score;
    //             p=p->link;
    //         }
    //     }
    // }
    return high_score;
}

void make_array_fromlist(node array[], my_list a)
{
    // node*[] p;
    // p = array[];
    node *p;
    p = new node;
    // node *a_receive;
    // a_receive = new node;
    // a_receive=a;
    p = a.head;
    node *s_array; // node 포인트 선언
    int n;
    n = a.node_count();    // a의 노드 수를 센다.
    s_array = new node[n]; // node array를 만든다.
    s_array = array;
    for (int i = 0; i < n; i++)
    {
        s_array[i].name = p->name;
        s_array[i].score = p->score;
        p = p->link;
    }
}

void my_list::list_merge(my_list b)
{
    node* p;
    p= new node;
    p = head; //p는 head를 가리킨다.
    int n=node_count();
    for(int i=0; i<n-1; i++){
        p=p->link;
    }
    p->link=b.head;
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

    cout << " --- The contents of the list A ---  \n";
    a.show_all_data();

    double max;

    max = a.max_score();
    cout << "\n\n The max. score  = " << max << endl;

    node *s_array; // node 포인트 선언
    int n;
    n = a.node_count();    // a의 노드 수를 센다.
    s_array = new node[n]; // node array를 만든다.

    make_array_fromlist(s_array, a);
    cout << "\n --- The contents of the array ---  \n";
    for (int k = 0; k < n; k++)
        cout << k << " : " << s_array[k].name << " : " << s_array[k].score << endl;

    my_list b;
    tmp.set_data("Bae", 88.4);
    b.add_to_head(tmp);
    tmp.set_data("Son", 67.2);
    b.add_to_head(tmp);
    tmp.set_data("Cho", 97.5);
    b.add_to_head(tmp);
    tmp.set_data("Kwon", 77.4);
    b.add_to_head(tmp);
    //linked list b를 a에 붙인다.
    a.list_merge(b);   // the list b is no longer available.
    cout << "\n\n --- The contents of the list A ---  \n";
    a.show_all_data();

    max = a.max_score();
    cout << "\n\n The max. score  = " << max << "\n\n";

    return 0;
}
