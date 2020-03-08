#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <stdexcept>
#include "RationalNumber.h"


// counter stuff

int RationalNumber::count = 0;

int RationalNumber::get_count() {
	return RationalNumber::count;
}


// used to simplify the fractions after operations or initialization

void RationalNumber::simplify() {
	long long simplification = std::__gcd(m_numerator, m_denominator);
	m_numerator /= simplification;
	m_denominator /= simplification;
}


RationalNumber::RationalNumber() {
	m_negative = false;
	m_numerator = 0;
	m_denominator = 1;
	count++;
}

RationalNumber::RationalNumber(long long numerator) {
	m_negative = numerator < 0;
	m_numerator = (numerator < 0) ? -numerator : numerator;
	m_denominator = 1;
	count++;
}

RationalNumber::RationalNumber(long double numerator) {
	m_negative = numerator < 0;
	numerator = numerator < 0 ? -numerator : numerator;
	m_denominator = 1;

	while (std::fmod(numerator, 1) != 0) {
		numerator *= 10;
		m_denominator *= 10;
	}

	m_numerator = static_cast<unsigned long long>(numerator);

	simplify();
	count++;
}

RationalNumber::RationalNumber(long long numerator, long long denominator) {
	m_negative = (numerator < 0) ^ (denominator < 0);
	m_numerator = numerator < 0 ? -numerator : numerator;
	m_denominator = denominator < 0 ? -denominator : denominator;

	simplify();
	count++;
}

RationalNumber::RationalNumber(long double numerator, long long denominator) {
	m_negative = (numerator < 0) ^ (denominator < 0);
	numerator = numerator < 0 ? -numerator : numerator;
	m_denominator = denominator < 0 ? -denominator : denominator;

	while (std::fmod(numerator, 1) != 0) {
		numerator *= 10;
		m_denominator *= 10;
	}

	m_numerator = static_cast<unsigned long long>(numerator);

	simplify();
	count++;
}

RationalNumber::RationalNumber(long long numerator, long double denominator) {
	m_negative = (numerator < 0) ^ (denominator < 0);
	m_numerator = numerator < 0 ? -numerator : numerator;
	denominator = denominator < 0 ? -denominator : denominator;

	while (std::fmod(denominator, 1) != 0) {
		m_numerator *= 10;
		denominator *= 10;
	}

	m_denominator = static_cast<unsigned long long>(denominator);

	simplify();
	count++;
}

RationalNumber::RationalNumber(long double numerator, long double denominator) {
	m_negative = (numerator < 0) ^ (denominator < 0);
	numerator = numerator < 0 ? -numerator : numerator;
	denominator = denominator < 0 ? -denominator : denominator;

	while (std::fmod(denominator, 1) != 0 || std::fmod(numerator, 1) != 0) {
		numerator *= 10;
		denominator *= 10;
	}

	m_numerator = static_cast<unsigned long long>(numerator);
	m_denominator = static_cast<unsigned long long>(denominator);

	simplify();
	count++;
}

RationalNumber::~RationalNumber() {
	count--;
}


// "debug" tools for me

void RationalNumber::info(bool detail) const{
	if (detail)
	{
		std::cout << "negative: " << m_negative << std::endl;
		std::cout << "numerator: " << m_numerator << std::endl;
		std::cout << "denominator: " << m_denominator << std::endl;
	}
	std::cout << (m_negative ? "-" : "") << "(" << m_numerator << "/" << m_denominator << ")" << std::endl;
}

void RationalNumber::cptool(const RationalNumber& rational_nb) const{
	long long lcm = std::lcm(m_denominator, rational_nb.m_denominator);

	int sign1 = (m_negative) ? -1 : 1;
	int sign2 = (rational_nb.m_negative) ? -1 : 1;
	std::cout << "nb1: " << sign1*(m_numerator * (lcm/m_denominator)) << std:: endl;
	std::cout << "nb2: " << sign2*(rational_nb.m_numerator * (lcm/rational_nb.m_denominator)) << std:: endl;
	std::cout << "is equal: " << (sign1*(m_numerator * (lcm/m_denominator)) == sign2*(rational_nb.m_numerator * (lcm/rational_nb.m_denominator))) << std::endl;
}


