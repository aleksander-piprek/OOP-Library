#include <iostream>
#include <string.h>

class Book
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
            std::cout << "Created book: " << *title << " by "<< *author << " ISBN: " << *isbn << " Genre: " << *genre << " Availability: " << *availability << std::endl;
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

class Member
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
            std::cout << "New member: " << *name << " ID: " << *id << " Membership status: " << *status << std::endl;
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
    std::string _title = "Harry-Potter";
    std::string _author = "J.K. Rowling";
    int _isbn = 1;
    std::string _genre = "Fantasy";
    bool _availability = true;
    auto HarryPotter = new Book(&_title, &_author, &_isbn, &_genre, &_availability);
 
    std::string _name = "Aleksander Piprek";
    int _id = 1;
    bool _status = true;
    auto AleksanderPiprek = new Member(&_name, &_id, &_status);

    return 1;
}