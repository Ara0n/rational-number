#ifndef RATIONALLIST
#define RATIONALLIST 

#include "RationalNumber.h"
#include <iostream>

void swap(RationalNumber*, RationalNumber*);

class RationalList
{
private:
	int m_max_size;
	int m_current_size;
	RationalNumber *m_array;

public:
	RationalList();
	RationalList(const int);
	RationalList(const RationalList&);
	~RationalList();

	void size() const;
	void info() const;
	void resize(const int);
	void push(const RationalNumber);
	RationalNumber pop();
	RationalList unique();
	void sort();

	bool operator == (const RationalList&) const;
	bool operator != (const RationalList&) const;

	friend std::ostream& operator << (std::ostream&, const RationalList&);
	friend std::istream& operator >> (std::istream&, RationalList&);

	RationalNumber& operator [] (const int);
	const RationalNumber& operator [] (const int) const;
};

#endif