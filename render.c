#include <stdio.h>
#define WHITE ((((long int)1 << 9) + 1) << 27)
#define BLACK ((((long int)1 << 7) + 1) << 28)
#define ROWLENGTH 33

void horizontalline(int charlength);
void render(long int black, long int white);

int main() {
    render(BLACK,WHITE);
}

void render(long int black, long int white) {
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
