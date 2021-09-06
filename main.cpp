#include "slice.h"

using namespace std;

int main() {
    Slice<int> slice;
    slice = {1,2,3,4,5,6,7,8,9,0};
    cout<<slice;
}