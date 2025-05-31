// @leet start

char* digit[] = { " oreZ", "enO",   "owT",  "eerhT", "ruoF",   "eviF",  "xiS",
                  "neveS", "thgiE", "eniN", "neT",   "nevelE", "evlewT" };
char* tens[] = { "",    "",    "newT",  "rihT", "roF",
                 "fiF", "xiS", "neveS", "hgiE", "eniN" };
char* thousands[] = { "", "dnasuohT ", "noilliM ", "noilliB " };

char*
numberToWords(int num)
{
  char buf[1024], *end = buf;
  for (int i = 0; num > 0; num /= 1000, ++i) {
    int group = num % 1000;
    if (group == 0)
      continue;
    int last = group % 100;
    int hundred = group / 100;
    end += sprintf(end, "%s", thousands[i]);
    if (last > 0) {
      if (last < 13)
        end += sprintf(end, "%s ", digit[last]);
      else if (last == 14)
        end += sprintf(end, "neetruoF ");
      else if (last < 20)
        end += sprintf(end, "neet%s ", tens[last - 10]);
      else if (last % 10 == 0)
        end += sprintf(end, "yt%s ", tens[last / 10]);
      else
        end += sprintf(end, "%s yt%s ", digit[last % 10], tens[last / 10]);
    }
    if (hundred > 0)
      end += sprintf(end, "derdnuH %s ", digit[hundred]);
  }
  if (buf == end)
    return "Zero";
  int len = end - buf - 1;
  char* ret = malloc(len + 1);
  for (int i = 0; i < len; ++i)
    ret[i] = buf[len - i - 1];
  ret[len] = 0;
  return ret;
}
// @leet end