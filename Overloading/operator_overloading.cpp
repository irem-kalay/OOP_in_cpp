#include <iostream>
using namespace std;

class Complex
{
    private:
        int real;
        int img;

    public:
        void print_real_img()
        {
            cout<< "Complex Number is: "<< real << " +" <<" "<< img<<"i\n";
        }

        Complex(int r=0, int i=0)
        {
            real= r;
            img= i;
        }
    friend Complex operator+(Complex c1, Complex c2);
        
};

Complex operator+(Complex c1, Complex c2)   //This is for friend operator overloading
        {
            Complex temp;
            temp.real= c1.real + c2.real;
            temp.img= c1.img + c2.img;

            return temp;
        }

int main()
{
    Complex c1(3,7), c2(5,4), c3;

    c3 = c1 + c2;    //Operator overloaded , add fonksiyonunun ismini "operator+" olarak değiştirdim
    c3.print_real_img();

    return 0;
}