#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed
{
private:

	int			value;
	const int	fract = 8;

public:
	Fixed();
	Fixed(Fixed const &other);
	virtual ~Fixed();

	Fixed &operator=(Fixed const &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif