#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<int> v(20);
  random_device rd; mt19937 gen(rd()); uniform_int_distribution<> dis(1,40); auto rand = bind(dis,gen);
  generate( std::begin(v), std::end(v), rand);
  sort( std::begin(v), std::end(v));
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  for(auto &i: v) i*=i;
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  int triples =0;
  for (size_t i = 0; i < v.size(); ++i) {
    if(v[i]!=-1)
      for (size_t j = i+1; j < v.size(); ++j) {
        if(v[j]!=-1) {
          int c2 = v[i]+v[j];
          auto c2it = find( std::begin(v), std::end(v), c2);
          if(c2it!=std::end(v)) {
            ++triples;
            *c2it=v[i]=v[j]=-1;
          }
        }
      }
  }
  cout << " triples = " << triples << endl;
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  return 0;
}