long double RationalNumber::float_repr() {
	long double numerator = static_cast<long double>(m_numerator);
	return (numerator/m_denominator) * (m_negative ? -1 : 1);
}


// ex1-7 rounding stuff

long long RationalNumber::floor() const{
	if (m_denominator == 1) {
		return m_numerator * (m_negative ? -1 : 1);
	} else if (m_negative) {
		return -(m_numerator/m_denominator) - 1;
	} else {
		return m_numerator/m_denominator;
	}
}

long long RationalNumber::ceil() const{
	if (m_denominator == 1) {
		return m_numerator * (m_negative ? -1 : 1);
	} else if (m_negative) {
		return -(m_numerator/m_denominator);
	} else {
		return m_numerator/m_denominator + 1;
	}
}

// using the definition from: Graham, Ronald L.; Knuth, Donald E.; Patashnik, Oren (1992), Concrete mathematics: a foundation for computer science, Addison-Wesley, p. 70, ISBN 0-201-14236-8
RationalNumber RationalNumber::frac_part() const {
	int sign = (m_negative ? -1 : 1);
	long long numerator = sign * m_numerator % m_denominator;
	return RationalNumber(numerator, static_cast<long long>(m_denominator));
}


// ex1-8 median

RationalNumber mediant(const RationalNumber& rational_nb1, const RationalNumber& rational_nb2) {
	if (!(rational_nb1.m_negative || rational_nb2.m_negative)) {
		long long numerator = rational_nb1.m_numerator + rational_nb1.m_denominator;
		long long denominator = rational_nb2.m_numerator + rational_nb2.m_denominator;
		return RationalNumber(numerator, denominator);
	}
	throw std::out_of_range("can't be used with negative rational numbers");
}


// classic arithmetic operators

RationalNumber& RationalNumber::operator=(const RationalNumber& rational_nb) {
	if (this == &rational_nb) {
		return *this;
	}

	m_negative = rational_nb.m_negative;
	m_numerator = rational_nb.m_numerator;
	m_denominator = rational_nb.m_denominator;
	return *this;
}

// ex 1-10 root calculation
bool is_nb_rootable(const unsigned long long nb) {
	return std::sqrt(nb) == std::sqrt(static_cast<long double>(nb));
}

bool RationalNumber::is_rootable() const{
	return is_nb_rootable(m_numerator) && is_nb_rootable(m_denominator) && !m_negative;
}

int RationalNumber::sqrt() {
	if (is_rootable()) {
		m_numerator = std::sqrt(m_numerator);
		m_denominator = std::sqrt(m_denominator);
		return 0;
	}
	return -1;
}

RationalNumber other_sqrt(const RationalNumber& rational_nb) {
	if (rational_nb.is_rootable()) {
		long long numerator = std::sqrt(static_cast<long long>(rational_nb.m_numerator));
		long long denominator = std::sqrt(static_cast<long long>(rational_nb.m_denominator));
		return RationalNumber(numerator, denominator);
	}
	throw std::out_of_range("no longer a rational number");
}


RationalNumber RationalNumber::operator+(const RationalNumber& rational_nb) const{
	long long lcm = std::lcm(m_denominator, rational_nb.m_denominator);

	int sign1 = (m_negative) ? -1 : 1;
	int sign2 = (rational_nb.m_negative) ? -1 : 1;
	long long new_numerator = sign1*(m_numerator * (lcm/m_denominator)) + sign2*(rational_nb.m_numerator * (lcm/rational_nb.m_denominator));
	return RationalNumber(new_numerator, lcm);
}

RationalNumber RationalNumber::operator-(const RationalNumber& rational_nb) const{
	long long lcm = std::lcm(m_denominator, rational_nb.m_denominator);

	int sign1 = (m_negative) ? -1 : 1;
	int sign2 = (rational_nb.m_negative) ? -1 : 1;
	long long new_numerator = sign1*(m_numerator * (lcm/m_denominator)) - sign2*(rational_nb.m_numerator * (lcm/rational_nb.m_denominator));
	return RationalNumber(new_numerator, lcm);
}


