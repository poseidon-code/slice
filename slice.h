#pragma once

#include<iostream>
#include<vector>
#include<sstream>

/// @brief An implementation of dynamic sized, console based space seperated list input with inbuilt console output and input operator overloads, inspired from Python's List.
template <typename T>
class Slice {
    private:
        std::vector<T> slice;

    public:
        /// @brief A default-parameterised constructor of Slice for initiaizing the actual slice.
        Slice(std::vector<T> s={}) { slice = s; }

        /// @brief Overloaded = operator. Used to initialize an instance of Slice using '='(equals/assignment) operator with a list enclosed in '{}'(braces).
        Slice<T> &operator=(std::initializer_list<T> l) {
            slice = l;
            return *this;
        }

        /// @returns An iteratable instance of Slice.
        std::vector<T> get() { return slice; }

        /// @returns Size of the Slice.
        int size() { return slice.size(); }
};

/// @brief Overloaded << operator. Used with standard output to print a Slice to console.
template <typename T>
std::ostream &operator<<(std::ostream &os, Slice<T> &s) {
    // get the Slice
    auto slice=s.get();

    os<<"[";
    for (auto e : slice) {
        // if Slice is of 'string' type, then print elements in ""(double quotes)
        if(std::is_same<T, std::string>::value) os<<"\""<<e<<"\"";

        // if Slice is of 'char' type, then print elements in ''(single quotes)
        else if(std::is_same<T, char>::value) os<<"\'"<<e<<"\'";

        // else print the elements as it is
        else os<<e;

        // print with ', '(comma) seperation
        os<<", ";
    }
    os<<"\b\b]";

    return os;
}

/// @brief Overloaded >> operator. Used with standard input to initialize a Slice with input from console.
template <typename T>
std::istream &operator>>(std::istream &is, Slice<T> &s) {
    // generate stringstream from inputed string
    std::string str; getline(std::cin, str); std::stringstream ss(str);

    // create temporary vector & an element of that vector
    std::vector<T> slice; T e;

    // append <space> seperated elements to the temporary vector
    while(ss>>e) {
        slice.push_back(e);
        if(ss.peek() == ' ') ss.ignore();
    }

    // initialize Slice class with temporary vector ('=' operator is overloaded)
    s=slice;

    return is;
}
