//Nihal Sahu
//Conway's Game of Life

#include <iostream>
#include <vector>

using namespace std;

int ruleCheck(int cell, int neighbourCells);
void printGen(const vector<vector<int>>& someVector);

int main() {
    int gridSize, numGen, neighbours{0}, numAlive, cellLocation;    //declaring variables for grid size, number of generations, number of neighbours, number of initial alive cells, and alive cell locations.

    cout << "Enter the size of the grid: "; //asking the user to input the size of the grid
    cin >> gridSize;

    if (gridSize <= 0) {
        cout << "Grid size must be greater than 0. Try again." << endl; //data sanitization for if the inputted grid size is not a whole number greater than 0. the program will end if this happens.
        return 0;
    }

    vector <vector<int>> grid(gridSize);    //declaration of grid (represents the old generation)
    vector <vector<int>> tempGrid(gridSize);    //declaration of temporary grid (holds values for the current generation)

    for (int i = 0; i < gridSize; i++) {    //fills both grids with 0 to start
       for (int j = 0; j < gridSize; j++) {
           grid[i].push_back(0);
           tempGrid[i].push_back(0);
       }
    }

    cout << "Enter the amount of initial alive cells (must be in between 1 & " << gridSize * gridSize << "): "; //asks the user to input how many initial alive cells they want
    cin >> numAlive;

    if (numAlive < 1 || numAlive > gridSize * gridSize) {
        cout << "The number of initial alive cells must be within 1 & " << gridSize * gridSize << ". Try again." << endl;   //data sanitization if the number alive cells is less than 1 or exceeds the amount of possilble cells in the grid
        return 0;
    }

    for (int i = 0; i < numAlive; i++) {    //loop which asks the user to input the location of each alive cell. the loop runs for the amount of initial alive cells that the user previously inputted.
        cout << "Enter the location of alive cell (must be between 0 & " << gridSize * gridSize << "): ";
        cin >> cellLocation;

        if (cellLocation < 0 || cellLocation > gridSize * gridSize) {
            cout << "Location must be within bounds." << endl;  //data sanitization if the inputted cell location is not within the grids bounds
            i--;
            continue;
        }

        grid[cellLocation / gridSize][cellLocation % gridSize] = 1; //replaces the cell location value from 0 to 1 (dead to alive)
    }

    cout << "Enter the number of generations: ";    //asks the user to input the number of generations that the neighbourhood will evolve for
    cin >> numGen;

    if (numGen <= 0) {
        cout << "The number of generations must be greater than 0. Try again." << endl; //data sanitization if the user inputs any number of generations below 1. the program will end if this happens.
        return 0;
    }

    for (int currentGen = 0; currentGen <= numGen; currentGen++) {  //loop which runs once for each generation

        cout << endl << "Generation " << currentGen << endl;

        printGen(grid); //function call which prints the current generation

        for (int row = 0; row < gridSize; row++) {  //loop which runs for each row of the grid within one generation
            for (int column = 0; column < gridSize; column++) { //loop which runs for each column of the grid within one generation

                if (row == 0 && column == 0) {  //if the current cell being checked is in the top left corner. checks if the three possible neighbour cells are dead or alive.
                    if (grid[row][column + 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column + 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column] == 1)
                        neighbours++;
                }
                else if (row == 0 && column == gridSize - 1) {  //if the current cell being checked is in the top right corner. checks if the three possible neighbour cells are dead or alive.
                    if (grid[row][column - 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column - 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column] == 1)
                        neighbours++;
                }
                else if (row == gridSize - 1 && column == 0) {  //if the current cell being checked is in the bottom left corner. checks if the three possible neighbour cells are dead or alive.
                    if (grid[row - 1][column] == 1)
                        neighbours++;

                    if (grid[row - 1][column + 1] == 1)
                        neighbours++;

                    if (grid[row][column + 1] == 1)
                        neighbours++;
                }
                else if (row == gridSize - 1 && column == gridSize - 1) {   //if the current cell being checked is in the bottom right corner. checks if the three possible neighbour cells are dead or alive.
                    if (grid[row - 1][column] == 1)
                        neighbours++;

                    if (grid[row - 1][column - 1] == 1)
                        neighbours++;

                    if (grid[row][column - 1] == 1)
                        neighbours++;
                }
                else if (row == 0) {    //if the current cell being checked is in the top row. checks if the five possible neighbour cells are dead or alive.
                    if (grid[row][column - 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column - 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column] == 1)
                        neighbours++;

                    if (grid[row + 1][column + 1] == 1)
                        neighbours++;

                    if (grid[row][column + 1] == 1)
                        neighbours++;
                }
                else if (row == gridSize - 1) {     //if the current cell being checked is in the bottom row. checks if the five possible neighbour cells are dead or alive.
                    if (grid[row][column - 1] == 1)
                        neighbours++;

                    if (grid[row - 1][column - 1] == 1)
                        neighbours++;

                    if (grid[row - 1][column] == 1)
                        neighbours++;

                    if (grid[row - 1][column + 1] == 1)
                        neighbours++;

                    if (grid[row][column + 1] == 1)
                        neighbours++;
                }
                else if (column == 0) {     //if the current cell being checked is in the left most column. checks if the five possible neighbour cells are dead or alive.
                    if (grid[row - 1][column] == 1)
                        neighbours++;

                    if (grid[row - 1][column + 1] == 1)
                        neighbours++;

                    if (grid[row][column + 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column + 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column] == 1)
                        neighbours++;

                }
                else if (column == gridSize - 1) {      //if the current cell being checked is in the right most column. checks if the five possible neighbour cells are dead or alive.
                    if (grid[row - 1][column] == 1)
                        neighbours++;

                    if (grid[row - 1][column - 1] == 1)
                        neighbours++;

                    if (grid[row][column - 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column - 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column] == 1)
                        neighbours++;
                }
                else {      //if the current cell being checked is NOT on the edge of the grid. checks if the eight possible neighbour cells are dead or alive.
                    if (grid[row - 1][column] == 1)
                        neighbours++;

                    if (grid[row - 1][column + 1] == 1)
                        neighbours++;

                    if (grid[row][column + 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column + 1] == 1)
                        neighbours++;

                    if (grid[row + 1][column] == 1)
                        neighbours++;

                    if (grid[row + 1][column - 1] == 1)
                        neighbours++;

                    if (grid[row][column - 1] == 1)
                        neighbours++;

                    if (grid[row - 1][column - 1] == 1)
                        neighbours++;

                }

                tempGrid[row][column] = ruleCheck(grid[row][column], neighbours);   //the current cell being checked has its value and amount of neighbour cells passed into the ruleCheck function, will determine if the cell will be alive or dead in the next generation.
                neighbours = 0;     //sets the maount of alive neighbour cells to 0
            }
        }

        grid = tempGrid;  //after all cells in the current gen have been checked, the old generation changes into the generation that was just checked.
    }

    return 0;
}

int ruleCheck (int cell, int neighbourCells) {

    if (cell == 0) {    //if the cell is dead
        if (neighbourCells == 3) {      //checks for breeding rule. if it does not have exactly three alive neighbour cells, the cell will remain dead.
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (cell == 1) {   //if the cell is alive
        if (neighbourCells == 2 || neighbourCells == 3) {   //checks for just right rule. if so, the cell will remain alive.
            return 1;
        }
        else if (neighbourCells < 2 || neighbourCells > 3) {  //checks for underpopulation or overpopulation rule. if so the cell will die in the next generation.
            return 0;
        }
    }

}

void printGen(const vector<vector<int>>& someVector) {  //function which prints the current generation grid.

    for(vector<int> row : someVector) {
        for(int elem : row) {
            cout << elem << " ";
        }

        cout << endl;
    }

}
