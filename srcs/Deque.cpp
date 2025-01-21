#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"
#include <algorithm>

std::deque<std::pair<void *, void *>*> PmergeMe::getPairDeq() {
	return (_pairDeq);
}

void PmergeMe::fillDeque(char **av) {
    for (size_t i = 1; av[i]; i++) {
        _deq.push_back(atoui(av[i]));
    }
	for (std::deque<void *>::iterator it = _deq.begin(); it != _deq.end(); it ++) {
		_pairDeq.push_back(new std::pair<void *, void *>(*it, NULL));
	}
}

unsigned long int	PmergeMe::dataOfPairDeque(std::deque<std::pair<void *, void *> *>::iterator it) {
	int i = 0;
	std::pair<void *, void *> *pair = static_cast<std::pair<void *, void *> *>(*it);
	while (i != (_deep )) {
		pair = static_cast<std::pair<void *, void *> *>(pair->first);
		i++;
	}
	std::pair<unsigned int , unsigned int> *result = reinterpret_cast<std::pair<unsigned int, unsigned int> * >(pair);
	return result-> first;
}

void	PmergeMe::freeDeqPair(std::deque<std::pair<void *, void *> *> Deq) {
	for (std::deque<std::pair<void *, void *> *>::iterator it = Deq.begin(); it != Deq.end(); it++) {
		delete(*it);
	}
}

std::deque<std::pair<void *, void *> *>	PmergeMe::pairingDeq(std::deque<std::pair<void *, void *> *> &toSort) {
	std::deque<std::pair<void *, void *> *> newDeq;
	for (std::deque<std::pair<void *, void *> *>::iterator it = toSort.begin(); it != toSort.end() && (it + 1) != toSort.end(); it += 2) {
		if (dataOfPairDeque(it) > dataOfPairDeque(it + 1))
			newDeq.push_back(new std::pair<void*, void*>(*it, *(it + 1)));
		else
			newDeq.push_back(new std::pair<void*, void*>(*(it + 1), *it));
	}
	if (toSort.size() % 2 == 1) {
		for (std::deque<std::pair<void *, void *> *>::iterator it = toSort.begin(); it != toSort.end(); it ++) {
			if ((it + 1) == toSort.end())
				newDeq.push_back(new std::pair<void *, void *>(*it, NULL));
		}
	}
	return newDeq;
}

std::deque<std::pair<void *, void *>*> PmergeMe::getOnlyBigDeq(std::deque<std::pair<void *, void *> *> &Deq) {
    std::deque<std::pair<void *, void *>*> toRet;
    for (std::deque<std::pair<void *, void *> *>::iterator it = Deq.begin(); it != Deq.end(); it++) {
        toRet.push_back(static_cast<std::pair<void *, void *> *>((*it)->first));
    }
    return toRet;
}

std::deque<std::pair<void *, void *>*> PmergeMe::getOnlySmallDeq(std::deque<std::pair<void *, void *> *> &Deq) {
    std::deque<std::pair<void *, void *>*> toRet;
    for (std::deque<std::pair<void *, void *> *>::iterator it = Deq.begin(); it != Deq.end(); it++) {
		if ((*it)->second != NULL)
        	toRet.push_back(static_cast<std::pair<void *, void *> *>((*it)->second));
    }
    return toRet;
}

std::deque<std::pair<void *, void *>*> PmergeMe::depairingDeq(std::deque<std::pair<void *, void *> *> &toDep) {
	std::deque<std::pair<void *, void *>*> bigNumber = getOnlyBigDeq(toDep);
    std::deque<std::pair<void *, void *>*> smallNumber = getOnlySmallDeq(toDep);

	std::deque<std::pair<void *, void *>*> afterDep = mergeInsertionDeq(bigNumber, smallNumber);
	return (afterDep);
}

std::deque<std::pair<void *, void *> *>	PmergeMe::recursiveSortDeq(std::deque<std::pair<void *, void *> *> before) {
	_deep++;

	if (before.size() <= 1) {	// plus que deux elements, on les swap ou on les garde meme pas sur que ce soit utile se swapper
		_deep--;
		return (before);
	}
	std::deque<std::pair<void *, void *> *> newDeq = pairingDeq(before); // fais le pairage
	std::deque<std::pair<void *, void *> *> retDeq = recursiveSortDeq(newDeq); // rappelle de la fonction si on a plus de 2 element

	retDeq = depairingDeq(retDeq);
	for (std::deque<std::pair<void *, void *> *>::iterator it = newDeq.begin(); it != newDeq.end(); ++it) {
        delete *it;
    }
	_deep--;
	return (retDeq);
}

void	PmergeMe::sortDeq() {
	std::deque<std::pair<void *, void *> *> toSort;
	setBeforeDeq();
	_resultDeq = recursiveSortDeq(_pairDeq);
	setAfterDeq();
}




std::deque<std::pair<void *, void *>*> PmergeMe::mergeInsertionDeq(std::deque<std::pair<void *, void *>*>& bigNumbers, std::deque<std::pair<void *, void *>*>& smallNumbers) {
    std::deque<std::pair<void *, void *>*> result;
    // result.reserve(bigNumbers.size() + smallNumbers.size());
    result = bigNumbers;
    if (smallNumbers.empty()) {
        return result;
    }
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    while (jacobsthal.back() < smallNumbers.size()) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    for (size_t i = 0; i < smallNumbers.size(); ++i) {
        std::pair<void *, void *>* toInsert = smallNumbers[i];
        size_t left = 0;
        size_t right = result.size();
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (dataOfPairDeque(result.begin() + mid) < dataOfPairDeque(smallNumbers.begin() + i)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, toInsert);
	}
    return result;
}

void	PmergeMe::setBeforeDeq() {
	_beforeDeq = getCurrentTimeInMilliseconds();
}

void	PmergeMe::setAfterDeq() {
	_afterDeq = getCurrentTimeInMilliseconds();
}

void	PmergeMe::printTimeDeq() {
	std::cout << "Time to process a range of " << _pairDeq.size() << " elements with std::deque : " << _afterDeq - _beforeDeq << "us" << std::endl;
}