#ifndef RATIONALNUMBER
#define RATIONALNUMBER 

class RationalNumber
{
private:
	bool m_negative;
	unsigned long long m_numerator;
	unsigned long long m_denominator;
	void simplify();
public:
	RationalNumber();
	RationalNumber(long long);
	RationalNumber(long double);
	RationalNumber(long long, long long);
	RationalNumber(long double, long long);
	RationalNumber(long long, long double);
	RationalNumber(long double, long double);
	~RationalNumber();

	// "debug" tools for me
	void info(bool) const;
	void cptool(const RationalNumber&) const;

	long double float_repr();

	// ex1-7 rounding stuff
	long long floor() const;
	long long ceil() const;
	RationalNumber frac_part() const;

	// stream operators
	friend std::ostream& operator << (std::ostream&, const RationalNumber&);
	friend std::istream& operator >> (std::istream&, RationalNumber&);

	// classic arithmetic operators
	RationalNumber& operator = (const RationalNumber&);
	RationalNumber operator + (const RationalNumber&) const;
	RationalNumber operator - (const RationalNumber&) const;
	RationalNumber operator * (const RationalNumber&) const;
	RationalNumber operator / (const RationalNumber&) const;

	// increment and decrement operators
	RationalNumber operator ++ ();
	RationalNumber operator ++ (int);
	RationalNumber operator -- ();
	RationalNumber operator -- (int);

	// reatributing arithmetic operator
	RationalNumber operator += (const RationalNumber&);
	RationalNumber operator -= (const RationalNumber&);
	RationalNumber operator *= (const RationalNumber&);
	RationalNumber operator /= (const RationalNumber&);


	// logical comparison
	bool operator < (const RationalNumber&) const;
	bool operator > (const RationalNumber&) const;
	bool operator <= (const RationalNumber&) const;
	bool operator >= (const RationalNumber&) const;
	bool operator == (const RationalNumber&) const;
	bool operator != (const RationalNumber&) const;
};

#endif