/*
    Author          : Prashant Gupta
    Date Created    : 20th August 2015
    Comments        : This source file was created as a part of assignment 1. Problem statement was Impelement Dijkstra Using Fibonacci heap.
    Purpose         : This file contains the implementation of dijkstra

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
    This file has code for both the representation (Adjacency matrix and Adjacency list) seperated by conditional compilation directives whose values are defined in dijkstra.hpp header file
*/

#include"dijkstra.hpp"


/***********************Adjecency Matrix*************************/


/***********************Class dijkstra Private functions************************/

#ifdef __ADJ_MAT__

//Function for adjacency matrix representation

void d1::dijkstra::initialize_single_source(){
    //Function to initialize the algorithm
    int itr;
    for(itr = 0; itr < this->number_of_vertices; itr++){    //Initializes all nodes except source to max value
        data * d = new data(INT_MAX/2, 0, itr);
        this->v.push_back(d);
    }
    this->v[this->source]->distance = 0;                    //Initializes source node to 0
}

void d1::dijkstra::relax(int u, int v){
    //Function to update the shortest distance of any node from source
    data accumulated_weight;
    accumulated_weight = *this->v[u] + this->g[u][v];       //Calculate the new distance
    if(*this->v[v] > accumulated_weight){                   //If new distance is minimum than the existing distance
        accumulated_weight.node_number = this->v[v]->node_number;   //Updating node_number to decrease the key
        accumulated_weight.parent = this->v[v]->parent;             //Updating parent value to decrease the key
        this->fh.fib_heap_decrease_key(*this->v[v], accumulated_weight);    //calling fibonacci heap decrease key to
                                                                            //update the distance
        this->v[v]->parent = u;                                     //Updating the parent to the node
    }
}

/*************************Class dijkstra Public functions***************************/

d1::dijkstra::dijkstra(std::vector< std::vector<int> > & g, int source){
    //Overloaded constructor It receives the graph and source to run dijkstra
    this->g = g;
    this->source = source;
    this->number_of_vertices = this->g.size();
}

void d1::dijkstra::run(){
    //Function to start dijkstra
    int itr;
    std::set<data *> S;
    a1::node * n;
    data * u;
    int u_node_number;
    this->initialize_single_source();
    for(itr = 0; itr < this->number_of_vertices; itr++){        //Initializing fibonacci heap with all the vertices
        this->fh.fib_heap_insert(*this->v[itr]);
    }
    while(fh.min_node != NULL){                                 //Until fibonacci heap is not empty
        u = fh.fib_heap_extract_min();
        S.insert(u);
        u_node_number = u->node_number;
        for(itr = 0; itr < this->number_of_vertices; itr++){
            if(this->g[u_node_number][itr] != 0){               //If edge exists
                this->relax(u_node_number, itr);                //Update shortes path
            }
        }
    }
}

