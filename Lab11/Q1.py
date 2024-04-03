def BFS (node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur=q.pop(0)
        print (cur.name)
        for con in cur.connections :
            if not con.visited :
                q.append(con)
                con.visited = True



def DFS(node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop()  # remove last element from q and put it in cur
        print(cur.name)
        for con in cur.connections:
            if not con.visited:
                q.append(con)
                con.visited = True

# Example usage:
# DFS(C) # C D E F B A



# Implement a Graph:
                
class node:
    def __init__(self):
        self.val = 0
        self.neighbours = []

def makeGraph():
    return None
    