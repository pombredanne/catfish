/*
Part of Catfish
(c) 2017 by  Mingfu Shao, Carl Kingsford, and Carnegie Mellon University.
See LICENSE for licensing.
*/

#ifndef __SUBSETSUM1_H__
#define __SUBSETSUM1_H__

#include <vector>
#include "equation.h"

using namespace std;

typedef pair<int, int> PI;

// for given v compute all subsetsums 
// and then backtrace for given targets
class subsetsum
{
public:
	subsetsum(const vector<PI> &s, const vector<PI> &t);

private:
	vector<PI> source;					// given input
	vector<PI> target;					// given target numbers
	int ubound;							// upper bound we would try 

	vector< vector<bool> > table1;		// dp table1
	vector< vector<int> > table2;		// dp table2

public:
	vector<equation> eqns;

public:
	int solve();
	int print();
	static int test();

private:
	int init();
	int fill();
	int optimize();
	int backtrace(int ti, equation &eqn);
};

#endif
