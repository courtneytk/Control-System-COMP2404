#include "Airline.h"

//General constructor with one argument
Airline::Airline(const string& givenName): name(givenName)
{

}

//Deconstructor
Airline::~Airline()
{
  for(int i=0; i<aircrafts.getSize(); i++)
  {
    delete aircrafts[i];
  }

  for(int y=0; y<parts.getSize(); y++)
  {
    delete parts[y];
  }

}

//Gets aircraft of interest
bool Airline::getAircraft(const string& registration, Aircraft** aircraft)
{
  for(int i=0; i<this->aircrafts.getSize(); i++)
  {
    if(this->aircrafts[i]->getRegistration() == registration)
    {
      *aircraft = this->aircrafts[i];
      return true;
    }
  }

  return false;

}

//Gets parts of interest
bool Airline::getParts(const string& name,Part** part)
{

  for(int i=0; i<this->parts.getSize(); i++)
  {
    if(this->parts[i]->getName() == name)
    {
      *part = this->parts[i];
      return true;
    }
  }

  return false;

}

//Adds an aircraft to the array of aircrafts
bool Airline::addAircraft(const string& type, const string& registration)
{
  if(this->aircrafts.isFull())
  {
    return false;
  }
  this->aircrafts.add(new Aircraft(type, registration));
  return true;
}

//Adds a part to a given aircraft
bool Airline::addPart(const string& part, int fh_inspect, int it_inspect)
{
  if(this->parts.isFull())
  {
    return false;
  }
  if(fh_inspect != 0 && it_inspect != 0)
  {
    this->parts.add(new FHIT_Part(part, fh_inspect, it_inspect));
    return true;
  }
  else if(fh_inspect == 0)
  {
    this->parts.add(new IT_Part(part, it_inspect));
    return true;
  }
  else if(it_inspect == 0)
  {
    this->parts.add(new FH_Part(part, fh_inspect));
    return true;
  }

  return false;
}

//Updates the number of flight hours for an aircraft and its parts
bool Airline::takeFlight(const string reg, int hours)
{

  Aircraft* aircraft;

  if(getAircraft(reg,&aircraft))
  {
    aircraft->takeFlight(hours);
    return true;
  }

  cout<<"There is no aircraft matching the registration information."<<endl;
  return false;

}

//Determines if an inspection is required on a part
bool Airline::inspectionReport(const string& reg, Date& date)
{
  Aircraft* aircraft;
  Array<Part*> array;

  if(!getAircraft(reg,&aircraft))
  {
    cout<<"There is no aircraft matching the registration information."<<endl;
    return false;
  }
  cout<<"\nThe following parts from "<<reg<<" require inspection:"<<endl;

  if(aircraft->inspectionReport(date,array))
  {
    for(int i=0; i<array.getSize(); i++)
    {
      cout<<*array[i]<<endl;
    }

    return true;
  }

  return false;
}

//Installs a given part onto an aircraft based on registration and part name
bool Airline::install(const string& airReg, const string& partName, Date& date)
{
  Aircraft* aircraft;
  Part* part;

  if(getAircraft(airReg,&aircraft) && getParts(partName,&part))
  {
    aircraft->install(part,date);
    return true;
  }

  cout<<"There is no aircraft or part matching the given information."<<endl;
  return false;

}

//Prints all the aircrafts in the airline
void Airline::printAircraft() const
{
    for(int i=0; i<aircrafts.getSize(); i++)
    {
      cout<<*aircrafts[i]<<endl;
    }
}

//Prints all the parts in the airline
void Airline::printParts() const
{

  for(int i=0; i<parts.getSize(); i++)
  {
    cout<<*parts[i]<<endl;
  }
}

//Overload statement to print member functions
ostream& operator<<(ostream& ost,const Airline& airline)
{
  return ost<<"\nAirline: "<<airline.name<<"\n"<<endl;

}
