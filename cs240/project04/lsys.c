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
int currY = 299;
double currH = 0.0;
int length = 1;

int minX = 300;
int maxX = 0;
int minY = 300;
int maxY = 0;

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

// FUNCTION DECLARATIONS >>>
char* getRule(char c);
double degreesToRadians(double angle);
void drawLine();
void move();
void drawAxiom(char* axiom, double angle);
void scaleAxiom(char* axiom, double angle);
char* getRule(char c);
state* initState(int x, int y, double heading);
void loadState(state *s);
void push(state *s);
state* pop();
void drawFractal(char* axiom, double heading, double angle, int depth, int fractalNumber);
// <<< FUNCTION DECLARATIONS

// ANGLE OPERATIONS >>>
double degreesToRadians(double angle)
{
    return (angle * M_PI / 180.0);
}

double radiansToDegrees(double angle)
{
    return (angle * 180.0 / M_PI);
}
// <<< ANGLE OPERATIONS

// AXIOM OPERATIONS >>>
void drawLine()
{
    int x1, y1, x2, y2;
    
    x1 = currX;
    y1 = currY;
    x2 = currX + ceil(length * cos(currH));
    y2 = currY + ceil(length * sin(currH));
    
    if (x1 == x2)
    {
        if (y2 > y1)
        {
            int i;
            for (i = y1; i <= y2; i++)
                bmp_set_pixel(bmp, x1, i, pixelW);
        }
        else
        {
            int i;
            for (i = y1; i >= y2; i--)
                bmp_set_pixel(bmp, x1, i, pixelW);
        }
    }
    else if (y1 == y2)
    {
        if (x2 > x1)
        {
            int i;
            for (i = x1; i <= x2; i++)
                bmp_set_pixel(bmp, i, y1, pixelW);
        }
        else
        {
            int i;
            for (i = x1; i >= x2; i--)
                bmp_set_pixel(bmp, i, y1, pixelW);
        }
    }
    else
    {
        if (x2 > x1)
        {
            int i;
            for (i = x1; i <= x2; i++)
            {
                int y;
                y = tan(currH) * (i - x2) + y1;
                bmp_set_pixel(bmp, i, y, pixelW);
            }
        }
        else
        {
            int i;
            for (i = x1; i >= x2; i--)
            {
                int y;
                y = tan(currH) * (i - x1) + y1;
                bmp_set_pixel(bmp, i, y, pixelW);
            }
        }
    }
    
    currX = x2;
    currY = y2;
}

void measure()
{
    int x1, y1, x2, y2;
    
    x1 = currX;
    y1 = currY;
    x2 = currX + ceil(length * cos(currH));
    y2 = currY + ceil(length * sin(currH));
    
    if (x2 < minX) minX = x2;
    if (x2 > maxX) maxX = x2;
    if (y2 < minY) minY = y2;
    if (y2 > maxY) maxY = y2;
    
    currX = x2;
    currY = y2;
}

void move()
{
    int x1, y1, x2, y2;
    
    x1 = currX;
    y1 = currY;
    x2 = currX + ceil(length * cos(currH));
    y2 = currY + ceil(length * sin(currH));
    
    if (x2 < minX) minX = x2;
    if (x2 > maxX) maxX = x2;
    if (y2 < minY) minY = y2;
    if (y2 > maxY) maxY = y2;
    
    currX = x2;
    currY = y2;
}

void rotate(double angle)
{
    currH = currH + angle;
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
            rotate(-1 * angle);
        else if (axiom[i] == '-')
            rotate(angle);
        else if (axiom[i] == '[')
            push(initState(currX, currY, currH));
        else if (axiom[i] == ']')
            loadState(pop());
    }
}

