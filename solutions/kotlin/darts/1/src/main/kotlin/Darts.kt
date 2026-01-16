import kotlin.math.sqrt

object Darts {

    fun score(x: Number, y: Number): Int {
        val newX = x.toDouble()
        val newY = y.toDouble()
        val distance = sqrt(newX * newX + newY * newY)
        return when {
            distance > 10 -> 0
            distance > 5 -> 1
            distance > 1 -> 5
            else -> 10
        }
    }
}
