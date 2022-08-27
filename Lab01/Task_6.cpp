#include<iostream>
using namespace std;
class Shape{
    private:
    string shape_name;
    public:
    Shape(){
    }
    void set_name(string h){ shape_name = h; }
    string get_name(){
        return shape_name;
    }
    ~Shape(){
    }
};
int main(){
    Shape *shapes  = new Shape[5];
    string name;
    for(int i = 0 ; i < 5 ; i++){
        cout<<"Shape name: ";
        cin>>name;
        shapes[i].set_name(name);
    }
    for(int i = 0 ; i < 5 ; i++){
        cout<<endl<<"Shape: "<<shapes[i].get_name();
    }
    delete[] shapes;
}

