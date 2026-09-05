/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:07:18 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/28 01:51:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <deque>
#include <limits>
#include <list>
#include <numeric>
#include <vector>

class Span {
private:
	unsigned int N;
	std::vector<int> vector;

public:
	typedef std::vector<int>::iterator iterator;
	typedef std::vector<int>::const_iterator const_iterator;

	Span();
	Span(unsigned int n);
	Span(const Span&);
	Span& operator=(const Span&);
	~Span();

	void addNumber(int);

	template <typename Iterator>
	void addnumber(Iterator begin, Iterator end) {
		long distance = std::distance(begin, end);
		if (vector.size() + static_cast<unsigned int>(distance) > N)
			throw SpanException("Span: capacity reached");
		vector.insert(vector.end(), begin, end);
	}

	int shortestSpan();
	int longestSpan();

	class SpanException : public std::exception {
	private:
		const char* _msg;
		SpanException();

	public:
		SpanException(const char*);
		SpanException(const SpanException&);
		SpanException& operator=(const SpanException&);
		virtual ~SpanException() throw();
		virtual const char* what() const throw();
	};
};

#endif
