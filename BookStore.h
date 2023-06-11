#include <map>
#include <string.h>
#include "Book.h"
#include <queue>
#include "Person.h"
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class BookStore{
    public:
        //constructor
        BookStore();
        
        //destructor
        ~BookStore();
        
        //add a book
        void addBook(int id, char* title, char* author, int numberOfPages, double price, int amount);
        
        //if contains the book with a specific id 
        bool containsBook(int id);
        
        //take all the books from the database
        void readBookDatabase();
        
        //write back all the books in the database
        void writeBookDatabase();
        
        //delete the book with id bookId
        void deleteBook(int bookid);
        
        //get a specific book
        Book& getBook(int id);

        //get a specific person
        Person& getPerson(int id);

        //add a person in the clients database
        void addPerson(int id, char* firstName, char* lastName, char* country, char* city);
        
        //delete a client
        void deleteClient(int id);

        //if a person exist in the clients database
        bool containsPerson(int id);
        
        //get total day income
        double getTotalDayIncome() const;
        
        //set an order from a specific person
        void setBookOrder(int personId, int bookId,int amount);

        //increase the amount of a specific book
        void increaseAmount(int bookId, int amount);

        //store the clients in the clients database
        void writeClientsDatabase();

        //read the clients from the database
        void readClientsDatabase();
    private:
        vector<Book> books;
        vector<Person> clients;
        map<int, int> bookIds;
        map<int, int> personIds;
        map<int, vector<pair<int,int>>> bookOrders;
        queue<Book*> quBooks;
        queue<Person*> quPeople;
        double totalDayIncome;
};
