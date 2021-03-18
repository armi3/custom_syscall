#include <stdio.h>

 SYSCALL_DEFINE1(is_balanced, char *, msg) {

  char buf[256];
  long copied = strncpy_from_user(buf, msg, sizeof(buf));
  if (copied < 0 || copied == sizeof(buf))
    return -EFAULT;

  int len = 0;
  char*aux;
  for (aux = buf; *aux != '\0'; aux++){
    len ++;
  }
  char stack[100];
  int s = 0;
  int *p = &s;
  int currP = 0;
  int i;
  for (i = 0; i < len; i++) {
    if (buf[i] == '[' || buf[i] == '(') {
      stack[currP] = buf[i];
      currP++;
    }
    if (buf[i] == ']' || buf[i] == ')') {
      currP--;
      char c = stack[currP];
      if (!((buf[i] == ']' && c == '[') || (buf[i] == ')' && c == '('))) {
        return 1;
      }
    }
  }

  if (currP != 0) {
    return 0;
  }
  return 1;
}
