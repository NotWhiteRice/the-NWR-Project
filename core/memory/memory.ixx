export module nwr.memory;

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
export void memmove(void *dest, void *src, size_t len) {
	if(src == nullptr) throw "nwr.memory memmove(*d, *s, len): s cannot be a nullptr";
	char *d = (char *) dest, *s = (char *) src;
	if(dest == nullptr) {
		while(len--) s[len] = 0;
	} else {
		if(d < s) {
			while(len--) {
				*d++ = *s;
				*s++ = 0;
			}
		} else {
			d += len - 1; s += len - 1;
			while(len--) {
				d[len] = s[len];
				s[len] = 0;
			}
		}
	}
}
export void memset(void *dest, char value, size_t len) {
	char *d = (char *) dest;
	while(len--) d[len] = value;
}