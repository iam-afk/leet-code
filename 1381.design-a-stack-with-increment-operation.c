// @leet start

typedef struct
{
  int *buf, *inc;
  uint16_t size, top;
} CustomStack;

CustomStack*
customStackCreate(int maxSize)
{
  CustomStack* obj = malloc(sizeof *obj);
  *obj = (CustomStack){ .buf = malloc(maxSize * sizeof(int)),
                        .inc = malloc(maxSize * sizeof(int)),
                        .size = maxSize,
                        .top = 0 };
  return obj;
}

void
customStackPush(CustomStack* obj, int x)
{
  if (obj->top == obj->size)
    return;
  obj->buf[obj->top] = x;
  obj->inc[obj->top] = 0;
  ++obj->top;
}

int
customStackPop(CustomStack* obj)
{
  if (obj->top == 0)
    return -1;
  --obj->top;
  if (obj->top > 0)
    obj->inc[obj->top - 1] += obj->inc[obj->top];
  return obj->buf[obj->top] + obj->inc[obj->top];
}

void
customStackIncrement(CustomStack* obj, int k, int val)
{
  if (obj->top == 0)
    return;
  if (k > obj->top)
    k = obj->top;
  obj->inc[k - 1] += val;
}

void
customStackFree(CustomStack* obj)
{
  free(obj->inc);
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