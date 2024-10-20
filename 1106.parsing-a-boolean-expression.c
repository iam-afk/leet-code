// @leet start
struct state
{
  char* next;
};

static bool
expr(struct state* state)
{
  bool value;
  switch (*state->next++) {
    case 't':
      return true;
    case 'f':
      return false;
    case '!':
      ++state->next;
      value = !expr(state);
      ++state->next;
      break;
    case '&':
      value = true;
      while (*state->next++ != ')')
        value &= expr(state);
      break;
    case '|':
      value = false;
      while (*state->next++ != ')')
        value |= expr(state);
      break;
  }
  return value;
}

bool
parseBoolExpr(char* expression)
{
  return expr(&(struct state){ .next = expression });
}
// @leet end