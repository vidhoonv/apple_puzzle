/*
* QUEUE Class
* ===========
* Methods defined:
* push()
* pop()
* front()
* clear()
* sze()
* isSorted()
* isEmpty()
* isFull()
*/
#include<exception>
using namespace std;



class myQueueException: public exception{

	virtual const char* what() const throw()
	{
		return "Queue Exception - empty or full to do this operation";
	}
};

template <class ElementType>
class Queue{

private:		
		int size;
		int capacity;
		ElementType *data;
		int head,tail;

		

		myQueueException myex;

public:
	int sze(){
			return size;
		}
	//constructor with default size
		Queue(){
			data = new ElementType[MAXSIZE];
			capacity = MAXSIZE;
			size = 0;
			head = 0;
			tail = 0;
		} 
		//constructor with user defined size
		Queue(int sz){
			data = new ElementType[sz];
			capacity = sz;
			size = 0;
			head = 0;
			tail = 0;
		}

		//to check if Queue is empty
		bool isEmpty(){
			if(size==0){
				return true;
			}
			return false;
		}
		//to check if Queue is full
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
			head = 0;
			tail = 0;
		}
		void push(ElementType elem){
			if(isFull()){				
				throw myex;
			}

			data[tail] = elem;			
			size++;	
			tail++;
			tail=tail%capacity;
		}

		void pop(){
			if(isEmpty()){				
				throw myex;
			}

			size--;
			head++;
			head=head%capacity;
		}

		ElementType front(){
			if(isEmpty()){				
				throw myex;
			}
			return data[head];
		}

		bool isSorted(){
			int i=head+1, k=0;
			i%=capacity;
			while(k<size-1){
				if(i==0){
					if(data[capacity-1]>data[i]){
						return false;
					}
				}
				else if(data[i-1]>data[i]){
					return false;
				}
				
				i++;
				i%=capacity;
				k++;				
			}

			return true;
		}
		/* a display method for debug */
		void display(){
			int i=0,k=0;
			while(k<size){
				cout<<data[i]<<" ";
				i++;
				i%=capacity;
				k++;
			}
			cout<<endl;
		}
};