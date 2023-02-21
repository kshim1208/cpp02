#include "Fixed.hpp"

#include <iostream>
#include <fstream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_ = 0;
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_ = source.getRawBits();
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_ = number;
	this->fixed_ <<= this->frac_bit_;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	if (number == NAN || number == INFINITY)
	{
		std::cout << "Inappropriate float value" << std::endl;
		exit(1);
	}
	this->fixed_ = roundf(number * (1 << this->frac_bit_));
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
	return (this->fixed_);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_ = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(this->fixed_) / (1 << this->frac_bit_));
}

int Fixed::toInt() const
{
	return (this->fixed_ >> this->frac_bit_);
}

std::ostream& operator<<(std::ostream &output, const Fixed &source)
{
	output << source.toFloat();
	return (output);
}
