#pragma once


namespace nwr {
	class UniversalParser {
	private:
		const char *getFileExtension(const char *file);

	public:
		UniversalParser( );
		virtual void parse(int args, ...);
	} typedef Parser;
}
