# Educational Practice
Just simple C++ program for educational practice. All output data in russian language.

It can be used for count words from input text and sort them by amount of characters. Result files contain sorted word array, and analysis - time of sort and amount of words of each size.

In this project was used quick sort that uses mid size of word in array as reference number. Code below.

```c++
vector<string> quick_Sort(vector<string> array_to_sort)
{
    int array_to_sort_size = array_to_sort.size();
    if (array_to_sort_size > 1) {
        vector<string> first_part(0), second_part(0);
        int first_part_size = first_part.size();
        int second_part_size = second_part.size();
        int max_size = 0, min_size = 100000;

        // Finding a reference number
        for (int i = 0; i < array_to_sort_size; i++) {
            if (array_to_sort[i].size() > max_size)
                max_size = array_to_sort[i].size();
            if (array_to_sort[i].size() < min_size)
                min_size = array_to_sort[i].size();
        }
        int mid_size = (max_size + min_size) / 2;
        //
        
        // Splitting the array
        for (int i = 0; i < array_to_sort_size; i++) {
            if (array_to_sort[i].size() > mid_size) {
                first_part_size++;
                first_part.resize(first_part_size);
                first_part[first_part_size-1] = array_to_sort[i];
            }
            else {
                second_part_size++;
                second_part.resize(second_part_size);
                second_part[second_part_size-1] = array_to_sort[i];
            }
        }
        //

        // Working with recursion and creating a ready-made array
        if (first_part_size != 0 && second_part_size != 0) {
            int j = 0;
            if (first_part_size > 1) {
                first_part = quick_Sort(first_part);
                for (j = 0; j < first_part_size; j++) {
                    array_to_sort[j] = first_part[j];
                }
            }
            else {
                array_to_sort[j] = first_part[0];
                j++;
                }
            if (second_part_size > 1) {
                second_part = quick_Sort(second_part);
                int k = 0;
                for (j; k < second_part_size; j++) {
                    array_to_sort[j] = second_part[k];
                    k++;
                }
            }
            else
                array_to_sort[j] = second_part[0];
        }
    }
    return array_to_sort;
}
```

Considering that the quick sort is performed on average in linearithmic time, tests of this algorithm on 10 different texts showed very good results that you can see in this graph below. It is based on data from analysis files.

![2022-04-13_11-36-03](https://user-images.githubusercontent.com/103406111/163135526-e3b89a46-8d98-4bb0-896f-bce3feb43f36.png)

This graph shows that time complexity of sort in this program is almost linear. Linear quick sort time is the best possible.
