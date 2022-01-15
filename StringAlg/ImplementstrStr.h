#pragma once
class ImplementstrStr
{

public:
	//�������
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
		//���p2�ܱ�����β������������
		if (!*p2) return p1_old;
		p1 = p1_old + 1;
	}

	return nullptr;
}