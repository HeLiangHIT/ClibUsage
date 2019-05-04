#include <iostream>
#include "nod.hpp"

void print_sum( int x, int y ) {
    std::cout << x << "+" << y << "=" << (x+y) << std::endl;
}
void print_product( int x, int y ) {
    std::cout << x << "*" << y << "=" << (x*y) << std::endl;
}

int main(int argc, char const *argv[]) {
    // We create a signal with two integer arguments.
    nod::signal<void(int,int)> signal;
    // Let's connect our slot
    signal.connect( print_sum );
    signal.connect( print_product );

    // Call the slots
    signal(10, 15);
    signal(-5, 7);
    return 0;
}
