#pragma once
class Item
{
public:
	Item() { m_statBoost = 0; };
	Item(float damageBoost) { m_statBoost = damageBoost; }
	float getStatusBoost() { return m_statBoost; }

private:
	float m_statBoost = 0;
};