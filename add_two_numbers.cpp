#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode* ls) {
	std::cout << "[";
	while(ls) {
		std::cout << ls->val << ", ";
		ls = ls->next;
	}
	std::cout << "]" << std::endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = nullptr;
	ListNode* start = nullptr;
	ListNode* ls = nullptr;
	bool carry = false;

	while (l1 || l2) {
		ls = new ListNode(0);
		if (l1) {
			ls->val += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			ls->val += l2->val;
			l2 = l2->next;
		}

		// check if carry
		if (carry) {
			ls->val += 1;
		}
		
		if (ls->val > 9) {
			// set if carry
			ls->val -= 10;
			carry = true;
		} else {
			carry = false;
		}

		if (head) {
			// head is not null
			head->next = ls;
			head = ls;
		} else {
			// head is null
			head = ls;
			start = ls;
		}
	} // end while
	if (carry) {
		head->next = new ListNode(1);
	}
	return start;
    }
};


int main(void) {
	std::cout << "this is it!" << std::endl;
	ListNode l1_1 = ListNode(1);
	ListNode l1_2 = ListNode(2, &l1_1);
	ListNode l1_3 = ListNode(3, &l1_2);
	ListNode* l1_p = &l1_3;

	ListNode l2_1 = ListNode(5);
	ListNode l2_2 = ListNode(6, &l2_1);
	ListNode l2_3 = ListNode(7, &l2_2);
	ListNode l2_4 = ListNode(8, &l2_3);
	ListNode l2_5 = ListNode(9, &l2_4);
	ListNode* l2_p = &l2_5;
	print_list(l2_p);

	Solution solution = Solution();
	ListNode* head = solution.addTwoNumbers(l1_p, l2_p);
	print_list(head);

	return 0;
}
