#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>

class Contact {

private:

	static std::string		field_names[5];
	std::string		field_values[5];

public:

	Contact();
	~Contact();

	void	setInfo(void);
	void	preview(void);
	void	fullview(void);

};

#endif