RationalNumber RationalNumber::operator*(const RationalNumber& rational_nb) const{
	int sign = (m_negative ^ rational_nb.m_negative) ? -1 : 1;
	return RationalNumber(sign * static_cast<long long>(m_numerator * rational_nb.m_numerator), static_cast<long long>(m_denominator * rational_nb.m_denominator));
}

RationalNumber RationalNumber::operator/(const RationalNumber& rational_nb) const{
	int sign = (m_negative ^ rational_nb.m_negative) ? -1 : 1;
	return RationalNumber(sign * static_cast<long long>(m_numerator * rational_nb.m_denominator), static_cast<long long>(m_denominator * rational_nb.m_numerator));
}


// increment and decrement operators

RationalNumber RationalNumber::operator++() {
	m_numerator += m_denominator;
	simplify();
	return *this;
}

RationalNumber RationalNumber::operator++(int) {
	m_numerator += m_denominator;
	simplify();
	return *this;
}

RationalNumber RationalNumber::operator--() {
	m_numerator -= m_denominator;
	simplify();
	return *this;
}

RationalNumber RationalNumber::operator--(int) {
	m_numerator -= m_denominator;
	simplify();
	return *this;
}


// reatributing arithmetic operator

RationalNumber RationalNumber::operator+=(const RationalNumber & rational_nb) {
	*this = *this + rational_nb;
	simplify();
	return *this;
}

RationalNumber RationalNumber::operator-=(const RationalNumber & rational_nb) {
	*this = *this - rational_nb;
	simplify();
	return *this;
}

RationalNumber RationalNumber::operator*=(const RationalNumber & rational_nb) {
	*this = *this * rational_nb;
	simplify();
	return *this;
}

RationalNumber RationalNumber::operator/=(const RationalNumber & rational_nb) {
	*this = *this / rational_nb;
	simplify();
	return *this;
}


// logical comparison

bool RationalNumber::operator<(const RationalNumber& rational_nb) const{
	long long lcm = std::lcm(m_denominator, rational_nb.m_denominator);

	int sign1 = (m_negative) ? -1 : 1;
	int sign2 = (rational_nb.m_negative) ? -1 : 1;
	return sign1*(m_numerator * (lcm/m_denominator)) < sign2*(rational_nb.m_numerator * (lcm/rational_nb.m_denominator));
}

bool RationalNumber::operator>(const RationalNumber& rational_nb) const{
	return rational_nb < *this;
}

bool RationalNumber::operator<=(const RationalNumber & rational_nb) const{
	return !(*this > rational_nb);
}

bool RationalNumber::operator>=(const RationalNumber & rational_nb) const{
	return !(*this < rational_nb);
}

bool RationalNumber::operator==(const RationalNumber& rational_nb) const{
	long long lcm = std::lcm(m_denominator, rational_nb.m_denominator);

	int sign1 = (m_negative) ? -1 : 1;
	int sign2 = (rational_nb.m_negative) ? -1 : 1;
	return sign1*(m_numerator * (lcm/m_denominator)) == sign2*(rational_nb.m_numerator * (lcm/rational_nb.m_denominator));
}

bool RationalNumber::operator!=(const RationalNumber & rational_nb) const{
	return !(*this == rational_nb);
}


// stream manipulation

std::ostream& operator<<(std::ostream& output, const RationalNumber& rational_nb) {
	std::string sign = rational_nb.m_negative ? "-" : "";
	output << (rational_nb.m_negative ? "-" : "");
	if (rational_nb.m_denominator == 1)
	{
		output << rational_nb.m_numerator;
	} else {
		output << "(" << rational_nb.m_numerator << "/" << rational_nb.m_denominator << ")";
	}
	return output;
}

std::istream& operator>>(std::istream& input, RationalNumber& rational_nb) {
	char sign;
	std::cout << "positive ? (y/n) ";
	input >> sign;
	rational_nb.m_negative = tolower(sign) == 'n';
	std::cout << "numerator: ";
	input >> rational_nb.m_numerator;
	std::cout << "denominator: ";
	input >> rational_nb.m_denominator;
	rational_nb.simplify();
	return input;
}
