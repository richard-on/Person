//
// Created by Richard on 07.12.2020.
//

#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H

#include <string>

class Person {
public:
    enum class Gender {
        MALE,
        FEMALE
    };

    Person(const std::string& aName, const Gender& gender, Person* Mother, Person* Father = nullptr);

    int getId() const;
    const std::string& getName() const;
    Person *getMother() const;
    Person *getFather() const;
    friend std::ostream& operator << (std::ostream& ostream, const Person& other);
    std::string toString() const;

    static Person createAdam();
    static Person createEva();
    static Person giveBirth(const std::string& aName, const Gender& gender, Person* Mother, Person* Father = nullptr);

    virtual ~Person() = default;

private:
    const int _ID;
    static int _nextID;
    std::string _name;
    Gender _gender;
    Person* _mother;
    Person* _father;

    Person(const std::string& aName, const Gender& gender);
    Person(const Person&) = delete;
    Person& operator=(const Person&) = delete;
    static std::string getGender(Gender gender);
};



#endif //PERSON_PERSON_H
