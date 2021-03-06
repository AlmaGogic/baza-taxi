#include <iostream>
using namespace std; 

template<typename T>
class ArrayList
{
private:
	T* elements; 
	int size;  
	int maxlength;
public:
	ArrayList(int n = 100); 
	ArrayList(const ArrayList<T>& list); 
	const ArrayList<T>& operator=(const ArrayList<T>&); 
	bool empty() const; 
	bool full() const; 
	int Size() const { return size; } 
	int maxLength() const { return maxlength; } 
	void print() const; 
	bool equal(int location, const T& obj) const;  
	void insertAtLocation(int location, const T& objInsert); 
	void insertAtEnd(const T& objInsert); 
	void removeFromLocation(int location); 
	void replaceAtLocation(int location, const T& objNew); 
	void deleteList(); 
	int search(const T& obj); 
	void insert(const T& obj); 
	void remove(const T& obj); 
	T& grabElement(int location);
  int returnIdLocation(int id);

	~ArrayList(void) { delete [] elements; }
};


template<typename T>
ArrayList<T>::ArrayList(int n)
{
  if (n<0)  
	  maxlength  = 100; 
  else maxlength = n; 
  size = 0; 
  elements = new T[n];
}


template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& list)
{
	maxlength = list.maxlength(); 
	size = list.size(); 
	elements = new T[maxlength]; 
	for (int i = 0; i<size; i++)
		elements[i] = list.elements[i];
}


template<typename T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& drugaLista)
{
	if (this!=&drugaLista) 
	{
		delete [] elements; 
		maxlength = drugaLista.maxlength(); 
		size = drugaLista.size(); 
		elements = new T[maxlength]; 
		for (int i= 1; i<size; i++)
			elements[i] = drugaLista.elements[i];
	}
	return *this; 
}


template<typename T>
bool ArrayList<T>::empty() const
{
	return (size == 0);
}


template<typename T>
bool ArrayList<T>::full() const
{
	return (size == maxlength);
}


template<typename T>
void ArrayList<T>::print() const
{
	for (int i = 0; i<size; i++)
		cout << elements[i] << " ";
	cout << endl; 
}



template<typename T>
bool ArrayList<T>::equal(int location, const T& obj) const
{
	return (elements[location]==obj); 
}


template<typename T> 
void ArrayList<T>::insertAtLocation(int location, const T& objInsert)
{
	if (location<0 || location > maxlength)
		throw string("Can't insert at given location. Enter index from 0 to maximal list size.");
	else 
	{
		if (full())
			throw string("List is full. It's not possible to insert another element. ");
		else 
		{
			for (int i = size; i>location; i--) 
				elements[i] = elements[i-1]; 
			elements[location] = objInsert; 
			size++; 
		} 
	}
}


template<typename T> 
void ArrayList<T>::insertAtEnd(const T& objInsert)
{
	if (full())
		throw string("List is full. It's not possible to insert another element. ");
	else 
	{
		elements[size] = objInsert;
		size++; 
	}
}


template<typename T> 
void ArrayList<T>::removeFromLocation(int location)
{
	if (location<0 || location >= size)
		throw string("There is no element on that location or you entered an invalid value.");
	else 
	{
		for (int i = location; i<size - 1; i++)
			elements[i] = elements[i+1];
		size--;  
	}
}


template<typename T> 
void ArrayList<T>::replaceAtLocation(int location, const T& objNew)
{
	if (location<0 || location >= size)
		throw string("There is no element on that location or you entered an invalid value.");
	else 
	{
		elements[location] = objNew; 
	}
}


template<typename T> 
void ArrayList<T>::deleteList()
{
	delete [] elements; 
	size = 0; 
}


template<typename T> 
int ArrayList<T>::search(const T& obj)
{
	for (int i = 0; i<size; i++)
	{
		if (elements[i]==obj)
			return i; 
	}
	return -1; 
}


template<typename T> 
void ArrayList<T>::insert(const T& obj)
{
	if (search(obj)==-1)
	{
		insertAtEnd(obj);  
	}
}


template<typename T> 
void ArrayList<T>::remove(const T& obj)
{
	if (search(obj)!=-1) 
	{
		removeFromLocation(search(obj));
	}
}


template<typename T> 
T& ArrayList<T>::grabElement(int location) 
{
	if (location<0 || location >= size)
		throw string("There is no element on that location or you entered an invalid value.");
	else 
		return elements[location];
}

template<typename T>
int ArrayList<T>::returnIdLocation(int id)
{
  for(int i=0; i<size; ++i)
  {
    if(elements[i].getID() == id)
      return i;
  }
  return -1;
}


