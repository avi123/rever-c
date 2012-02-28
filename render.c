#include <stdio.h>
#include <string.h>

#define EMPTY ((long unsigned int)1 << 63) + 2
#define EXIT ((long unsigned int)1 << 63) + 1
#define INIT_WHITE ((((long unsigned int)1 << 9) + 1) << 27)
#define INIT_BLACK ((((long unsigned int)1 << 7) + 1) << 28)
#define ROWLENGTH 33

enum currentcolor { BLACK, WHITE };
long unsigned int getempty(long unsigned int black, long unsigned int white);
long unsigned int getmove();
int highestbit();
void horizontalline(int charlength);
void render(long unsigned int black, long unsigned int white);

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
        switch(move = getmove()) {
            case EMPTY:
                render(getempty(blackboard,whiteboard),0);
                break; 
            case EXIT:
                return;
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
   
    if(strcmp(move,"EMPTY")==0) {
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
