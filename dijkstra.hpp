/*
    Author          : Prashant Gupta
    Date Created    : 20th August 2015
    Comments        : This header was created as a part of assignment 1. Problem statement was Impelement Dijkstra Using Fibonacci heap.
    Purpose         : This file contains the decleration of classes used to implement dijkstra.

***********************************File Revision Details*************************************************
_______________________________________________________________________________________________________________________
| Date      |       Changes                                                                                             |
________________________________________________________________________________________________________________________|
|20/08/2015 |   First Draft of the file                                                                                 |
________________________________________________________________________________________________________________________|
|02/09/2015 |   Added comments in the file                                                                              |
________________________________________________________________________________________________________________________|

*/

/*
    This file contains implementation for both the representation of graphs.
*/


#ifndef __DIJKSTRA_HPP__
#define __DIJKSTRA_HPP__

#include<iostream>
#include<climits>
#include<vector>
#include<set>
#include<iterator>
#include"fib_heap.hpp"                                              //Custom defined header file. Contains interface
                                                                    //for Fibonacci heap.
#include"misc.hpp"                                                  //Custom defined header file. Contains interface
                                                                    //for data class.


/*
Change this define statement here (values are written alongside) to switch between adjacency matrix and adjacency list form. Both representation is defined under the namespace d1.
In case of Adjacency Matrix representation, it contains only 1 class named as dijkstra.
In case of Adjacency List representation, it contains 2 classes named as g_node and dijkstra.
g_node class is the node definition for adjacency list form.
dijkstra class contains the interface for the dijkstra implementation.
*/

#define __ADJ_MAT__  //Values are : __ADJ_MAT__ and __ADJ_LST__

#ifdef __ADJ_MAT__      //Adjacency Matrix form

namespace d1{
    class dijkstra{
        //Private member decleration
        private: int number_of_vertices;                //This variable will store number of vertices
        private: std::vector< std::vector<int> > g;     //This variable will store the complete graph
        private: std::vector<data *> v;                 //This variable will store shortest distance from the source
                                                        //node
        private: int source;                            //This variable will store source vertex
        private: a1::heap fh;                           //Variable to access fibonacci heap data structure
        //Public member decleration
        //Private method decleration
        private: void initialize_single_source();       //Initilize the dijkstra.
                                                        //Distance in all the nodes accept starting node will be
                                                        //assigned maximum possible value, start node will have that
                                                        //value set to zero.
        private: void relax(int, int);                  //This function updates the path from source to destined node
        //Public method decleration
        public: dijkstra(std::vector< std::vector<int> > &, int);   //Constructor for this class.
                                                                    //Accepts two values, First the whole graph
                                                                    //Second Source
        public: void run();                             //Function to start the dijkstra
        public: void print_graph();                     //Function to print the input graph
        public: void print_result();                    //Function to print the shortest path
    };
};

#endif // __ADJ_MAT__


#ifdef __ADJ_LST__      //Adjacency List form

namespace d1{
    class g_node{                                       //Class defining a node of a graph
        //Private member decleration
        //Public member decleration
        public: g_node * next;                          //Pointer to the next element in the graph in adjacency list
                                                        //form
        public: int node_number;                        //Node number of the arrow end of the graph
        public: int weight;                             //Weight of the edge
        //Private method decleration
        //Public method decleration
        public: g_node(int, int);                       //Constructor for the class, Argument list is as follow:
                                                        // 1. node_number
                                                        // 2. weight
    };
    class dijkstra{
        //Private member decleration
        private: int number_of_vertices;                //This variable will store number of vertices
        private: std::vector< g_node * > g;             //This variable will store all the graphs
        private: std::vector<data *> v;                 //This variable will store shortest distance from the source
                                                        //node
        private: int source;                            //This variable store the source vertex for the dijkstra
        private: a1::heap fh;                           //Variable to access fibonacci heap data structure
        //Public member decleration
        //Private method decleration
        private: void create_graph(std::vector< std::vector<int> > &);  //This method will create the graph from the
                                                                        //edges
        private: void initialize_single_source();       //Initialize single source
        private: void relax(int, g_node *);             //This function updates the path from source to destined node
        //Public method decleration
        public: dijkstra(std::vector< std::vector<int> > &, int, int);  //Constructor for the class. Receives three
                                                                        //agrugments
                                                                        // 1. Edges of graph
                                                                        // 2. Number of vertices
                                                                        // 3. Source node
        public: void run();                             //Function to start the dijkstra
        public: void print_graph();                     //Function to print the graph
        public: void print_result();                    //Function to print the shortest path
    };
};

#endif // __ADJ_LST__

#endif
