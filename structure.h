#pragma once

class StaticStructure;

class Structure
{
	using default_type = int;
	StaticStructure *m_ststructure_ptr;
	default_type m_hull;
	default_type m_shield;
	bool m_exploded;

	int get_rapid_fire(Structure &another);

public:
	Structure(StaticStructure *ststructure);
	bool attack(Structure &another);
	bool check_if_explodes();
	bool prepare_for_new_round();
	int get_id() const;
	bool is_exploded() const;
};
