// Bubble sorts the inputted array.
template <class elemType>
void modifiedBubbleSort(elemType list[], int length) {
    bool hasSwapped = true;
    elemType temp;
    // Iterates until there were no swaps since that means
    // everything's in place
    do {
        hasSwapped = false;
        // Goes through each element
        for (int i = 0; i < length-1; i++) {
            if (list[i] > list[i+1]) { // Out of order
                // Swap
                temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
                hasSwapped = true;
            }
        }
    } while (hasSwapped);
}
