#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"
#include "defs.h"

using namespace std;

class Part {

  friend ostream& operator<<(ostream&, const Part&);

	public:
    //constructor
		Part(const string& givenName);

    //deconstructor
    virtual ~Part();

    //getters and setters
    const string& getName() const;

    //member functions
    void addFlightHours(int);
    void install(Date&);

    //virtual member functions
    virtual bool inspection(const Date&) const = 0;

	protected:

    //virtual print function
    virtual void print(ostream&) const = 0;
    
    string name;
    Date installationDate;
    int flighthours;

};
#endif
