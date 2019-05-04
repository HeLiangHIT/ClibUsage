/* 编译: g++ -std=c++17 example.cpp -o example  */

#include "pprint.hpp"
#include <complex>
#include <vector>

int main(int argc, char const *argv[])
{
    pprint::PrettyPrinter printer;

    printer.print(5);
    printer.print(3.14f);
    printer.print(2.718);
    printer.print(true);
    printer.print('x');
    printer.print("Hello, 世界");
    printer.print(nullptr);

    typedef std::array<std::array<int, 3>, 3> Mat3x3;
    Mat3x3 matrix;
    matrix[0] = {1, 2, 3};
    matrix[1] = {4, 5, 6};
    matrix[2] = {7, 8, 9};
    printer.print("Matrix =", matrix);

    printer.quotes(true);
    printer.print("A", "B", "C");

    using namespace std::complex_literals;
    std::complex<double> foo = 1. + 2.5i;
    std::complex<double> bar = 9. + 4i;
    printer.print(foo, "*", bar, "=", (foo * bar));   // parameter packing

    enum Color { RED = 2, BLUE = 4, GREEN = 8 };
    Color color = BLUE;
    printer.print(color);

    std::vector<std::map<std::string, int>> foo {{{"a", 1}, {"b", 2}}, {{"c", 3}, {"d", 4}}};
    printer.compact(true);
    printer.print("Foo =", foo);
    return 0;
}