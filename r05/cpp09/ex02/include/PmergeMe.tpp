/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:55:15 by sklaokli          #+#    #+#             */
/*   Updated: 2026/06/12 15:17:18 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include <algorithm>
#include <iterator>
#include <vector>

// Regular binary search helper for values
template <typename Container>
typename Container::iterator binarySearch(typename Container::iterator start,
    typename Container::iterator end, int target) {
	while (start < end) {
		typename Container::iterator mid =
		    start + std::distance(start, end) / 2;
		if (*mid > target) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

template <typename Iterator>
void PmergeMe::fordJohnsonSort(Iterator start, Iterator end) {
	typedef typename std::iterator_traits<Iterator>::value_type ValueType;
	size_t size = std::distance(start, end);
	if (size < 2) return;

	// 1. Isolate pair groups and separate an odd element if it exists
	std::vector<ValueType> mainChain;
	std::vector<ValueType> pends;
	bool hasLeftover = (size % 2 != 0);
	ValueType leftover = 0;

	Iterator it = start;
	if (hasLeftover) {
		Iterator leftoverIt = end;
		std::advance(leftoverIt, -1);
		leftover = *leftoverIt;
		end = leftoverIt;  // Shrink operational bounds
	}

	// 2. Create pairs, sort them internally, and sort them recursively
	// To keep this clear, efficient, and 100% immune to iterator corruption:
	std::vector<std::pair<ValueType, ValueType> > pairs;
	for (it = start; it != end;) {
		ValueType first = *it++;
		ValueType second = *it++;
		if (first > second) {
			std::swap(first, second);
		}
		pairs.push_back(std::make_pair(first, second));
	}

	// Sort pairs based on their larger value (the second element)
	for (size_t i = 0; i < pairs.size(); ++i) {
		for (size_t j = i + 1; j < pairs.size(); ++j) {
			if (pairs[i].second > pairs[j].second) {
				std::swap(pairs[i], pairs[j]);
			}
		}
	}

	// 3. Populate Main Chain and Pends initial layout
	for (size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].second);
		pends.push_back(pairs[i].first);
	}

	// The first pend element is mathematically guaranteed to be smaller than
	// the first main chain leader, so we can insert it at index 0 without
	// needing a binary search lookup.
	if (!pends.empty()) {
		mainChain.insert(mainChain.begin(), pends[0]);
	}

	// 4. Generate Jacobsthal insertion order indexes
	std::vector<size_t> jacobsthalIndices;
	jacobsthalIndices.push_back(1);  // Since item 0 is already handled
	jacobsthalIndices.push_back(3);
	while (jacobsthalIndices.back() < pends.size()) {
		size_t next = jacobsthalIndices.back() +
		              2 * jacobsthalIndices[jacobsthalIndices.size() - 2];
		jacobsthalIndices.push_back(next);
	}

	// 5. Unwind and execute binary insertions using the Jacobsthal blocks
	size_t lastJacob = 1;
	for (size_t i = 0; i < jacobsthalIndices.size(); ++i) {
		size_t targetJacob = jacobsthalIndices[i];
		if (targetJacob >= pends.size()) {
			targetJacob = pends.size() - 1;
		}

		for (size_t j = targetJacob + 1; j > lastJacob; --j) {
			size_t idx = j - 1;
			if (idx >= pends.size()) continue;

			// Find appropriate insertion window bounds up to where its partner
			// element lives
			ValueType targetValue = pends[idx];
			typename std::vector<ValueType>::iterator searchEnd =
			    mainChain.end();

			// Optimization: only search up to where its original pair leader is
			// in the main chain
			if (idx < pairs.size()) {
				searchEnd = std::find(
				    mainChain.begin(), mainChain.end(), pairs[idx].second);
			}

			typename std::vector<ValueType>::iterator insertPos =
			    binarySearch<std::vector<ValueType> >(
			        mainChain.begin(), searchEnd, targetValue);
			mainChain.insert(insertPos, targetValue);
		}
		lastJacob = targetJacob + 1;
		if (lastJacob >= pends.size()) break;
	}

	// 6. If an odd item was isolated at the start, insert it now
	if (hasLeftover) {
		typename std::vector<ValueType>::iterator insertPos =
		    binarySearch<std::vector<ValueType> >(
		        mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(insertPos, leftover);
	}

	// 7. Write the sorted sequence back into your container attributes safely!
	std::copy(mainChain.begin(), mainChain.end(), start);
}

#endif
