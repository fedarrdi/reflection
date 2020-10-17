#include<stdio.h>
#include <stdbool.h>

//-------------------------------------------------------------------------------------------------

#define GRIDSIZE 30
#define CIRCLESIM 'o'
#define VECTORSIM '='
#define DIST(x, y, x1, y1) (x - x1)*(x - x1) + (y - y1)*(y - y1)
#define CHECK(x, y, x1, y1) \
int curr_dist = dist[y1][x1] + 1;\
if(!vis[y][x] || dist[y][x] > curr_dist)\
{\
    dist[y][x] = curr_dist;shortest_path(x, y, x1, y1, vis, dist);\
}

#define CHECK1(x, y) \
if(find_path(x, y, x1, y1, d + 1, dist, path))\
{\
    path[y][x] = 1;\
    return 1;\
}

//--------------------------------------------------------------------------------------------------

char space[GRIDSIZE][GRIDSIZE];

void fill_space()
{
    for(int y = 0;y < GRIDSIZE;y++)
        for(int x = 0;x < GRIDSIZE;x++)
        {   
            if(x == 0 || y == 0 || x == GRIDSIZE - 1 || y == GRIDSIZE - 1)
                space[y][x] = '#';
            else 
                space[y][x] = ' ';
        }
}

void print_space()
{
    for(int y = 0;y < GRIDSIZE;y++)
    {
        for(int x = 0;x < GRIDSIZE;x++)
        {
            printf("%c ", space[y][x]);       
        }
        printf("\n");
    }
}

//-----------------------------------------------------------------------------------------------------

void draw_circle(int Ox, int Oy, int r)
{
    for(int y = 1;y < 2*r;y++)
        for(int x = 1;x < 2*r;x++)
        {
            int currx = Ox - r + x;
            int curry = Oy - r + y; 
            if(DIST(currx, curry, Ox, Oy)  <= r*r)
                if (currx > 0 && curry > 0 &&  currx < GRIDSIZE && curry <  GRIDSIZE)
                    space[curry][currx] = CIRCLESIM;
        }
}

//-----------------------------------------------------------------------------------------------------

void shortest_path(int x, int y, int x1, int y1, bool *vis, int *dist)
{   
    vis[y][x] = 1;

    if(x == x1 && y == y1 || DIST(x, y, x1, y1) == 0){ return; }

    if(x + 1 < GRIDSIZE - 1){ CHECK(x + 1, y, x, y) }
    if(x - 1 > 0){ CHECK(x - 1, y, x , y) }
    if(y + 1 < GRIDSIZE - 1){ CHECK(x, y + 1, x, y) }
    if(y - 1 > 0){ CHECK(x, y - 1, x, y) }
    if(x + 1 < GRIDSIZE - 1 && y + 1 < GRIDSIZE - 1){ CHECK(x + 1, y + 1, x, y) }
    if(x - 1 > 0 && y - 1 > 0){ CHECK(x - 1, y - 1, x , y) }
    if(y + 1 < GRIDSIZE - 1 &&  x - 1 > 0){ CHECK(x - 1, y + 1, x, y) }
    if(y - 1 > 0 && x + 1 < GRIDSIZE - 1){ CHECK(x + 1, y - 1, x, y) }
    
}

int find_path(int x, int y, int x1, int y1, int d, const int *dist, int *path)
{
    if(x == x1 && y == y1 && d == dist[y1][x1])
        return 1;

    if(d == dist[y1][x1])
        return 0;
 
    if(x + 1 < GRIDSIZE - 1){ CHECK1(x + 1, y) }
    if(x - 1 > 0){ CHECK1(x - 1, y) }
    if(y + 1 < GRIDSIZE - 1){ CHECK1(x, y + 1) }
    if(y - 1 > 0){CHECK1(x, y - 1) }
    if(x + 1 < GRIDSIZE - 1 && y + 1 < GRIDSIZE - 1){  CHECK1(x + 1, y + 1) }
    if(x - 1 > 0 && y - 1 > 0){  CHECK1(x - 1, y - 1)}
    if(y + 1 < GRIDSIZE - 1 &&  x - 1 > 0){  CHECK1(x - 1, y + 1) }
    if(y - 1 > 0 && x + 1 < GRIDSIZE - 1){  CHECK1(x + 1, y - 1) }

}

void draw_vector(int x, int y, int x1, int y1)
{
    bool vis[GRIDSIZE][GRIDSIZE];
    long long dist[GRIDSIZE][GRIDSIZE];
    int path[GRIDSIZE][GRIDSIZE];
    
    for(int i = 1;i < GRIDSIZE;i++)
        for(int j = 1;j < GRIDSIZE;j++)
        {
            vis[i][j] = 0;
            dist[i][j] = 1e6;
            path[i][j] = -1;
        }


    vis[y][x] = 1;
    dist[y][x] = 0;
    shortest_path(x, y, x1, y1, vis, dist);
    find_path(x1, y1, x, y, 0, dist, path);
    
    for(int y = 0;y < GRIDSIZE;y++)
        for(int x = 0;x < GRIDSIZE;x++)
            if(path[y][x] != -1 && x != 0 && y != 0 && x != GRIDSIZE - 1 && y != GRIDSIZE - 1)
                space[y][x] = VECTORSIM;
} 


void move_vector(int x, int y, int x1, int y1,int px, int py)
{
    space[y][x] = ' ';
    space[y1][x1] = ' ';
    for(int i = 1;i < GRIDSIZE - 1;i++)
        for(int j = 1;j < GRIDSIZE - 1;j++)
            if(space[i][j] = VECTORSIM)
                space[y + py][x + px] = VECTORSIM;
}

//------------------------------------------------------------------------------------------------------


struct Line{ int x;int y;int x1;int y1;int

int are2LinesColliding()
{

}

//-----------------------------------------------------------------------------------------------------
int main()
{

    return 0;
}


