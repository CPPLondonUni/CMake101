#include "Widget.h"
#ifdef SHOW_SECRET_MESSAGE
#include <iostream>
#endif

int main() {
	Widget w;
#ifdef SHOW_SECRET_MESSAGE
	std::cout << "Cool Story Bro.\n";
#endif
}

