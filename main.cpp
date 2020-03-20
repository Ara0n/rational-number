#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <assert.h>
#include "RationalNumber.h"
#include "RationalList.h"

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

	RationalNumber root_test = RationalNumber(9LL);
	root_test.sqrt();
	cout << root_test << endl;
	root_test = RationalNumber(-4LL);
	root_test.sqrt();
	cout << root_test << endl;
	root_test = RationalNumber(-4LL, -9LL);
	root_test.sqrt();
	cout << root_test << endl;
	root_test = RationalNumber(12.5L, 2LL);
	root_test.sqrt();
	cout << root_test << endl;

	cout << "quadratic: x² + 2x + 1" << endl;
	quadratic(RationalNumber(1LL), RationalNumber(2LL), RationalNumber(1LL));
	cout << "quadratic: x² + 5x + 4" << endl;
	quadratic(RationalNumber(1LL), RationalNumber(5LL), RationalNumber(4LL));
	cout << "quadratic: x² - x - 1" << endl;
	quadratic(RationalNumber(1LL), RationalNumber(-1LL), RationalNumber(-1LL));
	cout << "quadratic: x² + 9" << endl;
	quadratic(RationalNumber(1LL), RationalNumber(0LL), RationalNumber(9LL));
	cout << "quadratic: x² + x + 1" << endl;
	quadratic(RationalNumber(1LL), RationalNumber(1LL), RationalNumber(1LL));

	cout << "mediant: " << mediant(another_ra_nb, two) << endl;


	cout << "test 1" << endl;
	RationalList test = RationalList();
	test.size();
	test.push(one);
	test.push(one);

	cout << test << endl;
	cout << test.unique() << endl;

	cout << test.pop() << endl;
	test.size();

	cout << "test 2" << endl;
	const RationalList test2 = RationalList(5);
	test2.size();

	cout << "test 3" << endl;
	RationalList test3 = RationalList(test2);
	test3.size();
	test3.push(another_one);
	test3.size();

	cout << test << endl << test2 << endl << test3 << endl;

	assert(test == test3);
	assert(test != test2);

	cout << test[0] << endl;
	test[0] = two;
	cout << test[0] << endl;

	test.pop();

	assert(test != test3);
	assert(test == test2);


	cin >> another_one;
	cout << another_one << endl;
	cout << setprecision(20) << another_one.float_repr() << endl;
	cout << RationalNumber::get_count() << endl;

	cin >> test;
	cout << test << endl;

	test.info();


	return EXIT_SUCCESS;
}