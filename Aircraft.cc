#include "Aircraft.h"

//General constructor with two arguments
Aircraft::Aircraft(const string& typeP, const string& regis): type(typeP), registration(regis),flighthours(0)
{

}

//Deconstructor
Aircraft::~Aircraft()
{

}

//Getters
const string& Aircraft::getRegistration() const { return this->registration; }

//Adds a part to the array of parts and installs
bool Aircraft::install(Part* part, Date& date)
{
  this->parts.add(part);
  part->install(date);
  return true;
}

//Updates the flight hours member variable
bool Aircraft::takeFlight(int hours)
{
  this->flighthours = this->flighthours + hours;

  for(int i=0; i<this->parts.getSize();i++)
  {
    this->parts[i]->addFlightHours(hours);
  }

  return true;
}

//Checks whether an inspection is required for any parts installed on the aircraft
bool Aircraft::inspectionReport(const Date& date,Array<Part*>& array)
{
  for(int i=0; i<this->parts.getSize();i++)
  {
    if(this->parts[i]->inspection(date))
    {
      array.add(this->parts[i]);
    }
  }
  if(array.getSize() > 0)
  {
    return true;
  }

  return false;
}

//Overload statement to output member variables
ostream& operator<<(ostream& ost,const Aircraft& aircraft)
{
  return ost<<"\nAircraft Type: "<<aircraft.type<<"\n"<<"Registration: "<<aircraft.registration<<endl;

}
