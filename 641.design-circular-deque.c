// @leet start

typedef struct
{
  int* buf;
  int cap, len;
  int head, tail;
} MyCircularDeque;

MyCircularDeque*
myCircularDequeCreate(int k)
{
  MyCircularDeque* deque = malloc(sizeof(MyCircularDeque));
  *deque = (MyCircularDeque){
    .buf = malloc(sizeof(int) * k),
    .cap = k,
    .len = 0,
    .head = 0,
    .tail = 0,
  };
  return deque;
}

bool
myCircularDequeInsertFront(MyCircularDeque* obj, int value)
{
  if (obj->len == obj->cap)
    return false;
  obj->head = (obj->head + obj->cap - 1) % obj->cap;
  obj->buf[obj->head] = value;
  obj->len++;
  return true;
}

bool
myCircularDequeInsertLast(MyCircularDeque* obj, int value)
{
  if (obj->len == obj->cap)
    return false;
  obj->buf[obj->tail] = value;
  obj->tail = (obj->tail + 1) % obj->cap;
  obj->len++;
  return true;
}

bool
myCircularDequeDeleteFront(MyCircularDeque* obj)
{
  if (obj->len == 0)
    return false;
  obj->head = (obj->head + 1) % obj->cap;
  obj->len--;
  return true;
}

bool
myCircularDequeDeleteLast(MyCircularDeque* obj)
{
  if (obj->len == 0)
    return false;
  obj->tail = (obj->tail + obj->cap - 1) % obj->cap;
  obj->len--;
  return true;
}

int
myCircularDequeGetFront(MyCircularDeque* obj)
{
  if (obj->len == 0)
    return -1;
  return obj->buf[obj->head];
}

int
myCircularDequeGetRear(MyCircularDeque* obj)
{
  if (obj->len == 0)
    return -1;
  return obj->buf[(obj->tail + obj->cap - 1) % obj->cap];
}

bool
myCircularDequeIsEmpty(MyCircularDeque* obj)
{
  return obj->len == 0;
}

bool
myCircularDequeIsFull(MyCircularDeque* obj)
{
  return obj->len == obj->cap;
}

void
myCircularDequeFree(MyCircularDeque* obj)
{
  free(obj->buf);
  free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);

 * bool param_2 = myCircularDequeInsertLast(obj, value);

 * bool param_3 = myCircularDequeDeleteFront(obj);

 * bool param_4 = myCircularDequeDeleteLast(obj);

 * int param_5 = myCircularDequeGetFront(obj);

 * int param_6 = myCircularDequeGetRear(obj);

 * bool param_7 = myCircularDequeIsEmpty(obj);

 * bool param_8 = myCircularDequeIsFull(obj);

 * myCircularDequeFree(obj);
*/
// @leet end