#include <iostream>
#include "Board.h"

namespace Chess {
	void Board::Render()
	{
        m_Rect.w = BoxWidthX;
        m_Rect.h = BoxHeightY;
        for(int x = 0; x < BoardXBoxes; x++){
            for(int y = 0; y < BoardYBoxes; y++){
                SDL_Color Color = (x + y) % 2 == 0 ? m_Dark : m_Light;
				m_Rect.x = x * BoxWidthX; 
				m_Rect.y = y * BoxHeightY;
                SDL_SetRenderDrawColor(Window::Renderer, Color.r, Color.g, Color.b, Color.a);
				SDL_RenderFillRect(Window::Renderer, &m_Rect);
                Window::LoadTextureImage("assets/textures/r256.png");
                SDL_RenderCopy(Window::Renderer, Window::Texture, NULL, &m_Rect);
            }
        }
        SDL_RenderPresent(Window::Renderer);
	}

    void Board::Init120SqTo64(){
        m_File = FILE_A;
        m_Rank = RANK_1;
        m_Sq = A1;

        for(int i = 0; i < BOARD_SQ_NUM; i++){
            m_Sq120To64[i] = 65;
        }
        for(int i = 0; i < 64; i++){
            m_Sq64To120[i] = 120;
        }
        for(m_Rank = RANK_1; m_Rank <= RANK_8; m_Rank++){
            for(m_File = FILE_A; m_File <= FILE_H; m_File++){
                m_Sq = FR2SQ(m_File, m_Rank);
                m_Sq64To120[m_Sq64] = m_Sq;
                m_Sq120To64[m_Sq] = m_Sq64;
                m_Sq64++;
            }
        }
    }

    void Board::Print120Sq(){
		std::cout << "120 SQ BOARD:" << std::endl;
        for(int i = 0; i < BOARD_SQ_NUM; i++){
            if(i % 10 == 0) std::cout << std::endl;
            printf("%5d", m_Sq120To64[i]);
        }
        std::cout << std::endl;
        std::cout << std::endl;

		std::cout << "Normal Board:" << std::endl;
		for(int i = 0; i < 64; i++){
			if(i % 8 == 0) std::cout << std::endl;
			printf("%5d", m_Sq64To120[i]);
		}
        std::cout << std::endl;
        std::cout << std::endl;

    }

	void Board::PrintBitBoard(uint64_t bb){
		for(m_Rank = RANK_8; m_Rank >= RANK_1; m_Rank--){
			for(m_File = FILE_A; m_File <= FILE_H; m_File++){
				m_Sq = FR2SQ(m_File, m_Rank); // 120 based index
				m_Sq64 = m_Sq120To64[m_Sq]; // convert to 64 based board

				if((m_ShiftMe << m_Sq64) & bb)
					//std::cout << "X";
					printf("%5s", "X");
				else
					//std::cout << "-";
					printf("%5s", "-");
			}
			std::cout << std::endl;
		}
	}

	//https://stackoverflow.com/questions/30680559/how-to-find-magic-bitboards
    int Board::PopBits(uint64_t *bb) {
        uint64_t b = *bb ^ (*bb - 1);
        unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
        *bb &= (*bb - 1);
        return BitTable[(fold * 0x783a9b23) >> 26];
    }

    int Board::CountBits(uint64_t b) {
		int i;
		for(i = 0; b; i++, b &= b - 1);
		return i;
	}

    void Board::InitBitMasks(){

        for(int i = 0; i < 64; i++){
            m_SetMask[i] = 0ULL;
            m_ClearMask[i]  = 0ULL;
        }

        for(int i = 0; i < 64; i++){
            m_SetMask[i] |= (1ULL << i);
            m_ClearMask[i] = ~m_SetMask[i];
        }
    }

	void Board::PrintAllBoards(){
		Init120SqTo64();
		Print120Sq();
		
        /*
		m_BitBoard |= (1ULL << m_Sq120To64[D2]);
		m_BitBoard |= (1ULL << m_Sq120To64[D3]);
		m_BitBoard |= (1ULL << m_Sq120To64[D4]);

		PrintBitBoard(m_BitBoard);
		while(m_BitBoard){
			m_Sq64 = PopBits(&m_BitBoard);
			std::cout << "popped: " << m_Sq64 << std::endl;
			PrintBitBoard(m_BitBoard);
        }
        */
        InitBitMasks();
        SETBIT(m_BitBoard, 61);
        PrintBitBoard(m_BitBoard);
	}


}
