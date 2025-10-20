func finalValueAfterOperations(operations []string) int {
    res := 0
    for _, op := range operations {
        firstChar := op[:1]
        if firstChar == "X" {
            if op[1:] == "++" {
                res++
            } else {
                res--
            }
        } else {
            if op[:2] == "++" {
                res++
            } else {
                res--
            }
        }
    }

    return res
}