#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"

PmergeMe::PmergeMe() :_deep(0) {}

PmergeMe::~PmergeMe() {

}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	_vec = copy._vec;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy) {
	_vec = copy._vec;
	return (*this);
}

void PmergeMe::fillVector(char **av) {
    std::vector<unsigned long int *> tmp;
    
    for (size_t i = 1; av[i]; i++) {
        tmp.push_back(atoui(av[i]));
    }


    for (std::vector<unsigned long int *>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
        delete *it;
    }
}