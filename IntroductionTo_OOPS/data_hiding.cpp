#include <iostream>
using namespace std;


class Rectangle
{
    private:
        int lenght;
        int breadth;

    public: //There can be 3 Types constructors

        //Non parametrized Constructor
      /*  Rectangle()
        {
            lenght=0;
            breadth=0;
        }
    */
        //Parametrized Constructor, now with the zeroes it is also a default constructor
        Rectangle(int l=0, int b=0)
        {
            setLenght(l);
            setBreadth(b);
        }

        //Copy Constructor
        Rectangle(Rectangle &r)
        {
            setLenght(r.getLength());
            setBreadth(r.getBreadth());
        }

        void setLenght(int l)
        {
            if(l>=0){
                lenght=l;
            }
            else{
                lenght=0;
                cout<<"Invalid length!\n ";
            }
        }
        void setBreadth(int b)
        {
            if(b>=0){
                breadth=b;
            }
            else{
                breadth=0;
                cout<<"Invalid breadth! \n";
            }
        }
        int getLength()
        {
            return lenght;
        }
        int getBreadth()
        {
            return breadth;
        }
        int area()
        {
            return breadth*lenght;
        }
        int perimeter()
        {
            return 2*(breadth + lenght);
        }
};

int main()
{
    Rectangle r1(10,5);
    cout<<r1.area()<<endl;

    Rectangle r2;   //Non parametrized constructor zero and zero
    cout<<r2.perimeter()<< endl;

    Rectangle r3(r1);   //The copy constructor
    cout<<r3.area()<<endl;

    return 0;
}