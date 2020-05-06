#include "structure_builder.h"
#include "battle.h"

int main() {
	Battle battle = Battle();
	StructureBuilder sb = StructureBuilder();

	battle.add_structure(Battle::ATTACKER, sb.get_structure(ID::SMALL_CARGO), 10);
	battle.add_structure(Battle::DEFENDER, sb.get_structure(ID::SMALL_CARGO), 10);

	battle.simulate(100);
    return 0;
}
