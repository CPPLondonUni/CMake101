#include "Widget.h"
#include <iostream>

Widget::Widget() {
	std::cout << "Widget Open\n";
}

Widget::~Widget() {
	std::cout << "Widget Close\n";
}
