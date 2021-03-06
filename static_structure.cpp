#include "static_structure.h"

StaticStructure::StaticStructure()
{
}

StaticStructure::StaticStructure(std::map<int, int> rapid_fire, StaticStructure::default_type attack, StaticStructure::default_type hull, StaticStructure::default_type shield, StaticStructure::default_type cargo, StaticStructure::default_type fuel_cons, resources cost):
    m_rapid_fire(rapid_fire),
    m_attack(attack),
    m_hull(hull),
    m_shield(shield),
    m_cargo(cargo),
    m_fuel_cons(fuel_cons),
    m_cost(cost)
{
}

StaticStructure::default_type StaticStructure::get_attack() const
{
    return m_attack;
}

StaticStructure::default_type StaticStructure::get_hull() const
{
    return m_hull;
}

StaticStructure::default_type StaticStructure::get_shield() const
{
    return m_shield;
}

void StaticStructure::set_id(int id)
{
    m_id = id;
}

StaticStructure::default_type StaticStructure::get_cargo() const
{
    return m_cargo;
}

StaticStructure::default_type StaticStructure::get_fuel_cons() const
{
    return m_fuel_cons;
}

int StaticStructure::get_id() const
{
    return m_id;
}

int StaticStructure::get_rapid_fire(int id) const
{
    int rapid = 0;
    std::map< int, int>::const_iterator rapid_pos = m_rapid_fire.find(id);
    if (rapid_pos != m_rapid_fire.end())
    {
        rapid = rapid_pos->second;
    }
    return rapid;
}

resources StaticStructure::get_cost() const
{
    return m_cost;
}
