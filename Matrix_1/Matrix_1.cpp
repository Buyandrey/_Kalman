#include <vector>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;
using strmatr = vector<vector<double>>;

class matrix {
public:
	matrix(const strmatr& str){
		M_ = str;
	}
	pair<size_t,size_t> Get_NxM() { return(make_pair(M_.size(), M_.at(0).size())); }
private:
	strmatr M_;
};

ostream& operator << (ostream& os, const vector<double>& r) {
	os << "[ ";
	for (const double& i : r) {
		os << i << ' ';
	}
	return  os << ']';
}
ostream& operator << (ostream& os, const strmatr& r) {
	for (size_t i = 0; i < r.at(0).size(); i++) {
		for (size_t j = 0; j < r.size(); j++)
			cout << setw(4) << setfill(' ') <<r.at(i).at(j)<< endl;
	}
	return  os;
}
int main()
{
	return 0;
}
