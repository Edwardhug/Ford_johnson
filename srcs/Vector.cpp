#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"

void PmergeMe::fillVector(char **av) {
    for (size_t i = 1; av[i]; i++) {
        _vec.push_back(atoui(av[i]));
    }
	for (std::vector<void *>::iterator it = _vec.begin(); it != _vec.end() && (it + 1) != _vec.end(); it += 2) {
		if (static_cast<unsigned long int *>(*it) > static_cast<unsigned long int *>(*(it + 1))) {
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


	// std::cout << "Contenu de _pairVec :" << std::endl;
    // for (std::vector<std::pair<void *, void *> *>::iterator it = _pairVec.begin(); it != _pairVec.end(); ++it) {
    //     unsigned long int *first = static_cast<unsigned long int *>((*it)->first);
    //     unsigned long int *second = static_cast<unsigned long int *>((*it)->second);
	// 	if (!second)
	// 		std::cout << "(" << *first << ", " << "NULL" << ")" << std::endl;
	// 	else
	// 		std::cout << "(" << *first << ", " << *second << ")" << std::endl;
    // }
}

std::vector<std::pair<void *, void *> *>	PmergeMe::swapTheLastTwoVector(std::vector<std::pair<void *, void *> *> before) {
	std::vector<std::pair<void *, void *> *>::iterator it = ;
	if (getDataVector)
}

std::vector<std::pair<void *, void *> *>	PmergeMe::recursiveSortVec(std::vector<std::pair<void *, void *> *> before) {
	_deep++;

	if (before.size() == 2) {	// plus que deux elements, on les swap ou on les garde
		return (swapTheLastTwoVector(before));
	}

}

void	PmergeMe::sortVec() {
	std::vector<std::pair<void *, void *> *> toSort;
	toSort = recursiveSortVec(_pairVec);
}