#define ALLOCSIZE 10000  // 可用的空间

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;


char *alloc(int n)
/* 分配空间 */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    } else
    {
        return 0;
    }
}


void afree(char *p)
/* 释放空间 */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
