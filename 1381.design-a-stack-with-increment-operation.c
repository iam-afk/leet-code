// @leet start

typedef struct
{
  int* buf;
  uint16_t size, top;
} CustomStack;

CustomStack*
customStackCreate(int maxSize)
{
  CustomStack* obj = malloc(sizeof *obj);
  *obj = (CustomStack){ .buf = malloc(maxSize * sizeof(int)), .size = maxSize, .top = 0 };
  return obj;
}

void
customStackPush(CustomStack* obj, int x)
{
  if (obj->top == obj->size)
    return;
  obj->buf[obj->top++] = x;
}

int
customStackPop(CustomStack* obj)
{
  if (obj->top == 0)
    return -1;
  return obj->buf[--obj->top];
}

void
customStackIncrement(CustomStack* obj, int k, int val)
{
  if (k > obj->top)
    k = obj->top;
  for (int i = 0; i < k; ++i)
    obj->buf[i] += val;
}

void
customStackFree(CustomStack* obj)
{
  free(obj->buf);
  free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);

 * int param_2 = customStackPop(obj);

 * customStackIncrement(obj, k, val);

 * customStackFree(obj);
*/
// @leet end