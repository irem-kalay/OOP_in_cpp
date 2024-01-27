#include <iostream>
using namespace std;


class Student
{
    private:
    int roll;
    string name;
    int mark1, mark2, mark3;

    public:
    void set_name(){cin >> this->name;}
    string get_name(){return this->name;}
    void set_roll(){cin>> this->roll;}
    void set_marks(){cin>> this->mark1 >> this->mark2>> this->mark3;}
    int get_roll(){return this->roll;}
    int total_mark();
    char Grade();
};

int Student::total_mark()
{
    return mark1+ mark2+ mark3;
}

char Student::Grade()
{
    if(total_mark()/3 >= 85)
    {
        return 'A';
    }
    else if(total_mark()/3 < 85 && total_mark()/3 > 50)
    {
        return 'B';
    }else{
        return 'C';
    }

}

int main()
{
    Student s;
    cout<< "Enter Roll number of a Student: ";
    s.set_roll();
    
    cout<< "Enter Name of a Student: ";
    s.set_name();

    cout << "Enter Marks in 3 subjects: ";
    s.set_marks();

    cout<< "Total Marks: "<<s.total_mark()<<"\n";

    cout << "Grade of Student: "<< s.Grade()<<"\n";

    return 0;
}