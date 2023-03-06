#pragma once

#include <vector>
#include <memory>
#include <bitset>

class Component;

constexpr std::size_t maxComponents = 32;

using Vector2D = std::vector<float, float>;
using Components = std::vector<std::unique_ptr<Component>>;
using ComponentsBitset = std::bitset<maxComponents>;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject() = 0;

	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;

private:
	Vector2D position;
	Components components;

protected:
	template <typename T> void addComponent(T* component);
	template <typename T> T& getComponent(T* component);
};