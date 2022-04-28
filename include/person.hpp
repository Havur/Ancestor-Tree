#include <string>
#include <vector>
#include <chrono>
#include <cmath>
#include <optional>

#ifndef ANCESTOR_TREE_PERSON_HPP
#define ANCESTOR_TREE_PERSON_HPP

class person {
private:
    std::string name_;
    std::string gender_;
    int birthYear_;
    std::optional<int> deathYear_;

public:
    person(std::string name, std::string gender, int birthYear, int deathYear) : name_(name), gender_(gender),
                                                                                 birthYear_(birthYear),
                                                                                 deathYear_(deathYear) {
    }

    [[nodiscard]] int getAge() const {
        int age;
        double now = floor(static_cast<double>(std::chrono::system_clock::now().time_since_epoch().count() / 31536000000.0));
        if (deathYear_) {
            age = *deathYear_ - birthYear_;
        } else {
            age = now - birthYear_;

        }
        return age;
    }


    std::string getName() const {
        return name_;
    }

    std::string getGender() const {
        return gender_;
    }

};

#endif //ANCESTOR_TREE_PERSON_HPP
