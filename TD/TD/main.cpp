#pragma once
//#include <SFML/Graphics.hpp>
#include "Game.h"
/* */
int main()
{
	std::cout << "hello world" << std::endl;
	Game_def::Game game;

	game.run();
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
// ������� ������� ����������
//void quickSort(int* numbers, int left, int right)
//{
//    int pivot; // ����������� �������
//    int l_hold = left; //����� �������
//    int r_hold = right; // ������ �������
//    pivot = numbers[left];
//    while (left < right) // ���� ������� �� ���������
//    {
//        while ((numbers[right] >= pivot) && (left < right))
//            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
//        if (left != right) // ���� ������� �� ����������
//        {
//            numbers[left] = numbers[right]; // ���������� ������� [right] �� ����� ������������
//            left++; // �������� ����� ������� ������
//        }
//        while ((numbers[left] <= pivot) && (left < right))
//            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
//        if (left != right) // ���� ������� �� ����������
//        {
//            numbers[right] = numbers[left]; // ���������� ������� [left] �� ����� [right]
//            right--; // �������� ������ ������� ������
//        }
//    }
//    numbers[left] = pivot; // ������ ����������� ������� �� �����
//    pivot = left;
//    left = l_hold;
//    right = r_hold;
//    if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
//        quickSort(numbers, left, pivot - 1);
//    if (right > pivot)
//        quickSort(numbers, pivot + 1, right);
//}
//int main()
//{
//    float a[10];
//    // ���������� ������� ���������� �������
//    for (int i = 0; i < 10; i++)
//        a[i] = rand() % 20 - 10;
//    // ����� ��������� ������� �� ����������
//    for (int i = 0; i < 10; i++)
//        printf("%0.f ", a[i]);
//    printf("\n");
//    quicksort(a, 0, 9); // ����� ������� ����������
//              // ����� ��������� ������� ����� ����������
//    for (int i = 0; i < 10; i++)
//        printf("%0.f ", a[i]);
//    printf("\n");
//    getchar();
//    return 0;
//}