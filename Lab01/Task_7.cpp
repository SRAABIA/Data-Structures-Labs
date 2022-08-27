#include <iostream>
using namespace std;
class Shape
{
private:
    int length, width, *area;

public:
    Shape()
    {
        this->area = new int;
    }
    Shape(int len, int wid, int p)
    {
        this->length = len;
        this->width = wid;
        this->area = new int;
        *this->area = p;
    }
    Shape(const Shape &);
    Shape &operator=(const Shape &);
    void print();
    void set_ptr(int);
    ~Shape()
    {
        delete area;
    }
};
Shape ::Shape(const Shape &obj)
{ // copy constructor
    cout << "copy constructor" << endl;
    (this)->length = obj.length;
    (this)->width = obj.width;
    (this)->area = new int;
    *(this)->area = *(obj.area);
}
Shape &Shape ::operator=(const Shape &obj)
{ // copy assignment operator
    // cleaning old memory;
    delete area;
    this->area = new int;
    *this->area = *obj.area;
    return *this;
}
void Shape ::set_ptr(int i)
{
    *this->area = i;
}
void Shape ::print()
{
    cout << endl
         << "Length: " << this->length;
    cout << endl
         << "Width: " << this->width;
    cout << endl
         << "Area: " << *this->area;
}
int main()
{
    Shape s1(4, 3, 12);
    Shape s2 = s1; // copy constructor is invoked each time we creates an object and assign other object to it
    Shape s3(1, 2, 3);

    s3 = s1;

    cout << endl
         << "s3";
    s3.print();

    cout << endl
         << endl
         << "Changing value of area in s1 from 12 to 100";

    cout << endl
         << "IF COMMENTING OUT ASSIGNMENT OPERATOR" << endl
         << "Shallow Copy Is Being Done: Pointing to the same location" << endl
         << "Changing the value of S1 also changes the value inside S3 as we have assigned s3 to s1";
    cout << endl
         << "Since we have used pointers inside out class it gets mandatory to override our assignment operator";

    s1.set_ptr(100);

    cout << endl
         << "s1";
    s1.print();
    cout << endl
         << "s2";
    s2.print();
    cout << endl
         << "s3";
    s3.print();

    cout << endl
         << "Assignment copy operator" << endl
         << "Deep copy is being done." << endl
         << "Pointing to different memory location";
}