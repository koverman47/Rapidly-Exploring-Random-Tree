#!/usr/bin/env python3

import matplotlib.pyplot as plt


nodes_x = []
nodes_y = []
edges_x = []
edges_y = []

def convert_data(path="graph.txt"):
    with open(path) as f:
        for line in f:
            line = line.translate({ord(c): None for c in '{}()\n'})
            line = line.split(',')
            edges_x.append([line[0], line[2]])
            edges_y.append([line[1], line[3]])
            nodes_x.append(line[0])
            nodes_x.append(line[2])
            nodes_y.append(line[1])
            nodes_y.append(line[3])


def plot_data():
    fig = plt.figure()
    plt.plot(nodes_x, nodes_y, "o")
    
    for i in range(len(edges_x)):
        plt.plot(edges_x[i], edges_y[i], 'k-')

    plt.show()


if __name__ == "__main__":
    convert_data("see.txt")
    plot_data()
