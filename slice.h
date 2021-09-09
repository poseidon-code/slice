#pragma once

#include<iostream>
#include<vector>

/// @brief An implementation of dynamic sized, console based space seperated list input with inbuilt console output and input operator overloads, inspired from Python's List.
template <typename T>
class Slice {
    private:
        std::vector<T> slice;

    public:
        /// @brief A default-parameterised constructor of Slice for initiaizing the actual slice.
        Slice(std::vector<T> s={});

        /// @brief Overloaded = operator. Used to initialize an instance of Slice using '='(equals/assignment) operator with a list enclosed in '{}'(braces).
        Slice<T> &operator=(std::initializer_list<T> l) {
            slice = l;
            return *this;
        }

        /// @returns An iteratable instance of Slice.
        std::vector<T> get();

        /// @returns Size of the Slice.
        int size();
};

/// @brief Overloaded << operator. Used with standard output to print a Slice to console.
template <typename T>
std::ostream &operator<<(std::ostream &os, Slice<T> &s);

/// @brief Overloaded >> operator. Used with standard input to initialize a Slice with input from console.
template <typename T>
std::istream &operator>>(std::istream &is, Slice<T> &s);
