#include <iostream>
#include "Person.h"
#include <string.h>
#include <map>
using namespace std;

//constructor
Person::Person(int id, char* firstName, char* lastName, char* country, char* city){
    this->id = id;
    strcpy(this->firstName,firstName);
    strcpy(this->lastName,lastName);
    strcpy(this->country,country);
    strcpy(this->city,city);
}

//copy constructor
Person::Person(const Person& person){
    this->id = person.id;
    strcpy(this->firstName,person.firstName);
    strcpy(this->lastName,person.lastName);
    strcpy(this->country,person.country);
    strcpy(this->city,person.city);
}


//simple constructor
Person::Person(){
    id = 0;
    strcpy(firstName,"");
    strcpy(lastName,"");
    strcpy(country,"");
    strcpy(city,"");
}

// id of person
int Person::getId() const{
    return id;
}

//firstname of person
char* Person::getFirstName() {
    return firstName;
}

//lastname of person
char* Person::getLastName() {
    return lastName;
}

//country of person
char* Person::getCountry() {
    return country;
}

//city of person
char* Person::getCity() {
    return city;
}


// personal details of person
ostream& operator<<(ostream &left, Person &person){
    left<<"Id: "<<person.getId()<<endl;
    left<<"FirstName: "<<person.getFirstName()<<endl;
    left<<"LastName: "<<person.getLastName()<<endl;
    left<<"Country: "<<person.getCountry()<<endl;
    left<<"City: "<<person.getCity()<<endl;
    return left;
}
