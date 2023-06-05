export module nwr.memory:manip;

namespace nwr {
	/*
	Copies a set amount of bytes from one pointer to another
	(dest, src, length)
	*/
	export void memcopy(void *dest, void *src, size_t len) {
		if(dest == nullptr) return;
		if(src == nullptr) throw "nwr.memory memcopy(*d, *s, len): s cannot be a nullptr";
		char *d = (char *) dest, *s = (char *) src;
		if(d < s) {
			while(len--) {
				*d++ = *s++;
			}
		} else {
			while(len--) {
				d[len] = s[len];
			}
		}
	}
	/*
	Moves a set amount of bytes from one pointer to another.
	(dest, src, length, filler (default: 0--'\0')
	*/
	export void memmove(void *dest, void *src, size_t len, char filler = 0) {
		if(src == nullptr) throw "nwr.memory memmove(*d, *s, len): s cannot be a nullptr";
		char *d = (char *) dest, *s = (char *) src;
		if(dest == nullptr) {
			while(len--) s[len] = 0;
		} else {
			if(d < s) {
				while(len--) {
					*d++ = *s;
					*s++ = filler;
				}
			} else {
				d += len - 1; s += len - 1;
				while(len--) {
					d[len] = s[len];
					s[len] = filler;
				}
			}
		}
	}
	/*
	Sets a set amount of bytes to a given value.
	*/
	export void memset(void *ptr, char value, size_t len) {
		char *p = (char *) ptr;
		while(len--) p[len] = value;
	}
}