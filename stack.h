#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack() = default;
    ~Stack() = default;  // Destructor to clean up automatically

    size_t size() const { return std::vector<T>::size(); }
    bool empty() const { return std::vector<T>::empty(); }
    
    void push(const T& item) { std::vector<T>::push_back(item); }

    void pop() {
        if (this->empty()) {
            throw std::underflow_error("Stack underflow: cannot pop from empty stack");
        }
        std::vector<T>::pop_back();
    }

    T const& top() const {
        if (this->empty()) {
            throw std::underflow_error("Stack underflow: cannot access top of empty stack");
        }
        return std::vector<T>::back();
    }
};

#endif