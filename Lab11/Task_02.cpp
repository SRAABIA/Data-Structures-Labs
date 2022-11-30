/*
Task 2
Given an array representation of min Heap, convert it to max Heap.
*/
#include<iostream>
#include<stdio.h>
using namespace std;
class heap{
    int capacity;
    int size;
    int*harr;
    int count;
    int*temparr;
    public:
    heap(int s){
        size = 0;
        count = 0 ;
        capacity = s;
        harr = new int[capacity];
        temparr = new int[capacity];
    }
    int parent(int i)   {   return (i - 1) / 2; }
    int left(int i) {   return (2 * i) + 1; }
    int right(int i)    {   return (2 * i) + 2; }
    void insert(int key){
        if (capacity == size){
            printf("\n\tHeap Overflow");
            return;
        }
        size++;
        int i = size - 1;
        harr[i] = key;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
        cout << endl
             << "\tKey inserted. " << harr[i];
        return;
    }
    void print()
    {   cout<<"\t  ";
        for (int i = 0; i < size; i++)
        {
            cout << harr[i] << " ";
        }
    }
    void MaxHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int max = i;
        if (l < size && harr[l] > harr[i])
        { // with parent
            max = l;
        }
        if (r < size && harr[r] > harr[max])
        {
            max = r;
        }
        if (max != i)
        {
            swap(harr[i], harr[max]); 
            MaxHeapify(max);
        }
    }
    void convert(){
        //starting from second last level
        for(int i = (capacity-2)/2 ; i>=0 ; i-- ){
            MaxHeapify(i);
        }
    }
};
int main(){
    int s = 6,k;
    // cout<<"\tCapacity of heap: ";cin>>s;
    heap obj(s);
    cout<<endl<<"\tMin Heap Insertion:"<<endl;
    int array[6] = {3, 5, 8, 17, 14, 21};
    for (int i = 0; i < 6; i++)
    {
        obj.insert(array[i]);
    }
    cout<<"\n\tPrinting Array representation of min heap:\n";
    obj.print(); 
    cout<<"\n\tConverting Min to MAX heap:\n";
    obj.convert();
    obj.print();
}