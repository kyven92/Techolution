#include <iostream>
#include <fstream>
#include <algorithm> 

using namespace std;


/***
 * Thought Process towards Dungeon Solution:
 * 
 * This problem is approach is similar to reaching points problem, where reaching the destination follows a pattern either right or down
 * Even this problem can be solved by tracing the path approach with given constraints but
 * this problem is constrained by cumulative cost of path, hence
 * one have to store the path cost which will help for choosing the direction while navigating
 * 
 * ***/
 

 /***
  * Method:
  * This problem will be solved bottom to up approach using dynamic programming for storing the cost of the path
  * ***/




int find_KnightMinHealth(int **roomsGrid,int rows,int columns)
{
    // As I am solving this problem using Dynamic Programming, I have to create a similar size array to store the cost matrix
    int dp[rows][columns]; 
    int m = rows, n = columns; 
  
    // As logic starts from the point where princess starts, after entering Knight should atleast have 1 health point 
    dp[m-1][n-1] = roomsGrid[m-1][n-1] > 0? 1:abs(roomsGrid[m-1][n-1]) + 1; 
  
    // Fill last row and last column as base to fill entire table 
    // max logic is used in case zero points or large positive points in the cell, in which case knight needs minimum of only 1 point
    for (int i = m-2; i >= 0; i--) 
         dp[i][n-1] = max(dp[i+1][n-1] - roomsGrid[i][n-1], 1); 

    for (int j = n-2; j >= 0; j--) 
         dp[m-1][j] = max(dp[m-1][j+1] - roomsGrid[m-1][j], 1); 
  
    // fill the table in bottom-up fashion 
    for (int i=m-2; i>=0; i--) 
    { 
        for (int j=n-2; j>=0; j--) 
        {
            //min logic is used for to compute choose minimum required points for knight to enter which will inturn used to compute the current cell
            int min_health_on_exit = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(min_health_on_exit - roomsGrid[i][j], 1);
        }
     } 
  
     return dp[0][0]; 


}


int main()
{
    int rows =0,columns=0;

    // reading the input file and populating the matrix
    ifstream inputFile("inputs.txt");
    inputFile>>rows>>columns;

    // for passing a 2D array as an argument to the find_KnightMinHealth method we need to create a double pointer interpretation
    int **roomsGrid = new int *[rows];

    for(int i=0;i<rows;i++)
    {
        //allocating memory blocks for colums
        roomsGrid[i]= new int[columns];
    }


    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            inputFile>>roomsGrid[i][j];
            // std::cout<<"Rooms Grid: "<<roomsGrid[i][j]<<endl;
        }
    }

    


    std::cout<<"Knights Minimum Health: "<<find_KnightMinHealth(roomsGrid,rows,columns)<<endl;
}