#include <iostream>
using namespace std;

class Complex
{
    private:
        int real;
        int img;

    public:
        void display()
        {
            cout<< real<<" + i"<< img;
        }

        Complex(int r=0, int i=0)
        {
            real= r;
            img= i;
        }
    friend Complex operator+(Complex c1, Complex c2);

    friend ostream& operator<<(ostream &o, Complex c1);
        
};

ostream& operator<<(ostream &o, Complex c1)
{
    o<< c1.real<< " + i"<< c1.img<<endl;
    return o;
}

Complex operator+(Complex c1, Complex c2)   //This is for friend operator overloading
        {
            Complex temp;
            temp.real= c1.real + c2.real;
            temp.img= c1.img + c2.img;

            return temp;
        }


int main()
{

    Complex c(10,5);
    cout<<c;

    return 0;
}