#include <iostream>
#include "BookStore.h"
#include <string.h>
#include <iterator>
#include <cmath>
#include <fstream>
using namespace std;

BookStore::BookStore(){
    totalDayIncome = 0.0;
}

BookStore::~BookStore(){
    while (!quBooks.empty()){
        Book* book = quBooks.front();
        quBooks.pop();
        delete book;
    }

    while(!quPeople.empty()){
        Person* person = quPeople.front();
        quPeople.pop();
        delete person;
    }
}

void BookStore::addBook(int id, char* title, char* author, int numberOfPages, double price, int amount){
    Book* book =  new Book(id, title, author, numberOfPages, price, amount);
    quBooks.push(book);
    cout<<*book<<endl;
    if (!containsBook(book->getId())){
       books.push_back(*book);
       bookIds[book->getId()] = books.size()-1;
       cout<<"Succesful add"<<endl;
    }
}

//delete a specic book from the store
void BookStore::deleteBook(int bookid){
    if (containsBook(bookid)){
        bool flag = false;
        books.erase(books.begin() + bookIds[bookid]);
        for (auto it = bookIds.begin();it!=bookIds.end();it++){
            if (flag){
                it->second -= 1;
            }
            else{
                if (bookid == it->first)
                   flag = true;
            }
        }
        for (auto it = bookOrders.begin();it!= bookOrders.end();it++){
            int pos = -1;
            for (int i=0;i<it->second.size();i++){
                if (it->second[i].first == bookid){
                    pos = i;
                    break;
                }
            }
            if (pos!=-1)
               it->second.erase(it->second.begin() + pos);
        }
        bookIds.erase(bookid);
        cout<<"Succesful delete"<<endl;
    }
    else
      cout<<"Such id does not exist"<<endl;
}

//get a specific book
Book& BookStore::getBook(int id){
    int index = bookIds[id];
    cout<<books[index].getAuthor();
    return books[index];
}

//increase the amount of a specific book
void BookStore::increaseAmount(int bookId, int amount){
    books[bookIds[bookId]].setBookAmount(amount);
}

//if  store contains a specific book
bool BookStore::containsBook(int id){
    map<int, int>::iterator it;
    it = bookIds.find(id);
    if (it == bookIds.end())
       return false;
    return true;
}

void BookStore::addPerson(int id, char* firstName, char* lastName, char* country, char* city){
     Person* person = new Person(id, firstName, lastName, country, city);
     quPeople.push(person);
     cout<<*person<<endl;
     clients.push_back(*person);
     personIds[id] = clients.size()-1;
     cout<<"Succesful add"<<endl;
}

//get a specific person
Person& BookStore::getPerson(int id){
    return clients[personIds[id]];
}

bool BookStore::containsPerson(int id){
    map<int, int>::iterator it;
    it = personIds.find(id);
    if (it == personIds.end())
        return false;
    return true;
}

//delete a client from the database
void BookStore::deleteClient(int id){
    if (containsPerson(id)){
        map<int, vector<pair<int,int>>>::iterator it;
        it = bookOrders.find(id);
        if (it != bookOrders.end())
           bookOrders.erase(id);
        bool flag = false;
        for (auto it1 = personIds.begin();it1!=personIds.end();it1++){
            if (flag)
               it1->second -= 1;
            else{
                if (it1->first == id)
                   flag = true;
            }    
        }
        clients.erase(clients.begin() + personIds[id]);
        personIds.erase(id);
        cout<<"Succesful delete"<<endl;
    }
    else
      cout<<"Such person id does not exist"<<endl;
}



//get total Day income
double BookStore::getTotalDayIncome() const{
    return totalDayIncome;
}


//an order from a specific person
void BookStore::setBookOrder(int personId, int bookId, int amount){
     int pos = -1;
     for (auto it = bookOrders.begin();it!=bookOrders.end();it++){
         for (int i=0;i<it->second.size();i++){
            if (bookId == it->second[i].first){
                pos = i;
                break;
            }
         }
     }
     if (pos != -1){
        bookOrders[personId][pos].second += min(books[bookIds[bookId]].getAmount(), amount);
        totalDayIncome += books[bookIds[bookId]].getPrice()*min(books[bookIds[bookId]].getAmount(), amount);
        books[bookIds[bookId]].setBookAmount(-min(books[bookIds[bookId]].getAmount(), amount));
     }
     else{
        bookOrders[personId].push_back({bookId,min(books[bookIds[bookId]].getAmount(), amount)});
        totalDayIncome += books[bookIds[bookId]].getPrice()*min(books[bookIds[bookId]].getAmount(), amount);
        books[bookIds[bookId]].setBookAmount(-min(books[bookIds[bookId]].getAmount(), amount));
     }
}


//store the books in the database
void BookStore::writeBookDatabase(){
    fstream file;
    file.open("Books.dat", ios::out | ios::binary);
    if (!file){
        cout<<"Error writing"<<endl;
        exit(0);
    }
    if (file.is_open()){
        for (Book book:books){
            file.write((char *) &book, sizeof(Book));
            cout<<"Succesful write!"<<endl;
        }
    }
    file.close();
}

//restore the books from the database
void BookStore::readBookDatabase(){
    ifstream file;
    file.open("Books.dat", ios::binary);
    if (!file){
        cout<<"Empty Books Database"<<endl;
        return;
    }
    if (file.is_open()){
        Book book;
        while (file.read((char *) &book, sizeof(Book))){
            cout<<"Succesful reading"<<endl;
            addBook(book.getId(), book.getTitle(), book.getAuthor(), book.getNumberOfPages(), book.getPrice(), book.getAmount());
        }
    }
    file.close();
}

//store the clients in the database
void BookStore::writeClientsDatabase(){
    fstream file;
    file.open("Clients.dat", ios::out | ios::binary);
    if (!file){
        cout<<"Error writing"<<endl;
        exit(0);
    }
    if (file.is_open()){
        for (Person client:clients){
            file.write((char *) &client, sizeof(Person));
            cout<<"Succesful write!"<<endl;
        }
    }
    file.close();
}

//restore the clients from the database
void BookStore::readClientsDatabase(){
    ifstream file;
    file.open("Clients.dat", ios::binary);
    if (!file){
        cout<<"Empty Clients Database"<<endl;
        return;
    }
    if (file.is_open()){
        Person client;
        while (file.read((char *) &client, sizeof(Person))){
            cout<<"Succesful reading"<<endl;
            addPerson(client.getId(), client.getFirstName(), client.getLastName(), client.getCountry(), client.getCity());
        }
    }
    file.close();
}