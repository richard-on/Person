//
// Created by Richard on 07.12.2020.
//

#include "Person.h"
#include <string>
#include <iostream>

int Person::_nextID = 0;
bool AdamIsCreated = false;
bool EvaIsCreated = false;

Person::Person(const std::string& aName,const Gender& gender, Person* Mother, Person* Father) : _ID(++_nextID) {
    _name = aName;
    _gender = gender;
    _mother = Mother;
    _father = Father;

}

Person::Person(const std::string& aName, const Gender& gender) : _ID(++_nextID){
    _name = aName;
    _mother = nullptr;
    _father = nullptr;
    _gender = gender;

}

Person Person::giveBirth(const std::string& aName, const Gender& gender, Person* Mother, Person* Father) {
    if((Father == nullptr || Father->_gender == Person::Gender::MALE) && (Mother->_gender == Person::Gender::FEMALE))
        return Person(aName, gender, Mother, Father);
    else
        throw std::exception("The child must have FEMALE mother and MALE father.");
}

Person Person::createAdam() {
    if(AdamIsCreated == false){
        AdamIsCreated = true;
        return Person("Adam", Gender::MALE);
    }
    else{
        throw std::exception("Adam has already been created.");
    }

}

Person Person::createEva() {
    if(EvaIsCreated == false) {
        EvaIsCreated = true;
        return Person("Eva", Gender::FEMALE);
    }
    else{
        throw std::exception("Eva has already been created.");
    }
}

std::string Person::toString() const {
    std::string output;
    output += "Name: " + _name;
    output += ", Gender: " + getGender(_gender);
    if(_mother != nullptr) {
        output += ", Mother's name: " + (_mother)->_name;
    }
    if(_father != nullptr) {
        output += ", Father's name: " + (_father)->_name;
    }

    return output;
}

int Person::getId() const {
    return _ID;
}

const std::string &Person::getName() const {
    return _name;
}

Person *Person::getMother() const {
    return _mother;
}

Person *Person::getFather() const {
    if(_father == nullptr){
        throw std::exception("This person's father has not been defined.");
    }
    return _father;
}

std::string Person::getGender(Gender gender) {
    if(gender == Gender::MALE){
        return "male";
    }
    else{
        return "female";
    }
}

std::ostream& operator<<(std::ostream& ostream, const Person& other) {
    ostream << other.toString();

    return ostream;
}




