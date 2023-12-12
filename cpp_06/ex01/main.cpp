#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->i = 3;
	data->s = "Haii";
	uintptr_t ptr = Serializer::serialize(data);
	std::cout << "ptr: " << ptr << std::endl;
	Data *data2 = Serializer::deserialize(ptr);
	std::cout << "data2->i: " << data2->i << std::endl;
	std::cout << "data2->s: " << data2->s << std::endl;
	std::cout << "data2: " << &data2 << std::endl;
	return 0;
}
