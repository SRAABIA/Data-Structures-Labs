/*
Task 1
Suppose 7 is inserted into the heap. What will 7’s left and right children be?
Left child =? Right Child =?
First build the heap and then display the right and left child for node 7.
Then apply heapsort and display the array in descending order
*/
#include <iostream>
#include <stdio.h>
using namespace std;
class MinHeap
{
public:
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int c){
        heap_size = 0;
        this->capacity = c;
        harr = new int[capacity];
    }
    int parent(int i)   {   return (i - 1) / 2; }
    int left(int i) {   return (2 * i) + 1; }
    int right(int i)    {   return (2 * i) + 2; }
    void insert(int key){
        if (capacity == heap_size){
            printf("\nHeap Overflow");
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        harr[i] = key;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
        cout << endl
             << "Key inserted. " << harr[i];
        return;
    }
    void print()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << harr[i] << " ";
        }
    }
    void Children_of_7()
    {
        cout << "     7" << endl;
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == 7)
            {
                cout << harr[left(i)] << "\t" << harr[right(i)];
            }
        }
    }
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
        { // with parent
            smallest = l;
        }
        if (r < heap_size && harr[r] < harr[smallest])
        { // with left and with parent
            smallest = r;
        }
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]); // swap if i is not the smallest of three
            MinHeapify(smallest);          // since smallest is now index of where was the smallest value located so after changing we need to check if the new value is smallest parent or not
        }
    }
    int Extractmin()
    {
        if (heap_size == 0)
            return INT8_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0); // it will not included the repeated value as we are subtracting one from heap_size
        return root;
    }
    void Heapsort()
    {
        int*arr = new int[heap_size];

        for (int i = heap_size - 1; i >= 0; i--)
        {
            arr[i] = Extractmin();
        }
        for(int i = 0 ; i < capacity ; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    int s = 7;
    MinHeap obj(s);
    int array[6] = {3, 5, 8, 17, 14, 21};
    for (int i = 0; i < 6; i++)
    {
        obj.insert(array[i]);
    }
    cout << "\nInserting 7 in heap...";
    obj.insert(7);
    cout << endl
         << "Printing heap..." << endl;
    obj.print();
    printf("\nPrinting children of 7...");
    cout << endl;
    obj.Children_of_7();
    printf("\nApplying Heapsort: \n");
    obj.Heapsort();
}