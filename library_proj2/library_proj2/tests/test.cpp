#include "../../Library/Stack.h"
#include <cassert>
#include <iostream>

void test_stack_basic() {
    Stack s;
    assert(s.isEmpty());
    s.push(1);
    s.push(2);
    assert(!s.isEmpty());
    assert(s.peek() == 2);
    assert(s.pop() == 2);
    assert(s.pop() == 1);
    assert(s.isEmpty());
}

void test_stack_initializer() {
    Stack s{10, 20, 30};
    assert(s.peek() == 30);
    assert(s[0] == 10);
    assert(s[1] == 20);
    assert(s[2] == 30);
}

void test_stack_copy_move() {
    Stack s{1,2};
    Stack s2 = s;
    assert(s2[0] == 1 && s2[1] == 2);
    Stack s3;
    s3 = s2;
    assert(s3[0] == 1 && s3[1] == 2);
    Stack s4 = std::move(s3);
    assert(s4[0] == 1 && s4[1] == 2);
}

void test_stack_exceptions() {
    Stack s;
    bool caught = false;
    try { s.pop(); } catch(...) { caught = true; }
    assert(caught);
    caught = false;
    try { s.peek(); } catch(...) { caught = true; }
    assert(caught);
}

int main() {
    test_stack_basic();
    test_stack_initializer();
    test_stack_copy_move();
    test_stack_exceptions();
    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}
