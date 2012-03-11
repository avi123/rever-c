#include <stdio.h>
#include <string.h>
#include "renderfunctions.h"

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
        int i;

        switch(move = getmove()) {
            case EDGE:
                render(EDGE_TOP | EDGE_BOTTOM | EDGE_LEFT | EDGE_RIGHT,0);
                break;
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

                for(i=0;i<numofpossiblemoves;i++) {
                    render(possiblemovesdecomposed[i],0);
                }
                break;
            case 0:
                printf("Invalid Entry\n");
                break;
            default:
                possiblemoves = getadjacent(move) & (currentcolor == BLACK ? whiteboard : blackboard);
                render(possiblemoves,0);
                numofpossiblemoves = numofmoves(possiblemoves);

                printf("Number of Possible Directions: %i\n",numofpossiblemoves);
                decompose(possiblemoves,possiblemovesdecomposed);

                for(i=0;i<numofpossiblemoves;i++) {
                    printf("Direction: %i\n",getdirection(move,possiblemovesdecomposed[i]));
                    render(possiblemovesdecomposed[i],0);
                }
                currentcolor == BLACK ? (blackboard |= move) : (whiteboard |= move);
                break;
        }
        render(blackboard,whiteboard);
    }
}