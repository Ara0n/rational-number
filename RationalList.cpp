#include "RationalList.h"
#include "RationalNumber.h"
#include <iostream>

RationalList::RationalList() {
	m_max_size = 1;
	m_current_size = 0;
	RationalNumber *m_array = new RationalNumber[1];
}

RationalList::RationalList(const int size) {
	m_max_size = size;
	m_current_size = 0;
	RationalNumber *m_array = new RationalNumber[size];
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

void RationalList::resize(const int new_size) {
	RationalNumber *new_array = new RationalNumber[new_size];
	for (int i = 0; i < m_current_size; ++i) {
		new_array[i] = m_array[i];
	}

	delete [] m_array;
	m_array = new_array;
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