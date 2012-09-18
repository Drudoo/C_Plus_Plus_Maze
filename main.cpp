//
//  Copyright 2012 the original author or authors.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
//
//  main.cpp
//  Maze
//
//  Created by Frederik Vanggaard on 9/17/12.
//
//  Contact: contact@drudoo.com
//
//

#include "main.h"
#include <iostream>
#include <ctime>

using namespace std;

void generateMaze();
void getPlayerInput();
void updateMaze();
void updateMazeWithoutEnemies();
void solveMaze();

struct gameUser {
    int health = 10;
    char player;
    int attack = 2;
};

struct enemyOne {
    int health = 5;
    char enemy = 'J';
    int attack = 2;
};

struct enemyTwo {
    int health = 3;
    char enemy = 'T';
    int attack = 1;
    
};

struct enemyThree {
    int health = 3;
    char enemy = 'K';
    int attack = 3;
};

int posX;
int posY;
int exitPosX;
int exitPosY;
int prevX;
int prevY;
int enemy1PosX;
int enemy1PosY;
int enemy2PosX;
int enemy2PosY;
int enemy3PosX;
int enemy3PosY;

const char HEIGHT = 10, WIDTH = 10;
const char player = 'X';
const char endExit = 'E';
//char maze[10][10];
unsigned char maze[WIDTH][HEIGHT] = {
    '#','#','#','#','#','#','#','#','#','#',
    '#',' ','#','#','#','#','#','#','#','#',
    '#',' ',' ',' ','#',' ',' ',' ','#','#',
    '#','#','#',' ','#',' ','#',' ','#','#',
    '#','#','#',' ','#',' ','#',' ','#','#',
    '#',' ',' ',' ',' ',' ','#',' ','E','#',
    '#',' ','#',' ','#',' ','#','#','#','#',
    '#','#','#',' ','#',' ','#','#','#','#',
    '#',' ',' ',' ','#',' ',' ',' ','#','#',
    '#','#','#','#','#','#','#','#','#','#'
};



int main () {
    
    char newGameChoice, solverChoice;
    bool gameOver(false), firstGame(true);
    
    srand((unsigned)time(NULL));
    
    ::posX = 1;
    ::posY = 1;
    ::exitPosX = 5;
    ::exitPosY = 8;
    
    ::enemy1PosX = 8;
    ::enemy1PosY = 5;
    
    ::enemy2PosX = 5;
    ::enemy2PosY = 3;
    
    ::enemy3PosX = 4;
    ::enemy3PosY = 7;
    
    do {
               
        if (!firstGame) {
            cout << "Do you whish to play again?" << endl;
            cout << "y or n" << endl;
            cin >> newGameChoice;
            
            if (newGameChoice == 'y') {
                return main();
            } else {
                return 0;
            }
        }
        
        cout << "Do you wish to let the computer solve the maze?" << endl;
        cout << "y or n" << endl;
        cin >> solverChoice;
        
        
        if (solverChoice == 'y') {
           
            
            while (1) {
                sleep(1);

                updateMazeWithoutEnemies();
                solveMaze();

                if (maze[posX][posY]=='E') {
                    cout << "\n\nMAZE SOLVED!\n\n";
                    break;
                }
            }
            
            gameOver = true;
            firstGame = false;
            
        } else {
            
            updateMaze();

            while (1) {
                getPlayerInput();
                updateMaze();
                
                if (maze[posX][posY]=='E') {
                    break;
                }

            }
            
                cout << "\nYOU WON!\n" << endl;
                gameOver = true;
                firstGame = false;

        
            /*
             
             1) Start at a random cell in the grid.
             2) Look for a random neighbor cell you haven't been to yet.
             3) If you find one, move there, knocking down the wall between the cells. If you don't find one, back up to the previous cell.
             4) Repeat steps 2 and 3 until you've been to every cell in the grid.
             
             */
            
        }
        
        
        
    } while (gameOver);
    
    return 0;
}


void generateMaze() {
    
}


