#include "Fixed.hpp"

const int Fixed::_fractionnalBitStore = 8;

Fixed::Fixed() {
    printf << "Default constructor called" << "\n";
    Fixed::_fixedPointStore = 0;
}

Fixed::Fixed(const int n) {
    printf << "Int constructor called" << "\n";
    Fixed::setRawBits(n << this->_fractionnalBitStore);
}

Fixed::Fixed(const float n) {
    printf << "Float constructor called" << "\n";
    this->_fixedPointStore = roundf(n * (1 << this->_fractionnalBitStore));
}

Fixed::Fixed(const Fixed& x) {
    printf << "Copy constructor called" << "\n";
    *this = x;
}

Fixed::~Fixed() {
    printf << "Destructor called" << "\n";
}

Fixed& Fixed::operator=(const Fixed& x) {
    printf << "Copy assignment operator called" << "\n";
    if (this != &x) {
        this->_fixedPointStore = x.getRawBits();
    }
    return *this;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointStore / (1 << this->_fractionnalBitStore);
}

int Fixed::toInt(void) const {
    return this->_fixedPointStore >> this->_fractionnalBitStore;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointStore;
}

void Fixed::setRawBits(const int raw) {
    this->_fixedPointStore = raw;
}

std::ostream &operator<<(std::ostream& os, Fixed const &x) {
    os << x.toFloat();
    return os;
}