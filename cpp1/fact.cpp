
int fact(int val = 1)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}
