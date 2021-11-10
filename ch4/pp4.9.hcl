bool xor = (a || b) && !(a && b)  // Mine
bool xor = (a && !b) || (!a && b) // Book's (probably superior)
