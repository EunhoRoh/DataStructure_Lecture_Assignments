#include <iostream>
#include <string>
using namespace std;

class element{
    public:
    string name;
    double score;
    void set_data(string n, double s);
};

void element::set_data(string n, double s){
    name=n;
    score=s;
}

#define HSIZE 100
class my_heap{
    element h[HSIZE];
    int csize;//the numbers of elements
    public:
    my_heap(); //size 초기화
    int h_size();//size 알기
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    void adjust(int t_root);
    my_heap(element a[],int n);
};
my_heap::my_heap(){
    csize=0;
}
bool my_heap::heap_empty(){
    if(csize==0)
        return true;
    else
        return false;
}

bool my_heap::heap_full(){
    if(csize>=HSIZE-1)
        return true;
    else
        return false;
}

int my_heap::h_size(){
    return csize;
}

void my_heap::insert_heap(element t){
    int k;
    csize++; //size 1증가
    k=csize; //끝원소 위치, 1부터 시작
    while((k!=1)&&(t.score>h[k/2].score)){ //k 가 1이 아닐때까지, left parent의 값이 주어진 t보다 작으면
    h[k]=h[k/2]; //chile에 parenet key 값 붙여넣기
    k/=2; //다시 parent 값으로 올리기
    }
    h[k]=t; //찾은 위치에다 넣기, 1이면 거기가 넣기
}

element my_heap::delete_heap(){
    element t;
    element tmp;
    int parent,child;

    t=h[1]; //for return value, root 원소
    tmp=h[csize];//끝원소, size 번째원소
    csize--; //size 줄이기
    parent=1;//root
    child=2; //root의 left child
    while(child<=csize){
        if((child<csize)&&(h[child].score<h[child+1].score))//오른쪽이 있고 오른쪽이 더 크면
            child++; //right child를 선택
        if(tmp.score>=h[child].score)//현재 원소가 아래 원소보다 이상이면 break
            break;
        h[parent]=h[child]; // 끓어올린다. child의 값을 parent로 올리기
        parent=child; //parent위치값을 한단계 내린다., 큰값 즉 올린 위치에 넣는 것이다.
        child*=2; //left로 내려간다., 다시 비교

    }
    h[parent]=tmp; // 현재 위치 값에 tmp를 넣는다.
    return t; //그리고 원래 root 값 return
}

void my_heap::adjust(int t_root) //root의 위치를 조정
{
    double tmpkey;
    int child;
    element tmp;

    tmp=h[t_root]; //root 기억
    tmpkey=h[t_root].score; //score
    child=2*t_root;//왼쪽

    while(child<=csize){//더이상 아래로 안 내려갈떼
        if((child<csize)&&(h[child].score<h[child+1].score))
            child++;
        if(tmpkey>h[child].score)//크면 끌어올리고 작으면 빠져나오기
            break;
        else{
            h[child/2]=h[child];
            child*=2;
        }

    }
    h[child/2]=tmp;// child보다 하나 큰 parent에 넣기
}

my_heap::my_heap(element a[],int n){
    int k;
    for(k=1;k<=n;k++)
        h[k]=a[k-1];
    csize=n;

    for(k=n/2; k>=1; k--)
        adjust(k);
}

int main(){
    my_heap h1;

    element temp;
    temp.set_data("Kim",88);
    h1.insert_heap(temp);
    temp.set_data("Lee",77);
    h1.insert_heap(temp);
    temp.set_data("Park",98);
    h1.insert_heap(temp);
    temp.set_data("Choi",74);
    h1.insert_heap(temp);
    temp.set_data("Ryu",94);
    h1.insert_heap(temp);
    temp.set_data("Cho",85);
    h1.insert_heap(temp);

    while (h1.h_size()>0){
        temp=h1.delete_heap();
        cout<<temp.name<<" : "<<temp.score<<'\n';
    }
    return 0;
    
}