#include "library.h"
#include <algorithm>

void Library::addBook(const std::shared_ptr<Book>& book) {
    books.push_back(book);
}

const std::vector<std::shared_ptr<Book>>& Library::getAllBooks() const {
    return books;
}

std::vector<std::shared_ptr<Book>> Library::findBooksByTitle(const std::string& title, bool partial) const {
    std::vector<std::shared_ptr<Book>> result;
    for (const auto& book : books) {
        if (partial) {
            if (book->getTitle().find(title) != std::string::npos) {
                result.push_back(book);
            }
        } else {
            if (book->getTitle() == title) {
                result.push_back(book);
            }
        }
    }
    return result;
}

std::vector<std::shared_ptr<Book>> Library::findBooksByAuthor(const Author& author) const {
    std::vector<std::shared_ptr<Book>> result;
    for (const auto& book : books) {
        for (const auto& a : book->getAuthors()) {
            if (a.getId() == author.getId()) {
                result.push_back(book);
                break;
            }
        }
    }
    return result;
}

std::vector<std::shared_ptr<Book>> Library::findBooksByTopic(const std::string& topic) const {
    std::vector<std::shared_ptr<Book>> result;
    for (const auto& book : books) {
        if (book->getTopic() == topic) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Book>> Library::findBooksByPublisher(const std::string& publisher) const {
    std::vector<std::shared_ptr<Book>> result;
    for (const auto& book : books) {
        if (book->getPublisher() == publisher) {
            result.push_back(book);
        }
    }
    return result;
}

std::string Library::findBookLocation(const std::string& title) const {
    for (const auto& book : books) {
        if (book->getTitle() == title) {
            return book->getLocation();
        }
    }
    return "";
}
