// @leet start

typedef struct
{
  int n;
  int p[40001];
} ProductOfNumbers;

ProductOfNumbers*
productOfNumbersCreate()
{
  ProductOfNumbers* res = malloc(sizeof *res);
  res->n = 0;
  res->p[0] = 1;
  return res;
}

void
productOfNumbersAdd(ProductOfNumbers* obj, int num)
{
  if (num == 0)
    obj->n = 0;
  else {
    obj->p[obj->n + 1] = obj->p[obj->n] * num;
    ++obj->n;
  }
}

int
productOfNumbersGetProduct(ProductOfNumbers* obj, int k)
{
  return k <= obj->n ? obj->p[obj->n] / obj->p[obj->n - k] : 0;
}

void
productOfNumbersFree(ProductOfNumbers* obj)
{
  free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);

 * int param_2 = productOfNumbersGetProduct(obj, k);

 * productOfNumbersFree(obj);
*/
// @leet end