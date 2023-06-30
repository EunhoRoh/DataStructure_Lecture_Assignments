#include <iostream>
using namespace std;

int main(){

    int list[10] = {23, 11, 15, 8, 17, 33, 7, 14, 19, 21};

    int i;

    my_sort(list, 10);
    for(i=0; i<10; i++)
        cout<<list[i]<<"\n";
    return 0;
}