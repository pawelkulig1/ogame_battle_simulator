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
    StaticStructure();
	StaticStructure(std::map<int, int> rapid_fire, default_type attack, default_type hull, default_type shield);
    default_type get_attack() const;
    default_type get_hull() const;
    default_type get_shield() const;
    int get_id() const;
    int get_rapid_fire(int id) const;
};

enum ID {
	SMALL_CARGO = 0,
	LARGE_CARGO = 1,
	LIGHT_FIGHTER = 2,
	HEAVY_FIGHTER = 3,
	CRUISER = 4,
	BATTLESHIP = 5,
	BATTLECRUISER = 6,
	BOMBER = 7,
	DESTROYER = 8,
	DEATHSTAR = 9,
	REAPER = 10,
	PATHFINDER = 11,
	RECYCLER = 12,
	ESPIONAGE_PROBE = 13,
	SOLAR_SATELLITE = 14,
	COLONY_SHIP = 15,
	CRAWLER = 16,

	//DEFENCE

	ROCKET_LAUNCHER = 17,
	LIGHT_LASER = 18,
	HEAVY_LASER = 19,
	ION_CANNON = 20,
	GAUSS_CANNON = 21,
	PLASMA_TURRET = 22,
	SMALL_DOME_SHIELD = 23,
	LARGE_DOME_SHIELD = 24,
    SIZE
};
