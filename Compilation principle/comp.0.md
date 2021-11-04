# 预实验 

## 1. 实现

- 链表、栈、队列创建、查找、插入、删除等基本操作。

## 2. 参考数据结构

```c++

//结点
typedef struct{
    struct Node *next;
    struct Node *pre;
    int data;
}Node;
//链表头结点
struct
{
    struct Node* head;
    struct Node* tail;
    int count;
} List;
typedef List Stack;//使用链表作为堆栈的底层实现结构
```

## 3. 参考过程

1.操作

### 2.1 表

#### 2.1.1. 初始化

```c++
void list_init(struct List* root){
    root->count = 0;
    root->head = NULL;
    root->tail = NULL;
}
```

#### 2.1.2 插入

```c++
//插入到队列末尾
void push_back(Node* node, List* list){
    if(list->head == NULL){//如果list头结点为空
        list->head = list->tail = node;
        node->next = node->pre = NULL;
        list->count++;
        return;
    }
    node->next = NULL;
    node->pre = list->tail;
    list->tail->next = node;
    list->tail = node;
    list->count++;
}
```

```c++
//插入到队列头部
void push_front(Node *node, List* list){
    if(list->head == NULL){
        list->head = list->tail = node;
        node->next = node->pre = NULL;
        list->count++;
        return;
    }
    node->pre= NULL;
    node->next = list->head;
    list->head->pre = node;
    list->head = node;
    list->count++;
}
//插入到位置locate
int insert(Node *node, List *list, int locate){
    //异常处理
    if(locate > list->count || locate < 0)
        return -1;
```



```c++
//插入到头部
if(locate == 0){
    push_front(node, list); 
    return 1;
}
//插入到尾部
if(locate == list->count){
    push_back(node, list); 
    return 1;
}
//其它
int curValue = -1;
//查找并插入到cur的前面
Node *cur = list->head;
while(++curValue < locate)cur = cur->next;
//插入
node->next = cur;
node->pre = cur->pre;
cur->pre->next = node;
cur->pre = node;
```


#### 2.1.3 查找

```c++
Node* search(Node *node, List *list, int &locate){
    //返回相应的头结点，并记录该结点的位置到locate中	
    locate = 0;
    Node *cur = list->head;
    while(cur != NULL && cur->data != node->data){cur = cur->next; locate++;}
    if(cur == NULL) locate = - 1;
    return cur;
}
```

#### 2.1.4. 删除

```c++
int remove(List *list, int locate){
    //异常
    if(locate >= list->count || locate < 0)return -1;

    if(locate == 0){//头部
        Node *p = list->head->next;
        free(list->head);
        p->pre = NULL;
        list->head = p;
    } else if(locate == list->count - 1){//尾部
        Node *p = list->tail->pre;
        free(list->tail);
        p->next = NULL;
        list->tail = p;
    } else{//其它
        //查找并保存到cur中
        int curValue = -1;
        Node *cur = list->head;
        while(++curValue < locate)cur = cur->next;
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        free(cur);
    }
    list->count--;
    return 1;
}
```

### 2.2. 堆栈操作

#### 2.2.1 初始化

```c++
void stack_init(Stack *s){
    list_init((List*)s);
}
```

#### 2.2.2 压栈

```c++
void push(struct Node* node, Stack* s){
    push_front(node, (List*)s);
}
```



#### 2.2.3 出栈

```c++
Node* pop(Stack* s){
    Node *node = s->head;
    if(s->head->next != NULL)
        s->head = s->head->next;
    return node;
}

```

#### 2.2.4 获得栈顶

```c++
Node* get_top_stack(struct Node* node, Stack* s){
    return s->head;
}
```



### 2.3. 队列操作

#### 2.3.1. 初始化队列

```c++
void queue_init(Queue *q){
    list_init((List*)q);
}
```



#### 2.3.2. 入队列

```c++
void in_queue(struct Node* node, Queue* q){
    push_back(node, (List*)q);
}
```



#### 2.3.3. 出队列

```c++
Node* out_queue(Queue* q){
    Node *node = q->head;
    if(q->head->next != NULL)
        q->head = q->head->next;
    return node;
}
```



#### 2.3.4. 获得队列头

 

```c++
Node* get_first_queue(struct Node* node, Queue* q){
    return q->head; 
}
```

