#include <iostream>

using std::cout;
using std::endl;
using std::cin;

const int NUM_CELLS = 10;
const int LINES = NUM_CELLS + 1;

bool game_over = false;
bool horizontal_lines[LINES][NUM_CELLS];
bool vertical_lines[NUM_CELLS][LINES];
int current_x = 0;
int current_y = 0;
int align = 1; // horizontal

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

    cout << NUM_CELLS << "  ";
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
        current_y -= 1;
        break;
    case 6: // right
        current_y += 1;
        break;
    case 8: // up
        current_x -= 1;
        break;
    case 5: // down
        current_x += 1;
        break;
    case 7: // rotate
        align *= -1;
        break;
    case 9: // select
        if (align == 1)
        {                   
            horizontal_lines[current_x][current_y] = true;
        } 
        else
        {
            vertical_lines[current_x][current_y] = true;
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
        
        cin >> key;
        processKey(key);        
    }
    
    return 0;
}