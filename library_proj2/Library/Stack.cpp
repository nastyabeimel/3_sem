#include "Stack.h"
#include <algorithm>

Stack::Stack() : data(nullptr), capacity(0), count(0) {}

Stack::Stack(std::initializer_list<int> list)
    : data(new int[list.size()]), capacity(list.size()), count(list.size()) {
    std::copy(list.begin(), list.end(), data);
}

Stack::Stack(const Stack& other)
    : data(new int[other.capacity]), capacity(other.capacity), count(other.count) {
    std::copy(other.data, other.data + other.count, data);
}

Stack::Stack(Stack&& other) noexcept
    : data(other.data), capacity(other.capacity), count(other.count) {
    other.data = nullptr;
    other.capacity = 0;
    other.count = 0;
}

Stack::~Stack() {
    delete[] data;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        count = other.count;
        data = new int[capacity];
        std::copy(other.data, other.data + count, data);
    }
    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        capacity = other.capacity;
        count = other.count;
        other.data = nullptr;
        other.capacity = 0;
        other.count = 0;
    }
    return *this;
}

int& Stack::operator[](size_t index) {
    if (index >= count) throw std::out_of_range("Index out of range");
    return data[index];
}

void Stack::resize(size_t new_capacity) {
    int* new_data = new int[new_capacity];
    std::copy(data, data + count, new_data);
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void Stack::push(int value) {
    if (count == capacity) resize(capacity == 0 ? 1 : capacity * 2);
    data[count++] = value;
}

int Stack::pop() {
    if (isEmpty()) throw std::out_of_range("Stack is empty");
    return data[--count];
}

int Stack::peek() const {
    if (isEmpty()) throw std::out_of_range("Stack is empty");
    return data[count - 1];
}

bool Stack::isEmpty() const {
    return count == 0;
}

std::string Stack::toString() const {
    std::string result = "[";
    for (size_t i = 0; i < count; ++i) {
        result += std::to_string(data[i]);
        if (i + 1 < count) result += ", ";
    }
    result += "]";
    return result;
}

Stack& Stack::operator<<(int value) {
    push(value);
    return *this;
}

Stack& Stack::operator>>(int& value) {
    value = pop();
    return *this;
}
