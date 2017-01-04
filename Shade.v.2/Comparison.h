#ifndef COMPARISON_H
#define COMPARISON_H

#include "Position.h"

using namespace std;

class Comparator {

private:

	using pair_type = pair<Position, int>;

public:

	bool operator()(const pair_type& lhs, const pair_type& rhs) const {

		if (lhs.second < rhs.second) {

			return true;


		} else if (lhs.first < rhs.first) {

			return true;
		}

		return false;
	}
};


struct Obj_compare {

	bool operator()(const Object* lhs, const Object* rhs) const {

		return *lhs < *rhs;
	}
};

#endif