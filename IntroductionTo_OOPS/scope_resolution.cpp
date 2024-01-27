#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;

    public:
        Rectangle();
        Rectangle(int l, int b);
        Rectangle(Rectangle &r);
        int getLength();
        int getBreadth();
        void setLength(int l);
        void setBreadth(int b);
        int area();
        int perimeter();
        bool isSquare();
        ~Rectangle();  
};
int Rectangle::getLength()
{
    return length;
}
int Rectangle::getBreadth()
{
    return breadth;
}
void Rectangle::setLength(int l)
{
    if(l>=0){
        length=l;
    }
    else{
        length=1;
        cout<<"Invalid length \n";
    }
}

void Rectangle::setBreadth(int b)
{
    if(b>=0){
        breadth=b;
    }
    else{
        breadth=1;
        cout<<"Invalid breadth \n";
    }
}

Rectangle::Rectangle()  //Default Constructor
{
    length= 1;
    breadth=1;
}
Rectangle::Rectangle(int l, int b)  //Parametrized Constructor
{
    setLength(l);
    setBreadth(b);
}
Rectangle::Rectangle(Rectangle &r)  //Copy constructor
{
    setLength(r.length);
    setBreadth(r.breadth);
}

int Rectangle::area()
{
    return length*breadth;
}
int Rectangle::perimeter()
{
    return 2*(length+breadth);
}
bool Rectangle::isSquare()
{
    if(length==breadth){
        cout<<"It is a Square\n";
        return true;
    }else{
        cout<<"It is not a Square\n";
        return false;
    }
}

Rectangle::~Rectangle()
{
    cout<< "Rectangle destroyed \n";
}//Destructor
int main()
{

    Rectangle r1(10,5);

    r1.isSquare();
    cout<< "Perimeter: "<<r1.perimeter()<< endl;

    return 0;
}