// iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <vector>
#include <set>
using namespace std;


void message(const char* m) { cout << m << endl; }
void message(const char* m, int i) { cout << m << ": " << i << endl; }

int main() {
    vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int>::iterator it1;   // iterator object

    // example of forward iterator -- it will only increment and not decrement
    for (it1 = v1.begin(); it1!=v1.end(); ++it1) { //only++it1 and not --it1
        cout << *it1 << " ";  // only printing it1 will not work

    }
    cout << endl;
    cout << "another way to access" << endl;
    vector<string> v2 = { "red","orange","green","yellow" };
    vector<string>::iterator it2;

    // define 2 new vector for end limits
    vector<string>::iterator start = v2.begin();
    auto end = v2.end();   // we can also use auto keyword

    for (it2 = start; it2 < end; it2++) {
        cout << *it2 << " ";
    }
    cout << endl;
    // range based for loop uses the 4wd iterator
    cout << "to access vector we can use range based for loop" << endl;
    vector<float> v3 = { 3.124224554f,2.556f,8.989f,7.786f }; // if f is not mentioned with values then the compiler take values as double and truncate them to float 
                                                              // for float values will be truncated to 5 decimal places
    for (auto i : v3) {  // if use int i then it will give only integer part of values and not decimal part. so use auto or float
        cout << i << " ";
    }
    cout << endl;

    cout << "******************* BIDIRECTIONAL ITERATOR**************************************" << endl;
    // CAN TRAVERSE IN BOTH DIRECTION

    set<int> set1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // it can vork with vector as well
    set<int>::iterator it11;   // iterator object

    // iterate forward
    for (it11 = set1.begin(); it11 != set1.end(); ++it11) {
        cout << *it11 << " ";
    }
    cout << endl;

    // iterate backward
    for (it11 = set1.end(); it11 != set1.begin();) {
        cout << *--it11 << " "; // we decremnt here because of iterator values - to get last and first element
       
    }
    cout << endl;

    // range-based for loop FOR BIDIRECTIONAL
    for (int i : set1) {
        cout << i << " ";
    }
    cout << endl;
    cout << "******************* RANDOM ACCESS ITERATOR added function along with above**************************************" << endl;
  
    it1 = v1.begin() + 5;
    message("element begin + 5", *it1);
    message("element [5]", v1[5]);

    it1 = v1.end() - 3;
    message("element end - 3", *it1);


    cout <<"******************* INPUT ITERATOR**************************************" << endl;
      // input iterator for input stream 
    double d1 = 0, d2 = 0;

    cout << "Two numeric values: " << flush;
    cin.clear();  // helps in clearing the error flags which are set when std::cin fails to interpret the input.
    istream_iterator<double> eos;         // default constructor is end-of-stream
    istream_iterator<double> iit(cin);    // stdin iterator

    if (iit == eos) {
        message("no values");
        return 0;
    }
    else {
        d1 = *iit++;
    }

    if (iit == eos) {
        message("no second value");
        return 0;
    }
    else {
        d2 = *iit;
    }

    cin.clear();
    cout << d1 << " * " << d2 << " = " << d1 * d2 << endl;


    cout << "*********************************************************" << endl;
    // output iterator for input stream 
    ostream_iterator<int> output(cout, " ");

    for (int i : { 3, 197, 42 , 90}) {
        *output++ = i;
    }
    cout << endl;

    return 0;
}