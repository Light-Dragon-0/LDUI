#include "BaseComponent.hpp"

BaseComponent::BaseComponent()
{
    this->parent = nullptr;
    this->children = std::list<BaseComponent*>();
}
BaseComponent::BaseComponent(BaseComponent* parent)
{
    this->parent = parent;
    this->children = std::list<BaseComponent*>();
}
void BaseComponent::addChild(BaseComponent* component)
{
    this->children.push_back(component);
}
void BaseComponent::removeChild(BaseComponent* component)
{
    this->children.remove(component);
}
BaseComponent* BaseComponent::getChild(long index)
{
    auto it = this->children.begin();
    std::advance(it, index);
    return *it;
}