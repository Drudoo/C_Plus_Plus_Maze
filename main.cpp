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

#include <iostream>
using namespace std;

void generateMaze();
void getPlayerInput();
void updateMaze();


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

int main () {
    
    
    char newGameChoice, solverChoice;
    bool gameOver(false), firstGame(true);
    int posX = 0;
    int posY = 0;
    
    
    const char HEIGHT = 10, WIDTH = 10;
    const char player = 'X';
    //char maze[10][10];
    unsigned char maze[WIDTH][HEIGHT] = {
        ' ','#','#','#','#','#','#','#','#','#',
        ' ',' ','#',' ','#','#','#','#','#','#',
        '#',' ',' ',' ','#',' ',' ',' ','#','#',
        '#','#','#',' ','#',' ','#',' ','#','#',
        '#','#','#',' ','#',' ','#',' ','#','#',
        '#',' ',' ',' ',' ',' ','#',' ',' ',' ',
        '#',' ','#',' ','#','#','#','#','#',' ',
        '#','#','#',' ','#',' ','#','#','#',' ',
        '#',' ',' ',' ','#',' ',' ',' ','#',' ',
        '#','#','#','#','#','#','#','#','#','E'
    };
    
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
            //RUN SOLVE ALGORITHM
            
            
//            cout << "GAME HAS BEEN PLAYED YOU ARE DEAD" << endl;
//            gameOver = true;
//            firstGame = false;
            
        } else {
            do {

                
                
                for (int y=0; y<HEIGHT; y++) {
                    cout << endl;
                    for (int x=0; x<WIDTH; x++) {
                        cout << maze[x][y];
                    }
                }
                
                
                maze[posX][posY] = player;
                
                
                getPlayerInput();
                updateMaze();
                
            } while (maze[posX][posY] !='E');
            
//            cout << "GAME HAS BEEN PLAYED YOU ARE DEAD" << endl;
//            gameOver = true;
//            firstGame = false;
            
            
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

//void generateMaze() {
//    
//    const char HEIGHT = 10, WIDTH = 10;
//    const char player = 'X';
//    //char maze[10][10];
//    unsigned char maze[WIDTH][HEIGHT] = {
//        ' ','#','#','#','#','#','#','#','#','#',
//        ' ',' ','#',' ','#','#','#','#','#','#',
//        '#',' ',' ',' ','#',' ',' ',' ','#','#',
//        '#','#','#',' ','#',' ','#',' ','#','#',
//        '#','#','#',' ','#',' ','#',' ','#','#',
//        '#',' ',' ',' ',' ',' ','#',' ',' ',' ',
//        '#',' ','#',' ','#','#','#','#','#',' ',
//        '#','#','#',' ','#',' ','#','#','#',' ',
//        '#',' ',' ',' ','#',' ',' ',' ','#',' ',
//        '#','#','#','#','#','#','#','#','#','E'
//    };
//    for (int y=0; y<HEIGHT; y++) {
//        cout << endl;
//        for (int x=0; x<WIDTH; x++) {
//            cout << maze[x][y];
//        }
//    }
//    
//    int posX = 0;
//    int posY = 0;
//    maze[posX][posY] = player;
//    cout << player;
//    
//}

void getPlayerInput() {
    
    char keyPress;
    cin >> keyPress;
    
    switch (keyPress) {
        case 'a':
            //move left
            cout << keyPress;
            break;
        case 'd':
            //move right
            cout << keyPress;
            break;
        case 'w':
            //move up
            cout << keyPress;
            break;
        case 's':
            //move down
            cout << keyPress;
            break;
            
        default:
            cout << "\n\nPress something!\n\n";
            break;
    }
    
}

void updateMaze() {
    
    
}

