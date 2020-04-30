#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intro() {
  printf(".              +   .                .   . .     .  .   \n");
  printf("                   .                    .       .     *\n");
  printf("  .       *                        . . . .  .   .  + . \n");
  printf("                                      .   .  +  . . .  \n");
  printf(".             Is anyone out there? .   .    .    . .   \n");
  printf("                              .     .     . +.    +  . \n");
  printf("                                .       .   . .        \n");
  printf("        . .                  .    * . . .  .  +   .    \n");
  printf("           +      .           .   .      +             \n");
  printf("                            .       . +  .+. .         \n");
  printf("  .                      .     . + .  . .     .      . \n");
  printf("           .      .    .     . .   . . .               \n");
  printf("      *             .    . .  +    .  .           *    \n");
  printf("          .     .    .  +   . .  *  .       .          \n");
  printf(" > oh yeah i left it in flag.txt + .                   \n");
  printf("          .     .    . .  *  .. . +   .     .          \n");
  printf(".   .  .  .  * . encode your transmissions! the vast < \n");
  printf(" .      .   .    emptyness is filtering out things     \n");
  printf(" .      .     *   .   .   . .  +   .    .            + \n");
  printf(" > aSBmb3Jnb3QgdG8gY2hlY2sgZm9yICQgYW5kICgpcwo=   .    \n");
  printf("   .            . +        . .  *      .               \n");
  printf("          . dGhhdHMgb2sgd2UgZmlsdGVyZWQgY29tbWFuZHMK < \n");
  printf("      .             .     *             .      +       \n");
}

int main(int argc, char* argv[]) {

  setvbuf(stdout, NULL, _IONBF, 0);

  char pingc[128] = "ping -c1 -i.2 -W1 ";
  char addr[110];
  char *danger = "`'/;!~+:\\[]?<>\"@";
  const char *bad[] = {"grep", "less", "more", "head", "tail", "vi", "nano"};

  intro();
  printf("Gimme an address to ping so we can who's out there:\n");
  fgets(addr, 110, stdin);

  if (strstr(addr, "sh")) {
    printf("IM ALLERGIC TO SHELLFISH\n");
    exit(0);
  }
  if (strstr(addr, "cat")) {
    printf("IM ALLERGIC TO CATS\n");
    exit(0);
  }
  for (int i = 0; i < 7; i++) {
    if (strstr(addr, bad[i])) {
      printf("I DON'T LIKE THAT WORD\n");
      exit(0);
    }
  }

  for (int d = 0; d < strlen(danger); d++) {
    for (int a = 0; a < strlen(addr); a++) {
      if (addr[a] == danger[d]) {
        addr[a] = ' ';
        printf("NOOOOOOOOO %c ALLLOWWWWWWWWWWWWED\n", danger[d]);
        exit(0);
      }
    }
  }

  strcat(pingc, addr);
  system(pingc);

  return 0;
}
