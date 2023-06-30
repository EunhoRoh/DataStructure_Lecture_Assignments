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
    int insert_root(node t);                // root로 node내용 t추가
    int insert_left(string tname, node t);  // tname의 node 왼쪽에 t 추가
    int insert_right(string tname, node t); // tname의 node 왼쪽에 t 추가

    double score_sum();          // 모든 node의 score 합
    double score_average();      // 모든 node의 core 평균
    void print_data_inorder();   // inorder 순서로 모든 node의 값 출력
    void print_data_preorder();  // preorder 순서로 모든 node의 값 출력
    void print_data_postorder(); // postorder 순서로 모든 node의 값 출력
    double max_score();
};

my_tree::my_tree()
{
    node_count = 0;
    root = NULL;
}

double sum_allnodes(node *p)
{
    if (p == NULL)
        return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

double my_tree::score_sum()
{
    return sum_allnodes(root);
}

double my_tree::score_average()
{
    double sum = score_sum();
    double average = score_sum() / (float)node_count;
    return average;
}

int my_tree::insert_root(node t)
{
    if (root != NULL)
        return 0;
    node *p;
    p = new node;
    (*p) = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count++;
    return 1;
}
int my_tree::insert_left(string tname, node tnode)
{
    int result;

    result = node_insert_left(root, tname, tnode);
    if (result == 1)
        node_count++;
    return result;
}

int node_insert_left(node *p, string tname, node tnode)
{
    int result;
    if (p == NULL)
        return 0;
    if (p->name == tname)
    {
        if (p->left != NULL)
            return -1;
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }
    else
    {
        result = node_insert_left(p->left, tname, tnode);
        if (result != 0)
            return result;
        return node_insert_left(p->right, tname, tnode);
    }
}
double my_tree::max_score()
{
    double result;

    result = find_maxscore(root);
    // if (result == 1) // result 1이라는 것은 넣었다는것
    //     node_count++;
    return result;
}

double find_maxscore(node *p)
{

    if (p == NULL)
        return 0; // p가 NULL이면 해당 tree가 없는 것이다.
    // 자 max값 p를 찾아보자
    //  만약
    double maxscore1 = p->score;
    double maxscore2 = find_maxscore(p->left);
    double maxscore3 = find_maxscore(p->right);

    if (maxscore1 < maxscore2)
    {
        maxscore1 = maxscore2;
    }
    if (maxscore1 < maxscore3)
    {
        maxscore1 = maxscore3;
    }
    return maxscore1;

    // if (p->score >= max_score)
    // { // 만약 root node의 name이 찾는 이름과 같으면
    //     if (p->left != NULL && p->right != NULL)
    //     {
    //         max_score = p->score;
    //         return max_score;
    //     } // 그런데 p의 right가 NULL이 아니라 차있다면
    //     max_score1 = p->score;
    //     return max_score;
    //     max_score = find_maxscore(p->left);
    //     // 그냥 그 결과를 return한다.
    //     // 만약 result가 0이라면 즉, 'tname'을 갖는 node가 없다면
    //     //  오른쪽 subtree부터 다시 찾기 시작한다.
    //     max_score2 = find_maxscore(p->right);

    //     // return -1 -> 차있어
    //     // node *t;              // left가 차있지 않다면
    //     // t = new node;         // t라는 포인터 노드의 새로운 공간 확보
    //     // (*t) = tnode;         // 값 할당하고
    //     // t->left = NULL;       // left, right NULL로 만들어 주고
    //     // t->right = NULL;
    //     // p->right = t; // p의 rifht 포인터 변수로 t를 가르키게 한다.
    //     // 그리고 값을 집어넣었다고 return
    // }
    // else // 만약 p->score가 max_score보다 크면 다음걸 찾아야지
    // {    // 만약 root의 이름이 tname이 아니라면
    //     max_score = find_maxscore(p->left);
    //     // 그냥 그 결과를 return한다.
    //     // 만약 result가 0이라면 즉, 'tname'을 갖는 node가 없다면
    //     //  오른쪽 subtree부터 다시 찾기 시작한다.
    //     max_score2 = find_maxscore(p->right);
    // }
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
    {                         // 만약 root node의 name이 찾는 이름과 같으면
        if (p->right != NULL) // 그런데 p의 right가 NULL이 아니라 차있다면
            return -1;        // return -1 -> 차있어
        node *t;              // left가 차있지 않다면
        t = new node;         // t라는 포인터 노드의 새로운 공간 확보
        (*t) = tnode;         // 값 할당하고
        t->left = NULL;       // left, right NULL로 만들어 주고
        t->right = NULL;
        p->right = t; // p의 rifht 포인터 변수로 t를 가르키게 한다.
        return 1;     // 그리고 값을 집어넣었다고 return
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

    cout << "the max. score  = " << thetree.max_score() << endl;

    string tname;
    cout << "The student name for score-search : "; // 점수를 검색하고자 하는 학생의 이름
    cin >> tname;
    double tscore = thetree.get_score_byname(tname);
    if (tscore < 0)
        cout << "\nThe name " << tname << " does not exist in the tree.\n\n";
    else
        cout << tname << "\'s score : " << tscore << endl;
    return 0;
}
