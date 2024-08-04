#ifndef PMERGEME_CPP
# define PMERGEME_CPP

# include <vector>
# include <deque>
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

	private:
		std::deque<void *> _deq;
		std::deque<std::pair<void *, void *>*> _pairDeq;
		std::deque<std::pair<void *, void *>*> _resultDeq;

		long	_beforeDeq;
		long	_afterDeq;

	public:

		void	fillDeque(char **av);
		void	sortDeq();
		std::deque<std::pair<void *, void *> *>	recursiveSortDeq(std::deque<std::pair<void *, void *> *> before);
		unsigned long int	dataOfPairDeque(std::deque<std::pair<void *, void *> *>::iterator it);
		std::deque<std::pair<void *, void *> *>	pairingDeq(std::deque<std::pair<void *, void *> *> &toSort);
		std::deque<std::pair<void *, void *> *>	depairingDeq(std::deque<std::pair<void *, void *> *> &toDep);
		std::deque<std::pair<void *, void *>*>	getOnlyBigDeq(std::deque<std::pair<void *, void *> *> &vec);
		std::deque<std::pair<void *, void *>*>	getOnlySmallDeq(std::deque<std::pair<void *, void *> *> &vec);
		std::deque<std::pair<void *, void *>*> mergeInsertionDeq(std::deque<std::pair<void *, void *>*>& bigNumbers, std::deque<std::pair<void *, void *>*>& smallNumbers);

		void	printResult(std::deque<std::pair<void *, void *> *> vec);
		void	freeDeqPair(std::deque<std::pair<void *, void *> *> vec);

		std::deque<std::pair<void *, void *>*>	getPairDeq();
		void	setBeforeDeq();
		void	setAfterDeq();
		void	printTimeDeq();
};

#endif