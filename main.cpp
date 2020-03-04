#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <assert.h>
#include "RationalNumber.h"

using namespace std;

int main() {
	const RationalNumber one = RationalNumber(1LL);
	const RationalNumber two = RationalNumber(2LL);
	RationalNumber another_one = RationalNumber(1LL);
	cout << RationalNumber::get_count() << endl;
	
	RationalNumber ra_nb = RationalNumber(254523LL, 21330LL);
	cout << ra_nb << endl;
	ra_nb = RationalNumber(-851LL);
	ra_nb = RationalNumber(451LL);
	ra_nb = RationalNumber(-6LL, 4LL);
	const RationalNumber another_ra_nb = RationalNumber(6LL, 4LL);
	cout << ra_nb << endl;
	cout << ra_nb << endl;
	cout << ra_nb << endl;
	cout << RationalNumber::get_count() << endl;

	assert(one < two);
	assert(two > one);
	assert(one == another_one);
	assert(one <= another_one);
	assert(one <= two);
	assert(two >= another_one);
	assert(one >= another_one);
	assert(another_one != two);

	another_one++; // now equals 2
	cout << another_one << endl;
	assert(another_one == two);
	another_one--; // now equals 1
	assert(another_one == one);
	cout << another_one << endl;

	cout << ra_nb << endl;
	cout << ra_nb.floor() << endl;
	cout << ra_nb.ceil() << endl;
	cout << ra_nb.frac_part() << endl;
	cout << another_ra_nb << endl;
	cout << another_ra_nb.floor() << endl;
	cout << another_ra_nb.ceil() << endl;
	cout << another_ra_nb.frac_part() << endl;

	cout << "mediant: " << mediant(another_ra_nb, two) << endl;

	cin >> another_one;
	cout << another_one << endl;
	cout << setprecision(20) << another_one.float_repr() << endl;

	cout << RationalNumber::get_count() << endl;

	return EXIT_SUCCESS;
}