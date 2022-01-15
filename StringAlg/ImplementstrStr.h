#pragma once
class ImplementstrStr
{

public:
	//暴力求解
	char *strStr(const char *haystack, const char *needle);

private:

};

char * ImplementstrStr::strStr(const char *haystack, const char *needle)
{
	// if needle is empty return the full string
	if (!*needle) return (char*)haystack;

	const char *p1;
	const char *p2;

	const char *p1_advance = haystack;

	for (p1 = haystack; *p1_advance; p1_advance++)
	{
		char *p1_old = (char*)p1;
		p2 = needle;
		while (*p1 && *p2 && *p1 == *p2) 
		{
			p1++;
			p2++;
		}
		//如果p2能遍历到尾部，则搜索到
		if (!*p2) return p1_old;
		p1 = p1_old + 1;
	}

	return nullptr;
}