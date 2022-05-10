#include "FH_Part.h"


//General constructor with two arguments
FH_Part::FH_Part(const string& name, int num): fh_inspect(num), Part(name)
{

}

//Destructor
FH_Part::~FH_Part()
{

}

//Compares the flight hours with the number of flight hours until inspection is required
bool FH_Part::inspection(const Date& date) const
{
  if(this->flighthours >= this->fh_inspect)
  {
    return true;
  }
  return false;
}

//Print function for member variables
void FH_Part::print(ostream& ost) const
{
  ost<<"Inspect every: "<<this->fh_inspect<<" flight hours"<<endl;
}
