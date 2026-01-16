fun reverse(input: String): String {
    var output: String = ""
    for (c in input) {
        output = c + output
    }
    return output
}
