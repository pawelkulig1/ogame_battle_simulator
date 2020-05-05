#pragma once
#include <map>

class StaticStructure {
	using default_type = int;
	default_type id;
	std::map<default_type, default_type> rapid_fire;
	default_type m_attack;
	default_type m_hull;
	default_type m_shield;
public:
    default_type get_attack() const;
    default_type get_hull() const;
    default_type get_shield() const;
};