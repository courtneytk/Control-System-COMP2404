#include "Part.h"


//General constructor with two arguments
Part::Part(const string& givenName): name(givenName), flighthours(0)
{

}

//Deconstructor
Part::~Part()
{

}

//Getters
const string& Part::getName() const { return this->name; }


//Adds flight hours to the number of hours the part has flown on the airplane
void Part::addFlightHours(int hours)
{
  this->flighthours = this->flighthours + hours;
}

//Updates the installation date with a given date
void Part::install(Date& date)
{
  this->installationDate = date;
}


//Overload statement to output member variables
ostream& operator<<(ostream& ost,const Part& part)
{
  ost<<"\nName: "<<part.name<<"\n"<<"Flight Hours: "<<part.flighthours<<"\n"
  <<"Installation Date: "<<part.installationDate;
  part.print(ost);
  return ost;

}
