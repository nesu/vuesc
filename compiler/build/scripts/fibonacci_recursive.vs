fun fibonacci_recursive(n: Int): Int
{
    if (n == 0) {
        return 0
    }

    if (n == 1) {
        return 1
    }

    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)
}

val result: Int = fibonacci_recursive(12)
printf("Fibonacci of 12: %d", result)