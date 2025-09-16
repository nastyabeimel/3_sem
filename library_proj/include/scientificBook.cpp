#include "ScientificBook.h"

ScientificBook::ScientificBook(int id, const std::string& title, const std::vector<Author>& authors,
                               const std::string& publisher, int year, const std::string& location,
                               const std::string& topic, const std::string& field, const std::string& category)
    : Book(id, title, authors, publisher, year, location, topic),
      field(field), category(category) {}

std::string ScientificBook::getField() const {
    return field;
}

std::string ScientificBook::getCategory() const {
    return category;
}

std::string ScientificBook::getInfo() const {
    std::string baseInfo = Book::getInfo();
    return baseInfo + "\nОбласть науки: " + field + "\nКатегория: " + category;
}
