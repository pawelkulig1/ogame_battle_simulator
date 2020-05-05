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
	StaticStructure();
    default_type get_attack() const;
    default_type get_hull() const;
    default_type get_shield() const;
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
	REAPER = 9,
	PATHFINDER = 10,
	RECYCLER = 11,
	ESPIONAGE_PROBE = 12,
	SOLAR_SATELLITE = 13,
	COLONY_SHIP = 14,
	CRAWLER = 15,
	//DEFENCE
	ROCKET_LAUNCHER = 16,
	LIGHT_LASER = 17,
	HEAVY_LASER = 18,
	ION_CANNON = 19,
	GAUSS_CANNON = 20,
	PLASMA_TURRET = 21,
	SMALL_DOME_SHIELD = 22,
	LARGE_DOME_SHIELD = 23,
};
