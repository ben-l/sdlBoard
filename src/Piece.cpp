#include "Piece.h"

namespace Chess {
    Piece::Piece(std::string color, SDL_Texture* texture, float posx, float posy) 
        : m_Color(color), m_Texture(texture), m_PosX(posx), m_PosY(posy) {
    }
}
