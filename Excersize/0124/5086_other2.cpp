#include <iostream>
using namespace;

int main()
{
    for (int a, b; cin >> a >> b && a ^ b;)
    
        printf(b % a ? a % b ? "neither\n" : "multiple\n" : "factor\n");
}