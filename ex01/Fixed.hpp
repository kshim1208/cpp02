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
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream &output, const Fixed &source);

#endif