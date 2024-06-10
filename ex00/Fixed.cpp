#include "Fixed.hpp"

const int Fixed::_fractionnalBitStore = 8;

Fixed::Fixed() {
    printf << "Default constructor called" << "\n";
    this->_fixedPointStore = 0;
}

Fixed::~Fixed() {
    printf << "Destructor called" << "\n";
}

Fixed::Fixed(const Fixed& x) {
    printf << "Copy constructor called" << "\n";
    *this = x;
}

Fixed& Fixed::operator=(const Fixed& x) {
    printf << "Copy assignment operator called" << "\n";
    if (this != &x) {
        this->_fixedPointStore = x.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    printf << "getRawBits member function called" << "\n";
    return this->_fixedPointStore;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointStore = raw;
}
