#ifndef TESTER_H
#define TESTER_H

#include "BST.h"

namespace Tester{
	/* Make some tests where common ancestor is 1 */
	bool test1(BST<int>& tree);

	/* Make some tests where common ancestor is 2 */
	bool test2(BST<int>& tree);

	/* Make some tests where common ancestor is 3 */
	bool test3(BST<int>& tree);

	/* Make some tests where common ancestor is 4 */
	bool test4(BST<int>& tree);

	/* Make some tests where common ancestor is 5 */
	bool test5(BST<int>& tree);

	/* Make some tests where common ancestor is 6 */
	bool test6(BST<int>& tree);

	/* Make some tests where common ancestor is 7 */
	bool test7(BST<int>& tree);

	/* Make some tests where common ancestor is 8 */
	bool test8(BST<int>& tree);

	/* Make some tests where common ancestor is 9 */
	bool test9(BST<int>& tree);

	/* Make some tests where common ancestor is 10 */
	bool test10(BST<int>& tree);

	/** execute all tests */
	bool testAll(string &msg);
};

#endif