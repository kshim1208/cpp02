#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
{
	this->fixed_ = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
	this->fixed_ = source.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	//It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_ = source.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_ = raw;
}
