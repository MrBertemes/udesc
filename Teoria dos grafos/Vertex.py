import sys


class Vertex():

    def __init__(self, id):
        self.id = id
        self.adj = {}
        self.explored = 0
        self.dist = sys.maxsize
        self.pred = -1

    def name(self):
        return str(self.id) + ' adjacent: ' + str([x.id for x in self.adj])

    def add_neighbor(self, neighbor, weight=0):
        self.adj[neighbor] = weight

    def get_connections(self):
        return self.adj.keys()

    def get_id(self):
        return self.id

    def get_weight(self, neighbor):
        return self.adj[neighbor]

    def grau_vertex(self):
        return len(self.adj)
