#include <iostream>
#include <fstream>
using namespace std;

struct stack {
	int data;
	stack* next;
};

void st(); //c������� ���� ����� ������

int pop(); //���������� ��������

void message(); //����

int getInt(); // ���������������. ��������� ��������� ��������, ���������� 0, ���� ������������

void push(int); // ���������������. �������� ���� �������� � ����
void pushCon(); // ���� ������ �� �������
void pushFile(); // ���� ������ �� ����� 

void showAll(); // ������� �� �����
void write(); // ������� � ����

int check(); //����������, ���� �� � ����� ���� �� ���� �������, ������� � �������� ���������

void clean(); //������� ��� �������� �� �����