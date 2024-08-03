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
		std::vector<std::pair<void *, void *> *>	swapTheLastTwoVector(std::vector<std::pair<void *, void *> *> before);
};

#endif