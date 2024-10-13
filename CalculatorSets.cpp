#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <ctime>
#include <random>
#include <algorithm>
#include <sstream>



class Set
{
public:
	std::vector<int> elements;
	static std::vector<int> Universal;
private:
	std::string setName;
public:
  void MakeSet(char makingType, int size){
    switch (makingType){
      case 'r':
        for (int i = 0; i < size; i++){
          int tmp;
          tmp = rand() % 100-50;
          elements.push_back(tmp);
        }
        std::sort(elements.begin(), elements.end());
	      elements.erase(std::unique(elements.begin(), elements.end()), elements.end());
        break;
      case 'm':
        for (int i = 0; i < size; i++){
          int tmp;
          std::cin >> tmp; 
          elements.push_back(tmp);
        }
        std::sort(elements.begin(), elements.end());
	      elements.erase(std::unique(elements.begin(), elements.end()), elements.end());
        break;
      default:
        std::cout << "Wrong sign!\n";
        break;
    }
  }
};

std::vector<int> Set::Universal;


void makeSortedAndUnique(Set a) {
	std::sort(a.elements.begin(), a.elements.end());
	a.elements.erase(std::unique(a.elements.begin(), a.elements.end()), a.elements.end());
}

Set findUnion(Set a, Set b){
	Set tmp;
  for (int i = 0; i < a.elements.size();i++){
    tmp.elements.push_back(a.elements[i]);
  }
  for (int i = 0; i < b.elements.size(); i++){
    tmp.elements.push_back(b.elements[i]);
  }

  makeSortedAndUnique(tmp);
	return tmp;
}

Set findIntersection(Set a, Set b) {
	Set tmp;
	for (int i = 0; i < a.elements.size(); i++) {
		for (int j = 0; j < b.elements.size(); j++) {
			if (a.elements[i] == b.elements[j])
				tmp.elements.push_back(a.elements[i]);
		}
	}
	makeSortedAndUnique(tmp);
	return tmp;
}

Set findDifference(Set a, Set b) {
	Set tmp;
	for (int i = 0; i < a.elements.size(); i++) {
		tmp.elements.push_back(a.elements[i]);
	}
	for (int i = 0; i < tmp.elements.size(); i++) {
		for (int j = 0; j < b.elements.size(); j++)
		{
			if (tmp.elements[i] == b.elements[j])
				tmp.elements.erase(tmp.elements.begin() + i);
		}
	}
	makeSortedAndUnique(tmp);
	return tmp;
}

Set findSymmetricDifference(Set a, Set b) { 
	Set tmp1, tmp2, tmp;
	tmp1 = findUnion(a, b);
	tmp2 = findIntersection(b, a);
	tmp = findDifference(tmp1, tmp2);
	makeSortedAndUnique(tmp);
	return tmp;
}

Set completion(Set a){
	Set tmp;

	for (int i = 0; i < a.elements.size(); i++) {
		tmp.elements.push_back(a.elements[i]);
	}
	for (int i = 0; i < tmp.elements.size(); i++) {
		for (int j = 0; j < a.Universal.size(); j++)
		{
			if (tmp.elements[i] == a.Universal[j])
				tmp.elements.erase(tmp.elements.begin() + i);
		}
	}
	makeSortedAndUnique(tmp);
	return tmp;
}

void elementBelong(Set a, int elem) {
	for (const auto& x : a.elements) {
		if (x == elem) {
			std::cout << "Element belong to this set\n";
		}
		else
			std::cout << "Element does not belong to this set\n";
	}
}

void printOutSet(Set a) {
	for (const auto& x : a.elements) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;
}

void subset(Set a, Set b){
  
  for (int i = 0; i < a.elements.size(); i++){
    int count = 0;
    for (int j = 0; j < b.elements.size();i++){
      if (a.elements[i] == b.elements[j]){
        count++;
        if (count == b.elements.size()){
          std::cout << "Is subset\n";
          break;
        }
      }
    }
  }

}

int main()
{
  srand(time(0));
  for (int i = -100; i < 101; i++) {
		Set::Universal.push_back(i);
	}

  std::vector<Set> sets{5};
  std::cout << "How much sets do you want to create?\n";
  int setNum;
  std::cin >> setNum;

  for (int i = 0; i < setNum; i++){
    Set tmp;

    char creationType;
    int setSize;

    std::cout << "Input how to create a set, 'm' for manual or 'r' for random\n";
    std::cin >> creationType;
    
    std::cout << "Input size of a set\n";
    std::cin >> setSize;

    tmp.MakeSet(creationType, setSize);
    sets.push_back(tmp);
  }
}
