# MY SOLUTION FOR LAB 10 Q1 (and Q2)
# Keep the graph, except, instead of adjacent python lists for each node (1 level deep), use linked lists implementation.
# ex. Node A connected to B, C. linked list for a.adj would look like [b,c]
# You can make it any order (make B or C a head)

import numpy as np
import LL as L # use for linked list

class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = L.LL() # create linked list (takes in nothing as parameters) full of Node classes NOT value (string) values

def are_nodes_linked(node1, node2):
    # node1 and node2 are linked if there is an edge between
    # node1 and node2
    # Assume graph is undirected
    
    llnode = node1.neighbours.head # GRAPH NODE TYPE -> ACCESS LINKED LIST TYPE -> LL Node type

    if llnode == None: # if empty linked list, return false
        return False 
    
    while (llnode.data.value != node2.value): # compare 
        if (llnode.next != None): # if the linked list isn't over, go to the next Node
            llnode = llnode.next.data
        else: # went through the list and never found a match
            return False

    return True


def get_node_by_str(nodes, node_str):
    return nodes.get(node_str, None)
    # for node in nodes:
    #     if node.value == node_str:
    #         return node
    # return None

def are_airports_linked(airports, airport1_str, airport2_str):
    airport1 = get_node_by_str(airports, airport1_str)
    airport2 = get_node_by_str(airports, airport2_str)
    if airport1 is None or airport2 is None:
        return False
    return are_nodes_linked(airport1, airport2)

def set_neighbours(airport, lon):
    # airport and list of neighbours


    airport.neighbours = L.LL()
    airport.neighbours.head = L.Node(lon[0]) # set head to a node value (alternatively, do it in the for loop as there is code to account for that)

    temp = airport.neighbours

    for i, val in enumerate(lon):
        if(i==0):
            continue
        temp.insert(i,L.Node(val))        

def make_airport_graph1():
    yyz = Node("YYZ")
    yvr = Node("YVR")
    yul = Node("YUL")
    whitehorse = Node("Whitehorse")
    '''
    yyz.neighbours = set([yvr, yul])
    yvr.neighbours = set([yyz, yul, whitehorse])
    yul.neighbours = set([yyz, yvr])
    whitehorse.neighbours = set([yvr])
    '''

    set_neighbours(yyz,[yvr, yul])
    set_neighbours(yvr, [yyz, yul, whitehorse])
    set_neighbours(yul, [yyz, yvr])
    
    airport_dict = {}
    for airport in [yyz, yvr, yul, whitehorse]:
        airport_dict[airport.value] = airport
    
    return airport_dict

def convert_to_adj_matrix(airports):
    adj_matrix = np.zeros((len(airports), len(airports)))
    # make an empty matrix of 0s

    airport_callsigns = sorted(list(airports.keys()))
    airport_callsigns_idx = {}
    for i, airport_callsign in enumerate(airport_callsigns):
        airport_callsigns_idx[airport_callsign] = i

    # Fill in airport_callsigns_idx dictionary with indices of alphabetically ordered airports {"a":0,"b":1,...}

    for airport_callsign, airport in airports.items(): # airport is the airport_dict with {"YYZ",yyz,"YVR",yvr ... }
        for neighbour in airport.neighbours:
            adj_matrix[airport_callsigns_idx[airport_callsigns], airport_callsigns_idx[neighbour.value]] = 1
            # adj_matrix[airport_callsigns_idx[neighbour.value], airport_callsigns_idx[airport_callsign]] = 1

    return adj_matrix, airport_callsigns_idx


if __name__ == '__main__':
    airports = make_airport_graph1()
    print("Toronto (YYZ) is connected to Montreal (YUL)?", are_airports_linked(airports, "YYZ", "YUL")) # True
    print("(YUL) is connected to (YVR)?", are_airports_linked(airports, "YUL", "YVR")) # true
    print("(YUL) is connected to (Whitehorse)?", are_airports_linked(airports, "YUL", "Whitehorse")) #false