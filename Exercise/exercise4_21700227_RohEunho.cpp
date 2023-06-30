#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string name;
    double score;
    node *left, *right;
    void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class my_tree
{
public:
    int node_count;                         // 현재 node 수
    node *root;                             // root를 가리키는 pointer
    my_tree();                              // 초기화
    int insert_root(node t);                // root로 node 내용 t추가
    int insert_left(string tname, node t);  // tname의 node 왼쪽에 t추가
    int insert_right(string tname, node t); // tname의 node 오른쪽에 t 추가

    double score_sum();          // 모든 node의 score합
    double score_average();      // 모든 node의 core 평균
    void print_data_inorder();   // inorder 순서로 모든 node의 값 출력
    void print_data_preorder();  // preorder 순서로 모든 node의 값 출력
    void print_data_postorder(); // postorder 순서로 모든 node의 값 출력
};

my_tree::my_tree()
{ // constructor :초기 empty 상태 설정
    node_count = 0;
    root = NULL;
}

int my_tree::insert_root(node t)
{
    if (root != NULL) // 루트에 값이 들어가 있으므로
        return 0;
    node *p;
    p = new node;
    (*p) = t;       // p라는 node 공간 확보해서 t 값 넣기
    p->left = NULL; // p의 left, right NULL로 만들기
    p->right = NULL;
    root = p; // root pointer로 하여금 p가리키기
    node_count++;
    return 1; // root에 넣으면 1 return;
}



double my_tree::score_sum()
{
    return sum_allnodes(root);
}

double sum_allnodes(node *p)
{
    if (p == NULL)
        return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
    // 자기의 left와 right와 자기자신을 더한다.
}

double my_tree::score_average()
{
    double sum = score_sum();
    double average = score_sum()/(float)node_count;
    return average;

}

int my_tree::insert_left(string tname, node tnode)
{
    /*
    return
    1: insert 과정 성공
    0: 'tname'을 갖는 node가 없음
    -1: 'tname'을 갖는 노드는 있으나 왼쪽이 NULL이 아닌경우
    */
    int result;

    result = node_insert_left(root, tname, tnode);
    // member 함수 아님, root 포인터 변수를 이용해 recursion 쓰려고
    if (result == 1) // result가 성공하면 insert하면 node 갯수 하나 증가
        node_count++;
    return result;
}

int node_insert_left(node *p, string tname, node tnode)
{
    int result;
    if (p == NULL)
        return 0; // p가 NULL이면 해당 tree가 없는 것이다.
    if (p->name == tname)
    {                        // 만약 root node의 name이 찾는 이름과 같으면
        if (p->left != NULL) // 그런데 p의 left가 NULL이 아니라 차있다면
            return -1;       // return -1 -> 차있어
        node *t;             // left가 차있지 않다면
        t = new node;        // t라는 포인터 노드의 새로운 공간 확보
        (*t) = tnode;        // 값 할당하고
        t->left = NULL;      // left, right NULL로 만들어 주고
        t->right = NULL;
        p->left = t; // p의 left 포인터 변수로 t를 가르키게 한다.
        return 1;    // 그리고 값을 집어넣었다고 return
    }
    else
    { // 만약 root의 이름이 tname이 아니라면
        result = node_insert_left(p->left, tname, tnode);
        // recursive call로 다시 p의 왼쪽 subtree부터 찾아간다.
        if (result != 0)   // 만약 result의 결과가 1이거나(insert 과정 성공),-1이면(왼쪽이 차있으면)
            return result; // 그냥 그 결과를 return한다.
        // 만약 result가 0이라면 즉, 'tname'을 갖는 node가 없다면
        //  오른쪽 subtree부터 다시 찾기 시작한다.
        return node_insert_left(p->right, tname, tnode);
    }
}


int my_tree::insert_right(string tname, node tnode)
{
    int result;

    result = node_insert_right(root, tname, tnode);
    if (result == 1)
        node_count++;
    return result;
}

int node_insert_right(node *p, string tname, node tnode)
{
    int result;
    if (p == NULL)
        return 0; // p가 NULL이면 해당 tree가 없는 것이다.
    if (p->name == tname)
    {                        // 만약 root node의 name이 찾는 이름과 같으면
        if (p->right != NULL) // 그런데 p의 right가 NULL이 아니라 차있다면
            return -1;       // return -1 -> 차있어
        node *t;             // left가 차있지 않다면
        t = new node;        // t라는 포인터 노드의 새로운 공간 확보
        (*t) = tnode;        // 값 할당하고
        t->left = NULL;      // left, right NULL로 만들어 주고
        t->right = NULL;
        p->right = t; // p의 rifht 포인터 변수로 t를 가르키게 한다.
        return 1;    // 그리고 값을 집어넣었다고 return
    }
    else
    { // 만약 root의 이름이 tname이 아니라면
        result = node_insert_right(p->left, tname, tnode);
        // recursive call로 다시 p의 왼쪽 subtree부터 찾아간다.
        if (result != 0)   // 만약 result의 결과가 1이거나(insert 과정 성공),-1이면(왼쪽이 차있으면)
            return result; // 그냥 그 결과를 return한다.
        // 만약 result가 0이라면 즉, 'tname'을 갖는 node가 없다면
        //  오른쪽 subtree부터 다시 찾기 시작한다.
        return node_insert_right(p->right, tname, tnode);
    }
}

void inorder_print(node *p)
{
    if (p == NULL)
        return;

    inorder_print(p->left);
    cout << p->name << " : " << p->score << "\n";
    inorder_print(p->right);
}

void my_tree::print_data_inorder()
{
    inorder_print(root);
}

void postorder_print(node *p)
{
    if (p == NULL)
        return;

    postorder_print(p->left);
    postorder_print(p->right);
    cout << p->name << " : " << p->score << "\n";
    

}

void my_tree::print_data_postorder()
{
    postorder_print(root);
}

void preorder_print(node *p)
{
    if (p == NULL)
        return;
    cout << p->name << " : " << p->score << "\n";
    postorder_print(p->left);
    postorder_print(p->right);
    
}

void my_tree::print_data_preorder()
{
    preorder_print(root);
}

int main()
{
    my_tree thetree;
    node tmp;
    tmp.set_data("Kim", 81.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 86.2);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 79.4);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 77.8);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 92.2);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 68.6);
    thetree.insert_right("Park", tmp);
    tmp.set_data("Yang", 72.8);
    thetree.insert_left("Ryu", tmp);
    tmp.set_data("Jung", 62.3);
    thetree.insert_left("Cho", tmp);

    cout << "Score Sum : " << thetree.score_sum() << "\n";
    cout << "Score Average : " << thetree.score_average() << "\n";
    cout << "\nInorder Traversal Result \n";
    thetree.print_data_inorder();
    cout << "\nPreorder Traversal Result \n";
    thetree.print_data_preorder();
    cout << "\nPostorder Traversal Result \n";
    thetree.print_data_postorder();

    return 0;
}