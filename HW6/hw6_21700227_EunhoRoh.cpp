#include <iostream>
#include <string>
using namespace std;
#define Q_SIZE 100

class book_info
{
public:
    string book_name;
    int page_number;
    int price;
    void set_data(string s1, int s2, int i1);
};

void book_info::set_data(string s1, int s2, int i1)
{
    book_name = s1;
    page_number = s2;
    price = i1;
}

class my_queue
{
    book_info q[Q_SIZE];
    int front, rear;

public:
    my_queue();
    void insert_q(book_info x);
    book_info delete_q();
    bool queue_full();
    bool queue_empty();
    book_info take_front();
};

my_queue::my_queue()
{
    front = 0;
    rear = 0;
}

void my_queue::insert_q(book_info x)
{
    if (!queue_full())
    {
        q[rear] = x;
        rear = (rear + 1) % Q_SIZE;
    }
}

book_info my_queue::delete_q()
{
    book_info tmp;
    if (!queue_empty())
    {
        tmp = q[front];
        front = (front + 1) % Q_SIZE;
        return (tmp);
    }
    else
    {
        cout << "Queue Empty!";
    }
}

book_info my_queue::take_front()
{
    book_info tmp;
    if (!queue_empty())
    {
        tmp = q[front];
        return (tmp);
    }
    else
    {
        cout << "Queue Empty!";
    }
}

bool my_queue::queue_full()
{
    if ((rear + 1) % Q_SIZE == front)
        return true;
    else
        return false;
}

bool my_queue::queue_empty()
{
    if ((rear == front))
        return true;
    else
        return false;
}

int main()
{
    my_queue a;

    book_info tmp;

    tmp.set_data("Don Quixote", 1605, 400);
    a.insert_q(tmp);

    tmp.set_data("Lord of the Rings", 1111, 1212);
    a.insert_q(tmp);

    tmp.set_data("Moby Dick", 1851, 6666);
    a.insert_q(tmp);

    int com;
    while (true)
    {
        cout << "\n-- Menu --\n\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Show the front book_info\n";
        cout << "4. Quit\n";
        cout << "\t\tSelect a command: ";
        cin >> com;

        if (com == 1)
        {
            string b_name;
            int p_num;
            int price;
            cout << "\nEnter book name: ";
            cin >> b_name;
            cout << "Enter book page number: ";
            cin >> p_num;
            cout << "Enter book's price: ";
            cin >> price;
            tmp.set_data(b_name, p_num, price);
            a.insert_q(tmp);
            cout << "\nData was inseted.\n";
        }
        else if (com == 2)
        {
            book_info tmp2 = a.delete_q();
            string b_name = tmp2.book_name;
            int p_num = tmp2.page_number;
            int price = tmp2.price;
            cout << "\nThe first node was deleted.\n";
            cout << "Deleted node's book name is " << b_name << ".";
            cout << "\nDeleted node's book page number is " << p_num << ".";
            cout << "\nDeleted node's book price is " << price << ".\n";
        }
        else if (com == 3)
        {

            book_info tmp3 = a.take_front();
            string b_name = tmp3.book_name;
            int p_num = tmp3.page_number;
            int price = tmp3.price;
            cout << "\nFront node's book name is " << b_name << ".\n";
            cout << "Front node's book page number is " << p_num << ".\n";
            cout << "Front node's book price is " << price << ".\n";
        }
        else if (com == 4)
        {
            cout << "\nSystem exited." << endl;
            break;
        }
        else
        {
            cout << "\nWrong number. Insert again.";
        }
    }
    cout << "Let's show all elements!\n";
    while (!a.queue_empty())
    {
        tmp = a.delete_q();
        cout << tmp.book_name << " : " << tmp.page_number << " : " << tmp.price << "\n";
    }
    return 0;
}
