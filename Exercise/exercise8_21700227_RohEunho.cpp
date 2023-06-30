#include <iostream>
#include <string>

using namespace std;

class bst_node
{
public:
    string s_id;
    string name;
    double score;
    bst_node *left, *right;
    void set_data(string s1, string s2, double n);
    void print_data();
};

class bst_tree
{
    bst_node *root;
    int csize;

public:
    bst_tree();
    bst_node get_root();
    void insert_node(bst_node t);
    void show_inorder();
    void rotate_left();
    void rotate_right();
    bst_node search(string tid); // key 값으로 searh
};

bst_tree::bst_tree()
{
    root = NULL;
    csize = 0;
}

bst_node bst_tree::get_root()
{
    return *root;
}

void bst_node::set_data(string s1, string s2, double n)
{
    s_id = s1;
    name = s2;
    score = n;
}

void bst_node::print_data()
{
    cout << s_id << " : " << name << " : " << score << endl;
}

void inorder(bst_node *troot)
{
    if (troot == NULL)
        return;
    inorder(troot->left);                                                     // left subtree의 모든 node의 data값을 inorder 순서로 출력
    cout << troot->s_id << ":" << troot->name << ":" << troot->score << '\n'; // root node의 data값을 출력
    inorder(troot->right);                                                    // right subtree의 모든 node의 data값을 inorderㄹ 순서로 출력
}
void bst_tree::show_inorder()
{
    inorder(root);
}

void bst_tree::rotate_left()
{
    bst_node *p;
    bst_node *p_left;
    p = root->right; // 오른쪽 저장
    p_left = p->left;

    p->left = root;
    root->right = p_left;

    root = p;

    // root->right=p->left;//root right을 오른쪽의 left와연결
    // p->left=root; //p->왼쪽을 root와 연결
    // p=root; //p를 root로 설정
}

void bst_tree::rotate_right()
{
    bst_node *p;
    bst_node *p_right;
    p = root->left; // 오른쪽 저장
    p_right = p->right;

    p->right = root;
    root->left = p_right;

    root = p;
}

bst_node bst_tree::search(string tid)
{
    bst_node *p;
    p = root;
    if (root == NULL)
    {
        // 해당 node 없을때
        bst_node tmp;
        tmp.set_data("0000000", "None", -1);
        cout << "The key " << tid << "does not exist.\n";
        return tmp;
    }
    while (1)
    {
        if (p->s_id == tid) // 찾으면
            return (*p);    // p가 가리키는 내용 return
        if (p->s_id < tid)
        { // p의 학번이 주어진 tid보다 크면
            if (p->right == NULL)
            { // 해당 노드 없음 처리
                bst_node tmp;
                tmp.set_data("0000000", "None", -1);
                cout << "The key " << tid << "does not exist.\n";
                return tmp;
            }
            else
                p = p->right; // 못찾을때
        }
        else
        {
            if (p->left == NULL)
            {
                bst_node tmp;
                tmp.set_data("0000000", "None", -1);
                cout << "The key " << tid << "does not exist.\n";
                return tmp;
            }
            else
                p = p->left;
        }
    }
}

void bst_tree::insert_node(bst_node t)
{
    bst_node *p;
    bst_node *tmp;

    tmp = new bst_node; // 공간확보
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL; // insert하면 항상 leaf Node다.

    if (root == NULL)
    { // root가 없으면 바로 root로 만들기
        root = tmp;
        return;
    }
    p = root; // root로부터 시작해서
    while (1)
    {
        if (p->s_id == t.s_id)
        { // 이미 존재할때
            cout << "Insertion Failed : the Key" << t.s_id << " already exists." << endl;
            return;
        }
        if (p->s_id < t.s_id)
        {
            if (p->right == NULL)
            {                   // child가 NULL일때
                p->right = tmp; // temp에 연결
                return;
            }
            else // 있으면 전진시켜서 다시 비교
                p = p->right;
        }
        else
        { // 만약 t.s_id가 p->s_id 보다 작으면
            if (p->left == NULL)
            { // 왼쪽부터 비교
                p->left = tmp;
                return;
            }
            else
                p = p->left;
        }
    }
}

int main()
{
    bst_node temp;
    bst_tree t1;
    temp.set_data("22200147", "Kim", 65);
    t1.insert_node(temp);
    temp.set_data("22200365", "Lee", 88);
    t1.insert_node(temp);
    temp.set_data("22200044", "Park", 92);
    t1.insert_node(temp);
    temp.set_data("22200077", "Choi", 71);
    t1.insert_node(temp);
    temp.set_data("22200683", "Ryu", 54);
    t1.insert_node(temp);
    temp.set_data("22200246", "Cho", 63);
    t1.insert_node(temp);
    temp.set_data("22200011", "Yang", 79);
    t1.insert_node(temp);

    cout << "\n\nNode List : inorder sequence \n";
    t1.show_inorder();

    string s_key = "22200077";
    temp = t1.search(s_key);

    cout << "\n -- " << s_key << "'s record ---" << endl;
    cout << " Student ID   : " << temp.s_id << endl;
    cout << " Student Name : " << temp.name << endl;
    cout << " Score        : " << temp.score << endl;

    t1.rotate_left();
    temp = t1.get_root();
    cout << "\n\nAfter ROTATE_LEFT operation \n";
    cout << "-- the left child of the root : ";
    temp.left->print_data();
    cout << "-- the root : ";
    temp.print_data();
    cout << "-- the right child of the root : ";
    temp.right->print_data();
    t1.rotate_right();
    t1.rotate_right();
    temp = t1.get_root();
    cout << "\n\nAfter ROTATE_RIGHT operation \n";
    cout << "-- the left child of the root : ";
    temp.left->print_data();
    cout << "-- the root : ";
    temp.print_data();
    cout << "-- the right child of the root : ";
    temp.right->print_data();

    return 0;
}
