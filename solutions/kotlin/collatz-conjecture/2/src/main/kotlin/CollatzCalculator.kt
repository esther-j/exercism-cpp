object CollatzCalculator {
    fun computeStepCount(start: Int): Int {
        require(start > 0) { "Only natural numbers are allowed" }
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
