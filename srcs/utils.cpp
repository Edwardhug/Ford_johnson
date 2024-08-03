#include "../includes/lib.hpp"
#include "../includes/PmergeMe.hpp"

unsigned long int *atoui(char *str) {
	unsigned long int ret;
	ret = 0;
	int i = 0;
	int	j = 1;

	while (str[i] && str[i + 1]) 
		i++;
	while (i >= 0) {
		ret += (str[i] - '0') * j;
		j *= 10;
		i--;
	}
	if (ret > 4294967295)
		throw (std::exception());
	unsigned long int *addr = new unsigned long int(ret);
	// std::cout << "pass" << *addr << std::endl;
	return (addr);
}