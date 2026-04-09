#include "vector.h" // our vector class;
#include <iostream>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << v << "\n";
    cout << "Hello: " << v[4] << "\n";
    return 0;
}