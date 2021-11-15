#pragma once
#include <SDL2/SDL.h>
#include "Window.h"
#include "Core.h"

namespace Chess {
    enum file
    {
        FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE
    };

    enum rank
    {
        RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE
    };

    enum layout {
        A1 = 21, B1, C1, D1, E1, F1, G1, H1,
        A2 = 31, B2, C2, D2, E2, F2, G2, H2,
        A3 = 41, B3, C3, D3, E3, F3, G3, H3,
        A4 = 51, B4, C4, D4, E4, F4, G4, H4,
        A5 = 61, B5, C5, D5, E5, F5, G5, H5,
        A6 = 71, B6, C6, D6, E6, F6, G6, H6,
        A7 = 81, B7, C7, D7, E7, F7, G7, H7,
        A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
    };

    class Board : public Window {
        public:
            void Render();
            void Resize();
            int GetBoardHeight(){ return BoardYBoxes * BoxHeightY; }
            int GetBoardWidth(){ return BoardXBoxes * BoxWidthX; }
            int m_Sq120To64[BOARD_SQ_NUM];
            int m_Sq64To120[64];
            void PrintAllBoards();
        private:
            SDL_Color m_Dark = {93,50,49,1};
            SDL_Color m_Light = {121,72,57,1};
            SDL_Rect m_Rect;
            int BoardXBoxes = 8;
            int BoardYBoxes = 8;
            int BoxWidthX = Window::Width / BoardXBoxes;
            int BoxHeightY = Window::Height / BoardYBoxes;
            // we need to use two boards
            // 1 with the normal 64 squares
            // 1 with 120 squares to detect if piece is out of bounds 
            // they need to be able to talk to each other
        private:
            uint64_t m_ShiftMe = 1ULL;
            int m_File;
            int m_Rank;
            int m_Sq = 0;
            int m_Sq64 = 0;
		    uint64_t m_BitBoard = 0ULL; 
            void Init120SqTo64();
            void Print120Sq();
            void PrintBitBoard(uint64_t bb);
    };
}
