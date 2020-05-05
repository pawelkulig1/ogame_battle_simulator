#pragma once
class StaticStructure;
class Structure {
	using default_type = int;
	StaticStructure* m_ststructure_ptr;
	default_type m_hull;
	default_type m_shield;
	bool m_exploded;
public:
	Structure(StaticStructure *ststructure);
	bool attack(Structure &another);
	bool is_exploding() const;
};

