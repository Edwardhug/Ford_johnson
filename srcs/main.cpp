#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"
#include <exception>

bool isDigit(char *str) {
	for (int i = 0; str[i]; i++) {
		if (str[i] > '9' || str[i] < '0')
			return (false);
	}
	return (true);
}

int main(int ac, char **av) {
	if (ac < 3) {
		std::cout << "Error: No Pmerge to do." << std::endl;
		return 1;
	}
	for (int i = 1; av[i]; i++) {
		if (isDigit(av[i]) == false) {
			std::cout << "Error: Need online positive numbers." << std::endl;
			return 1;
		}
	}

	PmergeMe Pmerge;
	try {
		Pmerge.fillVector(av);
	}
	catch (std::exception &e) {
		std::cout << "Error : too big number" << std::endl;
		return 1 ;
	}
	std::cout << "Before : ";
	Pmerge.printResult(Pmerge.getPairVec());
	Pmerge.setDeep(0);
	Pmerge.sortVec();
	std::cout << "After  : ";
	Pmerge.printResult(Pmerge.getResult());
	Pmerge.printTimeVec();
}