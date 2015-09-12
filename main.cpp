/*
    Author          : Prashant Gupta
    Date Created    : 20th August 2015
    Comments        : This debug was created as a part of assignment 1. Problem statement was Impelement Dijkstra Using Fibonacci heap.
    Purpose         : This file contains the test suit for the dijkstra algorithm

***********************************File Revision Details*************************************************
_______________________________________________________________________________________________________________________
| Date      |       Changes                                                                                             |
________________________________________________________________________________________________________________________|
|20/08/2015 |   First Draft of the file                                                                                 |
________________________________________________________________________________________________________________________|
|02/09/2015 |   Added comments to the file                                                                              |
________________________________________________________________________________________________________________________|

*/
#include"dijkstra.hpp"

using namespace a1;
using namespace d1;

int main(){
    #ifdef __ADJ_MAT__
    //Input 1
    std::cout << "Input 1: " << std::endl;
    std::vector< std::vector<int> > g;
    int number_of_vertices = 9;
    int g_2d[9][9] ={
                        {0, 4, 0, 0, 0, 0, 0, 8, 0},
                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 0, 10, 0, 2, 0, 0},
                        {0, 0, 0, 14, 0, 2, 0, 1, 6},
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 2, 0, 0, 0, 6, 7, 0}
                    };
    for(int i = 0; i < number_of_vertices; i++){
        std::vector<int> row(g_2d[i], g_2d[i] + sizeof(g_2d[i])/sizeof(int));
        g.push_back(row);
    }
    dijkstra d1(g, 0);
    d1.print_graph();
    d1.run();
    d1.print_result();
    //Input 2
    std::cout << "Input 2: " << std::endl;
    std::vector< std::vector<int> > g1;
    number_of_vertices = 5;
    int g_2d_1[5][5] = {
                            {0,10,0,5,0},
                            {0,0,1,2,0},
                            {0,0,0,0,4},
                            {0,3,9,0,2},
                            {2,0,6,0,0}
                       };
    for(int i = 0; i < number_of_vertices; i++){
        std::vector<int> row(g_2d_1[i], g_2d_1[i] + sizeof(g_2d_1[i])/sizeof(int));
        g1.push_back(row);
    }
    dijkstra d2(g1, 0);
    d2.print_graph();
    d2.run();
    d2.print_result();
#endif // __ADJ_MAT__
#ifdef __ADJ_LST__

    // Input 1:
    std::cout << "Input 1 : " << std::endl;
    int number_of_vertices;
    std::vector< std::vector < int > > g1;
    int g_2d_1[][3]={ {1,2,4},{1,8,8},
                    {2,1,4},{2,3,8},{2,8,11},
                    {3,2,8},{3,4,7},{3,6,4},{3,9,2},
                    {4,3,7},{4,5,9},{4,6,14},
                    {5,4,9},{5,6,10},
                    {6,3,4},{6,5,10},{6,7,2},
                    {7,4,14},{7,6,2},{7,8,1},{7,9,6},
                    {8,1,8},{8,2,11},{8,7,1},{8,9,7},
                    {9,3,2},{9,7,6},{9,8,7}
                    };
    int number_of_rows = sizeof(g_2d_1)/sizeof(int)/3;
    number_of_vertices = 9;
    for(int i = 0; i < number_of_rows; i++){
        std::vector<int> * row = new std::vector<int>(g_2d_1[i], g_2d_1[i] + sizeof(g_2d_1[i])/sizeof(int));
        g1.push_back(*row);
    }

    dijkstra d1(g1, number_of_vertices, 1);
    d1.run();
    d1.print_graph();
    d1.print_result();

    //input 2
    std::cout << "Input 2 : " << std::endl;
    std::vector< std::vector< int > > g2;
    int g_2d_2[][3]={ {1,2,10},{1,4,5},
                      {2,3,1},{2,4,2},
                      {3,5,4},
                      {4,2,3},{4,3,9},{4,5,2},
                      {5,1,2},{5,3,6}
                    };
    number_of_rows = sizeof(g_2d_2)/sizeof(int)/3;
    number_of_vertices = 5;
    for(int i = 0; i < number_of_rows; i++){
        std::vector<int > * row = new std::vector<int>(g_2d_2[i], g_2d_2[i] + sizeof(g_2d_2[i])/sizeof(int));
        g2.push_back(*row);
    }

    dijkstra d3(g2, number_of_vertices, 1);
    d3.run();
    d3.print_graph();
    d3.print_result();
#endif // __ADJ_LST__

    return 0;
}
