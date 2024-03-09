import networkx as nx
import matplotlib.pyplot as plt

# Criar o primeiro grafo
G1 = nx.Graph()
G1.add_edges_from([(1, 2), (2, 3), (3, 4), (4, 1)])

# Criar o segundo grafo isomorfo ao primeiro
G2 = nx.Graph()
G2.add_edges_from([(11, 12), (12, 13), (13, 14), (14, 11)])

# Mapear os vértices do segundo grafo para que seja isomorfo ao primeiro
mapping = {11: 1, 12: 2, 13: 3, 14: 4}
G2 = nx.relabel_nodes(G2, mapping)

# Mostrar os grafos
plt.figure(figsize=(10, 5))

plt.subplot(121)
nx.draw(G1, with_labels=True, font_weight='bold')
plt.title('Grafo 1')

plt.subplot(122)
nx.draw(G2, with_labels=True, font_weight='bold')
plt.title('Grafo 2 (Isomorfo ao Grafo 1)')

plt.show()
