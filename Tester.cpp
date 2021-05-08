#include "Tester.h"

/* Make some tests where common ancestor is 1 */
bool Tester::test1(BST<int>& tree){
	if(tree.commonAncestor(1, 2) != 1) return false;
	if(tree.commonAncestor(1, 1) != 1) return false;
	return true;
}

/* Make some tests where common ancestor is 2 */
bool Tester::test2(BST<int>& tree){
	if(tree.commonAncestor(2, 2) != 2) return false;
	return true;
}

/* Make some tests where common ancestor is 3 */
bool Tester::test3(BST<int>& tree){
	if(tree.commonAncestor(1, 4) != 3) return false;
	if(tree.commonAncestor(2, 3) != 3) return false;
	if(tree.commonAncestor(3, 4) != 3) return false;
	return true;
}

/* Make some tests where common ancestor is 4 */
bool Tester::test4(BST<int>& tree){
	if(tree.commonAncestor(4, 4) != 4) return false;
	return true;
}

/* Make some tests where common ancestor is 5 */
bool Tester::test5(BST<int>& tree){
	if(tree.commonAncestor(3, 7) != 5) return false;
	if(tree.commonAncestor(1, 6) != 5) return false;
	if(tree.commonAncestor(2, 8) != 5) return false;
	if(tree.commonAncestor(2, 7) != 5) return false;
	if(tree.commonAncestor(3, 10) != 5) return false;
	if(tree.commonAncestor(4, 10) != 5) return false;
	return true;
}

/* Make some tests where common ancestor is 6 */
bool Tester::test6(BST<int>& tree){
	if(tree.commonAncestor(6, 6) != 6) return false;
	return true;
}

/* Make some tests where common ancestor is 7 */
bool Tester::test7(BST<int>& tree){
	if(tree.commonAncestor(7, 7) != 7) return false;
	if(tree.commonAncestor(6, 9) != 7) return false;
	if(tree.commonAncestor(6, 8) != 7) return false;
	if(tree.commonAncestor(10, 6) != 7) return false;
	return true;
}

/* Make some tests where common ancestor is 8 */
bool Tester::test8(BST<int>& tree){
	if(tree.commonAncestor(8, 8) != 8) return false;
	return true;
}

/* Make some tests where common ancestor is 9 */
bool Tester::test9(BST<int>& tree){
	if(tree.commonAncestor(9, 9) != 9) return false;
	if(tree.commonAncestor(8, 10) != 9) return false;
	if(tree.commonAncestor(9, 8) != 9) return false;
	if(tree.commonAncestor(9, 10) != 9) return false;
	return true;
}

/* Make some tests where common ancestor is 10 */
bool Tester::test10(BST<int>& tree){
	if(tree.commonAncestor(10, 10) != 10) return false;
	return true;
}


bool Tester::testAll(string &msg){
	bool passed = true;
	msg = string("TESTING WITH TREE:\n") +
		  "         5     \n" +
	      "      /     \\ \n" +
		  "   3           7\n" + 
		  "  / \\         / \\\n" + 
		  " 1   4       6   9\n" +
		  "  \\            /  \\\n" +
		  "   2           8   10\n\n"; 
	BST<int> tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(7);
	tree.insert(1);
	tree.insert(4);
	tree.insert(6);
	tree.insert(9);
	tree.insert(2);
	tree.insert(8);
	tree.insert(10);
	if(!test1(tree)) { 
		msg += "Test 1 Failed\n"; 
		passed = false; 
	}
	if(!test2(tree)) { 
		msg += "Test 2 Failed\n"; 
		passed = false; 
	}
	if(!test3(tree)) { 
		msg += "Test 3 Failed\n"; 
		passed = false; 
	}
	if(!test4(tree)) { 
		msg += "Test 4 Failed\n"; 
		passed = false; 
	}
	if(!test5(tree)) { 
		msg += "Test 5 Failed\n"; 
		passed = false; 
	}
	if(!test6(tree)) { 
		msg += "Test 6 Failed\n"; 
		passed = false; 
	}
	if(!test7(tree)) { 
		msg += "Test 7 Failed\n"; 
		passed = false; 
	}
	if(!test8(tree)) { 
		msg += "Test 8 Failed\n"; 
		passed = false; 
	}
	if(!test9(tree)) { 
		msg += "Test 9 Failed\n"; 
		passed = false; 
	}
	if(!test10(tree)) { 
		msg += "Test 10 Failed\n"; 
		passed = false; 
	}
	return passed;
}
