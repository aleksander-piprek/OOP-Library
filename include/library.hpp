#include <iostream>
#include <string.h>
#include <vector>

class Book;
class Member;

class Library
{ 
    std::vector<Book*> bookList;
    std::vector<Member*> memberList;     
   
    public:
        Library();
        ~Library();
        
        void addBook(std::string *title, std::string *author, int *isbn, std::string *genre, bool *availability);
        void removeBook(int isbn);
        void displayBooks();
        void addMember(std::string name, int id, bool status);
        void displayMembers();
};

class Book : public Library
{    
    std::string* title;
    std::string* author;
    int* isbn;
    std::string* genre;
    bool* availability;   

    public:
        Book(std::string* title, std::string* author, int* isbn, std::string* genre, bool* availability);
        ~Book();

        // std::string getTitle()     { return *title; }
        // std::string getAuthor()    { return *author; }
        // int getIsbn()              { return *isbn; }
        // std::string getGenre()     { return *genre; }
        // bool getAvailability()     { return *availability; }

};

class Member : public Library
{
    std::string* name;
    int* id;
    bool* status;

    public:
        Member(std::string *name, int *id, bool *status);
        ~Member();

        // std::string getName()      { return *name; }
        // int getId()                { return *id; }
        // bool getStatus()           { return *status; }
};