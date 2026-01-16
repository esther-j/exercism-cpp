object CollatzCalculator {
    fun computeStepCount(start: Int): Int {
        if (start <= 0) {
            throw IllegalArgumentException()
        }
        var n = start
        var steps = 0
        while (n != 1) {
            when (n % 2) {
                0 -> { n /= 2 }
                1 -> { n = n * 3 + 1 }
            }
            steps++
        }
        return steps
    }
}
