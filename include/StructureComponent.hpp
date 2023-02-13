#include "vector2.hpp"
#include "Rectangle2D.hpp"

template<typename numericT>
class StructureComponent : public BaseComponent, public Rectangle2D<numericT>
{
	/*
	- can be controlled by it's parent
	- can have freedom of control
	(when processing)
	(free,controlled) | (relative,absolute)
	relative : the position is relative to the parent position
	absolute : the position is relative to the main component (window)
	free : the child can have its position uncontrolled by the parent
	controlled : the child position and size is controlled by the parent

	when a component is controlled , most likly the position is relative to the parent ignoring the options
	*/
public:
	StructureComponent(Rectangle2D& rect);
	StructureComponent(Rectangle2D& rect,BaseComponent* parent);
	StructureComponent(vector2<componentT> position,vector2<componentT> size);
	StructureComponent(vector2<componentT> position,vector2<componentT> size,BaseComponent* parent);
private:
};