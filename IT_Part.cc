#include "IT_Part.h"


//General constructor with two arguments
IT_Part::IT_Part(const string& name, int num): it_inspect(num),Part(name)
{

}

//Deconstructor
IT_Part::~IT_Part()
{

}

//Looks whether the installation and inspection dates correlate to the installed time
bool IT_Part::inspection(const Date& date) const
{
  if((date.toDays() - (this->installationDate.toDays())) >= this->it_inspect)
  {
    return true;
  }
  return false;
}

//Print function for member variables
void IT_Part::print(ostream& ost) const
{
  ost<<"Inspect every: "<<this->it_inspect<<" days installed"<<endl;
}
