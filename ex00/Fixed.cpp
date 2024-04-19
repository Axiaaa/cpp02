#include "Fixed.hpp"

Fixed::Fixed(int x) {
    Fixed::
    setRawBits(x); 
}

Fixed::~Fixed() {
    printf << "Destructor called" << "\n";
}

Fixed::Fixed() {
    printf << "Default constructor called" << "\n";
    Fixed::fixedPointStore = 0;
}

Fixed::Fixed(const Fixed& x) {
    printf << "Copy constructor called" << "\n";
    *this = x;
}

Fixed& Fixed::operator=(const Fixed& x) {
    printf << "Copy assignment operator called" << "\n";
    if (this != &x) {
        this->fixedPointStore = x.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    printf << "getRawBits member function called" << "\n";
    return Fixed::fixedPointStore;
}

void Fixed::setRawBits(int const raw) {
    Fixed::fixedPointStore = raw;
}
