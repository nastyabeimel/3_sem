#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include <string>
#include "book.h"
#include "author.h"

class Library {
private:
    std::vector<std::shared_ptr<Book>> books;
public:
    Library() = default;

    void addBook(const std::shared_ptr<Book>& book);
    const std::vector<std::shared_ptr<Book>>& getAllBooks() const;
    std::vector<std::shared_ptr<Book>> findBooksByTitle(const std::string& title, bool partial = false) const;
    std::vector<std::shared_ptr<Book>> findBooksByAuthor(const Author& author) const;
    std::vector<std::shared_ptr<Book>> findBooksByTopic(const std::string& topic) const;
    std::vector<std::shared_ptr<Book>> findBooksByPublisher(const std::string& publisher) const;
    std::string findBookLocation(const std::string& title) const;
};

#endif // LIBRARY_H
