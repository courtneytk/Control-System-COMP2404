#ifndef FHIT_PART_H
#define FHIT_PART_H

#include <iostream>
#include <string>
#include <iomanip>

#include "FH_Part.h"
#include "IT_Part.h"
#include "Date.h"
#include "defs.h"

using namespace std;

class FHIT_Part: public FH_Part, public IT_Part {

	public:
    //constructor
		FHIT_Part(const string& name, int numFH, int numIT);

    //destructor
    virtual ~FHIT_Part();

    //virtual member functions
    virtual bool inspection(const Date&) const;

	protected:
		
		//virtual print function
		virtual void print(ostream&) const;


};
#endif
