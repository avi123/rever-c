#include <stdio.h>
#include <string.h>
#include "renderfunctions.h"

#define EMPTY ((long unsigned int)1 << 63) + 2
#define EXIT ((long unsigned int)1 << 63) + 1
#define VALID ((long unsigned int)1 << 63) + 4
#define INIT_WHITE ((((long unsigned int)1 << 9) + 1) << 27)
#define INIT_BLACK ((((long unsigned int)1 << 7) + 1) << 28)
#define MAXMOVES 64
#define ROWLENGTH 33

int main() {
    if(highestbit() < 64) {
        printf("ERROR: Your system does not support 64bit integers\n");
        return 0;
    }
    else if(highestbit() > 64) {
        printf("WARNING: Your system's long unsigned integers are longer than 64bits");
    } 
    
    int currentcolor = BLACK;
    long unsigned int blackboard = INIT_BLACK,whiteboard = INIT_WHITE,move;
    render(blackboard,whiteboard);

    while(1)
    {
        long unsigned int possiblemoves,possiblemovesdecomposed[MAXMOVES];
        int numofpossiblemoves;

        switch(move = getmove()) {
            case EMPTY:
                render(getempty(blackboard,whiteboard),0);
                break; 
            case EXIT:
                return;
            case VALID:
                possiblemoves = ((currentcolor == BLACK ? getadjacent(whiteboard) : getadjacent(blackboard)) & getempty(blackboard,whiteboard));
                render(possiblemoves,0);
                numofpossiblemoves = numofmoves(possiblemoves);

                printf("Number of Possible Moves: %i\n",numofpossiblemoves);
                decompose(possiblemoves,possiblemovesdecomposed);

                int i;
                for(i=0;i<numofpossiblemoves;i++) {
                    render(possiblemovesdecomposed[i],0);
                }
                break;
            case 0:
                printf("Invalid Entry\n");
                break;
            default:
                currentcolor == BLACK ? (blackboard |= move) : (whiteboard |= move);
                break;
        }
        render(blackboard,whiteboard);
    }        
}
