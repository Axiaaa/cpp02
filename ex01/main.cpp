#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    printf << "a is " << a << std::endl;
    printf << "b is " << b << std::endl;
    printf << "c is " << c << std::endl;
    printf << "d is " << d << std::endl;
    printf << "a is " << a.toInt() << " as integer" << std::endl;
    printf << "b is " << b.toInt() << " as integer" << std::endl;
    printf << "c is " << c.toInt() << " as integer" << std::endl;
    printf << "d is " << d.toInt() << " as integer" << std::endl;
        
    return 0;
}
