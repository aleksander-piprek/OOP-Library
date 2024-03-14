#include "../include/library.hpp"

Library::Library()
{
}

Library::~Library()
{
}

void Library::addBook(std::string *title, std::string *author, int *isbn, std::string *genre, bool *availability)
{
    auto newBook = new Book(title, author, isbn, genre, availability);
    bookList.emplace_back(newBook);
}

void Library::removeBook(int *isbn)
{
    int index = 0;
    for(auto book : bookList)
    {
        if(book->getIsbn() == *isbn)
            bookList.erase(bookList.begin() + index);
               
        index++;
    }
}

void Library::displayBooks() 
{
    std::cout << "Displaying all books: " << std::endl;
    if(!bookList.empty())
    {
        for(auto book : bookList)
            std::cout << book->getTitle() 
                      << " by "<< book->getAuthor() 
                      << " ISBN: "<< book->getIsbn() 
                      << " Genre: " << book->getGenre() 
                      << " Availability: " << book->getAvailability() << std::endl;

    }
    else
        std::cout << "Empty library :(" << std::endl;

    std::cout << std::endl;
}      

void Library::addMember(std::string *name, int *id, bool *status)
{
    auto newMember = new Member(name, id, status);
    memberList.emplace_back(newMember);
}

void Library::displayMembers()
{
    std::cout << "Displaying all members" << std::endl;
    for(auto member : memberList)
        std::cout << "New member: " << member->getName() 
                  << " ID: " << member->getId() 
                  << " Membership status: " << member->getStatus() << std::endl;
    std::cout << std::endl;
}

void Library::borrowBook(int *isbn)
{
    for(auto book : bookList)
        if(book->getIsbn() == *isbn)
            if(book->getAvailability())
            {
                book->setAvailability(false);
                std::cout << "Book borrowed" << std::endl;
            }
            else
                std::cout << "Book unavailable" << std::endl;
}

void Library::returnBook(int *isbn)
{
    for(auto book : bookList)
        if(book->getIsbn() == *isbn)
            if(!book->getAvailability())
            {
                book->setAvailability(true);
                std::cout << "Book returned" << std::endl;
            }
            else
                std::cout << "Book already in library" << std::endl;
}

Book::Book(std::string* title, std::string* author, int* isbn, std::string* genre, bool* availability)
{
    this->title = new std::string(*title);
    this->author = new std::string(*author);
    this->isbn = new int(*isbn);
    this->genre = new std::string(*genre);
    this->availability = new bool(*availability);
}

Book::~Book()
{
    delete this->title;
    delete this->author;
    delete this->isbn;
    delete this->genre;
    delete this->availability;
}

Member::Member(std::string *name, int *id, bool *status)
{
    this->name = new std::string(*name);
    this->id = new int(*id);
    this->status = new bool(*status);
}
Member::~Member()
{
    delete this->name;
    delete this->id;
    delete this->status;
}

int main()
{
    auto library = new Library;
    
    std::string _title = "Harry-Potter";
    std::string _author = "J.K. Rowling";
    int _isbn = 1;
    std::string _genre = "Fantasy";
    bool _availability = true;

    library->addBook(&_title, &_author, &_isbn, &_genre, &_availability);

    std::string _name = "Aleksander Piprek";
    int _id = 1;
    bool _status = true;

    library->addMember(&_name, &_id, &_status);

    library->displayBooks();

    library->displayMembers();

    library->borrowBook(&_isbn);

    library->displayBooks();

    library->returnBook(&_isbn);

    library->displayBooks();

    // library->removeBook(1);

    // library->displayBooks();

    delete library;

    return 0;
}