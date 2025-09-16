// Минимальные модульные тесты для библиотеки Library
// Тесты написаны в процессе разработки для проверки основных функций
// Используется <cassert> для простоты

#include <cassert>
#include <vector>
#include <memory>
#include <string>
#include "../include/library.h"
#include "../include/author.h"
#include "../include/fictionBook.h"
#include "../include/scientificBook.h"

int main() {
    // Тест 1: Добавление книги
    Library lib;
    Author a1(1, "Лев", "Толстой");
    lib.addBook(std::make_shared<FictionBook>(1, "Война и мир", std::vector<Author>{a1}, "АСТ", 2014, "Полка A1", "Классика", "Роман", "Реализм"));
    assert(lib.getAllBooks().size() == 1); // Проверяем, что книга добавлена

    // Тест 2: Поиск по названию (точное совпадение)
    auto found = lib.findBooksByTitle("Война и мир");
    assert(found.size() == 1);
    assert(found[0]->getTitle() == "Война и мир");

    // Тест 3: Поиск по названию (частичное совпадение)
    auto foundPartial = lib.findBooksByTitle("война", true);
    assert(foundPartial.size() == 1);

    // Тест 4: Поиск по автору (один автор)
    auto foundByAuthor = lib.findBooksByAuthor(a1);
    assert(foundByAuthor.size() == 1);

    // Тест 5: Поиск по тематике
    auto foundByTopic = lib.findBooksByTopic("Классика");
    assert(foundByTopic.size() == 1);

    // Тест 6: Поиск по издательству
    auto foundByPublisher = lib.findBooksByPublisher("АСТ");
    assert(foundByPublisher.size() == 1);

    // Тест 7: Поиск местонахождения
    auto location = lib.findBookLocation("Война и мир");
    assert(location == "Полка A1");

    // Тест 8: Соавторство
    Author a2(2, "Александр", "Пушкин");
    lib.addBook(std::make_shared<FictionBook>(2, "Антология", std::vector<Author>{a1, a2}, "АСТ", 2021, "Полка A2", "Классика", "Сборник", "Реализм"));
    auto foundByAuthor2 = lib.findBooksByAuthor(a2);
    assert(foundByAuthor2.size() == 1); // Пушкин есть в соавторстве

    // Если дошли до конца, все тесты прошли
    return 0;
}
