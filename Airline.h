#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "IT_Part.h"
#include "FH_Part.h"
#include "FHIT_Part.h"

#include "Aircraft.h"

using namespace std;

class Airline {

	friend ostream& operator<<(ostream&, const Airline&);

	public:

    //constructor
		Airline(const string& givenName);

    //deconstructor
    virtual ~Airline();

    //member functions
    bool addAircraft(const string&, const string&);
    bool addPart(const string&, int, int);
    bool takeFlight(const string, int);
    void printAircraft() const;
    void printParts() const; 
    bool inspectionReport(const string&, Date&);
    bool install(const string&, const string&, Date&);

	private:

    string name;
    Array<Aircraft*> aircrafts;
    Array<Part*> parts;

    //getters and setters
    bool getAircraft(const string&, Aircraft**);
    bool getParts(const string&, Part**);

};
#endif
