#include <iostream>
using namespace std;

template <class type>
class GenStack{
public:
	GenStack();
	GenStack(int maxSize);
	~GenStack();

	type *stackarray;
	type *newstack;
	type top;
	int mSize;

	void push(type data);
	type pop();
	type peek();

	type size();
	void resize(int newSize);
	bool isEmpty();
	bool isFull();

};

//default constructor
template <class type>
GenStack<type>::GenStack(){
	stackarray = new type[200];
	newstack = new type[200];
	mSize = 200;
	top = -1;
}

//constructor
template <class type>
GenStack<type>::GenStack(int maxSize){
	stackarray = new type[maxSize];
	newstack = new type[maxSize];
	mSize = maxSize;
	top = -1;
}

//destructor
template <class type>
GenStack<type>::~GenStack(){
	delete stackarray;
	delete newstack;
}

//push function
template <class type>
void GenStack<type>::push(type data){
	stackarray[++top] = data;
}

//pop function
template <class type>
type GenStack<type>::pop(){
	if (isEmpty()){
		throw out_of_range("Stack underflow - program terminated.");
	}
	return stackarray[top--];
}

//peek function
template <class type>
type GenStack<type>::peek(){
	if (!isEmpty()){
		return stackarray[top];
	}
	else{
		throw out_of_range("Stack underflow - program terminated.");
	}
}

//check for size
template <class type>
type GenStack<type>::size(){
	return top + 1;
}

//resize stack
template <class type>
void GenStack<type>::resize(int newSize){
	mSize = newSize;
	type *temp = new type[mSize];

	for (int i = 0; i < top; i++){ //copy everything in old array to new array with different size
	temp[i] = stackarray[i];
	}

	delete stackarray; //delete old array from class
	stackarray = temp; // make class array equal newer array
	delete temp;
}

//check if empty
template <class type>
bool GenStack<type>::isEmpty(){
	return top == -1;
}

//check if full
template <class type>
bool GenStack<type>::isFull(){
	return (top == mSize - 1);
}
