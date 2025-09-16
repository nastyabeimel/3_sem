
#pragma once
#include "Book.h"

class FictionBook : public Book {
private:
    std::string genre;       // Жанр (роман, повесть, рассказ и т.д.)
    std::string movement;    // Литературное направление (реализм, романтизм и т.д.)

public:
    FictionBook(int id, const std::string& title, const std::vector<Author>& authors,
                const std::string& publisher, int year, const std::string& location,
                const std::string& topic, const std::string& genre, const std::string& movement);
    
    std::string getGenre() const;
    std::string getMovement() const;
    
    // Переопределяем виртуальный метод для вывода информации
    std::string getInfo() const override;
};
