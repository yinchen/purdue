#include <stdio.h>
#include <math.h>
#include "bmpfile.h"

#define MAX_RULES 50
#define MAX_CHARS 300

bmpfile_t *bmp;
rgb_pixel_t pixelW = {255, 255, 255, 0};
rgb_pixel_t pixelB = {0, 0, 0, 0};

int currX = 0;
int currY = 0;
double currH = 0.0;
int length = 1;

int numRules;
char codes[MAX_RULES];
char rules[MAX_RULES][MAX_CHARS];

typedef struct 
{
    int x;
    int y;
    double heading;
} state;

//
// FUNCTION DECLARATIONS >>>
//
char* getRule(char c);
double degreesToRadians(double angle);
void drawLine();
void move();
void drawAxiom(char* axiom, double angle);
char* getRule(char c);
state* initState(int x, int y, double heading);
void push(state *s);
state pop();
//
// <<< FUNCTION DECLARATIONS
//

//
// ANGLE OPERATIONS >>>
//
double degreesToRadians(double angle)
{
    return (angle * M_PI / 180.0);
}
//
// <<< ANGLE OPERATIONS
//

//
// AXIOM OPERATIONS >>>
//
void drawLine()
{
    int x1, y1, x2, y2;
    
    x1 = currX;
    y1 = currY;
    x2 = length * cos(currH);
    y2 = length * sin(currH);
    
    if (x1 == x2)
    {
        int i;
        for (i = y1; i <= y2; i++)
            bmp_set_pixel(bmp, x1, i, pixelW);
    }
    else if (y1 == y2)
    {
        int i;
        for (i = x1; i <= x2; i++)
            bmp_set_pixel(bmp, i, y1, pixelW);
    }
    else if (abs(x2 - x1) > abs(y2 - y1))
    {
        // y = (dy/dx)x + c
    }
    else if (abs(x2 - x1) < abs(y2 - y1))
    {
        // x = (dx/dy)y + c
    }
    
    currX = x2;
    currY = y2;
}

void move()
{
    int x1, y1, x2, y2;
    
    x1 = currX;
    y1 = currY;
    x2 = length * cos(currH);
    y2 = length * sin(currH);
    
    currX = x2;
    currY = y2;
}

void drawAxiom(char* axiom, double angle)
{
    int size;
    size = strlen(axiom);
    
    int i;
    for (i = 0; i < size; i++)
    {
        if (axiom[i] == 'F')
            drawLine();
        else if (axiom[i] == 'f')
            move();
        else if (axiom[i] == '+')
            currH = currH + angle;
        else if (axiom[i] == '-')
            currH = currH - angle;
        else if (axiom[i] == '[')
            push(initState(currX, currY, currH)); // push
        else if (axiom[i] == ']')
            pop(); // pop
        else
            drawAxiom(getRule(axiom[i]), angle);
    }
}
//
// <<< AXIOM OPERATIONS
//

//
// FRACTAL OPERATIONS >>>
//
char* getRule(char c)
{
    int i = 0;
    for (i = 0; i < MAX_RULES; i++)
    {
        int match = 0;
        
        if (codes[i] == c)
            return rules[i];
    }
    
    return NULL;
}
//
// <<< FRACTAL OPERATIONS
//

//
// STACK OPERATIONS >>>
//
state* initState(int x, int y, double heading)
{
    state *s = malloc(sizeof(state));
    s->x = x;
    s->y = y;
    s->heading = heading;
    return s;
}

void push(state *s)
{
    // do stuff
}

state pop()
{
    // do stuff
}
//
// <<< STACK OPERATIONS
//

int main()
{
	int numFractals;    
    scanf("%d", &numFractals);
    
    int depth;
    double angle, heading;
    char axiom[MAX_CHARS];
    
    int i;
    for (i = 0; i < numFractals; i++)
    {
        scanf("%d", &depth);
        scanf("%lf", &angle); 
        scanf("%lf", &heading);
        
        angle = degreesToRadians(angle);
        heading = degreesToRadians(heading);
        
        scanf("%s", axiom);
        scanf("%d", &numRules);
        
        int j;
        for (j = 0; j < numRules; j++)
        {
            scanf("%c -> %s\n", codes[j], rules[j]);
        }
    }
    
    bmp = bmp_create(300 * numFractals, 300, 32);

    
    
    bmp_save(bmp, "output.bmp");
	bmp_destroy(bmp);
}

