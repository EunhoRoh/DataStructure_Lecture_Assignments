#include <iostream>
using namespace std;
class Weight{
    private:
        int kg;
        int g;
    public:
        void set_weight(int n1, int n2);
        int get_weight();
};

void Weight::set_weight(int n1, int n2){
    g = n2;  
    kg = n1;
}

int Weight::get_weight(){
    g = kg*1000+g;
    return g;
}

Weight add_weight( Weight &c1, Weight &c2){
    Weight new_weight;
    int new_kg = (c1.get_weight() + c2.get_weight())/1000;
    int new_g = (c1.get_weight() + c2.get_weight())%1000;
    new_weight.set_weight(new_kg, new_g );
    return new_weight;
}

bool less_than( Weight &c1, Weight &c2){
    if(c1.get_weight()<c2.get_weight())
        return true;
    else
        return false;
}


int main()
{
    Weight w1, w2, w3;
    w1.set_weight(3, 400);
    w2.set_weight(2, 700);
    w3 = add_weight(w1, w2);
    cout<< w3.get_weight() <<" grams\n";
    if(less_than(w1, w2))
        cout<<"yes.\n";
    else
        cout<<"no.\n";

    return 0;
}

