#include <iostream>
using namespace std;
class Foo
{
public:
    Foo() {}
    Foo(const Foo &) { cout << "copy const foo&" << endl; }
    Foo(Foo &&) { cout << "copy Foo&&" << endl; }
    Foo &operator=(const Foo &) { cout << "operator= const foo&" << endl; }
    Foo &operator=(Foo &&) { cout << "opeator= foo&&" << endl; }

private:
};
Foo GetFoo()
{
    Foo foo;
    return foo;
}
int main()
{
    Foo foo;
    foo = GetFoo();
}
// -fno-elide-constructors禁止编译器RVO，NRVO优化