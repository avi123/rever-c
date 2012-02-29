#include <stdio.h>
#include <string.h>

#define EMPTY ((long unsigned int)1 << 63) + 2
#define EXIT ((long unsigned int)1 << 63) + 1
#define VALID ((long unsigned int)1 << 63) + 4
#define INIT_WHITE ((((long unsigned int)1 << 9) + 1) << 27)
#define INIT_BLACK ((((long unsigned int)1 << 7) + 1) << 28)
#define MAXMOVES 64
#define ROWLENGTH 33

enum currentcolor { BLACK, WHITE };
void decompose(long unsigned int moves,long unsigned int decomposedmoves[]);
long unsigned int getadjacent(long unsigned int board);
long unsigned int getempty(long unsigned int black, long unsigned int white);
long unsigned int getmove();
int numofmoves(long unsigned int moves);
int highestbit();
void horizontalline(int charlength);
void render(long unsigned int black, long unsigned int white);
