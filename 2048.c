//
//  main.c
//  2048
//
//  Created by vonking on 14-7-3.
//  Copyright (c) 2014年 vonking. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//#include <linux/timer.h>

#define FRAME_SIZE 4
#define FRAME_ALL (FRAME_SIZE)*(FRAME_SIZE)

typedef enum eDir{
UP,
DOWN,
LEFT,
RIGHT
}DIRECT_E;

int generateNum(void)
{
    if (rand() % 2 == 0) {
        return 2;
    }
    else
    {
        return 4;
    }
}

void printFrame(int frame[][4])
{
    int i, j;
    printf("================\r\n");
    for (i = 0; i < FRAME_SIZE; i++) {
        for (j = 0; j < FRAME_SIZE; j++) {
	    if (0 != frame[i][j]) {
                printf("%4d", frame[i][j]);
	    }
	    else {
		printf("  - ");
	    }
        }
        printf("\r\n");
    }
    printf("================\r\n");
}

void tightframe(int frame[][4])
{
    int i, j;
    return;
}

void moveup(int frame[][4])
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < FRAME_SIZE; i++) {        
        for (j = 0; j < FRAME_SIZE; j++) {
            if (frame[j][i] == 0)
            {
                for(; j < FRAME_SIZE - 1; j++)
                {
                    frame[j][i] = frame[j+1][i];
                }
                frame[j][i] = 0;
                j = 0;
            }
        }
    }
    printFrame(frame);
    for (i = 0; i < FRAME_SIZE; i++) {
        
        for (j = 0; j < FRAME_SIZE; j++) {
            if (frame[i][j] == frame[i][j + 1]) {
                frame[i][j] += frame[i][j + 1];
                for (k = j + 1; k < FRAME_SIZE - 1; k++) {
                    frame[i][k] = frame[i][k+1];
                }
            }
        }
    }
    printFrame(frame);
    return ;
}

void movedown(int frame[][4])
{
    return ;
}

void moveleft(int frame[][4])
{
    return ;
}

void moveright(int frame[][4] )
{
    return ;
}

void update(int frame[][4], DIRECT_E dir)
{
    int i;
    int k;
    int num = 0;
    int truepos;
    int newpos[4] = {0};
    int value = rand() % 4;
    switch (dir)
    {
	case UP:
	     newpos[0] = 11;
	     newpos[1] = 12;
	     newpos[2] = 13;
	     newpos[3] = 14;
	     break;
	case LEFT:
	     newpos[0] = 3;
	     newpos[1] = 7;
	     newpos[2] = 11;
	     newpos[3] = 15;
	     break;
	case DOWN:
	     newpos[0] = 0;
	     newpos[1] = 1;
	     newpos[2] = 2;
	     newpos[3] = 3;
	     break;
	case RIGHT:
	     newpos[0] = 0;
	     newpos[1] = 4;
	     newpos[2] = 8;
	     newpos[3] = 12;
	     break;
        default:
             break;
    }
    for(i = 0; i < FRAME_SIZE; i++)
    {
        k = newpos[rand()%FRAME_SIZE];
        if (frame[k/4][k%4]==0) {
           num++;
	}
    }
 
    if (3 == num) {
	printf("input anthor direction!\r\n");
	return;
    }

    for(i = 0; i < FRAME_SIZE; i++)
    {
        k = newpos[rand()%FRAME_SIZE];
        if (frame[k/4][k%4] == 0) {
            frame[k/4][k%4] = generateNum();
	    break;
	}

    }
   
    return ;
}

int main(int argc, const char * argv[])
{
    char c;
    int pos;
    int pre[FRAME_SIZE][FRAME_SIZE] = {0};
    
    /* initial data */
    //srand((int)timer(0));
    pos = rand() % FRAME_ALL;
    pre[pos/FRAME_SIZE][pos%FRAME_SIZE] = generateNum();
    
    do
    {
        printFrame(pre);
        c = getchar();
        if (c == 'w' ) {
	    printf("%c\r\n", c);
            moveup(pre);
            update(pre, UP);
        }
        else if (c == 'a') {
            moveleft(pre);
            update(pre, LEFT);
        }
        else if (c == 's') {
            movedown(pre);
            update(pre, DOWN);
        }else if (c == 'd') {
            moveright(pre);
            update(pre, RIGHT);
        }else if (c == '\n'){
	    /* do nothing */
	}else {
	    printf("%c\r\n", c);
            printf("error character\r\n");
        }
    } while (c != 'q');
        
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

