#pragma once

#define DEBUG
#ifdef DEBUG
    #define ASSERT(n) \
    if(!(n)){ \
        printf("%s - Failed ", #n); \
        printf("On %s ", __DATE__); \
        printf("At %s ", __TIME__); \
        printf("In File: %s ", __FILE__); \
        printf("At Line: %d\n",__LINE__); \
        exit(1); \
    }
#else
    #define ASSERT(n)
#endif

#define u64 uint64_t

#define MAX_GAME_MOVES 2048

// separate board to detect if piece is out of bounds 
#define BOARD_SQ_NUM 120

// returns 120 array based number for the out of bounds board
#define FR2SQ(file, rank) ( (21 + (file) ) + ( (rank) * 10 ))

// Bit Masks
#define SETBIT(bb, m_Sq) ((bb) |= m_SetMask[(m_Sq)])
#define CLEARBIT(bb, m_Sq) ((bb) &= m_ClearMask[(m_Sq)])
