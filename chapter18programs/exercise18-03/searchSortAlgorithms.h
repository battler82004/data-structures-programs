// If found, returns the position of an element in the
// inputted list. If not found, returns -1.
template<class elemType>
int seqOrdSearch(const elemType list[], int length,
    const elemType& item) {
    
    for (int i = 0; i < length; i++) { // Seq search
        if (list[i] == item) // Found
            return i;
    }
    return -1; // Not in list
} //end seqOrdSearch
