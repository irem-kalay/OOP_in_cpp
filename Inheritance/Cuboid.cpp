#include <iostream>
using namespace std;


class Rectangle
{
    private:
        int lenght;
        int breadth;

    public: 
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
        bool isSquare();
        ~Rectangle();
};
Rectangle::~Rectangle()
{
    cout<< "Rectangle is destructed "<< endl;
}
bool Rectangle::isSquare()
{
    if(lenght == breadth)
    {
        return true;
    }else{
        return false;
    }
}


class Cuboid:public Rectangle
{
    private:
        int height;

    public:
        Cuboid(int h)
        {
            height= h;
        }
        int getHeight(){return height;}
        void setHeight(int h){ height=h;}
        int volume(){return height*getLength()*getBreadth();}   //Also I could use getarea() function
};


int main()
{
    Cuboid c(5);
    c.setLenght(10);
    c.setBreadth(7);

    cout<< "Volume is "<<c.volume()<< endl;

    return 0;
}