#include <iostream>
#include <string.h>
#include <vector>

class Library
{
    std::vector<Book*> bookList;
    std::vector<Member*> memberList; 
    public:
        Library() 
        {

        }
        ~Library() 
        {

        }
        void addBook(std::string title, std::string author, int isbn, std::string genre, bool availability)
        {
            auto newBook = new Book(&title, &author, &isbn, &genre, &availability);
            bookList.push_back(newBook);
            std::cout << "Created book: " << title << " by "<< author << " ISBN: " << isbn << " Genre: " << genre << " Availability: " << availability << std::endl;
        }
        void removeBook()
        {

        }
        void displayBooks()
        {

        }        
        void addMember(std::string name, int id, bool status)
        {
            auto newMember = new Member(&name, &id, &status);
            memberList.push_back(newMember);
            std::cout << "New member: " << name << " ID: " << id << " Membership status: " << status << std::endl;
        }
        void removeMember()
        {

        }
        void displayMembers()
        {

        }
};

class Book : public Library
{
    std::string* title;
    std::string* author;
    int* isbn;
    std::string* genre;
    bool* availability;   
    public:
        Book(std::string* title, std::string* author, int* isbn, std::string* genre, bool* availability)
        {
            this->title = new std::string(*title);
            this->author = new std::string(*author);
            this->isbn = new int(*isbn);
            this->genre = new std::string(*genre);
            this->availability = new bool(*availability);
        }
        ~Book()
        {
            delete this->title;
            delete this->author;
            delete this->isbn;
            delete this->genre;
            delete this->availability;
        }
};

class Member : public Library
{
    std::string* name;
    int* id;
    bool* status;
    public:
        Member(std::string *name, int *id, bool *status)
        {
            this->name = new std::string(*name);
            this->id = new int(*id);
            this->status = new bool(*status);
        }
        ~Member()
        {
            delete this->name;
            delete this->id;
            delete this->status;
        }
};

int main()
{
    auto library = new Library;
        
    library->addBook("Harry-Potter", "J.K. Rowling", 1, "Fantasy", true);

    library->addMember("Aleksander Piprek", 1, true);

    library->displayBooks();

    library->displayMembers();

    return 1;
}