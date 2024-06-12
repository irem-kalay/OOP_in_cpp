#include<iostream>
#include <typeinfo>
#include <iomanip>
using namespace std;

//Represents all kinds of electric power plants
class Plant
{
    protected:
        string name;
        int megawatts;

    public:
        int year;
        
        Plant(string newName, int newMegawatts, int newYear)
        {
            this->name= newName;
            this->megawatts= newMegawatts;
            this->year= newYear;
        }
        virtual ~Plant(){}; //I added virtual destructor to be able to deallocate at the end the array of pointers allPlants
        virtual void plot()=0;  //Makes the class abstract
        virtual float getter()=0; //I added getter for calculating averages(I needed to access carbon and height)

};

class Coal : public Plant //Coal is derived from Plant
{
    private:
        float carbon;
    public:
    //The constructor using also Plant constructor
        Coal(string newName, int newYear, int newMegawatts, float newCarbon):Plant(newName, newMegawatts, newYear), carbon(newCarbon){}
        void plot(); //virtual plot function
        float getter(){return this->carbon;}
};
//The plot function for Coal
void Coal::plot()
{
    int numSymbols= this->megawatts/10;

    cout<<left<<setw(16)<< this->name<< setw(3)<< this->megawatts<<"   ";
    for(int i=0; i< numSymbols; i++)        
    {
        cout<< char(254);
    }
}

class Hydro : public Plant
{
    private:
        int height;
    
    public:
        Hydro(string newName, int newYear, int newMegawatts, int newHeight):Plant(newName, newMegawatts, newYear),height(newHeight){}
        void plot();
        float getter(){return (float)height;}
};

void Hydro::plot()
{
    int numSymbols= megawatts/100;
    cout<<left<<setw(16)<<this->name<< setw(5)<< this->megawatts<<" ";

    for(int i=0; i<numSymbols; i++)
    {
        cout<< char(177);
    }
    cout<< "\n";
}

//Making histogram for year
void makeHistogram(int year)
{
    for(int i=0; i<year; i++)
    {
        cout<< char(219);
    }
}


int main()
{
    Plant * allPlants[100];
    float avgCarbon=0.0, avgHeight=0.0;

    allPlants[0]= new Coal("Baihetan",2024 ,450 ,6.21);
    allPlants[1]= new Coal("Xiangji",2022 ,51 ,5.37);
    allPlants[2]= new Coal("Jaisalmer",2023 ,210 ,5.32);
    allPlants[3]= new Coal("Nyabarongo",2024 ,365 ,5.51);
    allPlants[4]= new Coal("Walney",2023 ,660 ,4.00);
    allPlants[5]= new Coal("Gateway",2023 ,405 ,5.18);
    allPlants[6]= new Coal("Vindhyachal",2023 ,520 ,5.92);
    allPlants[7]= new Coal("Taichung",2024 ,70 ,6.13);

    allPlants[8]= new Hydro("Yeongheung", 2023, 1800, 173);
    allPlants[9]= new Hydro("Kashiwazaki", 2022, 1330, 210);
    allPlants[10]= new Hydro("Coulee",2023,1209,135);
    allPlants[11]= new Hydro("Hongyanhe", 2024, 702, 195);
    allPlants[12]= new Hydro("Polaniec", 2022, 672,63);


int total=0, total2=0, year2=0, year3=0, year4=0;


cout<<"HISTOGRAM FOR ELECTRIC POWER PLANTS (MEGAWATTS):\n\n";
cout<< "COAL ELECTRIC PLANTS:\n";
    for(int i=0; i<13; i++)
    {
        if (typeid(*allPlants[i]) == typeid(Coal))
        {
            allPlants[i]->plot();
            avgCarbon += allPlants[i]->getter(); 
            cout<<"\n";
            total++;

            if(allPlants[i]->year== 2022)
            {
                year2++;
            }else if(allPlants[i]->year== 2023)
            {
                year3++;
            }else if(allPlants[i]->year== 2024)
            {
                year4++;
            }
        }
    }
  avgCarbon= avgCarbon/total; 
  cout<<"\nAverage Carbon Rate : "<< avgCarbon<< endl; 

cout<<"\n\n\nHYDRO ELECTRIC PLANTS:\n\n";

    for(int i=0; i<13; i++)
    {
        if (typeid(*allPlants[i]) == typeid(Hydro))
        {
            allPlants[i]->plot();
            cout<<"\n";

            avgHeight+= allPlants[i]->getter();
            total2++;

            if(allPlants[i]->year== 2022)
            {
                year2++;
            }else if(allPlants[i]->year== 2023)
            {
                year3++;
            }else if(allPlants[i]->year== 2024)
            {
                year4++;
            }
        }

    }
    avgHeight= avgHeight/total2;
    cout<<"Average Dam Height : "<< avgHeight<< endl;



cout<<"\n\n\nHISTOGRAMS FOR YEAR DISTRIBUTIONS:\n";
cout<<"YEAR 2022 ("<< year2<<") ";
makeHistogram(year2);

cout<<"\n\nYEAR 2023 ("<< year3<<") ";
makeHistogram(year3);

cout<<"\n\nYEAR 2024 ("<< year4<<") ";
makeHistogram(year4);


cout<<"\n\n";

//I am deallocating the spaces 
    for(int i=0; i<13; i++)
    {
        delete allPlants[i];
    }

    return 0;
}