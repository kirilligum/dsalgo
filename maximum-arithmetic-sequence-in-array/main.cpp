#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;

int maxarseq(const vector<int> & v) {
  int dif=0;
  int current_length=1;
  int max_length=1;
  int pos=0;
  for (size_t i = 1; i < v.size(); ++i) {
    int new_dif=v[i]-v[i-1];
    if(dif!=new_dif) {
      dif=new_dif;
      current_length=1;
    }
    ++current_length;
    if(current_length>=max_length) {
      max_length=current_length;
      pos=i;
    }
  }
  cout << "at pos " << pos << ", the max element is " << v[pos] << endl;
  for (size_t i = pos+1-max_length; i <= pos; ++i) { 
    cout << v[i] << " ";
  }
  cout << endl;
  return max_length;
}

int main(int argc, char const *argv[]) {
  vector<int> v(10000000);
  //default_random_engine re;
  random_device rd;
  mt19937 re(rd());
  uniform_int_distribution<int> dist (0,9);
  generate( std::begin(v), std::end(v), bind(dist,re));
  //std::copy(std::begin(v), std::end(v),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  cout <<endl;
  cout << maxarseq(v);
  return 0;
}
