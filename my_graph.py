from graph import Graph
if __name__ == '__main__':
    g = Graph()

    g.add_vertex('0')
    g.add_vertex('1')
    g.add_vertex('2')
    g.add_vertex('3')
    g.add_vertex('4')
    g.add_vertex('5')
    g.add_vertex('6')
    g.add_vertex('7')

    g.add_edge('0', '1', 80)
    g.add_edge('1', '0', 80)
    g.add_edge('1', '2',  80)
    g.add_edge('2', '1',  80)
    g.add_edge('0', '3', 61)
    g.add_edge('3', '0', 61)
    g.add_edge('3', '4', 76)
    g.add_edge('4', '3', 76)
    g.add_edge('4', '5',  72)
    g.add_edge('5', '4',  72)
    g.add_edge('5', '6',  80)
    g.add_edge('6', '5',  80)
    g.add_edge('1', '6', 220)
    g.add_edge('6', '1', 220)
    g.add_edge('6', '7',  71)
    g.add_edge('7', '6',  71)
    g.add_edge('7', '2',  69)
    g.add_edge('2', '7',  69)

    g.dijkstra('5')
    for n in g.dict.values():
        print("Id = ", n.id)
        print("DISTANCIA ATÉ 5!!!!!!!!!!:", n.dist)
        print("PREDECESSOR ", n.pred)

    g.BellmanFord('5')
    print("BellmanFord!\n\n\n\n")
    for n in g.dict.values():
        print("Id = ", n.id)
        print("DISTANCIA ATÉ 5:", n.dist)

    alok = g.FloydWarshall()
    print("FloydWarshall!\n\n\n\n")
    for n in alok:
        print(n)

    g.hierholzer()
    print("caxero\n\n\n\n")
    print(g.caixeiro_viajante(g, '0'))