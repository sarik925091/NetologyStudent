#ifndef _HEADER_GUARDS_CLASS_
#define _HEADER_GUARDS_CLASS_

class Counter
{
	int __count = 1;
public:
	Counter() {}
	Counter(int count);

	int increase();
	int decrease();
	int get_counter();
	int userInputInt();
	std::string userInputString();

};

#endif