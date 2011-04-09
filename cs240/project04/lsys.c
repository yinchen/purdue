#include <stdio.h>
#include <math.h>
#include "bmpfile.h"

#define MAX_RULES 50
#define MAX_CHARS 300
#define MAX_STACK 50

// global image file variables
bmpfile_t *bmp;
rgb_pixel_t pixelW = {255, 255, 255, 0};
rgb_pixel_t pixelB = {0, 0, 0, 0};

// global drawing variables
int currX = 0;
int currY = 0;
double currH = 0.0;
int length = 25;

// global fractal variables
int numRules;
char codes[MAX_RULES];
char rules[MAX_RULES][MAX_CHARS];

// global stack variables
typedef struct 
{
    int x;
    int y;
    double heading;
} state;

int stackIndex = -1;
state* stack[MAX_STACK];

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
void loadState(state *s);
void push(state *s);
state* pop();
void drawFractal(char* axiom, double angle, int depth);
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
            bmp_set_pixel(bmp, x1, i, pixelB);
    }
    else if (y1 == y2)
    {
        int i;
        for (i = x1; i <= x2; i++)
            bmp_set_pixel(bmp, i, y1, pixelB);
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
    
    // DEBUG
    printf("drawAxiom(%s, %f) called\n", axiom, angle);
    
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
            loadState(pop()); // pop
        else if ('A' <= axiom[i] && axiom[i] <= 'Z' ||
                 'a' <= axiom[i] && axiom[i] <= 'z')
            drawAxiom(getRule(axiom[i]), angle);
        else if (axiom[i] == 0)
            return;
        else
        {
            //printf("ERROR: Encountered invalid axiom command %c\n", axiom[i]);
            //exit(1);
            return;
        }
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

void drawFractal(char* axiom, double angle, int depth)
{
    // int i;
    // for (i = 0; i < depth; i++)
    // {
        drawAxiom(axiom, angle);
    // }
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

void loadState(state *s)
{
    // DEBUG
    printf("loadState() called\n");
    
    currX = (int)&s->x;
    currY = (int)&s->y;
    // currH = (double)s->heading;
}

void push(state *s)
{
    // DEBUG
    printf("push() called\n");
    
    stack[stackIndex + 1] = s;
}

state* pop()
{
    state *tmp;
    tmp = stack[stackIndex];
    
    stack[stackIndex] == NULL;
    stackIndex--;
    
    return tmp;
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
    
    bmp = bmp_create(300 * numFractals, 300, 32);
    
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
            char tmp[2];
            scanf("%s -> %s\n", tmp, rules[j]);
            codes[j] = tmp[0];
        }
        
        drawFractal(axiom, angle, depth);
    }
    
    bmp_save(bmp, "output.bmp");
	bmp_destroy(bmp);
}

