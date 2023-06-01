#include<iostream>
#include<stdio.h>
using namespace std;
#define INFINITY 9999
#define max 6
void dijkstra(int Graph[max][max], int n, int startnode)
{
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, minDistance, nextnode, i, j;

    // Initialize the cost matrix and distance array
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];

    for(i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while(count < n - 1)
    {
        minDistance = INFINITY;

        for(i = 0; i < n; i++)
            if(distance[i] < minDistance && !visited[i])
            {
                minDistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        for(i = 0; i < n; i++)
            if(!visited[i])
                if(minDistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = minDistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }

        count++;
    }

    // Print the shortest distance and path to each node
    float sum = 0;
    for(i = 0; i < n; i++){
        if(i != startnode)
        {
            //cout << "Distance from City " << startnode << " to City " << i << " is: " << distance[i] << endl;
            //cout << "Path: " << i;
            //j = i;
            // do
            // {
            //     j = pred[j];
            //     cout << " <- " << j;
            // } while(j != startnode);
            // cout << endl;
            sum += distance[i];
        }
    }
    cout << "  " << startnode << "          " << sum/5.0 << endl;

}

int main(){
    int adjMatrix[max][max]={
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int n = 6;
    cout << "Cities   "  << "Average Time" << endl; 
    for(int i = 0; i < n; i++){
        dijkstra(adjMatrix, n, i);
    }
    return 0;
}