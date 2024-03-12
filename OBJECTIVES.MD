Task: Building a Simple Library Management System

Create a simple library management system in C++ that utilizes OOP concepts such as classes, objects, inheritance, encapsulation, and polymorphism.

Requirements:

    Book Class: Create a class called Book with the following attributes:
        Title
        Author
        ISBN number
        Genre
        Availability status

    Member Class: Create a class called Member to represent library members. Each member should have the following attributes:
        Name
        ID
        Membership status

    Library Class: Implement a class called Library which represents the library itself. This class should include:
        A list of books available in the library.
        A list of registered members.
        Functions to:
            Add a new book to the library.
            Remove a book from the library.
            Display all books in the library.
            Register a new member.
            Display all registered members.

    Borrowing and Returning Books: Implement functions in the Library class to allow members to borrow and return books. Ensure that book availability is updated accordingly.

    Genre-specific Classes (Optional): Optionally, you can create specific classes for different genres of books (e.g., FictionBook, NonFictionBook) that inherit from the Book class.

    Error Handling: Implement proper error handling mechanisms for scenarios such as attempting to borrow a book that is not available or trying to return a book that hasn't been borrowed.

Additional Tasks:

    Implement serialization and deserialization functions to save and load library data to/from a file.
    Implement a sorting mechanism to sort books by title, author, or genre.
    Implement a search function to search for books by title, author, or ISBN number.
