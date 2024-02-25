import queue

adj_list={
    "a":["b","c","d"],
    "b":["e","f"],
    "c":["g","h"],
    "d":["i"],
    "e":[],
    "f":[],
    "g":[],
    "h":[],
    "i":[],    
    }

visited=[]
queue=[]
trop=[]

def bfs(visited,graph,node):
    visited.append(node)
    queue.append(node)

    while queue:
        m=queue.pop(0)
        trop.append(m)

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

    print("traversed output =",trop)
        


stnode=input("enter the start node from where you want to traverse= ")
bfs(visited,adj_list,stnode)





