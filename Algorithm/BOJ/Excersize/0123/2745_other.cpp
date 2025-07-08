#import <iostream>
using namespace std;

string a;
int b;

int main()
{
    cin >> a >> b;
    cout << stoi(a, 0, b);
}