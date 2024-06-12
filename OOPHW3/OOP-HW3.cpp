#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <algorithm>
//irem kalay 820220334
using namespace std;



class Book
{
    public:
        int book_id;
        int publication_year;
        int author_ID;
        int publisher_ID;
        string book_title;

        Book(){};
        Book(int, int, int, int, string);
        void print(); //Displays all members data on screen

};


map <int, string > publishers;
map <int, string> authors;
map<int, Book> books;


Book::Book(int newBookID, int newPublication_year, int newAuthorID, int newPublisherID, string newBookTile)
{
    this->book_id= newBookID;
    this->publication_year= newPublication_year;
    this->author_ID= newAuthorID;
    this->publisher_ID=newPublisherID;
    this->book_title= newBookTile;
}
void Book::print()
{
    cout <<left<< setw(10)<< this->book_id << setw(18) << this->publication_year; 
    cout <<left<<setw(18)<< authors.at(author_ID);  //Taking author name from the map
    cout << this->book_title<< endl;                 
}




int main()
{
    int publisherID;
    string publisherName;


    ifstream publisherFile;
    ifstream authorFile("AUTHORS.TXT");
    ifstream bookFile;




    publisherFile.open("PUBLISHERS.TXT"); //File is opened and ready to be read
    bookFile.open("BOOKS.TXT"); //Book file is opened



 while(!authorFile.eof())
    {
        int authorID;
        string author_fullname;

        authorFile >> authorID;
        
        authorFile.ignore();

        getline(authorFile, author_fullname);

        if(authorFile.fail()) break;
        authors[authorID] = author_fullname;    //Putting names into map
    }




    while( !publisherFile.eof())    //While file is not end , it will continue to read
    {
        publisherFile >> publisherID;
        getline(publisherFile, publisherName);

        publishers[publisherID] = publisherName;    //Putting into map pair
    }



    while(!bookFile.eof())
    {
        Book b;
        bookFile >> b.book_id>> b.publication_year>> b.author_ID>> b.publisher_ID;
        getline(bookFile, b.book_title);

        books[b.book_id] = b;
    }



//iterator for publishers
    map<int, string>::iterator ite;
    ite=publishers.begin();

//Iterator for books
    map<int, Book>::iterator it;
    it= books.begin();

    //For Terminal
    cout<<"LISTS OF ALL BOOKS GROUPED BY PUBLISHERS"<< endl;
    cout<<"========================================\n";

while(ite != publishers.end())
{

     // Count the number of books for this specific publisher
        int bookCount = 0;
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->second.publisher_ID == ite->first) 
            {
                ++bookCount;
                
            }
        }


    //I convert publisher name's letters to uppercase with transform from algorithm library
    transform(ite->second.begin(), ite->second.end(), ite->second.begin(), :: toupper);

    cout <<left<<setw(18)<<"\nPUBLISHER ID"<<":  00"<<ite->first<< endl;
    cout <<left<<setw(16)<<"PUBLISHER NAME"<< " :"<<ite->second<<endl;
    cout<< left<< setw(17)<<"NUMBER OF BOOKS"<< ":  "<< bookCount<<"\n"<<endl;

    cout<<"BOOK_ID   PUBLICATION_YEAR   AUTHOR_FULLNAME    BOOK_TITLE\n";

 
    for (auto it = books.begin(); it != books.end(); ++it) 
    {
        if (it->second.publisher_ID == ite->first) 
        {
            it->second.print();    
        }
}


    cout<<"--------------------------------------------------------------------------------------------------\n";
    ite++;
}

//I count total books
int totalbooks=0;
map<int, Book>::iterator it2;
for(it2=books.begin(); it2!= books.end(); it2++)
{
    totalbooks++;
}

cout<<"\nTOTAL NUMBER OF ALL BOOKS : "<< totalbooks<<endl<<"\nProgram finished."<<endl;

//Closing all the files that opened for reading
    publisherFile.close();
    authorFile.close();
    bookFile.close();

    return 0;
}
