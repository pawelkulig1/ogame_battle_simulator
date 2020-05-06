#include "static_structure.h"

StaticStructure::StaticStructure()
{
}

StaticStructure::StaticStructure(std::map<int, int> rapid_fire, StaticStructure::default_type attack, StaticStructure::default_type hull, StaticStructure::default_type shield):
    m_rapid_fire(rapid_fire),
    m_attack(attack),
    m_hull(hull),
    m_shield(shield)
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
