#include <iostream>

using std::cout;
using std::endl;
using std::cin;

const int NUM_CELLS = 2;
const int LINES = NUM_CELLS + 1;

bool game_over = false;
bool horizontal_lines[LINES][NUM_CELLS];
bool vertical_lines[NUM_CELLS][LINES];
int current_x = 0;
int current_y = 0;
int align = 1; // horizontal
int squares = 0;

void init () 
{
    for (int i = 0; i <= LINES; i++)
    {
        for (int j = 0; j < LINES; j++)
        {
            horizontal_lines[i][j] = false;
            vertical_lines[j][i] = false;
        }        
    }
}

void display ()
{
    system("clear");
    cout << "    ";

    for (int i = 0; i < LINES; i++)
    {
        cout << i << "   ";
    }
    
    cout << endl << endl;
    for (int i = 0; i < NUM_CELLS; i++)
    {
        cout << i << "   ";
        for (int j = 0; j < NUM_CELLS; j++)
        {
            if (horizontal_lines[i][j])
            {
                cout << "+---";
            }
            else 
            {
                cout << "+   ";
            }            
        }
        cout << "+" << endl << "    ";
        
        for (int k = 0;  k < NUM_CELLS; k++)
        {
            if (vertical_lines[i][k])
            {
                cout << "|   ";
            }
            else
            {
                cout << "    ";
            }            
        }
        if (vertical_lines[i][NUM_CELLS])
        {
            cout << "|" << endl;
        }
        else
        {
            cout << " " << endl;
        } 
    }

    cout << NUM_CELLS << "   ";
    for (int i = 0; i < NUM_CELLS; i++)
    {
        if (horizontal_lines[NUM_CELLS][i])
        {
            cout << "+---";
        }
        else
        {
            cout << "+   ";
        }               
    }
    cout << "+" << endl << endl;
}

void processKey(int key)
{
    switch (key)
    {
    case 0:
        game_over = true;
        break;
    case 4: // left
        if (current_y == 0 && align == 1)
        {
            current_y = NUM_CELLS - 1;
        } else if (current_y == 0 && align == -1)
        {
            current_y = NUM_CELLS;
        } else
        {
            current_y--;
        }             
        
        break;
    case 6: // right
        if ((current_y == NUM_CELLS - 1 && align == 1) || (current_y == NUM_CELLS && align == -1))
        {
            current_y = 0;
        } else
        {
            current_y++;
        }
                
        break;
    case 8: // up
        if (current_x == 0 && align == -1)
        {
            current_x = NUM_CELLS - 1;
        } else if (current_x == 0 && align == 1)
        {
            current_x = NUM_CELLS;
        } else
        {
            current_x--;
        } 
        break;
    case 5: // down
        if ((current_x == NUM_CELLS - 1 && align == -1) || (current_x == NUM_CELLS && align == 1))
        {
            current_x = 0;
        } else
        {
            current_x++;
        }
        break;
    case 7: // rotate
        align *= -1;
        if (current_y == NUM_CELLS)
        {
            current_y--;
        } else if (current_x == NUM_CELLS)
        {
            current_x--;
        }
                
        break;
    case 9: // select
        if (align == 1)
        {                   
            horizontal_lines[current_x][current_y] = true;            
            if (current_x > 0 && horizontal_lines[current_x - 1][current_y] && vertical_lines[current_x - 1][current_y] && vertical_lines[current_x - 1][current_y + 1])
            {
                squares++;
            }                
        
            if (current_x < NUM_CELLS && horizontal_lines[current_x + 1][current_y] && vertical_lines[current_x][current_y] && vertical_lines[current_x][current_y + 1])
            {
                squares++;
            }                
        } 
        else
        {
            vertical_lines[current_x][current_y] = true;
            if (current_y > 0 && vertical_lines[current_x][current_y - 1] && horizontal_lines[current_x][current_y -1] && horizontal_lines[current_x + 1][current_y - 1])
            {
                squares++;
            }                

            if (current_y < NUM_CELLS && vertical_lines[current_x][current_y + 1] && horizontal_lines[current_x][current_y] && horizontal_lines[current_x + 1][current_y])
            {
                squares++;
            }                
       }        
        break;
    default:
        break;
    }
}

int main()
{    
    init();
    int key;

    while (!game_over)
    {
        display();
        cout << "Current position (" << current_x << "," << current_y << ")";
        (align == 1) ? cout << " horizontal" : cout << " vertical";
        cout << endl;
        cout << "Squares: " << squares << endl;

        cin >> key;
        processKey(key); 
        
        if(squares == NUM_CELLS * NUM_CELLS) 
        {
            display();
            cout << "Squares: " << squares << endl;
            cout << "Game Over!" << endl;
            game_over = true;
        }
    }
    
    return 0;
}