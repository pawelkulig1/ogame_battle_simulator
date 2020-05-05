#include "structure.h"
#include <algorithm>
#include "static_structure.h"

Structure::Structure(StaticStructure *ststructure)
{
    m_ststructure_ptr = ststructure;
}

bool Structure::attack(Structure &another)
{
    const Structure::default_type default_hull = another.m_ststructure_ptr->get_hull();
    const Structure::default_type default_shield = another.m_ststructure_ptr->get_shield();
    const int threshold = static_cast<double>(0.7 * default_hull);
    int attack = m_ststructure_ptr->get_attack();

    if (attack <= 0.01 * static_cast<double>(default_shield))
    {
        
    }

    attack -= another.m_shield;
    if (attack < 0) {
        attack = -attack;
    }

    
    another.m_hull = std::max_element(another.m_hull - m_ststructure_ptr->get_attack(), 0);

    if (another.m_hull < threshold)
    {
        if ((rand() % default_hull) > another.m_hull);
        
    }
}

bool Structure::is_exploding() const
{
    return m_exploded;
}
