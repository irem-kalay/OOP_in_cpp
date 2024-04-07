#include <iostream>
using namespace std;

class Base
{
    public:
        Base()
        {
            cout<<"Non-param Base class"<< endl;
        }
        Base(int x)
        {
            cout<< "Parameter of Base class "<< x<< endl;
        }
};

class Derived: public Base
{
    public:
        Derived(){cout << "Non-param Derived class"<< endl;}
        Derived(int x){cout<< "Param of Derived class"<< x<< endl;}
        
        Derived(int x, int y):Base(x)   //Both parametrized constructors will be called
        {
            cout<< ""<< endl;
        }
};

int main()
{
    //Derived d;
    //Derived d(10);
    Derived d(5, 10);   //Constructors are called derived to base, but execution is from base to derived
                        //when we debug, we see that
}