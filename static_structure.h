#pragma once
#include <map>

class StaticStructure {
	using default_type = int;
	int m_id;
	std::map<int, int> m_rapid_fire;
	default_type m_attack;
	default_type m_hull;
	default_type m_shield;
public:
    default_type get_attack() const;
    default_type get_hull() const;
    default_type get_shield() const;
    int get_id() const;
    int get_rapid_fire(int id) const;
};