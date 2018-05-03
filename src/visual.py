#!/usr/bin/env python3

import matplotlib.pyplot as plt


nodes_x = []
nodes_y = []
edges_x = []
edges_y = []

dim1_x = []
dim1_y = []
dim2_x = []
dim2_y = []

fig = plt.figure()

def convert_data(node_x, node_y, edge_x, edge_y, path="graph.txt"):
    with open(path) as f:
        for line in f:
            line = line.translate({ord(c): None for c in '{}()\n'})
            line = line.split(',')
                
            edge_x.append([line[0], line[2]])
            edge_y.append([line[1], line[3]])
            node_x.append(line[0])
            node_x.append(line[2])
            node_y.append(line[1])
            node_y.append(line[3])


def plot_data(node_x, node_y, edge_x, edge_y, color="b"):
    #fig = plt.figure()
    plt.plot(node_x, node_y, color + "o")
    
    for i in range(len(edge_x)):
        plt.plot(edge_x[i], edge_y[i], 'k-')

    plt.show()




if __name__ == "__main__":
    convert_data(nodes_x, nodes_y, edges_x, edges_y, "see.txt")
    convert_data(dim1_x, dim1_y, dim2_x, dim2_y, "obstacles.txt")
    plot_data(nodes_x, nodes_y, edges_x, edges_y)
    plot_data(dim1_x, dim1_y, dim2_x, dim2_y, "r")
