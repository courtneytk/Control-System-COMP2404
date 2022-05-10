Purpose: This program will write portions of a control system for an airline where inspections, and part changes will occur.


Source Files: main.cc, Date.cc, Part.cc, FH_Part.cc, IT_Part.cc, FHIT_Part.cc, Array.cc, Aircraft.cc, Airline.cc, Control.cc, View.cc

Header Files: Date.h, Part.h, FH_Part.h, IT_Part.h, FHIT_Part.h, Array.h, Aircraft.h, Airline.h, Control.h, View.h


Source File Descriptions:

main.cc - Is a main function which acts as the main point of execution for the program, and this centralizes the calling
          of various class functions.

Date.cc - Is an entity object, and will store the information of a date.

Part.cc - An entity object which is a virtual base class of all the Parts.

FH_Part.cc - An entity object that represents a part that must be inspected after a certain number of flight hours.

IT_Part.cc - An entity object that represents a part that must be inspected after a certain number of days of being
             installed on an aircraft.

FHIT_Part.cc - An entity object that represents a part that must be inspected after a certain number of days of being
               installed on an aircraft and after a certain number of flight hours.

Array.cc - Container object that is a simple templated data structure.

Aircraft.cc - Is an entity/container object that has aircraft data and acts as a container for the installed Parts.

Airline.cc - Control object that tracks parts, aircraft, installations, flights, etc.

Control.cc - A control object that provides a test framework for the Airline.

View.cc - A view object that collects user input and provides system output.


To compile and launch:

1. Type "make a4" and click enter to compile and link the program (must be done within
   the directory storing this programs files) into an executable.

2. To run the program, simply insert "./a4" into the command line to run the program.
