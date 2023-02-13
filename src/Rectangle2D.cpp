#include "Rectangle2D.hpp"

template<typename componentT>
Rectangle2D<componentT>::Rectangle2D(vector2<componentT>& position,vector2<componentT>& size)
{
    this->position = position;
    this->size = size;
}
template<typename componentT>
Rectangle2D<componentT>::Rectangle2D(Rectangle2D& rect)
{
    this->position = rect.position;
    this->size = rect.size;
}