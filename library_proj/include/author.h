#pragma once
#include <string>

class Author {
private:
    int id;
    std::string firstName;
    std::string lastName;

public:
    Author(int id, const std::string& firstName, const std::string& lastName);
    
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    
    bool operator==(const Author& other) const;
    bool operator!=(const Author& other) const;
};
