int runRule(int a, int b, int c)
{
    int rule[8]={0,1,0,1,1,0,1,0};

    int d = (a<<2 | (b<<1) | (c));

    return(rule[d]);
}

void main()
{
    int bs=64;
    int i[64];
    int j[bs];
    int *cs;
    int *ns;
    int *ss;

    cs = i;
    ns = j;

    int a=0;
    int b=0;

    for (a=0;a<bs;a++)
    {
        i[a]=0;
    }
    i[32]=1;

    for (b=0;b<100;b++)
    {
        for (a=0;a<bs;a++)
        {
            if (a==0)
            {
                ns[a]=runRule(cs[bs-1],cs[0],cs[1]);
            }
            else if (a==bs-1)
            {
                ns[a]=runRule(cs[bs-2],cs[bs-1],cs[0]);
            }
            else
            {
                ns[a]=runRule(cs[a-1],cs[a],cs[a+1]);
            }    
        }
    
        for (a=0;a<bs;a++)
        {
            printf("%s",cs[a]==0?"..":"[]");
        }
        printf("\n");

        ss=cs;
        cs=ns;
        ns=ss;
    }
}
