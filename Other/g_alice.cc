#include <iostream>
using namespace std;
int Foo(), Gear();
int g_alice = Foo();
int g_bob = Gear();

int Foo()
{
    return g_bob;
}
int Gear() { return 3; }
int main()
{
    cout << g_alice << endl;
    cout << g_bob << endl;
}