//
//  Sort.cpp
//  DataStructure
//
//  Created by ItghostFan on 2021/10/28.
//

#include "Sort.hpp"

namespace Sort {

/**
 * 冒泡排序
 * O(n^2)
 * in-place
 * @detail 核心思想是在无序部分，两两swap，不需要增加临时变量，记录index或者value。
 * @discussion 此处排序方式是，大数往后移。
 */
void bubble(unsigned int* array, size_t length) {
    for(unsigned int i = 0; i < length; ++i) {
        for (unsigned int j = 0; j < length - i - 1; ++j) {     // 此处条件，减少操作已经排序好的有序大数。
            if (array[j] > array[j + 1]) {
                unsigned int swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }
}

/**
 * 选择排序
 * O(n^2)
 * in-place
 * @detail 核心思想是遍历未排序部分，记录极值index，swap极值和未排序边界值。
 * @discussion 此处排序方式是，小数往前swap。
 */
void selection(unsigned int* array, size_t length) {
    for(unsigned int i = 0; i < length; ++i) {
        int minIndex = i;
        for (unsigned int j = i + 1; j < length; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        unsigned int swap = array[i];
        array[i] = array[minIndex];
        array[minIndex] = swap;
    }
}

/**
 * 插入排序
 * O(n^2)
 * in-place
 * @detail 核心思想是将未排序边界值，在有序部分找到插入index处，准确插入。插入index后的所有value往后移一个位置。
 * @discussion 此处排序方式是，小数往前插。
 */
void insertion(unsigned int* array, size_t length) {
    for(unsigned int i = 1; i < length; ++i) {
        int value = array[i];
        int j = i - 1;
        for (; 0 <= j; --j) {      // 注意这里要用有符号，因为你懂的！
            if (array[j] > value) {
                array[j + 1] = array[j];
            } else {        // 是当前边界值，继续找处理排序部分。
                break;
            }
        }
        array[j + 1] = value;
    }
}

/**
 * 希尔排序
 * O(n log n)
 * in-place
 * @detail 核心思想是先利用gap序列由大到1，进行插入排序。
 * 大于1的gap序列，先把大部份数据排好序，最后1的gap就不会做过多的元素移位。
 * 这里的插入排序在大gap序列时，是根据gap间隔的数据按插入排序操作，不太容易理解。
 * 为了保持通用性，最后1的gap，也进行swap操作。
 * @discussion 此处排序方式是，小数往前swap。
 */
void shell(unsigned int* array, size_t length, unsigned int gap) {
    while (gap >= 1) {
        for (int i = gap; i < length; i++) {
            for (int j = i; j >= gap && array[j] < array[j - gap]; j -= gap) {
                unsigned int temp = array[j];
                array[j] = array[j - gap];
                array[j - gap] = temp;
            }
        }
        gap = gap >> 1;
    }
}

}
