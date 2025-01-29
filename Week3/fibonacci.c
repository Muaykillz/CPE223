int nthFibonacci(int n)
{
    // Base cases: return n if it's 0 or 1
    if (n <= 1)
    {
        return n;
    }
    // Recursive case: sum of previous two Fibonacci numbers
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

int main()
{
    int result = nthFibonacci(44);
    return 0;
}