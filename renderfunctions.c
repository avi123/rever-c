#include <stdio.h>
#include <string.h>
#include "renderfunctions.h"

void decompose(long unsigned int moves,long unsigned int decomposedmoves[]) {
    int i=0,j=0;

    while(moves) {
        (moves & 1) ? (decomposedmoves[j++] = ((long unsigned int)1 << i)) : 0;
        moves >>= 1;
        i++;
    }
}

long unsigned int getadjacent(long unsigned int board) {
    return ((board << 1) | (board >> 1) | (board << 8) | (board >> 8) | (board << 7) | (board >> 7) | (board << 9) | (board >> 9)) ^ board;
}

long unsigned int getempty(long unsigned int black, long unsigned int white) {
    return ~(black|white);
}

long unsigned int getmove() {
    int i = 0,c,x,y;
    char move[5];

    printf("Enter your move in the form x,y or EXIT to exit\n");
    printf("1,1 is the top left corner\n\n");

    while((c = getchar()) != '\n' && i < 5) {
        move[i] = c;
        i++;
    }

    if(i < 3)
        return 0;

    x = move[0] - '0';
    y = move[2] - '0';
  
    if(strcmp(move,"VALID")==0) {
        return VALID;
    }
    else if(strcmp(move,"EMPTY")==0) {
        return EMPTY; 
    } 
    else if(strcmp(move,"EXIT")==0) {
        return EXIT;
    }
    else if((x > 0) && (x < 9) && (y > 0) && (y < 9) && (move[1] == ',')) {
        return ((long int)1 << (x - 1 + (y - 1) * 8)); 
    }
    else {
        return 0;
    }
}

void render(long unsigned int black, long unsigned int white) {
    int row,column;
    char blackletter = (white != 0 ? 'B' : 'X');

    horizontalline(ROWLENGTH);
    for(row = 1; row <= 8; row++) {
        printf("|"); 
        for(column = 1; column <= 8; column++, black>>=1, white>>=1) {
            if(black & 1)
                printf(" %c |",blackletter);
            else if(white & 1)
                printf(" W |");
            else
                printf("   |");
        }
        printf("\n");
        horizontalline(ROWLENGTH);
    }
}

void horizontalline(int charlength) {
    int i;

    for(i = 1; i <= charlength; i++)
        printf("-");
    printf("\n");
}

int highestbit() {
    long unsigned int i = 1;
    int j;

    for(j=0;i!=0;j++)
        i<<=1;

    return j;
}

int numofmoves(long unsigned int moves) {
    int i=0;

    while(moves) {
        moves &= (moves - 1);
        i++;
    }

    return i;
}
