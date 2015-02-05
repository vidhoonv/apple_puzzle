#include<iostream>
#define MAXSIZE 100

#include "queue.h"
#include "stack.h"

using namespace std;

/*
 * moveContents - function to move the contents from queue (hand)
 * 					to stack (table)
 * @q - reference to deck in hand
 * @s - reference to deck in stack
 *
 */
template<class ElementType>
void moveContents(Queue<ElementType> &q,Stack<ElementType> &s){
	while(s.isEmpty()==false){
		//temp.push_back(s.top());
		q.push(s.top());
		s.pop();
	}	
}

/*
* numRounds - function to compute the number of rounds to shuffle 
*				the deck back to the original order
*	@numCards - number of cards in the deck
*
*/


long long numRounds(int numCards){
	long long nRounds = 0;
	Queue<int> hand{numCards};
	Stack<int> table{numCards};

	//prepare hand initial sorted order of deck
	for(int i=1;i<=numCards;i++){
		hand.push(i);
	}

	//start rounds
	while(1){
		int k=0;
		while(hand.isEmpty()==false){
			if(k%2==0){
				//add to top of table deck
				int elem1 = hand.front();
				hand.pop();
				table.push(elem1);
			}
			else{
				//add to bottom of hand deck
				int elem2 = hand.front();
				hand.pop();
				hand.push(elem2);
			}
			k++;
		}
		nRounds++;
		moveContents(hand,table);
		table.clear();
		if(hand.isSorted()){
			break;
		}
		//hand.display();
	}
	return nRounds;
}


int main(){
	int numCards=0;
	//cout<<"Enter number of cards:"<<endl;
	//cin>>numCards;
	//cout<<"Number of rounds required: "<<numRounds(numCards)<<endl;
	
	for(int i=1;i<=50;i++)
		cout<<i<<": "<<numRounds(i)<<endl;
	
	return 0;
}
/*
void testComponents(){

	
	//stack tests
	Stack<int> mystack{10};
	for(int i=0;i<10;i++){
		mystack.push(i);
	}
	for(int i=0;i<10;i++){
		cout<<mystack.top()<<endl;
		mystack.pop();
	}
	
	
	//queue tests
	Queue<int> myq{3};
	for(int i=0;i<3;i++){
		myq.push(i);
	}
	while(myq.isEmpty()==false){
		cout<<myq.front()<<endl;
		myq.pop();
	}

	for(int i=0;i<3;i++){
		myq.push(i);
	}
	myq.pop();
	cout<<"s:"<<myq.sze();
	myq.pop();
	cout<<"s:"<<myq.sze();
	myq.push(3);
	cout<<"s:"<<myq.sze();
	myq.push(4);
	cout<<"s:"<<myq.sze();
	while(myq.isEmpty()==false){
		cout<<myq.front()<<endl;
		myq.pop();
	}
	cout<<"s:"<<myq.sze();
	
}
*/