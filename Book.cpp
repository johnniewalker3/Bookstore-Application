#include <iostream>
#include "Book.h"
#include <string.h>
using namespace std;

//constructor with arguments
Book::Book(int id, char* title,  char* author, int numberOfPages, double price, int amount){
    this->id = id;
    strcpy(this->title, title);
    strcpy(this->author,author);
    this->numberOfPages = numberOfPages;
    this->price = price;
    this->amount = amount;
}
//simple constuctor
Book::Book(){
   id = -1;
   strcpy(title,"");
   strcpy(author,"");
   numberOfPages = 0;
   price = 0.0;
   amount = 0;
}

//copy constuctor
Book::Book(const Book& book){
    this->id = book.id;
    strcpy(this->title,book.title);
    strcpy(this->author,book.author);
    this->numberOfPages = book.numberOfPages;
    this->price = book.price;
    this->amount = book.amount;
}

//author of the book
 char* Book::getAuthor() {
    return author;
}

//title of the book
 char* Book::getTitle() {
    return title;
}

//primary key-id of the book
int Book::getId() const{
    return id;
}

//price of the book
double Book::getPrice() const{
    return price;
}

//number of pages at the book 
int Book::getNumberOfPages() const{
    return numberOfPages;
}

int Book::getAmount()const{
    return amount;
}

void Book::setAuthor(char* author){
    strcpy(this->author,author);
}

void Book::setId(int id){
    this->id = id;
}

void Book::setNumberOfPages(int pages){
    this->numberOfPages = pages;
}

void Book::setPrice(double price){
    this->price = price;
}

void Book::setTitle(char* title){
    strcpy(this->title,title);
}

void Book::setBookAmount(int in_amount){
    amount += in_amount;
}

//details of the book
ostream& operator<<(ostream& left,  Book &book){
    left<<"Id: "<<book.getId()<<endl;
    left<<"Title: "<< book.getTitle()<<endl;
    left<<"Author: "<<book.getAuthor()<<endl;
    left<<"Number Of Pages: "<<book.getNumberOfPages()<<endl;
    left<<"Price: "<<book.getPrice()<<endl;
    left<<"Amount: "<<book.getAmount()<<endl;
    return left;
}

