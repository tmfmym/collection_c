all: list_test queue_array_test binary_tree_test

list_test: List/list_test.c List/list.c List/list_node.c
	gcc List/list_test.c List/list.c List/list_node.c -g -o bin/list_test

queue_array_test: Queue/queue_array_test.c Queue/queue_array.c
	gcc Queue/queue_array_test.c Queue/queue_array.c -g -o bin/queue_array_test

binary_tree_test: 
	gcc Tree/binary_tree_test.c Tree/binary_tree.c -g -o bin/binary_tree_test