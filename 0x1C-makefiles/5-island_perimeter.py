#!/usr/bin/python3

Args:
grid (list[list[int]]): A rectangular grid with integers representing land and water zones.

Returns:
int: The perimeter of the island.

Raises:
ValueError: If the grid is invalid or contains more than one island.

"""
rows = len(grid)
cols = len(grid[0])

# check if the grid is valid
if rows < 1 or rows > 100 or cols < 1 or cols > 100:
    raise ValueError("Invalid grid size")

# find the first land cell
found_land = False
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == 1:
            found_land = True
            start_cell = (i, j)
            break
    if found_land:
        break

# check if there is more than one island
visited = set()
queue = [start_cell]
while queue:
    curr_cell = queue.pop(0)
    if curr_cell in visited:
        continue
    visited.add(curr_cell)
    i, j = curr_cell
    if grid[i][j] == 0:
        continue
    if i > 0:
        queue.append((i-1, j))
    if i < rows-1:
        queue.append((i+1, j))
    if j > 0:
        queue.append((i, j-1))
    if j < cols-1:
        queue.append((i, j+1))

if len(visited) != sum(row.count(1) for row in grid):
    raise ValueError("More than one island")

# count the perimeter of the island
perimeter = 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == 1:
            if i == 0 or grid[i-1][j] == 0:
                perimeter += 1
            if i == rows-1 or grid[i+1][j] == 0:
                perimeter += 1
            if j == 0 or grid[i][j-1] == 0:
                perimeter += 1
            if j == cols-1 or grid[i][j+1] == 0:
                perimeter += 1

return perimeter
