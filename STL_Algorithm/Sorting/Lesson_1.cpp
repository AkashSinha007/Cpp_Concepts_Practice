

#include <vector>
#include <algorithm>
#include <cmath> // for abs
#include "Employee.h"
#include <random>

using namespace std;

int main()
{
	vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
	auto v2 = v;
    /*
    sort():
    Sorts the elements in the range [first, last) in non-descending order. 
    The order of equal elements is not guaranteed to be preserved. 
    */
	sort(begin(v2), end(v2));

    /*elem1 > elem2 condition is for sorting in descending order*/
	sort(begin(v2), end(v2), [](int elem1, int elem2) {return elem1 > elem2; });

    /*Sorting based on a given condition*/
	sort(begin(v2), end(v2), 
		[](int elem1, int elem2) {return abs(elem1) > abs(elem2); });

	std::vector<Employee> staff{
		{ "Kate", "Gregory", 1000 },
		{ "Obvious", "Artificial", 2000 },
		{ "Fake", "Name", 1000 },
		{ "Alan", "Turing", 2000 },
		{ "Grace", "Hopper", 2000 },
		{ "Anita", "Borg", 2000 }
	};

	//std::sort(begin(staff), end(staff)); //- only works if operator< defined for Employee

	std::sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });
	std::sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });

	std::sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });
	std::stable_sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });

    /*
    is_sorted():
    Returns true if the range [first,last) is sorted into ascending order.
    */
	auto sorted = is_sorted(begin(v2), end(v2));
	sorted = is_sorted(begin(v2), end(v2),[](int elem1, int elem2) {return abs(elem1) > abs(elem2); });


    /*
    max_element():
    Returns an iterator pointing to the element with the largest value in the range [first,last).
    If more than one element fulfills this condition, the iterator returned points to the first of such elements.
    */
	int high = *(max_element(begin(v), end(v)));

    /*
    min_element():
    Returns an iterator pointing to the element with the smallest value in the range [first,last).
    If more than one element fulfills this condition, the iterator returned points to the first of such elements.
    */
	int low = *(min_element(begin(v), end(v)));
	sort(begin(v2), end(v2));
	low = *begin(v2);
	high = *(end(v2)-1);

    /*
    value a a a b b b c c c
    index 0 1 2 3 4 5 6 7 8
    bound       l     u

    Where l represents the lower bound of b, and u represents the upper bound of b
    */
	int positive = *upper_bound(begin(v2), end(v2), 0);

	std::sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });

	auto p = std::lower_bound(begin(staff), end(staff), "Gregory, Kate",
			[](Employee e1, std::string n) {return e1.getSortingName() < n; });
	int sal = p->getSalary();

	random_device randomdevice;
	mt19937 generator(randomdevice());
	
    /*
    shuffle:
    Reorders the elements in the given range [first, last) such that each 
    possible permutation of those elements has equal probability of appearance.
    */
	shuffle(begin(v2), end(v2), generator);


    /*
    Rearranges the elements in the range [first,last), in such a way that 
    the elements before middle are the smallest elements in the entire 
    range and are sorted in ascending order, while the remaining elements 
    are left without any specific order.
    */
	partial_sort(begin(v2), find(begin(v2), end(v2), 4), end(v2));


    /*
    is_sorted_until():
    Returns an iterator to the first element in the range [first,last) 
    which does not follow an ascending order.

    If the entire range is sorted, the function returns last.
    */
	int breakpoint = *is_sorted_until(begin(v2), end(v2));

	vector<int> v3(3);

    /*
    partial_sort_copy():
    Copies the smallest elements in the range [first,last) to 
    [result_first,result_last), sorting the elements copied. 
    The number of elements copied is the same as the distance between 
    result_first and result_last (unless this is more than the amount 
    of elements in [first,last)).
    The range [first,last) is not modified.
    */
	partial_sort_copy(begin(v), end(v), begin(v3), end(v3));

	v2 = {1,5,4,2,9,7,3,8,2};
	int i = *(begin(v2) + 4);

    /*
    nth_element()
    Rearranges the elements in the range [first,last), in such a way that 
    the element at the nth position is the element that would be in that position in a sorted sequence.

    The other elements are left without any specific order, except that 
    none of the elements preceding nth are greater than it, and none of 
    the elements following it are less.
    */
	nth_element(begin(v2), begin(v2)+4, end(v2));
	i = *(begin(v2) + 4);


	return 0;
}
