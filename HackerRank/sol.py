#!/usr/bin/python
# Head ends here
def getGraphLocationsForPair(grid, row_col, x=0, y=0):
    pos = []
    [pacman_x, pacman_y] = map(int,row_col.split(" "))
    if pacman_x>0 and grid[pacman_x-1][pacman_y]!='%':
        elm = " ".join([str(x) for x in [pacman_x-1, pacman_y]])
        pos = pos + [elm]
    if pacman_y<y-1 and grid[pacman_x][pacman_y+1]!='%':
        elm = " ".join([str(x) for x in [pacman_x, pacman_y+1]])
        pos = pos + [elm]
    if pacman_y>0 and grid[pacman_x][pacman_y-1]!='%':
        elm = " ".join([str(x) for x in [pacman_x, pacman_y-1]])
        pos = pos + [elm]
    if pacman_x<x-1 and grid[pacman_x+1][pacman_y]!='%':
        elm = " ".join([str(x) for x in [pacman_x+1, pacman_y]])
        pos = pos + [elm]
    return pos
def find_shortest_path(grid, start, end, x, y, path=[]):
        path = path + [start]
        if start == end:
            return path
        shortest = None
        pos = getGraphLocationsForPair(grid, start, x, y)
        for node in pos:
            if node not in path:
                newpath = find_shortest_path(grid, node, end, x, y, path)
                if newpath:
                    if not shortest or len(newpath) < len(shortest):
                        shortest = newpath
        return shortest
def dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid):
    pc=" ".join([str(x) for x in [pacman_r, pacman_c]])
    fd=" ".join([str(x) for x in [food_r, food_c]])
    return find_shortest_path(grid, pc, fd, r, c)
# Tail starts here
pacman_r, pacman_c = [ int(i) for i in raw_input().strip().split() ]
food_r, food_c = [ int(i) for i in raw_input().strip().split() ]
r,c = [ int(i) for i in raw_input().strip().split() ]
 
grid = []
for i in xrange(0, r):
    grid.append(raw_input().strip())
 
path=dfs(r, c, pacman_r, pacman_c, food_r, food_c, grid)
print len(path)
for pos in path:
    print pos

