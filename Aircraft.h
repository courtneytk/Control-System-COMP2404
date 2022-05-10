#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Part.h"
#include "Date.h"
#include "Array.h"
#include "defs.h"

using namespace std;

class Aircraft {

  friend ostream& operator<<(ostream&, const Aircraft&);

	public:
    //constructor
		Aircraft(const string&, const string&);

    //deconstructor
    virtual ~Aircraft();

    //getters and setters
    const string& getRegistration() const;

    //member functions
    bool install(Part*, Date&);
    bool takeFlight(int);
    bool inspectionReport(const Date&,Array<Part*>&);


	private:

    string type;
    string registration;
    int flighthours;
    Array<Part*> parts;
};
#endif