void getPlayerInput() {
    
    char keyPress;
    cin >> keyPress;
    
    switch (keyPress) {
        case 'a':
            //move left
            if (maze[posX-1][posY] == '#') {
                cout << "ERROR!";
            } else {
                posX = posX -1;
            }
            cout << "\n" << posX << " , " << posY << "\n";
            break;
        case 'd':
            //move right
            if (maze[posX+1][posY] == '#') {
                cout << "ERROR!";
            } else {
                posX = posX +1;
            }
            cout << "\n" << posX << " , " << posY << "\n";
            break;
        case 'w':
            //move up
            if (maze[posX][posY-1] == '#') {
                cout << "ERROR!";
            } else {
                posY = posY -1;
            }
            cout << "\n" << posX << " , " << posY << "\n";
            break;
        case 's':
            //move down
            if (maze[posX][posY+1] == '#') {
                cout << "ERROR!";
            } else {
                posY = posY +1;
            }
            cout << "\n" << posX << " , " << posY << "\n";
            break;
            
        default:
            cout << "\n\nPress something!\n\n";
            break;
    }
    
}

void updateMaze() {
    unsigned char maze[WIDTH][HEIGHT] = {
        '#','#','#','#','#','#','#','#','#','#',
        '#',' ','#','#','#','#','#','#','#','#',
        '#',' ',' ',' ','#',' ',' ',' ','#','#',
        '#','#','#',' ','#',' ','#',' ','#','#',
        '#','#','#',' ','#',' ','#',' ','#','#',
        '#',' ',' ',' ',' ',' ','#',' ','E','#',
        '#',' ','#',' ','#',' ','#','#','#','#',
        '#','#','#',' ','#',' ','#','#','#','#',
        '#',' ',' ',' ','#',' ',' ',' ','#','#',
        '#','#','#','#','#','#','#','#','#','#'
    };
    
    maze[enemy1PosX][enemy1PosY] = '@';
    maze[enemy2PosX][enemy2PosY] = '%';
    maze[enemy3PosX][enemy3PosY] = '$';
    maze[posX][posY] = player;
    maze[exitPosX][exitPosY] = endExit;

    
    for (int y=0; y<HEIGHT; y++) {
        cout << endl;
        for (int x=0; x<WIDTH; x++) {
            cout << maze[x][y];
        }
    }

}

void updateMazeWithoutEnemies() {
    unsigned char maze[WIDTH][HEIGHT] = {
        '#','#','#','#','#','#','#','#','#','#',
        '#',' ','#','#','#','#','#','#','#','#',
        '#',' ',' ',' ','#',' ',' ',' ','#','#',
        '#','#','#',' ','#',' ','#',' ','#','#',
        '#','#','#',' ','#',' ','#',' ','#','#',
        '#',' ',' ',' ',' ',' ','#',' ','E','#',
        '#',' ','#',' ','#',' ','#','#','#','#',
        '#','#','#',' ','#',' ','#','#','#','#',
        '#',' ',' ',' ','#',' ',' ',' ','#','#',
        '#','#','#','#','#','#','#','#','#','#'
    };
    
    maze[exitPosX][exitPosY] = endExit;
    maze[posX][posY] = player;

    
    for (int y=0; y<HEIGHT; y++) {
        cout << endl;
        for (int x=0; x<WIDTH; x++) {
            cout << maze[x][y];
        }
    }
}


void solveMaze() {
    maze[posX][posY] = '.';
    
    if ((maze[posX-1][posY] != '#') && (maze[posX-1][posY] != '.')) {
        posX = posX -1;
    }

    else if ((maze[posX][posY+1] != '#') && (maze[posX][posY+1] != '.')) {
        posY = posY +1;
    }
    
    else if ((maze[posX+1][posY] != '#') && (maze[posX+1][posY] != '.')) {
        posX = posX +1;
        
    }
    
    else if ((maze[posX][posY-1] != '#') && (maze[posX][posY-1] != '.')) {
        posY = posY -1;
    }
    
    cout << "\n" << posX << " , " << posY << "\n";

}
