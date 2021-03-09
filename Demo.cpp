/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::snowman(11114411) << endl;   /* Should print:
_===_
(.,.)
( : )
( : )
	*/
	cout << ariel::snowman(33232124) << endl;   /* Should print:
   _
  /_\
\(o_O)
 (] [)>
 (   )
	*/

	cout << ariel::snowman(13232324) << endl;
	cout << ariel::snowman(23232124) << endl;
	cout << ariel::snowman(34432124) << endl;
	cout << ariel::snowman(43232124) << endl;
	cout << ariel::snowman(11432124) << endl;
	cout << ariel::snowman(24432124) << endl;
	cout << ariel::snowman(33333333) << endl;
	cout << ariel::snowman(44444444) << endl;
	cout << ariel::snowman(11111111) << endl;
	try {
		cout << ariel::snowman(5) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	}
}
