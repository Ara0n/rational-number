#include "RationalList.h"
#include "RationalNumber.h"
#include <iostream>

	RationalList::RationalList() {
		m_max_size = 1;
		m_current_size = 0;
		m_array = new RationalNumber[1];
	}

RationalList::RationalList(const int size) {
	m_max_size = size;
	m_current_size = 0;
	m_array = new RationalNumber[size];
}

RationalList::RationalList(const RationalList& ra_list) {
	m_max_size = ra_list.m_max_size;
	m_current_size = ra_list.m_current_size;
	m_array = ra_list.m_array;
}

RationalList::~RationalList() {}



void RationalList::size() const{
	std::cout << "current size: " << m_current_size << std::endl;
	std::cout << "max size: " << m_max_size << std::endl;
}

void RationalList::info() const{
	size();
	std::cout << *this << std::endl;
}

void RationalList::resize(const int new_size) {
	RationalNumber *new_array = new RationalNumber[new_size];
	for (int i = 0; i < m_current_size; ++i) {
		new_array[i] = m_array[i];
	}

	delete [] m_array;
	m_array = new_array;
	m_max_size = new_size;
}


void RationalList::push(const RationalNumber ra_nb) {
	if (m_current_size < m_max_size) {
		m_array[m_current_size] = ra_nb;
		m_current_size++;
	} else {
		resize(2 * m_max_size);
		push(ra_nb);
	}
}


RationalNumber RationalList::pop() {
	if (m_current_size == 0) {
		throw std::out_of_range("the RationalList is empty");
	} else {
		m_current_size--;
		RationalNumber ra_nb = m_array[m_current_size];
		return ra_nb;
	}
}


bool RationalList::operator==(const RationalList& ra_list) const{
	if (m_current_size == ra_list.m_current_size) {
		for (int i = 0; i < m_current_size; ++i) {
			if (m_array[i] != ra_list.m_array[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool RationalList::operator!=(const RationalList& ra_list) const{
	return !(*this == ra_list);
}


std::ostream& operator<<(std::ostream& output, const RationalList& ra_list) {
	output << "[";
	for (int i = 0; i < ra_list.m_current_size; ++i) {
		if (i > 0) {
			output << ", ";
		}
		output << ra_list[i];
	}
	output << "]";

	return output;
}


std::istream& operator>>(std::istream& input, RationalList& ra_list) {
	int length;
	RationalNumber ra_nb;
	ra_list.m_current_size = 0;
	std::cout << "list length: ";
	input >> length;
	for (int i = 0; i < length; ++i) {
		std::cout << "inputing rational number:" << std::endl;
		input >> ra_nb;
		ra_list.push(ra_nb);
	}

	return input;
}


RationalNumber& RationalList::operator[](const int index) {
	if (index < m_current_size) {
	return m_array[index];
	}
	throw std::out_of_range("out of range");
}

const RationalNumber& RationalList::operator[](const int index) const{
	if (index < m_current_size) {
	return m_array[index];
	}
	throw std::out_of_range("out of range");
}
