#ifndef RATIONALLIST
#define RATIONALLIST 

#include "RationalNumber.h"

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
	void resize(const int);
	void push(const RationalNumber);
};

#endif