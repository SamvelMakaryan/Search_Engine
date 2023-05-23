#include <iostream>
#include <set>

int main() {
	std::string a = "zunis";
	std::string b = "helo";
	std::set<std::string> ob;
	ob.insert(a);
	ob.insert(b);
std::cout << *ob.find("helo");	
std::cout << (ob.find("hel") != ob.end());	
}
