
#include "FictionBook.h"

FictionBook::FictionBook(int id, const std::string& title, const std::vector<Author>& authors,
                         const std::string& publisher, int year, const std::string& location,
                         const std::string& topic, const std::string& genre, const std::string& movement)
    : Book(id, title, authors, publisher, year, location, topic),
      genre(genre), movement(movement) {}

std::string FictionBook::getGenre() const {
    return genre;
}

std::string FictionBook::getMovement() const {
    return movement;
}

std::string FictionBook::getInfo() const {
    std::string baseInfo = Book::getInfo();
    return baseInfo + "\nЖанр: " + genre + "\nЛитературное направление: " + movement;
}
