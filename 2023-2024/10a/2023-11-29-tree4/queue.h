typedef struct Node
{
    int val;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct QueueNode
{
    Node *val;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

QueueNode *create_node(Node *val);

Queue *init_queue();
void enqueue(Queue *queue, Node *val);

Node *dequeue(Queue *queue);

void clear_queue(Queue *queue);