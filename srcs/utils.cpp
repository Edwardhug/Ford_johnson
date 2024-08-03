#include "../includes/lib.hpp"
#include "../includes/PmergeMe.hpp"

void *atoui(char *str) {
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
	void *addr = new unsigned long int(ret);
	// std::cout << "pass" << *addr << std::endl;
	return (addr);
}

void	printVecPair(std::vector<std::pair<void *, void *>*> pair) {
	std::cout << "Contenu de _pairVec :" << std::endl;
    for (std::vector<std::pair<void *, void *> *>::iterator it = pair.begin(); it != pair.end(); ++it) {
        unsigned long int *first = static_cast<unsigned long int *>((*it)->first);
        unsigned long int *second = static_cast<unsigned long int *>((*it)->second);
		if (!second)
			std::cout << "(" << *first << ", " << "NULL" << ")" << std::endl;
		else
			std::cout << "(" << *first << ", " << *second << ")" << std::endl;
    }
}