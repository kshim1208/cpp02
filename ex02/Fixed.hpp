#ifndef FIXED_HPP
# define FIXED_HPP

# include <fstream>

class Fixed
{
	private:
		int	fixed_;
		static const int frac_bit_ = 8;

	public:
		Fixed();
		Fixed(const Fixed &source);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();
		Fixed& operator=(const Fixed &soruce);

		bool operator>(const Fixed &rhs);
		bool operator<(const Fixed &rhs);
		bool operator>=(const Fixed &rhs);
		bool operator<=(const Fixed &rhs);
		bool operator==(const Fixed &rhs);
		bool operator!=(const Fixed &rhs);

		Fixed operator+(const Fixed &source);
		Fixed operator-(const Fixed &source);
		Fixed operator*(const Fixed &source);
		Fixed operator/(const Fixed &source);

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& min(Fixed &src1, Fixed &src2);
		static const Fixed& min(const Fixed &src1, const Fixed &src2);
		static Fixed& max(Fixed &src1, Fixed &src2);
		static const Fixed& max(const Fixed &src1, const Fixed &src2);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream &output, const Fixed &source);

#endif