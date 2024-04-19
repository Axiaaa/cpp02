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

Fixed& Fixed::operator+(const Fixed& x) {

    Fixed *result = new Fixed();
    result->setRawBits(this->getRawBits() + x.getRawBits());
    return *result;
}

Fixed& Fixed::operator-(const Fixed& x) {

    Fixed *result = new Fixed();
    result->setRawBits(this->getRawBits() - x.getRawBits());
    return *result;
}

Fixed& Fixed::operator*(const Fixed& x) {

    Fixed *result = new Fixed();
    result->setRawBits((this->getRawBits() * x.getRawBits()) >> this->fractionnalBitStore); // x2 ?
    return *result;
}

Fixed& Fixed::operator/(const Fixed& x) {

    Fixed *result = new Fixed();
    result->setRawBits((this->getRawBits() << this->fractionnalBitStore) / x.getRawBits());
    return *result;
}

Fixed& Fixed::operator++() {
    this->fixedPointStore++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--() {
    this->fixedPointStore--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

bool Fixed::operator>(const Fixed& x) {
    return this->getRawBits() > x.getRawBits();
}

bool Fixed::operator<(const Fixed& x) {
    return this->getRawBits() < x.getRawBits();
}

bool Fixed::operator>=(const Fixed& x) {
    return this->getRawBits() >= x.getRawBits();
}

bool Fixed::operator<=(const Fixed& x) {
    return this->getRawBits() <= x.getRawBits();
}

bool Fixed::operator==(const Fixed& x) {
    return this->getRawBits() == x.getRawBits();
}

bool Fixed::operator!=(const Fixed& x) {
    return this->getRawBits() != x.getRawBits();
}

const Fixed& Fixed::min(const Fixed& x, const Fixed& y) {
    return(x.getRawBits() > y.getRawBits() ? x : y);
}

Fixed& Fixed::min(Fixed& x, Fixed& y) {
    return(x.getRawBits() > y.getRawBits() ? x : y);
}

const Fixed& Fixed::max(const Fixed& x, const Fixed& y) {
    return(x.getRawBits() > y.getRawBits() ? x : y);
}

Fixed& Fixed::max(Fixed& x, Fixed& y) {
    return(x.getRawBits() > y.getRawBits() ? x : y);
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