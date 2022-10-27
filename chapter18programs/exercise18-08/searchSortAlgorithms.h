// Insertion sorts the inputted list. (Not written by me)
template <class elemType>
void insertionSort(elemType list[], int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder <
        length; firstOutOfOrder++)
        if (list[firstOutOfOrder] <
            list[firstOutOfOrder - 1])
        { // Finds an out of place element
            elemType temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            // Keeps swapping earlier until correct pos
            do
            {
                list[location] = list[location - 1];
                location--;
            } while(location > 0 && list[location - 1] >
                temp);

            list[location] = temp;
        }
} //end insertionSort
