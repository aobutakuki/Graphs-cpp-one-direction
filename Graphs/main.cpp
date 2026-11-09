#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <list>

//1 . HASH FUNCTION -> (Name) (Neighbor) aka MAP




void addToMap(std::map<std::string, std::vector<std::string>>& map, std::string value1, std::vector<std::string> value2) {

	map.insert({ value1,value2 });
}

//2. MAKE A LIST INSERT NAME IN THE LIST

void addToList(std::list<std::string>& l1, std::string str) {
	l1.push_back(str);

}



//3. IS THE NAME A STRAWBERRY SELLER?

bool checkName(std::string name) {
	if (name == "Paul")
	{
		return true;
	}
	else {
		return false;
	}
}

// -> ADD NEIGHBOR TO THE LIST

void addNeighborToList(std::list<std::string>& l1, std::map<std::string, std::vector<std::string>> &map, std::string name) {
	std::vector<std::string> neighboors = map.at(name);
	std::cout << "[DEBUG] NEIGHBOORS AT " << name << "\n";
	while (!neighboors.empty())
	{
		std::cout << "Neighboor : " << neighboors.back() << "\n";
		l1.push_back(neighboors.back());
		neighboors.pop_back();
	}
}


// IDEA FOR GRAPHS

// [NAME 1] -> [NAME 1] [NAME 2] -> [NAME 2]







int main() {

	std::map<std::string, std::vector<std::string>> map;
	addToMap(map, "Richard", { "Robert", "Clyde" });
	addToMap(map, "Robert", { "Anna" });
	addToMap(map, "Clyde", { "Paul" });

	std::string currentName = "Richard";
	std::list<std::string> nameList;
	nameList.push_back(currentName);

	while (!nameList.empty()) {
		if (!checkName(currentName)) {
			std::cout << "Iterating..." << std::endl;
			addNeighborToList(nameList, map, currentName);
			nameList.pop_front();
			currentName = nameList.front();

		}
		else {
			std::cout << currentName << " is a strawberry vendor!";
			return 0;
		}

	}

	std::cout << "Could not find Neighbor" << std::endl;


	return 0;
}