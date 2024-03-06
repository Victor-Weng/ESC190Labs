class Queue:
    def __init__(self, size):
        self.data = [None]*size;
        self.size = size;
        self.start = 0; # (highest index)
        self.end = 0; # (lowest index)

    def enqueue(self, item):
        # add item to the end of the queue (highest index)

        if self.end == -1:
            print("Empty Queue");
        
        if self.data[(self.end + 1) % self.size] == None:
            # if the next slot is not taken up,
            self.end = (self.end + 1) % self.size; # modulo to wrap around
            self.data.append(item);   # O(n) worst-case, usually O(1)
        else:
            print("Queue is full >:}");


    def dequeue(self):
        # remove the item at the end of the queue (lowest index)
        if self.start == -1:
            print("Empty Queue");
        
        ret_val = self.data[self.end]
        del self.data[self.end]
        self.end = (self.end + 1) % self.size;
        return ret_val    
    
    def __str__(self):
        # It should output a string that represents the contents of the queue

        if self.start == -1:
            return "Queue is empty"
        else:
            queue_items = []
            i = self.start
            while i != self.end:
                queue_items.append(str(self.data[i]))
                i = (i + 1) % self.size
            queue_items.append(str(self.data[self.end]))
            return ' '.join(queue_items)
    

    
