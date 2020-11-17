
void func1(int a, int b, int c, int d, int e)
{
    
}

void func2(int a, int b, int c, int d, int e) 
{
    func1(a, b, c, d, e);
}

void main(void)
{
    func2(1, 2, 3, 4, 5);
}
