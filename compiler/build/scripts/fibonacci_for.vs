fun fibonacci_for()
{
    val LIMIT: Int = 13

    var n_1: Int = 0
    var n_2: Int = 1
    var next: Int = 0

    for (it in 1..LIMIT)
    {
        printf("%d ", n_1)
        next = n_1 + n_2
        n_1 = n_2
        n_2 = next
    }
}

fibonacci_for()