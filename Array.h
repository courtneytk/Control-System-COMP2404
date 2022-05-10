#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>

class Array {

	template <class P>
	friend ostream& operator<<(ostream&,const Array<P>&);

	public:
		//constructor
		Array();

		//destructor
		~Array();

		//other
		void add(T);
		T& operator[](int index) const;
		int getSize() const;
		bool isFull() const;

	private:
		int size;
		T* elements;

};

//No argument constructor
template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

//Destructor
template <class T>
Array<T>::~Array(){
	delete [] elements;
}

//Adds to the array of T elements if array is not full
template <class T>
void Array<T>::add(T t){

	if (size >= MAX_ARR)
	{
		return;
	}

  elements[size++] = t;
}

//Returns the size of the array
template <class T>
int Array<T>::getSize() const{
	return size;

}

//Determines if an array is full
template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARR;
}

//Operator overload
template <class T>
ostream& operator<<(ostream& ost,const Array<T>& array){
		for(int i=0; i<array.size; i++)
		{
			ost<<array.elements[i]<<endl;
		}
		return ost;
	}

//Get method
template <typename T>
T& Array<T>::operator[](int index) const{
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}

return elements[index];


}

#endif
