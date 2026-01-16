object Bob {
    fun isUpperCase(input: String): Boolean {
        if (input.all { !it.isLetter() }) {
            return false
        }
        return input.all{ !it.isLetter() || it.isUpperCase() }
    }
    fun hey(input: String): String {
        val s = input.trim()
        return when {
            s.endsWith("?") && isUpperCase(s) -> { "Calm down, I know what I'm doing!" }
            s.endsWith("?") -> { "Sure." }
            isUpperCase(s) -> { "Whoa, chill out!" }
            s.length == 0 -> { "Fine. Be that way!" }
            else -> { "Whatever." }
        }
    }
}
