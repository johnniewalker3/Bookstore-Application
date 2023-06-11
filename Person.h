#include <string.h>
#include <iostream>
using namespace std;


class Person{
   public:
      Person(int id, char* firstName, char* lastName, char* country, char* city);
      int getId()const;
      char* getFirstName();
      char* getLastName();
      char* getCountry();
      char* getCity();
      Person();
      Person(const Person& person);
      friend ostream& operator<<(ostream &left,  Person &person);//print person elements
   private:
      int id;//id of  a person.It comprises the primary key to discriminate people between them
      char firstName[20];//firstName of person
      char lastName[20];//lastName of person
      char country[30];//lastName of person
      char city[20];//city of a person
      //map<int,bool> personId;
};