// @leet start

typedef struct Booking
{
  int start, end;
  struct Booking *left, *right;
} Booking;

typedef struct
{
  Booking* root;
} MyCalendar;

MyCalendar*
myCalendarCreate()
{
  MyCalendar* calendar = malloc(sizeof(MyCalendar));
  calendar->root = 0;
  return calendar;
}

static bool
book(Booking** ptr, int start, int end)
{
  if (!*ptr) {
    *ptr = malloc(sizeof(Booking));
    **ptr = (Booking){ .start = start, .end = end, .left = 0, .right = 0 };
    return true;
  }
  if (end <= (*ptr)->start)
    return book(&(*ptr)->left, start, end);
  if ((*ptr)->end <= start)
    return book(&(*ptr)->right, start, end);
  return false;
}

bool
myCalendarBook(MyCalendar* obj, int start, int end)
{
  return book(&obj->root, start, end);
}

static void
freeBooking(Booking* ptr)
{
  if (ptr) {
    freeBooking(ptr->left);
    freeBooking(ptr->right);
    free(ptr);
  }
}

void
myCalendarFree(MyCalendar* obj)
{
  freeBooking(obj->root);
  free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);

 * myCalendarFree(obj);
*/
// @leet end