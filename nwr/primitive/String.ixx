export module nwr.primitive:String;

import :Character;
import nwr.memory;

namespace nwr {
    /*
	Returns the length (in bytes) of a given C string
	*/
	export size_t strlen(const char *cstr) {
		size_t len = 0;
		while(cstr[len] != '\0') len++;
		return len;
	}
	/*
	Returns whether or not two given C strings are equal
	Two C strings are considered equal if they are the same sequence of characters before the null terminator
	*/
	export bool strcomp(const char *cstr1, const char *cstr2) {
		for(size_t i = 0; cstr1[i] != '\0' && cstr2[i] != '\0'; i++)
			if(cstr1[i] != cstr2[i]) return false;
		return true;
	}
	/*
	Returns the length (in UTF-8 characters) of a given C string
	*/
	export size_t strcount(const char *cstr) {
		const char *ptr = cstr;
		size_t i = 0, j = 0;
		while(*ptr != '\0') {
			if(*ptr == 0xFF && ((j & 0b111) == 0)) j += 8;
			else if(((*ptr & 0xC0) != 0x80 && (j & 0b111) != 0b111) || ((*ptr & 0xC0) == 0x80 && j == 0)) {
				throw "[ERROR--nwr.String] strcount(*cstr): The given C string must be encoded in UTF-8";
			} else if(j == 0) {
				size_t k = 0;
				if((~(*ptr) & 0xF0) == 0) k += 4;
				if((~(*ptr) & (0xC0 >> k)) == 0) k += 2;
				if((~(*ptr) & (0x80 >> k)) == 0) k += 1;
				j += k;
				if(j == 0) j = 1;
				i++;
			}
			j--;
			ptr++;
		}
		if(j == 0) return i;
		throw "[ERROR--nwr.String] strcount(*cstr): The given C string must be encoded in UTF-8";
	}
	/*
	Returns the index of a specific character in a UTF-8 encoded C string
	*/
	export size_t strnav(const char *cstr, size_t index) {
		const char *ptr = cstr;
		size_t i = 0, j = 0;
		while(*ptr != '\0') {
			if(*ptr == 0xFF && ((j & 0b111) == 0)) j += 8;
			else if(((*ptr & 0xC0) != 0x80 && (j & 0b111) != 0b111) || ((*ptr & 0xC0) == 0x80 && j == 0)) {
				throw "[ERROR--nwr.String] strnav(*cstr, index): The given C string must be encoded in UTF-8";
			} else if(j == 0) {
				size_t k = 0;
				if((~(*ptr) & 0xF0) == 0) k += 4;
				if((~(*ptr) & (0xC0 >> k)) == 0) k += 2;
				if((~(*ptr) & (0x80 >> k)) == 0) k += 1;
				j += k;
				if(j == 0) j = 1;
				index--;
				i += j;
				if(index == 0) return i;
			}
			j--;
			ptr++;
		}
		throw "[ERROR--nwr.String] strnav(*cstr, index): The index must be a point on the string";
	}

	export struct String {
	private:
		char *str;
	public:
		String( ): str(new char[1] { 0 }) { }
		String(const String &other) {
			size_t len = strlen(other.str);
			str = new char[len + 1] { 0 };
			memcopy(str, other.str, len + 1);
		}
		String &operator=(const String &other) {
			size_t len = strlen(other.str);
			str = new char[len + 1] { 0 };
			memcopy(str, other.str, len + 1);
			return *this;
		}
		String(String &&other): str(other.str) {
			other.str = nullptr;
		}
		String &operator=(String &&other) {
			str = other.str;
			other.str = nullptr;
			return *this;
		}
		~String( ) {
			if(str != nullptr) delete[] str;
		}

		char *data( ) const {
			return str;
		}
		const char *cstr( ) const {
			return str;
		}

		/*
		Returns the amount of bytes allocated for the string
		*/
		size_t size( ) const {
			return strlen(str) + 1;
		}
		/*
		Returns the amount of characters in the string
		*/
		size_t length( ) const {
			return strcount(str);
		}

		/*
		Clears the data of the string
		Leaves behind a default string
		 default string is only a null terminator in memory
		*/
		void clear( ) {
			delete[] str;
			str = new char[1] { 0 };
		}


	} typedef UnicodeS;
}