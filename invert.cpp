#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    float score;
    node* next;
    void set_data(string n, float s) {
        name = n;
        score = s;
    }
};

class my_list {
public:
    node* head;
    my_list() {
        head = NULL;
    }
    void add_to_head(node& n) {
        n.next = head;
        head = &n;
    }
    node delete_from_head() {
        node tmp = *head;
        head = head->next;
        return tmp;
    }
    void invert() {
        node *prev = NULL; 
        node *current = head;
        node *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    friend bool list_equal(my_list a, my_list b);
};

bool list_equal(my_list a, my_list b) {
    node *current_a = a.head, *current_b = b.head;
    while (current_a != NULL && current_b != NULL) {
        if (current_a->name != current_b->name || current_a->score != current_b->score) {
            return false;
        }
        current_a = current_a->next;
        current_b = current_b->next;
    }
    return (current_a == NULL && current_b == NULL);
}

int main() {
    my_list a, b;
    node tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    a.add_to_head(tmp);

    tmp.set_data("Choi", 85.1);
    b.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    b.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    b.add_to_head(tmp);
    tmp.set_data("Kim", 83.5);
    b.add_to_head(tmp);

    b.invert();

    if (list_equal(a, b)) {
        cout << "Yes, the two lists are identical. \n";
    }
    else {
        cout << "No, They are not identical.\n";
    }

    tmp = b.delete_from_head();
    cout << tmp.name << " : " << tmp.score << "\n";
    return 0;
}