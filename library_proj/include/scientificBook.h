#pragma once
#include "Book.h"

class ScientificBook : public Book {
private:
    std::string field;       // Область науки (физика, математика и т.д.)
    std::string category;    // Категория (учебник, монография и т.д.)

public:
    ScientificBook(int id, const std::string& title, const std::vector<Author>& authors,
                  const std::string& publisher, int year, const std::string& location,
                  const std::string& topic, const std::string& field, const std::string& category);
    
    std::string getField() const;
    std::string getCategory() const;
    
    // Переопределяем виртуальный метод для вывода информации
    std::string getInfo() const override;
};
