#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "../include/author.h"
#include "../include/book.h"
#include "../include/fictionBook.h"
#include "../include/scientificBook.h"
#include "../include/library.h"

int main() {
    // Установка русской локали для корректного вывода кириллицы
    setlocale(LC_ALL, "Russian");
    
    // Создаем нескольких авторов
    Author tolstoy(1, "Лев", "Толстой");
    Author dostoevsky(2, "Федор", "Достоевский");
    Author pushkin(3, "Александр", "Пушкин");
    Author einstein(4, "Альберт", "Эйнштейн");
    Author hawking(5, "Стивен", "Хокинг");
    Author bohr(6, "Нильс", "Бор");
    
    // Векторы авторов для книг с соавторством
    std::vector<Author> physicsAuthors1 = {einstein, hawking};
    std::vector<Author> physicsAuthors2 = {einstein, bohr};
    std::vector<Author> classicAuthors = {tolstoy, pushkin};
    
    // Создаем библиотеку
    Library library;
    
    // Добавляем художественные книги
    library.addBook(std::make_shared<FictionBook>(
        1, "Война и мир", std::vector<Author>{tolstoy},
        "АСТ", 2014, "Полка A1", "Классическая литература",
        "Роман", "Реализм"
    ));
    
    library.addBook(std::make_shared<FictionBook>(
        2, "Преступление и наказание", std::vector<Author>{dostoevsky},
        "Эксмо", 2016, "Полка A2", "Классическая литература",
        "Роман", "Реализм"
    ));
    
    library.addBook(std::make_shared<FictionBook>(
        3, "Евгений Онегин", std::vector<Author>{pushkin},
        "АСТ", 2017, "Полка A1", "Классическая литература",
        "Роман в стихах", "Романтизм"
    ));
    
    
    // Добавляем научные книги
    library.addBook(std::make_shared<ScientificBook>(
        4, "Краткая история времени", std::vector<Author>{hawking},
        "АСТ", 2018, "Полка B1", "Наука",
        "Физика", "Популярная наука"
    ));
    
    library.addBook(std::make_shared<ScientificBook>(
        5, "Теория относительности", std::vector<Author>{einstein},
        "Наука", 1975, "Полка B2", "Наука",
        "Физика", "Научная литература"
    ));
    
    // Книги с соавторами
    library.addBook(std::make_shared<ScientificBook>(
        6, "Природа пространства и времени", physicsAuthors1,
        "Питер", 2020, "Полка B3", "Наука",
        "Теоретическая физика", "Научная литература"
    ));
    
    library.addBook(std::make_shared<ScientificBook>(
        7, "Квантовая механика: основы", physicsAuthors2,
        "Наука", 1985, "Полка B4", "Наука",
        "Квантовая физика", "Учебная литература"
    ));
    
    // Еще одна книга с соавторством для демонстрации
    library.addBook(std::make_shared<FictionBook>(
        8, "Антология русской классики", classicAuthors,
        "АСТ", 2021, "Полка A3", "Классическая литература",
        "Сборник", "Реализм"
    ));
    
    // Получаем все книги и итерируем по ним как по коллекции базового класса
    std::cout << "\n====== ВСЕ КНИГИ В БИБЛИОТЕКЕ ======\n";
    const auto& allBooks = library.getAllBooks();
    
    for (const auto& book : allBooks) {
        // Используем виртуальный метод getInfo() базового класса
        std::cout << book->getInfo() << "\n\n";
    }
    
    // Демонстрация: поиск книг по названию
    std::cout << "\n====== ПОИСК КНИГ ПО НАЗВАНИЮ ======\n";
    
    // Поиск по полному названию
    std::string titleToFind = "Война и мир";
    auto booksByTitle = library.findBooksByTitle(titleToFind);
    std::cout << "Книги с названием \"" << titleToFind << "\":\n";
    
    if (booksByTitle.empty()) {
        std::cout << "Книги не найдены.\n";
    } else {
        for (const auto& book : booksByTitle) {
            std::cout << book->getInfo() << "\n\n";
        }
    }
    
    // Поиск по части названия
    std::string partialTitle = "история";
    auto booksByPartialTitle = library.findBooksByTitle(partialTitle, true); // true - для частичного совпадения
    std::cout << "Книги, содержащие \"" << partialTitle << "\" в названии:\n";
    
    if (booksByPartialTitle.empty()) {
        std::cout << "Книги не найдены.\n";
    } else {
        for (const auto& book : booksByPartialTitle) {
            std::cout << book->getTitle() << " (" << book->getYear() << ")\n";
        }
    }
    
    // Демонстрация: поиск книг по автору (включая соавторство)
    std::cout << "\n====== ПОИСК КНИГ ПО АВТОРУ ======\n";
    
    // Поиск книг Эйнштейна (включая книги в соавторстве)
    std::cout << "Книги автора " << einstein.getFullName() << ":\n";
    auto einsteinBooks = library.findBooksByAuthor(einstein);
    
    if (einsteinBooks.empty()) {
        std::cout << "Книги не найдены.\n";
    } else {
        for (const auto& book : einsteinBooks) {
            std::cout << "- " << book->getTitle() << " (";
            
            // Выводим всех авторов книги
            const auto& authors = book->getAuthors();
            for (size_t i = 0; i < authors.size(); ++i) {
                if (i > 0) std::cout << ", ";
                std::cout << authors[i].getFullName();
            }
            
            std::cout << ")\n";
        }
    }
    
    // Демонстрация: поиск книг по тематике
    std::cout << "\n====== ПОИСК КНИГ ПО ТЕМАТИКЕ ======\n";
    
    std::string topicToFind = "Классическая литература";
    std::cout << "Книги по тематике \"" << topicToFind << "\":\n";
    auto booksByTopic = library.findBooksByTopic(topicToFind);
    
    if (booksByTopic.empty()) {
        std::cout << "Книги не найдены.\n";
    } else {
        for (const auto& book : booksByTopic) {
            std::cout << "- " << book->getTitle() << " (" << book->getYear()
                     << "), авторы: ";
            
            // Выводим авторов
            const auto& authors = book->getAuthors();
            for (size_t i = 0; i < authors.size(); ++i) {
                if (i > 0) std::cout << ", ";
                std::cout << authors[i].getFullName();
            }
            
            std::cout << "\n";
        }
    }
    
    
    // Демонстрация: поиск книг по издательству
    std::cout << "\n====== ПОИСК КНИГ ПО ИЗДАТЕЛЬСТВУ ======\n";
    
    std::string publisherToFind = "АСТ";
    std::cout << "Книги издательства \"" << publisherToFind << "\":\n";
    auto booksByPublisher = library.findBooksByPublisher(publisherToFind);
    
    if (booksByPublisher.empty()) {
        std::cout << "Книги не найдены.\n";
    } else {
        for (const auto& book : booksByPublisher) {
            std::cout << "- " << book->getTitle() << " (" << book->getYear() << ")\n";
        }
    }
    
    // Демонстрация: поиск местонахождения книги
    std::cout << "\n====== ПОИСК МЕСТОНАХОЖДЕНИЯ КНИГИ ======\n";
    
    std::string bookToLocate = "Евгений Онегин";
    std::cout << "Местонахождение книги \"" << bookToLocate << "\":\n";
    auto location = library.findBookLocation(bookToLocate);
    
    if (location.empty()) {
        std::cout << "Книга не найдена в библиотеке.\n";
    } else {
        std::cout << "Местонахождение: " << location << "\n";
    }
    
    // Еще один пример поиска местонахождения
    bookToLocate = "Теория относительности";
    std::cout << "\nМестонахождение книги \"" << bookToLocate << "\":\n";
    location = library.findBookLocation(bookToLocate);
    
    if (location.empty()) {
        std::cout << "Книга не найдена в библиотеке.\n";
    } else {
        std::cout << "Местонахождение: " << location << "\n";
    }
    
    
    std::cout << "\nДемонстрация работы библиотеки завершена.\n";
    return 0;
}
