static void
swap(int* a, int i, int j)
{
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

static void
sift_down(int* a, int n, int i)
{

  while (2 * i + 1 < n) {
    int l = 2 * i + 1, r = 2 * i + 2;
    int j = l;
    if (r < n && a[r] < a[l])
      j = r;
    if (a[i] < a[j])
      break;
    swap(a, i, j);
    i = j;
  }
}

static void
sift_up(int* a, int i)
{
  while (a[i] < a[(i - 1) / 2]) {
    swap(a, i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

typedef struct
{
  int* seats;
  int size;
} SeatManager;

SeatManager*
seatManagerCreate(int n)
{
  SeatManager* obj = malloc(sizeof *obj);
  obj->seats = calloc(n, sizeof(int));
  obj->size = n;
  for (int i = 0; i < n; ++i)
    obj->seats[i] = i + 1;
  return obj;
}

int
seatManagerReserve(SeatManager* obj)
{
  int reserve = obj->seats[0];
  obj->seats[0] = obj->seats[--obj->size];
  sift_down(obj->seats, obj->size, 0);
  return reserve;
}

void
seatManagerUnreserve(SeatManager* obj, int seat_number)
{
  int i = obj->size, p = (i - 1) / 2;
  obj->seats[obj->size++] = seat_number;
  sift_up(obj->seats, obj->size - 1);
}

void
seatManagerFree(SeatManager* obj)
{
  free(obj->seats);
  free(obj);
}

/**
 * Your SeatManager struct will be instantiated and called as such:
 * SeatManager* obj = seatManagerCreate(n);
 * int param_1 = seatManagerReserve(obj);

 * seatManagerUnreserve(obj, seatNumber);

 * seatManagerFree(obj);
*/