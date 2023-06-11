#include <iostream>
#include "BookStore.h"
#include <string.h>
#include <fstream>
#include <limits>
using namespace std;



void printMenu(){
    cout<<"-------------------------------------------------"<<endl;
    cout<<"1.Add a Book"<<endl;
    cout<<"2.Delete a book"<<endl;
    cout<<"3.Print the contents of a Book"<<endl;
    cout<<"4.Check the availability of a book"<<endl;
    cout<<"5.Increase the amount of a book"<<endl;
    cout<<"6.Add a client"<<endl;
    cout<<"7.Print the personal details of a client"<<endl;
    cout<<"8.Book order from a client"<<endl;
    cout<<"9.Delete a client"<<endl;
    cout<<"10.Exit"<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

void readBookDetails(int* id, char* title, char* author, int* numPages, double* price, int* quantity){
      cout<<"Id: ";
      cin>>*id;
      cout<<"Title: ";
      gets(title);
      gets(title);
      cout<<"Author: ";
      gets(author);
      cout<<"Number of pages: ";
      cin>>*numPages;
      cout<<"Price: ";
      cin>>*price;
      cout<<"Quantity of books: ";
      cin>>*quantity;
}


void readClientInformation(int* id, char* firstName, char* lastName, char* country, char* city){
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     cout<<"Id: ";
     cin>>*id;
     cout<<"FirstName:";
     gets(firstName);
     gets(firstName);
     cout<<"LastName:";
     gets(lastName);
     cout<<"Country: ";
     gets(country);
     cout<<"City: ";
     gets(city);
}


int main(){
    int choice;
    int id;
    int id2;
    bool active = true;
    char title[60];
    char author[30];
    int numPages;
    int quantity;
    double price;
    char firstName[20];
    char lastName[20];
    char country[30];
    char city[20];
    BookStore store;
    store.readBookDatabase();
    store.readClientsDatabase();
    while(active){
        printMenu();
        printf("Choice:");
        cin>>choice;
        switch(choice){
            case 1:
               readBookDetails(&id, title, author, &numPages, &price, &quantity);
               if (!store.containsBook(id))
                  store.addBook(id, title, author, numPages, price, quantity);
               else
                  cout<<"The book with id "<<id<<" already exists!"<<endl;
               break;
            case 2:
               cout<<"Book id: ";
               cin>>id;
               store.deleteBook(id);
               break;
            case 3:
               int bookId;
               cout<<"Id: ";
               cin>>bookId;
               if (store.containsBook(bookId))
                   cout<<store.getBook(bookId);
               else
                  cout<<"The book with id "<<bookId<<" does not exist in the book database"<<endl;
               break;
            case 4:
               cout<<"Book Id: ";
               cin>>id;
               if (store.containsBook(id)){
                  cout<<"The quantity of the book with id "<<id<<" is "<<store.getBook(id).getAmount()<<endl;
                  if (quantity == 0)
                     cout<<"Increase the amount of the books with id "<<id<<endl;
               }
               else
                  cout<<"Does not exist such a book"<<endl;
               break;
            case 5:
               cout<<"Book id: ";
               cin>>id;
               if (store.containsBook(id)){
                  cout<<"Read the amount of the books you want to add to the set of books with id "<<id;
                  cin>>quantity;
                  store.increaseAmount(id, quantity);
               }
               else
                  cout<<"The book with id "<<id<<" does not exist"<<endl;
               break;
            case 6:
               readClientInformation(&id, firstName, lastName, country, city);
               if (!store.containsPerson(id))
                  store.addPerson(id, firstName, lastName, country, city);
               else
                  cout<<"The client with id "<<id<<" already exists in the clients database"<<endl;
               break;
            case 7:
               cout<<"Person id: ";
               cin>>id;
               if (store.containsPerson(id))
                  cout<<store.getPerson(id);
               else
                  cout<<"The client with id "<<id<<" does not exist"<<endl;
               break;
            case 8:
               cout<<"Person id: ";
               cin>>id;
               if (store.containsPerson(id)){
                  cout<<"Book id: ";
                  cin>>id2;
                  if (store.containsBook(id2)){
                     cout<<"Books quantity: ";
                     cin>>quantity;
                     if (quantity > 0)
                        store.setBookOrder(id, id2, quantity);
                     else
                        cout<<"The quantity of books should not be zero"<<endl;
                  }
                  else
                     cout<<"The book with id "<<id2<<" does not exist in the book database"<<endl;
               }
               else
                 cout<<"The client with id "<<id<<" does not exist in the client database"<<endl;
               break;
            case 9:
               cout<<"Client id: ";
               cin>>id;
               store.deleteClient(id);
               break;
            case 10:
              cout<<"Exit from the program"<<endl;
              active = false;
              break;
            default:
              printf("Wrong input!");
        }
    }
    cout<<"Total Day Income: "<<store.getTotalDayIncome();
    store.writeClientsDatabase();
    store.writeBookDatabase();
    
    return 0;
}