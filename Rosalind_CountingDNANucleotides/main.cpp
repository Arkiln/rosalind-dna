// The problem, taken from rosalind.info/problems/dna
/*	A string is simply an ordered collection of symbols selected from some alphabet and formed into a word; the length of a string is the number of symbols that it contains.
	An example of a length 21 DNA string (whose alphabet contains the symbols 'A', 'C', 'G', and 'T') is "ATGCTTCAGAAAGGTCTTACG."
	Given: A DNA string ss of length at most 1000 nt.
	Return: Four integers (separated by spaces) counting the respective number of times that the symbols 'A', 'C', 'G', and 'T' occur in ss.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void nucleicCounter(string input, std::pair<char, unsigned __int16> *request, unsigned __int8 requestSize) {
	// Adds the number of times the letters requested appear in the given string

	for (unsigned __int16 i = 0; i < input.size(); i++) {
		for (unsigned __int8 j = 0; j < requestSize; j++) {
			if (request[j].first == input[i]) {
				request[j].second++;
			}
		}
	}
}

int main() {
	ifstream input("dataset.txt");

	if (input.is_open()) {
		string sequence;
		getline(input, sequence);

		pair<char, unsigned __int16> nucleotides[4];
		
		nucleotides[0].first = 'A';
		nucleotides[1].first = 'C';
		nucleotides[2].first = 'G';
		nucleotides[3].first = 'T';

		for (unsigned __int8 i = 0; i < 4; i++) {
			nucleotides[i].second = 0;
		}

		nucleicCounter(sequence, nucleotides, 4);

		for (unsigned __int8 i = 0; i < 4; i++) {
			cout << nucleotides[i].second << " ";
		}
	}
	else {
		cout << "nope" << endl;
	}

	return 0;
}