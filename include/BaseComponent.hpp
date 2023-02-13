#include <list>

class BaseComponent
{
public:
    BaseComponent();
    BaseComponent(BaseComponent* parent);
    void addChild(BaseComponent* component);
    void removeChild(BaseComponent* component);
    BaseComponent* getChild(long index);
private:
    BaseComponent* parent;
    std::list<BaseComponent*> children;
};