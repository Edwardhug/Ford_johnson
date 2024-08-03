#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"

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

    // Afficher les valeurs contenues dans le vecteur
    // for (std::vector<void *>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
    //     unsigned long int *value = static_cast<unsigned long int *>(*it);
    //     std::cout << *value << " "; // Déréférencer pour obtenir la valeur
    // }
    // std::cout << std::endl;
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

void	PmergeMe::swapTheLastTwoVector(std::vector<std::pair<void *, void *> *> &before) {
	std::vector<std::pair<void *, void *> *>::iterator it = before.begin();
	unsigned long int first = dataOfPairVector(it);
	unsigned long int second = dataOfPairVector(++it);

	if (first < second){
		std::swap(before[0], before[1]);
	}
}

std::vector<std::pair<void *, void *> *>	PmergeMe::recursiveSortVec(std::vector<std::pair<void *, void *> *> before) {
	_deep++;

	if (before.size() == 2) {	// plus que deux elements, on les swap ou on les garde
		swapTheLastTwoVector(before);
		return (before);
	}
	return (before);
}

void	PmergeMe::sortVec() {
	std::vector<std::pair<void *, void *> *> toSort;
	toSort = recursiveSortVec(_pairVec);
}

std::vector<std::pair<void *, void *>*> PmergeMe::getPairVec() {
	return (_pairVec);
}