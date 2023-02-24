#include "Fixed.hpp"

#include <iostream>
#include <fstream>

#include <cmath>

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

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->fixed_ > rhs.fixed_);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->fixed_ < rhs.fixed_);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->fixed_ >= rhs.fixed_);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->fixed_ <= rhs.fixed_);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->fixed_ == rhs.fixed_);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->fixed_ != rhs.fixed_);
}


Fixed Fixed::operator+(const Fixed &source) const
{
	float	tmp;

	tmp = this->toFloat() + source.toFloat();
	if (tmp == NAN || tmp == INFINITY)
	{
		std::cout << "Inappropriate float value" << std::endl;
		exit(1);
	}
	Fixed	arith = tmp;
	return (arith);
}

Fixed Fixed::operator-(const Fixed &source) const
{
	float	tmp;

	tmp = this->toFloat() - source.toFloat();
	if (tmp == NAN || tmp == INFINITY)
	{
		std::cout << "Inappropriate float value" << std::endl;
		exit(1);
	}
	Fixed	arith = tmp;
	return (arith);
}

Fixed Fixed::operator*(const Fixed &source) const
{
	float	tmp;

	tmp = this->toFloat() * source.toFloat();
	if (tmp == NAN || tmp == INFINITY)
	{
		std::cout << "Inappropriate float value" << std::endl;
		exit(1);
	}
	Fixed	arith = tmp;
	return (arith);
}

Fixed Fixed::operator/(const Fixed &source) const
{
	float	tmp;

	tmp = this->toFloat() / source.toFloat();
	if (tmp == NAN || tmp == INFINITY)
	{
		std::cout << "Inappropriate float value" << std::endl;
		exit(1);
	}
	Fixed	arith = tmp;
	return (arith);
}

Fixed& Fixed::operator++()
{
	this->fixed_++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->fixed_--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	arith;

	arith.fixed_ = this->fixed_;
	this->fixed_++;
	return (arith);
}

Fixed Fixed::operator--(int)
{
	Fixed	arith;

	arith.fixed_ = this->fixed_;
	this->fixed_--;
	return (arith);
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
	return (static_cast<float>(this->getRawBits()) / (1 << this->frac_bit_));
}

int Fixed::toInt() const
{
	return (this->getRawBits() >> this->frac_bit_);
}

Fixed& Fixed::min(Fixed &src1, Fixed &src2)
{
	return (src1.toFloat() <= src2.toFloat() ? src1 : src2);
}

const Fixed& Fixed::min(const Fixed &src1, const Fixed &src2)
{
	return (src1.toFloat() <= src2.toFloat() ? src1 : src2);
}

Fixed& Fixed::max(Fixed &src1, Fixed &src2)
{
	return (src1.toFloat() >= src2.toFloat() ? src1 : src2);
}

const Fixed& Fixed::max(const Fixed &src1, const Fixed &src2)
{
	return (src1.toFloat() >= src2.toFloat() ? src1 : src2);
}

std::ostream& operator<<(std::ostream &output, const Fixed &source)
{
	output << source.toFloat();
	return (output);
}
