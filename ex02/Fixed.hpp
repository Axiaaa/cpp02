#ifndef FIXED_HPP

#include <iostream>
#include <cmath>

#define printf std::cout


class Fixed {

    private :
        int fixedPointStore;
        static const int fractionnalBitStore;

    public :
    
        ~Fixed();
        Fixed();

        /*
        ** 1. A constructor that takes an int as a parameter and that converts it to the corresponding fixed point value.   
        */
        Fixed(const int n);

        /*
        ** 2. A constructor that takes a float as a parameter and that converts it to the corresponding fixed point value.
        */
        Fixed(const float n);

        /*
        ** 3. A copy constructor.
        */
        Fixed(const Fixed& x);

        /*
        ** Assignation operator overload.
        */
        Fixed& operator=(const Fixed& x);
        Fixed& operator+(const Fixed& x);
        Fixed& operator-(const Fixed& x);
        Fixed& operator*(const Fixed& x);
        Fixed& operator/(const Fixed& x);
        
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        bool operator>(const Fixed& x);
        bool operator<(const Fixed& x);
        bool operator>=(const Fixed& x);
        bool operator<=(const Fixed& x);
        bool operator==(const Fixed& x);
        bool operator!=(const Fixed& x);

        /*
        ** @brief Returns the minimum value between two fixed point values.
        ** @param const Fixed& x
        ** @param const Fixed& y
        ** @return const Fixed&
        */
        const static Fixed& min(const Fixed& x, const Fixed& y);
        
        /*
        ** @brief Returns the minimum value between two fixed point values.
        ** @param Fixed& x
        ** @param Fixed& y
        ** @return Fixed&
        */
        static Fixed& min(Fixed& x, Fixed& y);
        
        /*
        ** @brief Returns the maximum value between two fixed point values.
        ** @param const Fixed& x
        ** @param const Fixed& y
        ** @return const Fixed&
        */
        const static Fixed& max(const Fixed& x, const Fixed& y);
        
        /*
        ** @brief Returns the maximum value between two fixed point values.
        ** @param Fixed& x  
        ** @param Fixed& y
        ** @return Fixed&
        */
        static Fixed& max(Fixed& x, Fixed& y);

        /*
        ** @brief Returns the raw value of the fixed point value.
        ** @return int
        */
        int getRawBits(void) const;

        /*
        ** @brief Sets the raw value of the fixed point value.
        ** @param int raw
        ** @return none
        */
        void setRawBits(int const raw);

        /*
        ** @brief Returns the fixed point value as a float
        ** @return float
        */
        float toFloat(void) const;

        /*
        ** @brief Returns the fixed point value as an int.
        ** @return int
        */
        int toInt(void) const;
        
};

std::ostream &operator<<(std::ostream& os, Fixed const &x);

#endif