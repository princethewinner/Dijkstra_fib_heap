/*
    Author          : Prashant Gupta
    Date Created    : 20th August 2015
    Comments        : This header was created as a part of assignment 1. Problem statement was Impelement Dijkstra Using Fibonacci heap.
    Purpose         : Data class is needed for the integration of the fibonacci heap with the algorithm which uses it. Host algorithm should (It's mendatory) define this class and use it's object to pass the data to the fibonacci heap.

***********************************File Revision Details*************************************************
_______________________________________________________________________________________________________________________
| Date      |       Changes                                                                                             |
________________________________________________________________________________________________________________________|
|20/08/2015 |   First Draft of the file                                                                                 |
________________________________________________________________________________________________________________________|
|01/09/2015 |   Added Comments in the file                                                                              |
________________________________________________________________________________________________________________________|

*/

/*
Decleration shown in the file is specific for Dijkstra algorithm. For different applications member variables can be changed and all the operators shown below needs to define accordingly.
*/


#ifndef __MISC_HPP__
#define __MISC_HPP__

class data{
    //Private member decleration
    //Public member decleration
    public: int distance;                           //Stores Shortest distance from the source node.
    public: int parent;                             //Stores predecessor of the node which creates shortes path.
    public: int node_number;                        //Stores current node number for which above properties are defined
    //Private method decleration
    //Public method decleration
    public: data();                                 //Default constructor for this class
    public: data(int, int, int);                    //Overloaded constructor to initialize all the variables.
                                                    //variable sequence : distance, parent, node_number
    public: data(int);                              //Overloaded constructor to initilize with distance.
                                                    //Other variables will be initialize to zero
    public: bool operator<(const data &);           //Less than operator to compare data objects
                                                    //Comparison is done based on the value of distance.
    public: bool operator>(const data &);           //greater than operator to compare data objects
                                                    //Comparison is done based on the value of distance
    public: bool operator>=(const data &);          //greater than and equal to operator to compare data objects.
                                                    //Comparison is done based on the value of distance.
    public: bool operator<=(const data &);          //less than and equal to operator to compare data objects.
                                                    //Comparison is done based on the value of distance.
    public: bool operator==(const data &);          //equality comparison operator to compare data objects.
                                                    //Comparison is done based on the value of distance.
    public: void operator=(const data &);           //Assignment operator, assigns all the of the called object
                                                    //To the calling objects
    public: data operator+(const int &);            //Addition operator, increases the value of distance.
};

/*
    Definition of all these function is present in the data.cpp
*/

#endif //__MISC_HPP__
