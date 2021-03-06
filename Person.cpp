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
    if(Mother == nullptr) {
        throw std::exception("The child's mother must always be defined.");
    }
    if((Father == nullptr || Father->_gender == Person::Gender::MALE) && (Mother->_gender == Person::Gender::FEMALE)) {
        _mother = Mother;
        _father = Father;
    }
    else
        throw std::exception("The child must have FEMALE mother and MALE father.");

    _name = aName;
    _gender = gender;
}

Person::Person(const std::string& aName, const Gender& gender) : _ID(++_nextID){
    _name = aName;
    _mother = nullptr;
    _father = nullptr;
    _gender = gender;

}

Person Person::giveBirth(const std::string& aName, const Gender& gender, Person* Mother, Person* Father) {
    return Person(aName, gender, Mother, Father);

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
    output += _name;
    output += " " + getGender(_gender);
    if(_mother != nullptr) {
        output += " " + (_mother)->_name;
    }
    if(_father != nullptr) {
        output += " " + (_father)->_name;
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
    if(_mother == nullptr){
        throw std::exception("This person's mother has not been defined.");
    }
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
    ostream << "Name: " << other._name;
    ostream << ", Gender: " << Person::getGender(other._gender);
    if(other._mother != nullptr) {
        ostream << ", Mother's name: " << (other._mother)->_name;
    }
    if(other._father != nullptr) {
        ostream << ", Father's name: " << (other._father)->_name;
    }

    return ostream;
}




