#include <iostream>
#include "../Library/Stack.h"

int main(int argc, const char * argv[]) {
    // Демонстрация инициализации
    Stack s{1, 2, 3};
    std::cout << "Стек: " << s.toString() << std::endl;
    // Push
    s.push(4);
    std::cout << "После push(4): " << s.toString() << std::endl;
    // Peek
    std::cout << "peek(): " << s.peek() << std::endl;
    // Pop
    std::cout << "pop(): " << s.pop() << std::endl;
    std::cout << "После pop(): " << s.toString() << std::endl;
    // Проверка пустоты
    std::cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << std::endl;
    // Операторы сдвига
    s << 5 << 6;
    std::cout << "После s << 5 << 6: " << s.toString() << std::endl;
    int val;
    s >> val;
    std::cout << "s >> val: " << val << std::endl;
    std::cout << "Стек: " << s.toString() << std::endl;
    // Доступ по индексу
    std::cout << "Доступ по индексу [0]: " << s[0] << std::endl;
    // Копирование
    Stack s2 = s;
    std::cout << "Копия стека: " << s2.toString() << std::endl;
    // Присваивание
    Stack s3;
    s3 = s;
    std::cout << "Присваивание: " << s3.toString() << std::endl;
    // Перемещение
    Stack s4 = std::move(s3);
    std::cout << "После перемещения: " << s4.toString() << std::endl;
    // Обработка ошибок
    Stack empty;
    try {
        empty.pop();
    } catch(const std::exception& e) {
        std::cout << "Ошибка pop(): " << e.what() << std::endl;
    }
    try {
        empty.peek();
    } catch(const std::exception& e) {
        std::cout << "Ошибка peek(): " << e.what() << std::endl;
    }
    return 0;
}
