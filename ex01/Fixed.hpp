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