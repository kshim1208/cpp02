#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_ = 0;
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
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
