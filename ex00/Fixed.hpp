#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int	fixed_;
		static const int frac_bit_ = 8;
	public:
		Fixed();
		Fixed(const Fixed &source);
		~Fixed();
		Fixed& operator=(const Fixed &soruce);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif