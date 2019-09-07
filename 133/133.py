# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        visited = set()
        dic = dict()
        cc = Node(node.val, [])
        self.dfs(node, cc, visited, dic)
        return cc

    def dfs(self, curr, currNew, visited, dic):
        for node in curr.neighbors:
            if node in visited:
                currNew.neighbors.append(dic[node])
            else:
                nn = Node(node.val, [])
                dic[node] = nn
                currNew.neighbors.append(nn)
                self.dfs(node, nn, visited, dic)
