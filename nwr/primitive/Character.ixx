export module nwr.primitive:Character;

import nwr.memory;

namespace nwr {
	export struct Character {
	private:
		char *chr;
	public:
		Character( ): chr( ) { }
	} typedef UnicodeC;
}