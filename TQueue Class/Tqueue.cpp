#ifndef TQUEUE_H
#define TQUEUE_H
/********************************
 ** File: Tqueue.cpp
 ** Project: CMSC 202 Project 5, Fall 2017
 ** Author: Enzo Walker
 ** Date: 11/27/2017
 ** Section: 1093, Discussion: 1095
 ** Email: enzow1@umbc.edu
 **
 ** This class is a templated Queue that takes Type Pramaters of T
 ** which are then implemented in a First-In-First-Out Queue system.
 ** In our case, Song objects will be queued.
 ** 
 **
 ********************************/

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  void dequeue(T &); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve front (does not remove it)
  void queueFront(T &);    // Retrieve front (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: isFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int isFull(); //Returns 1 if queue is full else 0
  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int size(); //Returns size of queue
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****

//Tqueue()
//Default constructor for a Templated Queue
template <class T, int N>
Tqueue<T,N>::Tqueue(){
  m_data = new T[N];
  m_front = 0;
  m_back = 0;
}

//Tqueue( const Tqueue<T,N>& x)
//Copy constructor for a Tqueue
template <class T, int N> 
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ){

  m_data = new T[N];
  
  for(int i = 0; i < N; i++){
    m_data[i] = x.m_data[i];
  }
  
  m_front = x.m_front;
  m_back = x.m_back;
}

//~Tqueue()
//Destructor for Tqueue that deallocates each song in the queue
template <class T, int N>
Tqueue<T,N>::~Tqueue(){
  delete [] m_data;
  m_data = NULL;
}

//enqueue(T data)
//Adds item that is passed to the back of the queue
template <class T, int N>
void Tqueue<T,N>::enqueue(T data){
  //Enqueue's if the queue is not full
  if(!isFull()){
    m_data[m_back] = data;
    m_back++;
  }else{
    cout << "You have reached the max amount of songs allowed" << endl;
  }
}

//dequeue(T& data)
//Removes an item from the queue
template <class T, int N>
void Tqueue<T,N>::dequeue(T& data){
  if(!isEmpty())
    m_front++;
}

//queueFront(T& data)
//Retrieves front of the queue but does not remove it
template <class T, int N>
void Tqueue<T,N>::queueFront(T& data){
  
}

//isEmpty();
//Returns 1 if queue is empty, and 0 if it's not empty
template <class T, int N>
int Tqueue<T,N>::isEmpty(){ 
  if(size() == 0)
    return 1;
  else
    return 0;
}

//isFull()
//Returns 1 if queue is full, and 0 if it's not full
template <class T, int N>
int Tqueue<T,N>::isFull(){
  if(size() == N)
    return 1;
  else
    return 0;
}

//size()
//Returns the size of the queue
template <class T, int N>
int Tqueue<T,N>::size(){
  return abs((m_back - m_front));
}

//Overloaded assignment operator
//Assigns one Tqueue to another using the "=" operator
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=( Tqueue<T,N> y){

  delete [] m_data; 

  m_data = new T[N];

  for(int i = 0; i < N; i++){
    m_data[i] = y.m_data[i];
  }
  
  m_front = y.m_front;
  m_back = y.m_back;  

  return *this;
}

//Overloaded [] operator
//Properly returns a reference to an object of type T
template <class T, int N>
T& Tqueue<T,N>::operator[] (int x){
  return m_data[x+m_front];
}
#endif
