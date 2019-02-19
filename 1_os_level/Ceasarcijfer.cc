#include <iostream>
#include <string>
#include <vector>

int main() {
	std::cout << "Geef een tekst: ";
	std::string sentence;
	getline(std::cin, sentence);

	std::cout << "Geef een rotatie: ";
	int rotation;
	std::cin >> rotation;

	for (unsigned int i = 0; i < sentence.length(); i++) {
		char letter = sentence[i];
		if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122)) {
			if (letter + rotation > 90 && letter <= 90) {
				sentence[i] = letter - (91 - 65) + rotation;
			} else if (letter + rotation > 122 && letter <= 122) {
				sentence[i] = letter - (123 - 97) + rotation;
			} else {
				sentence[i] = sentence[i] + rotation;
			}
		}
	}
	std::cout << sentence;

	return 0;
}
