#include "GameObject.hpp"

GameObject::GameObject() {};

template <typename T>
void GameObject::addComponent(T* component)
{
	// must update a bitset 
	// must update a array of components
	// both for more easy access on the components

	std::unique_ptr<Component> uPtr{ component };
	components.emplace_back(uPtr)
}

template <typename T>
T& GameObject::getComponent(T* component)
{
}