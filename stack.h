/*
* STACK Class
* ===========
* Methods defined:
* push()
* pop()
* clear()
* isEmpty()
* isFull()
* top()
*
*/
#include<exception>
using namespace std;

class myStackException: public exception{

	virtual const char* what() const throw()
	{
		return "Stack Exception - empty or full to do this operation";
	}
};
template <class ElementType>
class Stack{

private:		
		int size;
		int capacity;
		ElementType *data;
		myStackException myex;

public:		

	//constructor with default size
		Stack(){
			data = new ElementType[MAXSIZE];
			capacity = MAXSIZE;
			size = 0;
		} 
		//constructor with user defined size
		Stack(int sz){
			data = new ElementType[sz];
			capacity = sz;
			size = 0;
		}

		//to check if stack is empty
		bool isEmpty(){
			if(size==0){
				return true;
			}
			return false;
		}
		//to check if stack is full
		bool isFull(){
			if(size==capacity){
				return true;
			}
			return false;
		}

		void clear(){
			if(isEmpty()){
				return;
			}

			size=0;
		}
		//to push new element to the top of the stack
		void push(ElementType item){
			if(isFull()){				
				throw myex;
			}

			data[size] = item;
			size++;			
		}
		//to remove element from the top of the stack
		void pop(){
			if(isEmpty()){
				throw myex;
			}
			size--;
			
		}
		// to get the element at the top of the stack
		ElementType top(){
			if(isEmpty()){
				throw myex;
			}
			ElementType temp = data[size-1];
			return temp;
		}		
};