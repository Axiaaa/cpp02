#include "Fixed.hpp"

const int Fixed::fractionnalBitStore = 8;

Fixed::Fixed() {
    printf << "Default constructor called" << "\n";
    Fixed::fixedPointStore = 0;
}

Fixed::Fixed(const int n) {
    printf << "Int constructor called" << "\n";
    Fixed::setRawBits(n << Fixed::fractionnalBitStore);
}

Fixed::Fixed(const float n) {
    printf << "Float constructor called" << "\n";
    this->fixedPointStore = roundf(n * (1 << this->fractionnalBitStore));
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
        Fixed::fixedPointStore = x.getRawBits();
    }
    return *this;
}

float Fixed::toFloat(void) const {
    return (float)this->fixedPointStore / (1 << this->fractionnalBitStore);
}

int Fixed::toInt(void) const {
    return this->fixedPointStore >> this->fractionnalBitStore;
}

int Fixed::getRawBits(void) const {
    return this->fixedPointStore;
}

void Fixed::setRawBits(const int raw) {
    this->fixedPointStore = raw;
}

std::ostream &operator<<(std::ostream& os, Fixed const &x) {
    os << x.toFloat();
    return os;
}