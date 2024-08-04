#ifndef PMERGEME_CPP
# define PMERGEME_CPP

#include <vector>
# include <utility>
#include <iostream>

class PmergeMe {

	private:
		int _deep;
		std::vector<void *> _vec;
		std::vector<std::pair<void *, void *>*> _pairVec;

	public:

		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &copy);
		void	fillVector(char **av);
		void	sortVec();
		std::vector<std::pair<void *, void *> *>	recursiveSortVec(std::vector<std::pair<void *, void *> *> before);
		unsigned long int	dataOfPairVector(std::vector<std::pair<void *, void *> *>::iterator it);
		std::vector<std::pair<void *, void *> *>	pairingVec(std::vector<std::pair<void *, void *> *> &toSort);
		std::vector<std::pair<void *, void *> *>	depairingVec(std::vector<std::pair<void *, void *> *> &toDep);
		std::vector<void *> getOnlyBigVec(std::vector<std::pair<void *, void *> *> &vec);
		std::vector<void *> getOnlySmallVec(std::vector<std::pair<void *, void *> *> &vec);
		std::vector<std::pair<void *, void *>*> mergeInsertion(std::vector<void*>& bigNumbers, std::vector<void*>& smallNumbers);
		void	insertSorted(std::vector<std::pair<void *, void *>*>& vec, void* value);

		std::vector<std::pair<void *, void *>*>	getPairVec();
		void	printFirstVector(std::vector<std::pair<void *, void *> *> vec);
		void	freeVecPair(std::vector<std::pair<void *, void *> *> vec);

};

#endif