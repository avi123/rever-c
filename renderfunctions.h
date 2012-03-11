#include <stdio.h>
#include <string.h>


#define EDGE_TOP ((long unsigned int)1 << 8) - 1
#define EDGE_BOTTOM (((long unsigned int)1 << 8) - 1) << 56
#define EDGE_LEFT ((long unsigned int)1 << 56) + ((long unsigned int)1 << 48) + ((long unsigned int)1 << 40) + ((long unsigned int)1 << 32) + ((long unsigned int)1 << 24) + ((long unsigned int)1 << 16) + ((long unsigned int)1 << 8) + (long unsigned int)1 
#define EDGE_RIGHT EDGE_LEFT << 7

#define EXIT ((long unsigned int)1 << 63) + 1
#define EMPTY ((long unsigned int)1 << 63) + 2
#define VALID ((long unsigned int)1 << 63) + 4
#define EDGE ((long unsigned int)1 << 63) + 8
#define INIT_WHITE ((((long unsigned int)1 << 9) + 1) << 27)
#define INIT_BLACK ((((long unsigned int)1 << 7) + 1) << 28)
#define MAXMOVES 64
#define ROWLENGTH 33

enum currentcolor { BLACK, WHITE };

/* breaks bitboard down into array of individual spaces */
void decompose(long unsigned int moves,long unsigned int decomposedmoves[]);

/* return a bitboard of adjacent spaces to bitboard */
long unsigned int getadjacent(long unsigned int board);

/* return a bitboard of empty spaces */
long unsigned int getempty(long unsigned int black, long unsigned int white);

/* prompts the user for a move or command */
long unsigned int getmove();

/* return the number of individual moves represented by a moves bitboard */
int numofmoves(long unsigned int moves);

/* return the number of bits in a long unsigned integer */
int highestbit();

/* render a horizontal line of specified length */
void horizontalline(int charlength);

/* render the current board, or a map of moves, if only black is specified */
void render(long unsigned int black, long unsigned int white);
