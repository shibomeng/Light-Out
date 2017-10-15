# Light-Out

• new n Creates a new n ⇥ n grid, where n   1. If there was already an active grid, that grid is destroyed and replaced with the new one.

• init Enters initialization mode. Subsequently, read pairs of integers r c and set the cell at row r, column c as on. The top-left corner is row 0, column 0. The coordinates -1 -1 end initialization mode. It is possible to enter initialization mode more than once, and even while the game is running. When initialization mode ends, the board should be displayed.

• game g Once the board has been initialized, this command starts a new game, with a commitment to solve the game in g moves or fewer.

• switch r c Within a game, switches the cell at row r, column c on or o↵, and then redisplays the grid.
