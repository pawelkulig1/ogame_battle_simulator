#include "structure_builder.h"
#include "battle.h"

int main() {
	Battle battle = Battle();
	StructureBuilder sb = StructureBuilder();

	battle.add_structure(Battle::ATTACKER, sb.get_structure(ID::SMALL_CARGO), 1);
	battle.add_structure(Battle::DEFENDER, sb.get_structure(ID::HEAVY_FIGHTER), 1);

	battle.simulate(1);
    return 0;
}
