#ifndef PMERGEME_CPP
# define PMERGEME_CPP

# include <vector>
# include <utility>
# include <iostream>
# include "lib.hpp"

class PmergeMe {

	private:
		int _deep;
		std::vector<void *> _vec;
		std::vector<std::pair<void *, void *>*> _pairVec;
		std::vector<std::pair<void *, void *>*> _result;

		long	_beforeVec;
		long	_afterVec;

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
		std::vector<std::pair<void *, void *>*>	getOnlyBigVec(std::vector<std::pair<void *, void *> *> &vec);
		std::vector<std::pair<void *, void *>*>	getOnlySmallVec(std::vector<std::pair<void *, void *> *> &vec);
		std::vector<std::pair<void *, void *>*> mergeInsertionVec(std::vector<std::pair<void *, void *>*>& bigNumbers, std::vector<std::pair<void *, void *>*>& smallNumbers);

		void	printResult(std::vector<std::pair<void *, void *> *> vec);
		void	freeVecPair(std::vector<std::pair<void *, void *> *> vec);

		std::vector<std::pair<void *, void *>*> getResult();
		std::vector<std::pair<void *, void *>*>	getPairVec();
		void	setDeep(int x);
		void	setBeforeVec();
		void	setAfterVec();
		void	printTimeVec();
};

#endif