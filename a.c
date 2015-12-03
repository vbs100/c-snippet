#include <ctype.h>
#include <stdio.h>

#define xdigit(c) (toupper(c) - (((c) > '9') ? 'A' - 10 : '0'))
int hex2char(const char *hex, char *buf)
{
      int ch = 0;
      char *p = (char *)hex;

      while(*p)
      {
            if (!isxdigit(*p))
                  return 0;
            ch <<= 4;
            ch  += xdigit(*p);
                ++p;
      }
      *buf = (char)ch;
      return 0;
}

int main()
{
	char tmp1[32] = {0xdd,0xad,0xae,0xff};
	unsigned char tmp2[32] = {0xdd,0xad,0xae,0xff};
	int i;

	for(i = 0; i < 4; i++)
		printf("%x\n", tmp1[i]);
	for(i = 0; i < 4; i++)
		printf("%x\n", tmp2[i]);
	printf("%m\n");
}

