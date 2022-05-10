#ifndef FH_PART_H
#define FH_PART_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Part.h"
#include "Date.h"
#include "defs.h"

using namespace std;

class FH_Part: virtual public Part {

	public:
    //constructor
		FH_Part(const string& name, int num);

    //virtual destructor
    virtual ~FH_Part();

    //virtual member functions
    virtual bool inspection(const Date&) const;

	protected:

		//virtual print function
		virtual void print(ostream&) const;

    int fh_inspect;

};
#endif
