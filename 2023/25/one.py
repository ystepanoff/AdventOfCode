import sys

# Assuming that in order to split the graph we need to remove at least
# three edges, this becomes a minimum edge cut problem.
import networkx as nx

G = {}
for line in sys.stdin:
    node, adj = line.rstrip().split(': ')
    G[node] = adj.split()
G = nx.Graph(G)

min_edge_cut = nx.minimum_edge_cut(G)
G.remove_edges_from(min_edge_cut)
connected_components = list(nx.connected_components(G))
assert len(connected_components) == 2
c1, c2 = connected_components
print(len(c1) * len(c2))