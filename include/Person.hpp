#include <string>
#include <utility>
#include <vector>
#include <chrono>
#include <cmath>
#include <optional>

#ifndef ANCESTOR_TREE_PERSON_HPP
#define ANCESTOR_TREE_PERSON_HPP
enum class Gender {
    female, male, other
};


class Person {
private:
    std::string name_;
    Gender gender_;
    int birthYear_;
    std::optional<int> deathYear_;

public:
    Person(std::string name, Gender gender, int birthYear, std::optional<int> deathYear) : name_(std::move(name)),
                                                                                           gender_(gender),
                                                                                           birthYear_(birthYear),
                                                                                           deathYear_(deathYear) {
    }

    [[nodiscard]] int getAge() const {   //Function to get age by using now, death and birth year and finding age
        int age;
        int now = floor(static_cast<double>(std::chrono::system_clock::now().time_since_epoch().count())/31556952000000 + 1970);
        //using chrono and dividing with a year in microseconds and adding 1970
        if (deathYear_) {
            age = *deathYear_ - birthYear_;
        } else {
            age = now - birthYear_;

        }
        return age;
    }

    void setGender(Gender gender) {   //setters and getters
        gender_ = gender;
    }
    void setBirthYear(const int birthYear) {
        birthYear_ = birthYear;
    }
    void setDeathYear(const int deathYear) {
        deathYear_ = deathYear;
    }
    void setName(const std::string& name) {
        name_ = name;
    }

    [[nodiscard]] const std::optional<int> getDeathYear() const {
        return deathYear_;
    }
    [[nodiscard]] std::string getName() const {
        return name_;
    }

    [[nodiscard]] Gender getGender() const {
        return gender_;
    }
    void makeEmptyPerson(){   //Function for deleting person, setting data equal to "none"
        name_ = "Empty";
        gender_ = Gender::other;
        birthYear_ = 0;
        deathYear_ = 0;

    }
    friend std::ostream& operator<<(std::ostream& os, const Person& person)   //operator overloading to get person info
    {
        os << "Name: " << person.getName() << "\n";
        os << "Age: " << person.getAge() << "\n";
        os << "Year of birth: " << person.birthYear_ << "\n";
        if(person.deathYear_){
        os << "Year of death: " <<  *person.deathYear_ << "\n";}
        else{
            os << "No year of death" << "\n";
        }
        bool isMale = person.getGender() == Gender::male;
        bool isFemale = person.getGender() == Gender::female;
        if (isMale) {
            os << "Gender: Male\n";
        } else if(isFemale) {
            os << "Gender: Female\n";
        }
        else {
            os << "Gender: Other\n";
        }
        return os;
    }
};

#endif //ANCESTOR_TREE_PERSON_HPP
