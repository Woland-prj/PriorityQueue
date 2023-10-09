#pragma once

using DataType = int;

struct PrQeData {
	DataType data;
	int priority;
};

class CPriorityQueue {
private:
	struct Qe {
		PrQeData prData;
		Qe* next;
	};
	Qe* head, * el;
public:
	CPriorityQueue() {
		head = nullptr;
		el = nullptr;
	}

	void push(PrQeData d) {
		Qe* ptr,* prev;
		el = new Qe;
		el->prData = d;
		ptr = head;
		prev = nullptr;
		while (ptr && ptr->prData.priority <= d.priority) {
			prev = ptr;
			ptr = ptr->next;
		}
		el->next = ptr;
		if (prev) {
			prev->next = el;
		}
		else {
			el->next = head;
			head = el;
		}
	}

	void changePriority(PrQeData d, int priority) {
		if (!this->isEmpty()) {
			Qe* ptr, * nxt, * prev;
			ptr = head;
			prev = nullptr;
			while (ptr) {
				if (ptr->prData.data == d.data) {
					el = ptr;
					if (prev)
						prev->next = el->next;
					else
						head = el->next;
					el->prData.priority = priority;
					el->next = nullptr;
					break;
				}
				prev = ptr;
				ptr = ptr->next;
			}
			if (!ptr || d.priority == priority) return;
			if (priority < head->prData.priority) {
				el->next = head;
				head = el;
				return;
			}
			ptr = head;
			nxt = nullptr;
			while (ptr) {
				nxt = ptr->next;
				if (nxt) {
					if (priority < nxt->prData.priority) {
						el->next = nxt;
						ptr->next = el;
						break;
					}
					else {
						ptr = nxt;
					}
				}
				else {
					ptr->next = el;
					break;
				}
			}
		}
	}

	bool isEmpty() {
		return head == nullptr;
	}

	PrQeData pop() {
		PrQeData d;
		if (!this->isEmpty()) {
			d = head->prData;
			el = head;
			head = el->next;
			delete el;
			return d;
		}
	}

	~CPriorityQueue() {
		while (!this->isEmpty()) {
			el = head;
			head = el->next;
			delete el;
		}
	}
};