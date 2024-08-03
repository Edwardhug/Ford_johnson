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
};

#endif