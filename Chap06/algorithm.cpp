// algorithm.cpp by Bill Weinman <http://bw.org/>
// 2018-09-27 for CppSTL
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

template <typename T>
const bool is_prime(const T& num) {
    if (num <= 1) return false;
    bool primeflag = true;
    for (T l = 2; l < num; ++l) {
        if (num % l == 0) {
            primeflag = false;
            break;
        }
    }
    return primeflag;
}
   // For searching and counting
template <typename T>
bool is_odd(const T& n) {
    return ((n % 2) == 1);
}

template <typename T>
bool is_even(const T & n) {
        return((n % 2) == 0);
    }

template <typename T>
bool is_even_tens(T& n) {
    if (n < 10) return false;
    return ((n / 10) % 2) == 0;
}

//template <typename T>
//bool mycomp(const T& lh, const T& rh) {
  //  return lh < rh;
//}

// for stable sort
template <typename T>
bool mycomp(const T& lh, const T& rh) {
    return int (lh) < int (rh);
}


// compare for reverse sort
template <typename T>
bool gtcomp(const T& lh, const T& rh) {
    return lh > rh;
}

int main() {
    int n = 41;
   
    // prime numbers < 100, out of order
    vector<int> v1 = { 71, 13, 59, 7, 53, 41, 29, 3, 97, 5, 11, 17, 19, 23, 2, 31, 83, 37, 41, 89, 43, 47, 61, 67, 73, 79 };
    disp_v(v1);

    //sort(v1.begin(), v1.end());
    //disp_v(v1);
    
    if(binary_search(v1.begin(), v1.end(), n)) {
        cout << "found " << n << endl;
       
    } 
    else {
        cout << "did not found " << n << endl;
    }

    // use iterator to find the lower position where search parameter is located
    auto itr11 = lower_bound(v1.begin(), v1.end(), n);
    //cout << "Lower Bound : " << *itr11 << endl;

    //auto itr12 = upper_bound(v1.begin(), v1.end(), n);
    //cout << "upper Bound : " << *itr12 << endl; // value after n

    auto eqr = equal_range(v1.begin(), v1.end(), n);
    cout << "Lower Bound : " << *eqr.first << endl;
    cout << "upper Bound : " << *eqr.second << endl;
    /*
    //searching the index of value
    const vector<int> v2 = { 71, 13, 59, 7, 53, 29, 3, 97, 5, 11, 17, 19, 23, 2, 31, 83, 37, 41, 89, 43, 47, 61, 67, 73, 79 };

    auto it = find(v1.begin(), v1.end(), 41);
    //auto it = find_if(v1.begin(), v1.end(),is_odd<int>);
    if (it != v1.end()) {
        size_t index = it - v1.begin();
        cout << "found at index " << index << ": " << *it << endl;
    }
    else {
        cout << "not found" << endl;
    }

    auto it1 = find_if(v1.begin(), v1.end(),is_odd<int>);
    if (it1 != v1.end()) {
        size_t index = it1 - v1.begin();
        cout << "found at index " << index << ": " << *it << endl;
    }
    else {
        cout << "not found" << endl;
    }
    // testing conditions-- all_of, any_of, none_of
    if (all_of(v1.begin(), v1.end(), is_prime<int>)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    // searcing for one vector in other vector
    const vector<int> v3 = { 71, 13, 59, 7, 53, 29, 3, 97, 5, 11, 17, 19,3, 23, 2, 31, 83, 37, 41,3, 89, 43, 47, 61, 67, 73, 79 };
    const vector<int> v4 = { 29, 3, 97, 5, 11, 17, 19, 23 };
    auto it11 = search(v3.begin(), v3.end(),v4.begin(), v4.end());
    if (it11 != v3.end()) {
        size_t index = it11 - v3.begin();
        cout << "found at index " << index << ": " << *it11 << endl;
    }
    else {
        cout << "not found" << endl;
    }

    // To count number of occurances of an element
    auto c = count(v3.begin(), v3.end(), 3);
        cout << "count = " << c << endl;

    // replacing and remoning element in container
   vector<int> vr = { 71, 53, 59, 8,655,655,655, 53, 20, 3, 11, 5, 11, 17, 19,3, 23, 2, 31, 83, 37, 41,3, 89, 43, 47, 61, 67, 73, 79 }; // do not use constant vector because values will be changed
   cout << " vector for replacing and removing function" << endl;
   disp_v(vr);
   replace(vr.begin(), vr.end(), 53, 1);
   cout << " vector after replacement" << endl;
   disp_v(vr);

   // replace if 
   replace_if(vr.begin(), vr.end(), is_even<int>, 999);
   cout << " vector after replacement" << endl;
   disp_v(vr);

   // remove  and remove_if
  auto rem = remove(vr.begin(), vr.end(),11);
  if (rem == vr.end()) {
      cout << " no removal" << endl;
  }
  else {
      vr.resize(rem - vr.begin());
  }
   disp_v(vr);
  // remove only consecutive duplicates

   auto dup = unique(vr.begin(), vr.end());
   if (dup == vr.end()) {
       cout << " no removal" << endl;
   }
   else {
       vr.resize(dup - vr.begin());
   }
   disp_v(vr);

   // modifying algo --  copy   copy_n, coy backward,  reverse copy
   vector <int > vc1 = { 1,2,3,4,5,6,7,8 };
   vector<int> vc2(vc1.size(), 0);
   disp_v(vc1);
   disp_v(vc2);
   //copy(vc1.begin(), vc1.end(), vc2.begin());
   //disp_v(vc2);
   //copy_n(vc1.begin(), 4, vc2.begin());
   //disp_v(vc2);
   
   //copy_backward(vc1.begin(),vc1.end(),vc2.end());
   //reverse_copy(vc1.begin(), vc1.end(), vc2.begin());
   // //disp_v(vc2);
 //********************** reverse **********
   reverse(vc1.begin(), vc1.end());
   cout << "simply reverses vc1" << endl;
   disp_v(vc1);
 // *********reversing string *********
   cout << "string reversing   " << endl;
   string s1 = "hello world";
   cout << "strng 1 = " << s1 << endl;
   reverse(s1.begin(), s1.end());
   cout << "reverse strng 1 = " << s1 << endl;

   // reverse copy for string
   string s1 = "hello world";
   string s2(s1.size(), 0);
   cout << "strng 1 = " << s1 << endl;
   cout << "strng 2 = " << s2 << endl;
   reverse_copy(s1.begin(), s1.end(), s2.begin());
  cout << " new strng 2 = " << s2 << endl;
   
// ************  PARTITION **************8
   //prime numbers > 10 & < 100
   vector<int> vp = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
   disp_v(vp);

   partition(vp.begin(), vp.end(), is_even_tens<int>);
   disp_v(vp);

   // ************  sorting **************8
   cout << " ************* SORTING ************* " << endl;
   vector<int> vs1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
   vector<double> vs2 = { 3.07, 2.49, 3.73, 6.58, 3.3, 2.72, 3.44, 8.78, 9.23, 4.09, 4.4, 1.65, 4.92, 0.42, 4.87, 5.03, 3.27, 7.29, 8.4, 6.12 };
   disp_v(vs1);
   disp_v(vs2);
   // SORTING -- sort(begin,, end)
   sort(vs1.begin(), vs1.end());
   disp_v(vs1);
   
   // using own comparison operator
   sort(vs1.begin(), vs1.end(),  mycomp<int>);

   // stable sort 
   vector <double> vs3 = vs2;
   sort(vs3.begin(), vs3.end(), mycomp<double>);
   disp_v(vs3);
   vs3 = vs2;
   stable_sort(vs3.begin(), vs3.end(), mycomp<double>);
   disp_v(vs3);
   
   // ************  merging **************

   vector<int> vm1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67 };
   vector<int> vm2 = { 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89, 11 };
   vector<int> vm3(vm1.size() + vm2.size());
   disp_v(vm1);
   disp_v(vm2);
   cout << endl;

   sort(vm1.begin(), vm1.end());
   sort(vm2.begin(), vm2.end());
   disp_v(vm1);
   disp_v(vm2);
   cout << endl;

   merge(vm1.begin(), vm1.end(), vm2.begin(), vm2.end(), vm3.begin());
   disp_v(vm3);
   */

   return 0;
}
