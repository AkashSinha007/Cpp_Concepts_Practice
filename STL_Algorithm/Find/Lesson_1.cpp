

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v{  4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
	string s{ "Hello I am a sentence" };

    //find the first zero in the collection
    auto result = find(begin(v),end(v),0);
    int weLookedFor = *result;
    cout<<"\nfinding 0 and we found: "<<weLookedFor;

    //find the first 2 after that zero
    result = find(result,end(v),2);
    if(result!=end(v)) //If it was within the iterator range from result to end
    {
        cout<<"\nfinding 2 and we found: "<<weLookedFor;
        weLookedFor=*result;
    }

    //find the first a
    auto letter = find(begin(s),end(s),'a');
    char aValue = *letter;
    cout<<"\nfinding 'a' and we found: "<<aValue;

    //find first odd value
    result= find_if(begin(v),end(v),[](auto elem){return elem%2!=0;});
    weLookedFor=*result;
    cout<<"\nfinding first odd value and we found: "<<weLookedFor;

    //find first even value
    result= find_if_not(begin(v),end(v),[](auto elem){return elem%2!=0;});
    weLookedFor=*result;
    cout<<"\nfinding first even value and we found: "<<weLookedFor;

    //find first prime number in vector 'v' which is in vector 'primes'
    vector<int> primes{1,2,3,5,7,11,13};
    result = find_first_of(begin(v), end(v), begin(primes), end(primes));
	weLookedFor = *result;
    cout<<"\nfinding first prime in vector v and we found: "<<weLookedFor;

    /*
    search():
     Iterator to the beginning of first occurrence of the sequence 
     [s_first, s_last) in the range [first, last). 
     If no such occurrence is found, last is returned.
    */
    vector<int> subsequence{ 2,4 };
    result = search(begin(v), end(v), begin(subsequence), end(subsequence));
	weLookedFor = *result;
	result++; result++;
	int firstElementAfterTwoIncrements = *result;
    cout<<"\nsearching first element in subsequence and adding 2 we found: "<<firstElementAfterTwoIncrements;

    //Searching subsequence in string
    string am = "am";
	letter = search(begin(s), end(s), begin(am), end(am));
	aValue = *letter;
    cout<<"\nsearching first 'a' with 'm' following it we found: "<<aValue;

    /*
    find_end():
    Iterator to the beginning of last occurrence of the sequence [s_first, s_last) in range [first, last). 
    
    Note: Here result++ will increament in reverse order
    */
	result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
	result++; result++;
	if (result != end(v))
	{
		weLookedFor = *result;
	}
    cout<<"\nsearching from end element in subsequence and adding 2 we found: "<<weLookedFor;


    /*
    search_n():

    template< class ForwardIt, class Size, class T >
    ForwardIt search_n( ForwardIt first, ForwardIt last, Size count,const T& value );
    
    Iterator to the beginning of the found sequence in the range [first, last). 
    If no such sequence is found, last is returned.
    If count is zero or negative, first is returned.
    */
   
   /*Count two consecutive '4' in vector v*/
    result = search_n(begin(v), end(v), 2, 4);
	result--;
	int two = *result;
    cout<<"\nTrying to find element just before two consecutive 4 and found : "<<two;


    /*
    adjacent_find:
    template< class ForwardIt, class BinaryPredicate>
    ForwardIt adjacent_find( ForwardIt first, ForwardIt last, BinaryPredicate p );

    an iterator to the first of the first pair of identical elements, that is, the first iterator it such that *it == *(it+1) for the first version or p(*it, *(it + 1)) != false for the second version.
    If no such elements are found, last is returned 
    */

    result = adjacent_find(begin(v), end(v));
	int six = *result;
	result++;
	six = *result;
    cout<<"\nThe first consecutive element from beginning of vector v is = "<<six;

    return 0;
}