#ifndef _PRIORITY_QUEUE_HXX
#define _PRIORITY_QUEUE_HXX

#include<iostream>

using namespace std;

template<typename elemType>
class priority_queue
{
    public:
	priority_queue(int n=10);
	~priority_queue();
	priority_queue(const priority_queue<elemType>& other);
        int Size() const;
	int Length() const;
        bool isEmpty() const;
        elemType& top();
        void push(const elemType& e);
        elemType pop();
        void rePRUp(int, int);
        void rePRDown(int, int);
	      void printPR();
        void swap(elemType&, elemType&);
	const priority_queue<elemType>& operator=(const priority_queue<elemType>&);

    private:
        elemType* elements;
        int size;
        int length;
};

template<typename elemType>
priority_queue<elemType>::priority_queue(int n)
{
	elements = new elemType[n];
	length=n;
	size=0;
}

template<typename elemType>
priority_queue<elemType>::~priority_queue()
{
	delete[] elements;
}

template<typename elemType>
int priority_queue<elemType>::Size() const
{
    return size;
}

template<typename elemType>
int priority_queue<elemType>::Length() const
{
	return length;
}

template<typename elemType>
bool priority_queue<elemType>::isEmpty() const
{
    return (size==0);
}

template<typename elemType>
elemType& priority_queue<elemType>::top()
{
    if(isEmpty())
    {
        throw string("Priority queue is empty.");
    }
    else
    {
        return elements[0];
    }
}

template<typename elemType>
void priority_queue<elemType>::push(const elemType& e)
{
    if(size == length)
        cout << "Priority queue is full." << endl;
    else
    {
        elements[size++] = e;
        rePRUp(0, size-1);
    }
}

template<typename elemType>
elemType priority_queue<elemType>::pop()
{
  if(!isEmpty())
  {
    int max = 0;
    for(int j = 1; j < size; ++j)
      if(elements[max] < elements[j])
        max = j;

    swap(elements[max], elements[size-1]);
    return elements[--size];
  }
  else
    return NULL;
}

template<typename elemType>
void priority_queue<elemType>::rePRUp(int root, int bottom)
{
    int parent;
    while(bottom > 0 && elements[bottom] > elements[(bottom-1)/2])
    {
        parent = (bottom-1)/2;        
        swap(elements[parent], elements[bottom]);
        rePRUp(root, parent);

   
    }
}

template<typename elemType>
void priority_queue<elemType>::rePRDown(int root, int bottom)
{
    while(root*2+1 < bottom)
    {
        int leftChild = (root*2+1);
        int rightChild = (leftChild + 1);
        if(rightChild < bottom) 
        {
            if(elements[rightChild] > elements[leftChild]) 
                leftChild = rightChild;
        }

        if(elements[leftChild] > elements[root]) 
        {
            swap(elements[root], elements[leftChild]);
            rePRDown(leftChild, bottom);
        }

        root = leftChild;
    }
}

template<typename elemType>
void priority_queue<elemType>::swap(elemType& a, elemType& b)
{
    elemType temp = a;
    a = b;
    b = temp;
}

template<typename elemType>
const priority_queue<elemType>& priority_queue<elemType>::operator=(const priority_queue<elemType>& other)
{
	if(this != &other)
	{
		delete[] elements;
		length = other.Length();
		size = other.Size();
		elements = new elemType[length];
		for(int i=0; i<size; ++i)
			elements[i] = other.elements[i];
	}
	
	return *this;
}

template<typename elemType>
priority_queue<elemType>::priority_queue(const priority_queue<elemType>& other)
{
	length = other.Length();
	size = other.Size();
	elements = new elemType[length];
	for(int i = 0; i<size; ++i)
		elements[i] = other.elements[i];
}

#endif
