/*
    Author          : Prashant Gupta
    Date Created    : 20th August 2015
    Comments        : This source file was created as a part of assignment 1. Problem statement was Impelement Dijkstra Using Fibonacci heap.
    Purpose         : This file contains the source code for data class.

***********************************File Revision Details*************************************************
_______________________________________________________________________________________________________________________
| Date      |       Changes                                                                                             |
________________________________________________________________________________________________________________________|
|20/08/2015 |   First Draft of the file                                                                                 |
________________________________________________________________________________________________________________________|
|02/09/2015 |   Added comment in the file                                                                               |
________________________________________________________________________________________________________________________|
*/

#include"misc.hpp"                                          //Custom defined header file, Contains decleration for data
                                                            //class

//Data class definition

data::data(){                                               //Default constructor of the class
    this->distance = 0;
    this->parent = 0;
    this->node_number = 0;
}

data::data(int distance, int parent, int node_number){      //Overloaded constructor of data class
    this->distance = distance;
    this->parent = parent;
    this->node_number = node_number;
}

data::data(int distance){                                   //Overloaded constructor of data class
    this->distance = distance;
    this->parent = 0;
    this->node_number = 0;
}

void data::operator=(const data & d){                       //Definition of = operator for data class.
    this->distance = d.distance;
    this->parent = d.parent;
    this->node_number = d.node_number;
}

bool data::operator>(const data & d){                       //Definition of > operator for data class.
    if(this->distance > d.distance)return true;
    else return false;
}

bool data::operator<(const data & d){                       //Definition of < operator for data class
    if(this->distance < d.distance)return true;
    else return false;
}

bool data::operator>=(const data & d){                      //Definition of >= operator for data class
    if(this->distance >= d.distance)return true;
    else return false;
}

bool data::operator<=(const data & d){                      //Definition of <= operator for data class
    if(this->distance <= d.distance)return true;
    else return false;
}

bool data::operator==(const data & d){                      //Definition of == operator for data class
    if(this->distance == d.distance)return true;
    else return false;
}

data data::operator+(const int & d){                        //Definition of + operator for data class
    data l;
    l.node_number = this->node_number;
    l.parent = this->parent;
    l.distance = this->distance + d;
    return l;
}
