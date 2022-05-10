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

    [[nodiscard]] int getAge() const {
        int age;
        int now = floor(static_cast<double>(std::chrono::system_clock::now().time_since_epoch().count() / 31557600000));
        if (deathYear_) {
            age = *deathYear_ - birthYear_;
        } else {
            age = now - birthYear_;

        }
        return age;
    }


    [[nodiscard]] std::string getName() const {
        return name_;
    }

    [[nodiscard]] Gender getGender() const {
        return gender_;
    }

};

#endif //ANCESTOR_TREE_PERSON_HPP
