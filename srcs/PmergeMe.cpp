#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"

PmergeMe::PmergeMe() :_deep(1) {}

PmergeMe::~PmergeMe() {
    for (std::vector<void *>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
        delete static_cast<unsigned long int *>(*it);
    }
	for (std::vector<std::pair<void *, void *> *>::iterator it = _pairVec.begin(); it != _pairVec.end(); it++) {
		delete(*it);
	}
}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	_vec = copy._vec;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy) {
	_vec = copy._vec;
	return (*this);
}