typedef struct node {
    char* name; // name of the node
    node* next; // the next node
} node;

typedef struct LL {
    node* head; // head node which is type node
} LL;

typedef struct gnode {
    char* name; // name of the graph node
    LL* neighbour; // List of linked list for neighbours that contains nodes with names
} gnode;