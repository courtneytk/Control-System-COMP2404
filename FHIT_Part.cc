#include "FHIT_Part.h"

//General constructor with two arguments
FHIT_Part::FHIT_Part(const string& name, int numFH, int numIT): FH_Part(name,numFH), IT_Part(name,numIT), Part(name)
{

}

//Destructor
FHIT_Part::~FHIT_Part()
{

}

//Uses the FH or IT class inspections to do inspections
bool FHIT_Part::inspection(const Date& date) const
{
  if(FH_Part::inspection(date) || IT_Part::inspection(date))
  {
    return true;
  }
  return false;
}

//Print function for member variables
void FHIT_Part::print(ostream& ost) const
{
  ost<<"Inspect every: "<<fh_inspect<<" flight hours"<<endl;
  ost<<"Inspect every: "<<it_inspect<<" days installed"<<endl;
}
