#include "vector2.hpp"

template<typename componentT>
class Rectangle2D
{
public:
	vector2<componentT> position;
	vector2<componentT> size;
	Rectangle2D(vector2<componentT>& position,vector2<componentT>& size);
	Rectangle2D(Rectangle2D& rect);
	//TODO : implement some functionality
private:
};