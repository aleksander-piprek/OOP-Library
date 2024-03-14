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
        void removeBook(int *isbn);
        void displayBooks();
        void addMember(std::string *name, int *id, bool *status);
        void displayMembers();

        void borrowBook(int *isbn);
        void returnBook(int *isbn);
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

        const std::string getTitle()     { return *title; }
        const std::string getAuthor()    { return *author; }
        const int getIsbn()              { return *isbn; }
        const std::string getGenre()     { return *genre; }
        const bool getAvailability()     { return *availability; }

        void setAvailability(bool change){ *availability = change;}            
};

class Member : public Library
{
    std::string* name;
    int* id;
    bool* status;

    public:
        Member(std::string *name, int *id, bool *status);
        ~Member();

        const std::string getName()      { return *name; }
        const int getId()                { return *id; }
        const bool getStatus()           { return *status; }
};