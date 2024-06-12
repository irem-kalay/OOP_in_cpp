#include<iostream>
using namespace std;


class Product
{
    public:
        string name;   
        float price;

        Product(){};
        Product(string n, float p){ this->name = n; this->price= p;}
};

const int N =5;
class Customer
{
    public:
        string customer_name;
        float credit_card_limit;   //1000 as default value
        Product list_of_ordered_products[N];
        int count_of_ordered_products;

        Customer(string cname, float cclimit);
        void operator+(Product P);
        float calculate_total_dept();
        void print();
};

Customer::Customer(string cname, float cclimit=1000)
{
    this-> customer_name= cname;
    this-> credit_card_limit= cclimit;
    count_of_ordered_products= 0;   //Initializes with zero at constructor

}

float Customer::calculate_total_dept()  //calculates and returns sum of prices
{
    float sum = 0;
    for(int i=0; i<count_of_ordered_products; i++)
    {
        sum += list_of_ordered_products[i].price;
    }
    return sum;
}

void Customer::operator+(Product P)
{
    float possible_dept= calculate_total_dept() + P.price;
    if(count_of_ordered_products == 5)  //When array is full.
    {   
        cout<<"\nAdd product : "<< P.name<<" "<< P.price<<endl;
        cout<<"Count of ordered products exceeded the maximum number.\nProduct add operation is not done.\n";
    }
    else if(possible_dept < credit_card_limit && count_of_ordered_products< N)
    {   
        list_of_ordered_products[count_of_ordered_products]= P;
        count_of_ordered_products++;
        cout<<"\nAdd product : "<< P.name<<" "<< P.price<<endl;
        cout<< "Product is added to customer successfully. \n";
    }
    else
    {   
        cout<<"\nAdd product : "<< P.name<<" "<< P.price<<endl;
        cout<< "Total debt exceeded the credit card limit.\nProduct add operation is not done.";
    }
}


void Customer::print()
{
    cout<<"\nCustomer name              : "<< customer_name<< endl;
    cout<<"Creadit card Limit         : "<< credit_card_limit;
    cout<<"\nCount of ordered products  : "<< count_of_ordered_products<< endl;
    cout<<"List of Ordered Products   :"<< endl;
    for(int i=0; i<count_of_ordered_products; i++)
    {
        cout<<i+1<<"."<< "  Name : "<< list_of_ordered_products[i].name<<"\tPrice : "<<list_of_ordered_products[i].price<<endl;
    }
    cout<<"TOTAL DEBT = " << calculate_total_dept()<< "\n\n";
    cout<<"***************************************************************************\n";
}

int main()
{
    Customer john("JOHN FISHER", 2000);
    Customer ronald("RONALD CRAIG");
    Customer thomas("THOMAS AUSTIN",750);

    //Creating Product objects
    Product Phone("Panasonic Phone  ", 800), Thosiba("Thosiba Battery  ",300), DVD("Kenwood DVD      ",400);
    Product Canon("Canon Battery    ",500), Nikon("Nikon Accessory  ",600), Yamaha("Yamaha Subwoofer ", 200);
    Product Whirlpool("Whirlpool Charger", 90), Logitech("Logitech Remote  ", 20), LG("LG Dryer         ", 100),
    Linksys("Linksys Router   ", 60), Nintendo("Nintendo Portable", 150), Mitsubishi("Mitsubishi Stand ", 50);
//Adding Products to the first customer John
    john + Phone;
    john + Thosiba;
    john + DVD;

    john.print();

//Adding Products to the second customer Ronald
    ronald + Canon;
    ronald + Nikon;
    ronald + Yamaha;

    ronald.print();

//Adding Products to the third customer Thomas
    thomas + Whirlpool;
    thomas + Logitech;
    thomas + LG;
    thomas + Linksys;
    thomas + Nintendo;
    thomas + Mitsubishi;

    thomas.print();



    return 0;
}