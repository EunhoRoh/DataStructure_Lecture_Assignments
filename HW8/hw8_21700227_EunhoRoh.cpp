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
    my_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    void show_all_data();
    int node_count();
    bool list_empty();
    int remove_a_node(string t_name);
    // 노드의 갯수 세는 함수
    double max_score();
    double min_score(); // 노드의 최대 값 return
    double average_score();
};

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

void my_list::add_to_tail(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if (tail != NULL)
        tail->link = p;
    else
        head = p;
    tail = p;
}

node my_list::delete_from_head()
{
    node temp; // for return
    node *t;
    t = head;          // for delete
    temp = *head;      // head값을 temp에 저장
    head = head->link; // 헤드는 헤드 다음값을 가리킨다.
    delete t;
    if (head == NULL)
        tail = NULL;
    return temp;
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
    node tmp;
    node *deleted_node;
    node *follow_node = NULL;

    for (lead_node = head; lead_node != NULL; lead_node = lead_node->link)
    {
        if (lead_node == head && lead_node->name == t_name)
        {
            tmp = delete_from_head();
            return 1;
        }
        else if (lead_node->name == t_name)
        {
            deleted_node = lead_node;

            follow_node->link = lead_node->link;
            delete deleted_node;
            return 1;
        }
        follow_node = lead_node;
    }
    return 0;
}

void my_list::show_all_data()
{
    node *p;

    for (p = head; p != NULL; p = p->link)
        cout << p->name << " : " << p->score << endl;
}

double my_list::average_score()
{
    node *p;
    double sum_score = 0;
    for (p = head; p != NULL; p = p->link)
    {
        sum_score += p->score;
    }
    double average = sum_score / node_count();
    return average;
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
    double max_score = 0.0;
    for (p = head; p != NULL; p = p->link)
    {
        if (max_score <= p->score)
        {
            max_score = p->score;
        }
    }
    return max_score;
}

double my_list::min_score()
{
    // linked list의 최대값 출력
    node *p;
    // p = new node;
    // p=head;
    double min_score = 1000.0;
    for (p = head; p != NULL; p = p->link)
    {
        if (min_score >= p->score)
        {
            min_score = p->score;
        }
    }
    return min_score;
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

    int com;
    while (true)
    {
        cout << "\n-- Menu --\n\n";
        cout << "1. Insert a node at head\n";
        cout << "2. Insert a node at tail\n";
        cout << "3. Delete a first node\n";
        cout << "4. Delete the element by name\n";
        cout << "5. Print all elements in order\n";
        cout << "6. Analysis of current elements\n";
        cout << "7. Quit\n\n";
        cout << "\t\tSelect a command: ";
        cin >> com;

        if (com == 1)
        {
            string name;
            double score;
            node tmp;

            cout << "\nEnter student's name: ";
            cin >> name;
            cout << "Enter student's score: ";
            cin >> score;
            tmp.set_data(name, score);
            a.add_to_head(tmp);
            cout << "\nData was inseted at head.\n";
        }
        else if (com == 2)
        {
            string name;
            double score;
            node tmp;
            cout << "\nEnter student's name: ";
            cin >> name;
            cout << "Enter student's score: ";
            cin >> score;
            tmp.set_data(name, score);
            a.add_to_tail(tmp);
            cout << "\nData was inseted at tail.\n";
        }
        else if (com == 3)
        {
            node tmp = a.delete_from_head();
            cout << "\nThe first node was deleted.\n";
            cout << "Deleted node's student's name is " << tmp.name << ".";
            cout << "\nDeleted node's student's score is " << tmp.score << ".\n";
        }
        else if (com == 4)
        {

            string name;
            int eval_num;
            node tmp;
            cout << "\nEnter student's name for deleting: ";
            cin >> name;
            eval_num=a.remove_a_node(name);
            if (eval_num == 1)
            {
                cout << "\nThe data that its name was " << name << " was deleted" << endl;
            }
            else
            {
                cout << "\nThere is no the data that its name is " << name << endl;
            }
        }
        else if (com == 5)
        {
            cout << "\nAll elements in order\n\n";
            a.show_all_data();
        }
        else if (com == 6)
        {
            cout << "\n<Analysis of All elements>\n\n";
            cout << "Number of elements: " << a.node_count() << '\n';
            cout << "The Maximum Score: " << a.max_score() << '\n';
            cout << "The Minimum Score: " << a.min_score() << '\n';
            cout << "The Average of all Scores: " << a.average_score() << '\n';
        }
        else if (com == 7)
        {
            cout << "\nSystme Out!" << endl;
            break;
        }
        else
        {
            cout << "\nWrong number. Insert again.";
        }
    }

    return 0;
}
