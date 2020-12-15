#include <iostream>
#include "Person.h"

int main() {
    try {
        Person Adam = Person::createAdam();
        //Person Adam2 = Person::createAdam();
        Person Eva = Person::createEva();
        //Person Eva2 = Person::createEva();

        std::cout << Adam.toString() << std::endl;
        std::cout << Eva.toString() << std::endl;

        Person Vlad = Person("Vlad", Person::Gender::MALE, &Eva);
        std::cout << Vlad.toString() << std::endl;

        Person Ivan = Person::giveBirth("Ivan", Person::Gender::MALE, &Eva, &Adam);
        std::cout << Ivan.toString() << std::endl;

        Person Lena = Person::giveBirth("Lena", Person::Gender::FEMALE, &Eva);
        std::cout << Lena.toString() << std::endl;

        Person Pavel = Person::giveBirth("Pavel", Person::Gender::MALE, &Lena);
        std::cout << Pavel.toString() << std::endl;

        std::cout << Pavel << std::endl;
        //Person Pavel2 = Person(Pavel);
        //std::cout << Pavel2 << std::endl;

        std::cout << Pavel.getId() << std::endl;
        std::cout << Pavel.getName() << std::endl;
        std::cout << Pavel.getMother()->toString() << std::endl;
        //std::cout << Pavel.getFather()->toString() << std::endl;

        //std::cout << Adam.getMother()->toString() << std::endl;

        Person Vasya = Person::giveBirth("Vasya", Person::Gender::MALE, nullptr, &Adam);

     }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
