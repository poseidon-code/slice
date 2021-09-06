#include "slice.h"
#include<sstream>

using namespace std;


/// @brief A default-parameterised constructor of Slice for initiaizing the actual slice.
template <typename T>
Slice<T> :: Slice(vector<T> s) { slice = s; }


/// @returns An iteratable instance of Slice.
template <typename T>
vector<T> Slice<T> :: get() { return slice; }


/// @returns Size of the Slice.
template <typename T>
int Slice<T> :: size() { return slice.size(); }


/// @brief Overloaded << operator. Used with standard output to print a Slice to console.
template <typename T>
ostream &operator<<(ostream &os, Slice<T> &s) {
    // get the Slice
    auto slice=s.get();

    os<<"[";
    for (auto e : slice) {
        // if Slice is of 'string' type, then print elements in ""(double quotes)
        if(is_same<T, string>::value) os<<"\""<<e<<"\"";

        // if Slice is of 'char' type, then print elements in ''(single quotes)
        else if(is_same<T, char>::value) os<<"\'"<<e<<"\'";

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
istream &operator>>(istream &is, Slice<T> &s) {
    // generate stringstream from inputed string
    string str; getline(cin, str); stringstream ss(str);

    // create temporary vector & an element of that vector
    vector<T> slice; T e;

    // append <space> seperated elements to the temporary vector
    while(ss>>e) {
        slice.push_back(e);
        if(ss.peek() == ' ') ss.ignore();
    }

    // initialize Slice class with temorary vector ('=' operator is overloaded)
    s=slice;

    return is;
}

// int main() {
//     Slice<int> slice;
//     slice = {1,2,3,45,6,7,8};
//     cout<<slice;
// }