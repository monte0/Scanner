#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// --------- Two DFAs ---------------------------------

// WORD DFA 
//go through every letter of a word to see if its a word
bool word(string s)
{
	int state = 0;
	int charpos = 0;

	//loop through s until we hit end
	while (s[charpos] != '\0')
	{
		if (state == 0) //q0
		{
			//if vowel: go state 1 (q0 q1)
			if (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'o')
				state = 1;
			//if c: go state 3 (qc)
			else if (s[charpos] == 'c')
				state = 3;
			//if s: go to state 4(qs)
			else if (s[charpos] == 's')
				state = 4;
			//if d, j, w, y, z: go to state 5
			else if (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z')
				state = 5;
			//if t: go to state 6
			else if (s[charpos] == 't')
				state = 6;
			else if (s[charpos] == 'g' || s[charpos] == 'b' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')
				state = 7;
			else
				return false;
		}
		else if (state == 1) // q0 q1
		{
			//if vowel, go state 1 (q0 q1)
			if (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'o')
				state = 1;
			else if (s[charpos] == 'n')
				state = 2;
			else if (s[charpos] == 'c')
				state = 3;
			else if (s[charpos] == 's')
				state = 4;
			else if (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z')
				state = 5;
			else if (s[charpos] == 't')
				state = 6;
			else if (s[charpos] == 'g' || s[charpos] == 'b' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r')
				state = 7;
			else
				return false;
		}
		else if (state == 2) // q0 qy
		{
			//if vowel, go state 1 (q0 q1)
			if (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'o')
				state = 1;
			//if c, go state 3 (qc)
			else if (s[charpos] == 'c')
				state = 3;
			else if (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z')
				state = 4;
			else if (s[charpos] == 's')
				state = 5;
			else if (s[charpos] == 't')
				state = 6;
			else if (s[charpos] == 'g' || s[charpos] == 'b' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')
				state = 7;
			else
				return false;
		}
		else if (state == 3) //qc
		{
			if (s[charpos] == 'h')
				state = 5;
			else
				return false;
		}
		else if (state == 4) //qs
		{
			if (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'o')
				state = 1;
			else if (s[charpos] == 'h')
				state = 5;
			else
				return false;
		}
		else if (state == 5) //qsa
		{
			if (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'o')
				state = 1;
			else
				return false;
		}
		else if (state == 6) //qt
		{
			if (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'o')
				state = 1;
			else
				return false;
		}
		else if (state == 7) //qy
		{
			if (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'o')
				state = 1;
			else if (s[charpos] == 'y')
				state = 5;
			else
				return false;
		}
		charpos++;
	}//end of while
   // where did I end up????
	if (state == 1 || state == 2)
		return(true);  // end in a final state
	else
		return(false);
}

// PERIOD DFA 
bool period(string s)
{
	int state = 0;
	int charpos = 0;
	// complete this **
	while (s[charpos] != '\0')
	{
		if (s[charpos] == '.')
			state = 1;

		charpos++;
	}
	if (state == 1)
	{
		return true;
	}
	return false;
}

// ------ Three  Tables -------------------------------------
enum tokentype { WORD1, WORD2, PERIOD, ERROR, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { "WORD1", "WORD2","PERIOD","ERROR", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM" };
string reservedwords[18] = { "masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi", "anata", "kare", "kanojo", "sore", "mata", "soshite", "shikashi", "dakara" };

// ------------ Scaner and Driver ----------------------- 
ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
int scanner(tokentype& tt, string& w)
{
	// ** Grab the next word from the file via fin
	// 1. If it is eofm, return right now.
	fin >> w; //next word
	if (w == "eofm") return(tt);

	/*  **
	2. Call the token functions (word and period)
	   one after another (if-then-else).
	   Generate a lexical error message if both DFAs failed.
	   Let the tokentype be ERROR in that case.*/
	if (word(w))
	{
		int r = -1; //check if in reserved words
		for (int i = 0; i < 18; i++)
		{
			if (w == reservedwords[i]) r = i;
		}
		if (r == 0) tt = VERB;
		else if (r == 1) tt = VERBNEG;
		else if (r == 2) tt = VERBPAST;
		else if (r == 3) tt = VERBPASTNEG;
		else if (r == 4) tt = IS;
		else if (r == 5) tt = WAS;
		else if (r == 6) tt = OBJECT;
		else if (r == 7) tt = SUBJECT;
		else if (r == 8) tt = DESTINATION;
		else if (r == 9 or r == 10 or r == 11 or r == 12 or r == 13) tt = PRONOUN;
		else if (r == 14 or r == 15 or r == 16 or r == 17) tt = CONNECTOR;
		else
		{
			if (w.at(w.length() - 1) == 'I' or w.at(w.length() - 1) == 'E') tt = WORD2;
			else tt = WORD1;
		}

	}
	else if (period(w))
	{
		tt = PERIOD;
	}
	else
	{
		cout << "Lexical Error: " << w << " is not in my language" << endl;
		tt = ERROR;
	}
	/*
	3. If it was a word,
	   check against the reservedwords list.
	   If not reserved, tokentype is WORD1 or WORD2
	   decided based on the last character.*/

	   // 4. Return the token type & string  (pass by reference)


}//the end of scanner


// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
int main()
{
	tokentype thetype;
	string theword;
	string filename;

	cout << "Enter the input file name: ";
	cin >> filename;

	fin.open(filename.c_str());

	// the loop continues until eofm is returned.
	while (true)
	{
		scanner(thetype, theword);  // call the scanner which sets
									// the arguments  
		if (theword == "eofm") break;  // stop now

		cout << "Type is:" << tokenName[thetype] << endl;
		cout << "Word is:" << theword << endl;
	}

	cout << "End of file is encountered." << endl;
	fin.close();

}// end