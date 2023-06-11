#include <string>
using namespace std;
class Book{
    public:
      //constructor
       Book(int id,char* title, char* author, int numberOfPages, double price,int amount);
       Book();

       //copy constructor
       Book(const Book& book);
       
       //id of the book
       int getId() const;
       void setId(int id);
       
       //title of the book
       char* getTitle();
       void setTitle(char* title);
       
       //author of the book
       char* getAuthor();
       void setAuthor(char* author);
       
       //total pages of the book
       int getNumberOfPages() const;
       void setNumberOfPages(int pages);

       //price of the book
       double getPrice() const;
       void setPrice(double price);
       
       //book amount
       int getAmount() const;
       void setBookAmount(int in_amount);
       
       //details of the book
       friend ostream& operator<<(ostream &left, Book &book);
    private:
       int id;
       char title[60];
       char author[30];
       int numberOfPages;
       double price;
       int amount;
};






