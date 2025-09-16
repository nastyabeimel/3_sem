#include "Author.h"

Author::Author(int id, const std::string& firstName, const std::string& lastName)
    : id(id), firstName(firstName), lastName(lastName) {}

int Author::getId() const {
    return id;
}

std::string Author::getFirstName() const {
    return firstName;
}

std::string Author::getLastName() const {
    return lastName;
}

std::string Author::getFullName() const {
    return firstName + " " + lastName;
}

bool Author::operator==(const Author& other) const {
    return id == other.id;
}

bool Author::operator!=(const Author& other) const {
    return !(*this == other);
}
