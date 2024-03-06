from Queue import *

test = Queue(6);
print(test);
test.enqueue(2);
test.enqueue(4);
test.enqueue(5);
test.enqueue(6);
test.enqueue(7);
print(test);
test.dequeue();
test.dequeue();
print(test);
