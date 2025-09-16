#pragma once
#include <string>
#include <vector>
#include "Author.h"

class Book {
protected:
    int id;
    std::string title;
    std::vector<Author> authors;
    std::string publisher;
    int year;
    std::string location; // Местоположение на полке
    std::string topic;    // Тематика книги

public:
    Book(int id, const std::string& title, const std::vector<Author>& authors,
         const std::string& publisher, int year, const std::string& location,
         const std::string& topic);
    
    virtual ~Book() = default;
    
    int getId() const;
    std::string getTitle() const;
    const std::vector<Author>& getAuthors() const;
    std::string getPublisher() const;
    int getYear() const;
    std::string getLocation() const;
    std::string getTopic() const;
    
    bool hasAuthor(const Author& author) const;
    
    // Виртуальный метод для вывода информации о книге
    virtual std::string getInfo() const;
};
