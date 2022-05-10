#ifndef IT_PART_H
#define IT_PART_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Part.h"
#include "Date.h"
#include "defs.h"

using namespace std;

class IT_Part: virtual public Part {

	public:
    //constructor
		IT_Part(const string& name,int num);

    //destructor
    virtual ~IT_Part();

    //virtual member functions
    virtual bool inspection(const Date&) const;

	protected:

		//virtual print function
		virtual void print(ostream&) const;
		
    int it_inspect;

};
#endif
