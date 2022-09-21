#include <iostream>
using namespace std;
int fun(int n)
{
        
    if (n > 100){
        cout<<"\t"<<n-10<<endl;
        return n - 10;
        }
        cout<<"\t"<<n+11<<endl;
    return fun(fun(n + 11));
}
int main()
{
    int r;
    cout<<"---------------------\n\tSTACK\n---------------------"<<endl;
    cout<<"\t"<<95<<endl;
    r = fun(95);
    cout << "---------------------\n Final Output: " << r<<"\n---------------------";
    return 0;
}