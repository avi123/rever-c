#include <stdio.h>
#include <string.h>

#define EXIT ((long unsigned int)1 << 63) + 1
#define INIT_WHITE ((((long unsigned int)1 << 9) + 1) << 27)
#define INIT_BLACK ((((long unsigned int)1 << 7) + 1) << 28)
#define ROWLENGTH 33

enum currentcolor { BLACK, WHITE };
long unsigned int getmove();
void horizontalline(int charlength);
void render(long unsigned int black, long unsigned int white);

int main() {
    int currentcolor = BLACK;
    long unsigned int blackboard = INIT_BLACK,whiteboard = INIT_WHITE,move;
    render(blackboard,whiteboard);

    while((move = getmove()) != EXIT)
    {
        if(move == 0) {
            printf("Invalid Entry\n");
        }
        else {
            currentcolor == BLACK ? (blackboard |= move) : (whiteboard |= move);
        }
        render(blackboard,whiteboard);
    }        
}

long unsigned int getmove() {
    int i = 0,c,x,y;
    char move[4];

    printf("Enter your move in the form x,y or EXIT to exit\n");
    printf("1,1 is the top left corner\n\n");

    while((c = getchar()) != '\n' && i < 4) {
        move[i] = c;
        i++;
    }

    if(i < 3)
        return 0;

    x = move[0] - '0';
    y = move[2] - '0';
    
    if(strcmp(move,"EXIT")==0) {
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

    horizontalline(ROWLENGTH);
    for(row = 1; row <= 8; row++) {
        printf("|"); 
        for(column = 1; column <= 8; column++, black>>=1, white>>=1) {
            if(black & 1)
                printf(" B |");
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
