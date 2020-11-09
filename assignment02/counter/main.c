int counter = 0x0;
int main() {
    int *p_int = (int *)&counter;
    ++(*p_int);
    ++(*p_int);
    ++(*p_int);
    counter ++;
    return 0;
}