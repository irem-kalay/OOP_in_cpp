#include<iostream>
using namespace std;

class Rectangle
{
    private:    //data hiding
        int lenght;
        int breadth;

    public:
        //Member functions

        void setLength(int l)
        {
            if(l>0)
                lenght=l;
            else
                lenght=0;
        }
        void setBreadth(int b)
        {
            if(b>0)
                breadth=b;
            else
                breadth=0;
        }

        int getLength(){return lenght;}
        int getBreadth(){return breadth;}
        int area()
        {
            return lenght*breadth;
        }
        int perimeter()
        {
            return 2*(lenght+breadth);
        }
};

class Cuboid:public Rectangle
{
    private:
        int height;

};



int main()
{

    Rectangle r1, r2;
    r1.setLength(10);
    r1.setBreadth(5);
    cout<<"Area " <<r1.area()<<endl;
    cout<<"Lenght "<< r1.getLength()<< endl;
    cout<<"Breadth "<< r1.getBreadth()<< endl;

    r2.setBreadth(-10);
    r2.setLength(5);

    cout<<r2.area()<< endl;

    return 0;
}