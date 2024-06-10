#include <iostream>

#define printf std::cout

class Fixed {

    private :
        int _fixedPointStore;
        static const int _fractionnalBitStore;

    public :

        ~Fixed();
        Fixed();

        /*
        ** @brief A constructor that takes an int as a parameter and that converts it to the corresponding fixed point value.
        */
        Fixed(int x);


        /*
        ** @brief A copy constructor.
        */
        Fixed(const Fixed& x);
        
        /*
        ** @brief Assignation operator overload.
        */
        Fixed& operator=(const Fixed& x);

        /*
        ** @brief Returns the raw value of the fixed point value.
        */
        int getRawBits(void) const;

        /*
        ** @brief Sets the raw value of the fixed point value.
        */
        void setRawBits(int const raw);

};