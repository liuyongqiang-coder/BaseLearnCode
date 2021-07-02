// CirQueue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class MyCircularQueue {
	//public:
	//	int list[100];
	//	int head = 0;
	//	int end = 0;
	//	int list_size = 0;
	//	int list_num = 0;
	//	MyCircularQueue(int k) {
	//		list_size = k;
	//	}
	//
	//	bool enQueue(int value) {
	//		if (list_size > end - head)
	//		{
	//			if (list_size == end)
	//			{
	//				end = 0;
	//			}
	//			list[end] = value;
	//			end++;
	//			list_num++;
	//			return true;
	//		}
	//		else
	//		{
	//			return false;
	//		}
	//	}
	//
	//	bool deQueue() {
	//		if (list_num > 0)
	//		{
	//			list[head] = 0;
	//			if (head == 0&&end == list_size-1)
	//			{
	//				end--;
	//			}
	//			else
	//			{
	//				if (head == list_size)
	//				{
	//					head = 0;
	//				}
	//				else
	//				{
	//					head++;
	//				}
	//			}
	//			list_num--;
	//			if (head == end)
	//			{
	//				head = 0;
	//				end = 0;
	//			}
	//			return true;
	//		}
	//		else
	//		{
	//			return false;
	//		}

	//}

	//int Front() {
	//	if (list_num == 0)
	//	{
	//		return -1;
	//	}
	//	else
	//	{
	//		return list[head];
	//	}
	//}

	//int Rear() {
	//	return list[end - 1];
	//}

	//bool isEmpty() {
	//	if (list_num == 0)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	//bool isFull() {
	//	if (end - head == list_size)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}

	//}
private:
	int *data;
	int front, rear;
	int len;
public:
	MyCircularQueue(int k) {
		data = new int[k];
		front = rear = -1;
		len = k;
	}

	~MyCircularQueue() {
		delete[] data;
	}

	bool enQueue(int value) {
		if (isFull())
			return false;
		if (isEmpty())
			front++;
		rear = (rear + 1) % len;//rear后移一位,若到最后则转到数组头部
		data[rear] = value;
		return true;
	}

	bool deQueue() {
		if (isEmpty())
			return false;
		if (front == rear&&front != -1)//只剩一位
			front = rear = -1;
		else
			front = (front + 1) % len;
		return true;
	}

	int Front() {
		if (isEmpty())
			return -1;
		return data[front];
	}

	int Rear() {
		if (isEmpty())
			return -1;
		return data[rear];
	}

	bool isEmpty() {
		return(front == rear&&front == -1);
	}

	bool isFull() {
		return((rear + 1) % len == front);
	}
};

int main()
{
	MyCircularQueue *queue = new MyCircularQueue(8);
	bool a = queue->enQueue(3);
	a = queue->enQueue(2);
	a = queue->enQueue(5);
	a = queue->enQueue(0);
	bool f = queue->deQueue();
	f = queue->deQueue();
	bool r = queue->isEmpty();
	r = queue->isEmpty();
	int num = queue->Rear();
	num = queue->Rear();
	f = queue->deQueue();
    return 0;
}

