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
    std::vector<void *> tmp;
    
    for (size_t i = 1; av[i]; i++) {
        tmp.push_back(static_cast<void *>(atoui(av[i])));
    }

    // Afficher les valeurs contenues dans le vecteur
    for (std::vector<void *>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
        unsigned long int *value = static_cast<unsigned long int *>(*it);
        std::cout << *value << " "; // Déréférencer pour obtenir la valeur
    }
    std::cout << std::endl;

    // Libérer la mémoire allouée
    for (std::vector<void *>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
        delete static_cast<unsigned long int *>(*it); // Libérer chaque unsigned long int alloué
    }
}