void d1::dijkstra::print_graph(){
    //Function to print the input graph
    int row;
    int col;

    for(row = 0; row < this->number_of_vertices; row++){
        for(col = 0; col < this->number_of_vertices; col++){
            std::cout << this->g[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void d1::dijkstra::print_result(){
    //Function to print the shortest distance
    int itr;
    std::cout << "Using Adjacency matrix" << std::endl;
    std::cout << "Source : " << this->source << std::endl;
    for(itr = 0; itr < this->number_of_vertices; itr++){
        std::cout << "Vertex : " << this->v[itr]->node_number << " Distance from source : " << this->v[itr]->distance << std::endl;
    }
}

#endif // __ADJ_MAT__


/**************************Adjecency Graph***************************/

#ifdef __ADJ_LST__

/*************************Class g_node Public functions************************/

d1::g_node::g_node(int node_number, int weight){
    //Overloaded constructor to create the node with node_number and weight
    this->node_number = node_number;
    this->weight = weight;
    this->next = NULL;
}

/*******************Class dijkstra Private functions***************************/

void d1::dijkstra::create_graph(std::vector< std::vector<int> > & edges){
    //Function to create the graph
    int itr;
    int len = edges.size();
    std::vector< d1::g_node * > * g = new std::vector< d1::g_node * >(this->number_of_vertices + 1, NULL);
    //Creates a vector to store the edge list of the vertex
    for(itr = 0; itr < len; itr++){     //Loop iterate over all the edges and creates graph
        d1::g_node * n = new d1::g_node(edges[itr][1], edges[itr][2]);  //Create a new graph node
        if((*g)[edges[itr][0]] == NULL){
            (*g)[edges[itr][0]] = n;
        }
        else{
            n->next = (*g)[edges[itr][0]];
            (*g)[edges[itr][0]] = n;
        }
    }
    this->g = *g;                   //Strores the local reference of graph to the class variable
}

void d1::dijkstra::initialize_single_source(){
    //Function to initialize the algorithm
    int itr;
    for(itr = 0; itr <= this->number_of_vertices; itr++){      //Initializes all nodes except source to max value
        data * d  = new data(INT_MAX/2, 0, itr);
        this->v.push_back(d);
    }
    this->v[this->source]->distance = 0;                       //Initializes source vertex to 0
}

void d1::dijkstra::relax(int u, g_node * x){
    data accumulated_weight;
    accumulated_weight = *this->v[u] + x->weight;               //Calculate the new distance
    if(*this->v[x->node_number] > accumulated_weight){          //If new distance is minimum than the existing distance
        accumulated_weight.node_number = this->v[x->node_number]->node_number;  //Updating node_number to decrease the
                                                                                //key
        accumulated_weight.parent = this->v[x->node_number]->parent;            //Updating parent value to decrease
                                                                                //the key
        this->fh.fib_heap_decrease_key(*this->v[x->node_number], accumulated_weight);   //calling fibonacci heap
                                                                                        //decrease key to update the
                                                                                        //distance
        this->v[x->node_number]->parent = u;                    //Updating the parent to the node
    }
}

/********************************Class dijkstra Public functions*************************/

d1::dijkstra::dijkstra(std::vector< std::vector<int> > & edges, int number_of_vertices, int source){
    //Overloaded constructor to create the dijkstra class object.
    this->source = source;
    this->number_of_vertices = number_of_vertices;
    this->create_graph(edges);              //Creates graph from the edges
}

void d1::dijkstra::run(){
    //Function to run the dijkstra
    int itr;
    std::set<data *> S;
    d1::g_node * trav;
    data * u;
    int u_node_number;
    this->initialize_single_source();
    for(itr = 1; itr <= this->number_of_vertices; itr++){       //Initializing fibonacci heap with all the vertices
        this->fh.fib_heap_insert(*this->v[itr]);
    }
    while(fh.min_node != NULL){
        u = fh.fib_heap_extract_min();
        S.insert(u);
        u_node_number = u->node_number;
        trav = this->g[u_node_number];
        while(trav != NULL){                                    //Iterate over all the edges of the node explored
            this->relax(u_node_number, trav);
            trav = trav->next;
        }
    }
}

void d1::dijkstra::print_graph(){
    //Function to print the input graph
    int itr;
    d1::g_node * n;
    std::cout << "(node number, weight)" << std::endl;
    for(itr = 0; itr <= this->number_of_vertices; itr++){
        if(this->g[itr] != NULL){
            std::cout << "Vertex: " << itr << " ";
            n = this->g[itr];
            while(n != NULL){
                std::cout << "(" << n->node_number << "," << n->weight << ") ";
                n = n->next;
            }
            std::cout << std::endl;
        }
    }
}

void d1::dijkstra::print_result(){
    //Function to print the shortes path
    int itr;
    std::cout << "Using Adjacency list" << std::endl;
    std::cout << "Source : " << this->source << std::endl;
    for(itr = 1; itr <= this->number_of_vertices; itr++){
        std::cout << "Vertex : " << this->v[itr]->node_number << " Distance from source : " << this->v[itr]->distance << std::endl;
    }
}

#endif //__ADJ_LST__