void scaleAxiom(char* axiom, double angle)
{
    int size;
    size = strlen(axiom);
    
    int i;
    for (i = 0; i < size; i++)
    {
        if (axiom[i] == 'F')
            measure();
        else if (axiom[i] == 'f')
            move();
        else if (axiom[i] == '+')
            rotate(-1 * angle);
        else if (axiom[i] == '-')
            rotate(angle);
        else if (axiom[i] == '[')
            push(initState(currX, currY, currH));
        else if (axiom[i] == ']')
            loadState(pop());
    }
    
    int height;
    height = maxY - minY;
    
    int width;
    width = maxX - minX;
    
    if (height > width)
        length = 300 / height;
    else
        length = 300 / width;
}
// <<< AXIOM OPERATIONS

// FRACTAL OPERATIONS >>>
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

void drawFractal(char* axiom, double heading, double angle, int depth, int fractalNumber)
{
    currX = 149 + (300 * fractalNumber);
    currY = 299;
    currH = heading;
    
    minX = 300;
    maxX = 0;
    minY = 300;
    maxY = 0;
    
    int dim;
    dim = depth;
    if (depth == 0)
        dim = 1;
    
    char masterAxiom[MAX_RULES * dim * MAX_CHARS];
    strcpy(masterAxiom, axiom);
    
    char rule[MAX_RULES * dim * MAX_CHARS];
    char after[MAX_RULES * dim * MAX_CHARS];
    
    int i;
    for (i = 0; i < depth; i++)
    {
        int j;
        for (j = 0; j < strlen(masterAxiom); j++)
        {
            if ('A' <= masterAxiom[j] && masterAxiom[j] <= 'Z' ||
                'a' <= masterAxiom[j] && masterAxiom[j] <= 'z')
            {
                if (masterAxiom[j] != 'F' &&
                    masterAxiom[j] != 'f')
                {
                    strcpy(rule, getRule(masterAxiom[j]));
                    strcpy(after, masterAxiom+(j + 1));
                    
                    strcpy(masterAxiom+j, rule);
                    strcpy(masterAxiom+(j + strlen(rule)), after);
                    
                    j = j + strlen(rule) + 1;
                }
            }
        }
    }
    
    scaleAxiom(masterAxiom, angle);
    
    currX = 149 + (300 * fractalNumber);
    currY = 299;
    currH = heading;
    
    stackIndex = -1;
    
    drawAxiom(masterAxiom, angle);
}
// <<< FRACTAL OPERATIONS

// STACK OPERATIONS >>>
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
    currX = (int)s->x;
    currY = (int)s->y;
    currH = (double)s->heading;
}

void push(state *s)
{
    stack[stackIndex + 1] = s;
    stackIndex++;
}

state* pop()
{
    state *tmp;
    tmp = stack[stackIndex];
    
    stack[stackIndex] == NULL;
    stackIndex--;
    
    return tmp;
}
// <<< STACK OPERATIONS

// IMAGE FILE OPERATIONS >>>
void resetImage(int width, int height)
{
    int x, y;
    for (x = 1; x <= width; x++)
        for (y = 1; y <= height; y++)
            bmp_set_pixel(bmp, x, y, pixelB);
}
// <<< IMAGE FILE OPERATIONS

int main()
{
	int numFractals;    
    scanf("%d", &numFractals);
    
    int depth;
    double angle, heading;
    char axiom[MAX_CHARS];
    
    bmp = bmp_create(300 * numFractals, 300, 32);
    resetImage(300 * numFractals, 300);
    
    int i;
    for (i = 0; i < numFractals; i++)
    {
        scanf("%d", &depth);
        scanf("%lf", &angle); 
        scanf("%lf", &heading);
        
        angle = degreesToRadians(angle);
        currH = degreesToRadians(heading);
        
        scanf("%s", axiom);
        scanf("%d", &numRules);
        
        int j;
        for (j = 0; j < numRules; j++)
        {
            char tmp[2];
            scanf("%s -> %s\n", tmp, rules[j]);
            codes[j] = tmp[0];
        }
        
        drawFractal(axiom, heading, angle, depth, i);
    }
    
    bmp_save(bmp, "output.bmp");
	bmp_destroy(bmp);
}
