#include <stdio.h>

struct maze_t{
	int x, y;
	int maze[100][100];
};
typedef struct maze_t maze_t;
struct point_t{
	int x, y;
};
typedef struct point_t point_t;

point_t route[100];
point_t exitPoint;

int solveMaze(maze_t maze, point_t start, point_t end);
int main(){
	maze_t maze;
	int i, j;
	int length;
	point_t start, exit;
	
	scanf("%d %d", &maze.x, &maze.y);
	for (i = 0; i < maze.x; ++i) {
		for (j = 0; j < maze.y; ++j) {
			scanf("%d", &maze.maze[i][j]);
		}
	}
	start.x = start.y = 1;
	exit.x = maze.x - 2;
	exit.y = maze.y - 2;
	length = solveMaze(maze, start, exit);
	
	for (i = 0; i < length; i++){
		printf("(%d, %d) -> ", route[i].x, route[i].y);
	}
	printf("\n");
	return 0;
}

void setExit(int x, int y)
{
	exitPoint.x = x;
	exitPoint.y = y;
}
int reachExit(int x, int y)
{
	return exitPoint.x == x && exitPoint.y == y;
}
void stepOn(maze_t maze, int x, int y)
{
	maze.maze[x][y] = 1;
}
void stepBack(maze_t maze, int x, int y)
{
	maze.maze[x][y] = 0;
}
int findAvailStep(point_t availStep[4], maze_t maze, int x, int y)
{
	int stepAvail = 0;
	int i, j;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i * j == 0 && maze.maze[x + i][y + j] <= 0)
			{// <= 0 means can be step on
				availStep[stepAvail++] = (point_t) { x + i, y + j };
			}
		}
	}
	return stepAvail;
}
int tryStep(maze_t maze, int x, int y, int step)
{
	point_t availStep[4];
	int availCount;
	int result;
	int i;
	if (reachExit(x, y))
	{
		point_t tmp = {x, y};
		route[step] = tmp;
		return step;
	}
	else
	{
		stepOn(maze, x, y);
		availCount = findAvailStep(availStep, maze, x, y);
		if (availCount == 0)
		{
			stepBack(maze, x, y);
			return -1;
		}
		else
		{
			for (i = 0; i < availCount; i++)
			{
				result = tryStep(maze, availStep[i].x, availStep[i].y, step + 1);
				if (result != -1)
				{
					point_t tmp = {x, y};
					route[step] = tmp;
					return result;
				}
				else
				{
					stepBack(maze, availStep[i].x, availStep[i].y);
				}
			}
			return -1;
		}
	}
}
int solveMaze(maze_t maze, point_t start, point_t end)
{
	setExit(end.x, end.y);
	return tryStep(maze, start.x, start.y, 0);
}
