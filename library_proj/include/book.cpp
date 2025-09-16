#include "Book.h"
#include <algorithm>
#include <sstream>

Book::Book(int id, const std::string& title, const std::vector<Author>& authors,
           const std::string& publisher, int year, const std::string& location,
           const std::string& topic)
    : id(id), title(title), authors(authors), publisher(publisher),
      year(year), location(location), topic(topic) {}

int Book::getId() const {
    return id;
}

std::string Book::getTitle() const {
    return title;
}

const std::vector<Author>& Book::getAuthors() const {
    return authors;
}

std::string Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}

std::string Book::getLocation() const {
    return location;
}

std::string Book::getTopic() const {
    return topic;
}

bool Book::hasAuthor(const Author& author) const {
    return std::find(authors.begin(), authors.end(), author) != authors.end();
}

std::string Book::getInfo() const {
    std::stringstream ss;
    ss << "Книга: " << title << " (" << year << ")\n";
    ss << "Авторы: ";
    
    for (size_t i = 0; i < authors.size(); ++i) {
        if (i > 0) ss << ", ";
        ss << authors[i].getFullName();
    }
    
    ss << "\nИздательство: " << publisher;
    ss << "\nТематика: " << topic;
    ss << "\nМестонахождение: " << location;
    
    return ss.str();
}
