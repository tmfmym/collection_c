all: list queue stack tree

list: list_test

queue: queue_array_test queue_list_test

stack: stack_array_test stack_list_test

tree: binary_tree_test

list_test: List/list_test.c List/list.c List/list_node.c
	gcc List/list_test.c List/list.c List/list_node.c -g -o bin/list_test

queue_array_test: Queue/queue_array_test.c Queue/queue_array.c
	gcc Queue/queue_array_test.c Queue/queue_array.c -g -o bin/queue_array_test

queue_list_test: Queue/queue_list_test.c Queue/queue_list.c
	gcc Queue/queue_list_test.c Queue/queue_list.c -g -o bin/queue_list_test

stack_array_test: Stack/stack_array_test.c Stack/stack_array.c
	gcc Stack/stack_array_test.c Stack/stack_array.c -g -o bin/stack_array_test

stack_list_test: Stack/stack_list_test.c Stack/stack_list.c
	gcc Stack/stack_list_test.c Stack/stack_list.c -g -o bin/stack_list_test

binary_tree_test: 
	gcc Tree/binary_tree_test.c Tree/binary_tree.c -g -o bin/binary_tree_test