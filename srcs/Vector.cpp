#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"

std::vector<std::pair<void *, void *>*> PmergeMe::getPairVec() {
	return (_pairVec);
}

void PmergeMe::fillVector(char **av) {
    for (size_t i = 1; av[i]; i++) {
        _vec.push_back(atoui(av[i]));
    }
	for (std::vector<void *>::iterator it = _vec.begin(); it != _vec.end() && (it + 1) != _vec.end(); it += 2) {	
		if ((*(static_cast<unsigned long int *>(*it))) > (*(static_cast<unsigned long int *>(*(it + 1))))) {
			_pairVec.push_back(new std::pair<void *, void *>(*it, *(it + 1)));
		}
		else { 
			_pairVec.push_back(new std::pair<void *, void *>(*(it + 1), *it));
		}
	}
	if (_vec.size() % 2 == 1) {
		for (std::vector<void *>::iterator it = _vec.begin(); it != _vec.end(); it ++) {
			if ((it + 1) == _vec.end())
				_pairVec.push_back(new std::pair<void *, void *>(*it, NULL));
		}
	}
}

unsigned long int	PmergeMe::dataOfPairVector(std::vector<std::pair<void *, void *> *>::iterator it) {
	int i = 0;
	std::pair<void *, void *> *pair = static_cast<std::pair<void *, void *> *>(*it);
	while (i != (_deep )) {
		pair = static_cast<std::pair<void *, void *> *>(pair->first);
		i++;
	}
	std::pair<unsigned int , unsigned int> *result = reinterpret_cast<std::pair<unsigned int, unsigned int> * >(pair);
	return result-> first;
}

void	PmergeMe::freeVecPair(std::vector<std::pair<void *, void *> *> vec) {
	for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
		delete(*it);
	}
}

std::vector<std::pair<void *, void *> *>	PmergeMe::pairageVec(std::vector<std::pair<void *, void *> *> &toSort) {
	std::vector<std::pair<void *, void *> *> newVec;
	for (std::vector<std::pair<void *, void *> *>::iterator it = toSort.begin(); it != toSort.end() && (it + 1) != toSort.end(); it += 2) {
		if (dataOfPairVector(it) > dataOfPairVector(it + 1))
			newVec.push_back(new std::pair<void*, void*>(*it, *(it + 1)));
		else
			newVec.push_back(new std::pair<void*, void*>(*(it + 1), *it));
	}
	if (toSort.size() % 2 == 1) {
		for (std::vector<std::pair<void *, void *> *>::iterator it = toSort.begin(); it != toSort.end(); it ++) {
			if ((it + 1) == toSort.end())
				newVec.push_back(new std::pair<void *, void *>(*it, NULL));
		}
	}
	return newVec;
}

void	PmergeMe::printFirstVector(std::vector<std::pair<void *, void *> *> vec) {
	std::cout << "profondeur = " << _deep << " " << " value = ";
		for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << dataOfPairVector(it) << " ";
	}
	std::cout << std::endl;
}

std::vector<std::pair<void *, void *> *>	PmergeMe::recursiveSortVec(std::vector<std::pair<void *, void *> *> before) {
	_deep++;
	printFirstVector(before);

	if (before.size() == 2) {	// plus que deux elements, on les swap ou on les garde meme pas sur que ce soit utile se swapper
		_deep--;
		return (before);
	}
	std::vector<std::pair<void *, void *> *> newVec = pairageVec(before); // fais le pairage
	std::vector<std::pair<void *, void *> *> retVec = recursiveSortVec(newVec); // rappelle de la fonction si on a plus de 2 element
	freeVecPair(newVec);

	_deep--;
	return (before);
}

void	PmergeMe::sortVec() {
	std::vector<std::pair<void *, void *> *> toSort;
	toSort = recursiveSortVec(_pairVec);
}