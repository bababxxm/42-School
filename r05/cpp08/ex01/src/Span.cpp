/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:12:35 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/28 20:06:42 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// --- SpanException --- //

Span::SpanException::SpanException(const char* msg) : _msg(msg) {}

Span::SpanException::SpanException(const SpanException& other)
    : _msg(other._msg) {}

Span::SpanException& Span::SpanException::operator=(
    const SpanException& other) {
	if (this != &other) _msg = other._msg;
	return *this;
}

Span::SpanException::~SpanException() throw() {}

const char* Span::SpanException::what() const throw() {
	return _msg;
}

// --- Span --- //

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {
	vector.reserve(n);
}

Span::Span(const Span& other) : N(other.N), vector(other.vector) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		N = other.N;
		vector = other.vector;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
	if (vector.size() >= N) throw SpanException("Span: capacity reached");
	vector.push_back(value);
}

int Span::shortestSpan() {
	if (vector.size() < 2)
		throw SpanException("Span: at least 2 numbers required");

	std::vector<int> sorted(vector);
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> diffs(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

	return *std::min_element(diffs.begin() + 1, diffs.end());
}

int Span::longestSpan() {
	if (vector.size() < 2)
		throw SpanException("Span: at least 2 numbers required");
	const_iterator min_it = std::min_element(vector.begin(), vector.end());
	const_iterator max_it = std::max_element(vector.begin(), vector.end());
	return *max_it - *min_it;
}
