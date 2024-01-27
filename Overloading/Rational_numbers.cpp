#include <iostream>
using namespace std;

class Rational
{
    private:
        int p;  //Pay
        int q;  //Payda

    public:

    int get_p(){return this->p;}
    int get_q(){return this->q;}

    Rational(int p=0, int q=0)
    {
        this->p = p;
        this->q = q;
    }

    friend Rational operator+(Rational r1, Rational r2);
    friend ostream & operator<<( ostream &out, Rational &R);
};

ostream& operator<<(ostream &out, Rational &R)
{
    out<< R.p <<"/" << R.q;
    return out; //Bunu returnlediğimde mainde cout<< bir şeyler << bir şeyler
                //ikinci << operatörden sonra da yazmama izin veriyor.
                //eğer fonskiyon tipi void olsaydı ikinci operatörden sonra yazmama
                //izin vermezdi
}

Rational operator+(Rational r1, Rational r2)
{
    Rational temp(0,0);
    if(r1.q != 0 && r2.q !=0)
    {
        if(r1.q == r2.q)
        {
            temp.p= r1.p + r2.p;
            temp.q= r1.q;
            return temp;
        }else
        {
            temp.q = r1.q * r2.q;
            temp.p = (r1.p * r2.q) + (r2.p * r1.q);
            return temp;
        }
    }
    cout<<"It cannot be calculated "<< endl;
    return temp;
}

int main()
{

    Rational r1(3,4), r2(2,5), r3,r4(5,0);

    r3= r1+r2;
    //r3= r1+ r4;    It cannnot be calculated

    cout<<"Sum of "<< r1<< " and "<<r2<< " is "<< r3<< endl;

    return 0;
}