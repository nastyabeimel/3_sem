//
//  main.cpp
//  library_proj2
//
//  Created by Олег on 09.09.2025.
//

#include <iostream>
#include "../Library/Stack.h"

int main(int argc, const char * argv[]) {
    Stack s{1, 2, 3}; // инициализация через список
    std::cout << "Стек: " << s.toString() << std::endl;
    s.push(4);
    std::cout << "После push(4): " << s.toString() << std::endl;
    int top = s.peek();
    std::cout << "peek(): " << top << std::endl;
    int popped = s.pop();
    std::cout << "pop(): " << popped << std::endl;
    std::cout << "После pop(): " << s.toString() << std::endl;
    std::cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << std::endl;
    s << 5 << 6; // оператор сдвига влево (push)
    std::cout << "После s << 5 << 6: " << s.toString() << std::endl;
    int val;
    s >> val; // оператор сдвига вправо (pop)
    std::cout << "s >> val: " << val << std::endl;
    std::cout << "Стек: " << s.toString() << std::endl;
    std::cout << "Доступ по индексу [0]: " << s[0] << std::endl;
    return 0;
}
