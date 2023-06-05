#include <iostream>

export module nwr.memory:allocator;

using std::cout;
using std::endl;

const size_t kilobyte = 1024;
const size_t megabyte = 1024 * kilobyte;
const size_t gigabyte = 1024 * megabyte;

const size_t stackCapacity = 5000;
namespace nwr {
	struct HeapBlock {
		char *start;
		size_t size;
	};

	struct HeapStack {
		size_t size;
		HeapBlock stack[stackCapacity];
	};

	const size_t heapCapacity = 10 * megabyte;
	char heap[heapCapacity];
	size_t heapSize;

	HeapStack heapStack = {0};
	HeapStack freeStack = {
		.size = 1,
		.stack = {{.start = heap, .size = sizeof(heap)}}
	};

	int stackFind(const HeapStack *stack, void *ptr) {
		for(int i = 0; i < stack->size; i++) {
			if(stack->stack[i].start == ptr) {
				return i;
			}
		}
		return -1;
	}

	void stackDump(const HeapStack *stack) {
		cout << "Blocks (" << stack->size << "):" << endl;
		for(size_t i = 0; i < stack->size; i++) {
			cout << "  start: " << (void *) stack->stack[i].start << ", size: " << stack->stack[i].size << endl;
		}
	}

	export void printHeap( ) {
		cout << "heapStack-----------------" << endl;
		stackDump(&heapStack);
		cout << "freeStack-----------------" << endl;
		stackDump(&freeStack);
	}

	void stackInsert(HeapStack *stack, void *ptr, size_t size) {
		if(stack->size >= stackCapacity) throw "[ERROR--nwr.allocator] stackInsert(*stack, *ptr, size)\\ Out of available blocks: max = 5000";
		stack->stack[stack->size].start = (char *) ptr;
		stack->stack[stack->size].size = size;

		for(size_t i = stack->size; i > 0 && stack->stack[i].start < stack->stack[i - 1].start; i--) {
			HeapBlock temp = stack->stack[i];
			stack->stack[i] = stack->stack[i - 1];
			stack->stack[i - 1] = temp;
		}

		stack->size++;
	}

	void stackRemove(HeapStack *stack, size_t index) {
		if(index >= stack->size) throw "[ERROR--nwr.allocator] stackRemove(*stack, i)\\ Index is out of bounds";
		for(size_t i = index; i < (size_t) stack->size - 1; i++) {
			stack->stack[i] = stack->stack[i + 1];
		}
		stack->size--;
	}

	export void *alloc(size_t count) {
		if(count > 0) {
			for(size_t i = 0; i < freeStack.size; i++) {
				const HeapBlock block = freeStack.stack[i];
				if(block.size >= count) {
					stackRemove(&freeStack, i);
					const size_t tailSize = block.size - count;
					stackInsert(&heapStack, block.start, count);
					if(tailSize > 0) {
						stackInsert(&freeStack, block.start + count, tailSize);
					}
					return block.start;
				}
			}
		}

		return nullptr;
	}

	export void free(void *ptr) {
		if(ptr != nullptr) {
			int i = stackFind(&heapStack, ptr);
			if(i < 0) throw "[ERROR--nwr.allocator] deallocate(*ptr)\\ Unable to retrieve pointer";
			stackInsert(&freeStack, heapStack.stack[i].start, heapStack.stack[i].size);
			int j = stackFind(&freeStack, heapStack.stack[i].start);
			stackRemove(&heapStack, i);
			if(j < freeStack.size - 1) if(freeStack.stack[j].start + freeStack.stack[j].size == freeStack.stack[j + 1].start) {
				freeStack.stack[j].size += freeStack.stack[j + 1].size;
				stackRemove(&freeStack, j + 1);
			}
			if(j > 0) if(freeStack.stack[j - 1].start + freeStack.stack[j - 1].size == freeStack.stack[j].start) {
				freeStack.stack[j - 1].size += freeStack.stack[j].size;
				stackRemove(&freeStack, j);
			}
		}
	}
}