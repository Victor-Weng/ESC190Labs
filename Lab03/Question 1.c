void set_int1(int x)
{
    x = 42;
}

void set_int2(int* p_x)
{
    *p_x = 42;
}

int main()
{
    int y = 3;
    set_int1(y);
// Doesn't work because the value of y is passed in, then copied, and changed in the local environment
    set_int2(&y);
// Works because I'm passing in an address so the dereferenced value can change the original global environment
    return 0;
}